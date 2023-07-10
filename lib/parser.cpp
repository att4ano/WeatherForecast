#include "parser.h"
#include <sstream>

void Parser::Parse(nlohmann::json& config) {
    frequency_ = config["frequency"];
    days_ = config["number_days"];
    cpr::Url url = cpr::Url{"https://api.api-ninjas.com/v1/city"};
    std::vector<cpr::AsyncResponse> responses_array;
    for (size_t i = 0; i < config["city_names"].size(); ++i) {
        std::ostringstream ss1;
        ss1 << config["city_names"][i];
        std::string name = ss1.str();
        responses_array.emplace_back(
                cpr::GetAsync(url, cpr::Header{{"X-Api-Key", "Xt2GLkJl8IsvR2z3GSKVOv0amlMulNEeVKb04Sx4"}}, cpr::Parameters{{"name", name.substr(1, name.size() - 2)}}));
    }
    for (auto& async_responses: responses_array) {
        cpr::Response response = async_responses.get();
        nlohmann::json city_json = nlohmann::json::parse(response.text.substr(1, response.text.size() - 2));
        cities_.emplace_back(city_json);
    }
    cpr::Url weather_url = cpr::Url{"https://api.open-meteo.com/v1/forecast"};
    std::vector<cpr::AsyncResponse> weather_responses_array;
    for (size_t i = 0; i < cities_.size(); ++i) {
        cpr::Parameters params{{"latitude",      std::to_string(cities_[i].GetCoordinates().latitude)},
                               {"longitude",     std::to_string(cities_[i].GetCoordinates().longitude)},
                               {"forecast_days", std::to_string(kNumberDays)},
                               {"hourly",        "temperature_2m,weathercode,apparent_temperature,windspeed_10m,precipitation_probability,precipitation,visibility"}};
        weather_responses_array.emplace_back(cpr::GetAsync(weather_url, params));
    }

    for (size_t i = 0; i < weather_responses_array.size(); ++i) {
        cpr::Response response = weather_responses_array[i].get();
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
            cities_[i].GetForecast().push_back(day);
        }
    }
}
