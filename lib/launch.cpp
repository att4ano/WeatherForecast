#include "launch.h"

static bool first_parse = true;

void Update(Parser& parser) {
    cpr::Url weather_url = cpr::Url{"https://api.open-meteo.com/v1/forecast"};
    std::vector<cpr::AsyncResponse> responses_array;
    for (auto& city : parser.GetCities()) {
        cpr::Parameters params{{"latitude",      std::to_string(city.GetCoordinates().latitude)},
                               {"longitude",     std::to_string(city.GetCoordinates().longitude)},
                               {"forecast_days", std::to_string(kNumberDays)},
                               {"hourly",        "temperature_2m,weathercode,apparent_temperature,windspeed_10m,precipitation_probability,precipitation,visibility"}};
        responses_array.emplace_back(cpr::GetAsync(weather_url, params));
        city.GetForecast().clear();
    }
    for (size_t i = 0; i < responses_array.size(); ++i) {
        cpr::Response response = responses_array[i].get();
        nlohmann::json weather_json = nlohmann::json::parse(response.text);
        for (int j = 0; j < kNumberDays; ++j) {
            City::Day day;
            for (int k = 0; k < 4; ++k) {
                Time current_time = static_cast<Time>(k);
                size_t current_hour = (kStartHour + k + (kStepHour * j)) + kHourDays * i;
                day.first[current_time] = Weather(weather_json["hourly"]["temperature_2m"][current_hour],
                                                  weather_json["hourly"]["apparent_temperature"][current_hour],
                                                  weather_json["hourly"]["windspeed_10m"][current_hour],
                                                  weather_json["hourly"]["visibility"][current_hour],
                                                  weather_json["hourly"]["precipitation"][current_hour],
                                                  weather_json["hourly"]["precipitation_probability"][current_hour],
                                                  weather_json["hourly"]["weathercode"][current_hour]);
                std::stringstream ss1;
                ss1 << weather_json["hourly"]["time"][kStartHour + kHourDays * j];
                day.second = ss1.str().substr(1, ss1.str().size() - 8);
                ss1.clear();
            }
            parser.GetCities()[i].GetForecast().push_back(day);
        }
    }
}

void UpdateTimer(Parser& parser, ftxui::ScreenInteractive& screen, std::atomic<bool>& is_active) {
    uint32_t frequency = parser.GetFrequency();
    while (is_active) {
        for (int i = 0; i < frequency; ++i) {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            if (!is_active) {
                break;
            }
        }
        if (!is_active) {
            break;
        }
        screen.PostEvent(ftxui::Event::Custom);
    }
}

void Output(Parser& parser) {
    int64_t index = 0;
    int amount_of_days = 2;
    auto screen = ftxui::ScreenInteractive::TerminalOutput();
    std::atomic<bool> is_active = true;
    auto renderer = ftxui::Renderer([&parser, &index, &amount_of_days] {
        return ShowCityDay(parser.GetCities()[index], amount_of_days);
    });
    auto component = CatchEvent(renderer, [&](const ftxui::Event& event) {
        if (event == ftxui::Event::Escape) {
            screen.ExitLoopClosure()();
            return true;
        } else if (event == ftxui::Event::Character('n')) {
            index = (++index) % parser.GetCities().size();
            return true;
        } else if (event == ftxui::Event::Character('p')) {
            --index;
            if (index < 0) {
                index = parser.GetCities().size() - 1;
            }
            return true;
        } else if (event == ftxui::Event::Character('+')) {
            amount_of_days = std::min(++amount_of_days, kNumberDays);
            return true;
        } else if (event == ftxui::Event::Character('-')) {
            amount_of_days = std::max(--amount_of_days, 1);
            return true;
        } else if (event == ftxui::Event::Character('r') || event == ftxui::Event::Custom) {
            Update(parser);
            return true;
        } else {
            return false;
        }
    });
    std::thread update_timer(UpdateTimer, std::ref(parser), std::ref(screen), std::ref(is_active));
    screen.Loop(component);
    is_active = false;
    update_timer.join();
}

void RunForecast(std::ifstream& file) {
    Parser parser;
    nlohmann::json forecast_json = nlohmann::json::parse(file);
    parser.Parse(forecast_json);
    std::thread f1(Output, std::ref(parser));
    f1.join();
}
