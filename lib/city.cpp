#include "city.h"

void City::Update() {
    cpr::Response weather_response = cpr::Get(
            cpr::Url{"https://api.open-meteo.com/v1/forecast?latitude=" + std::to_string(coordinates_.latitude) +
                     "&longitude=" + std::to_string(coordinates_.longitude) +
                     "&hourly=temperature_2m,apparent_temperature,precipitation_probability,precipitation,weathercode,visibility,windspeed_10m&forecast_days=" +
                     std::to_string(kNumberDays)});
    if (weather_response.status_code == 200) {
        nlohmann::json weather_json = nlohmann::json::parse(weather_response.text);
        for (int i = 0; i < kNumberDays; ++i) {
            City::Day day;
            for (int j = 0; j < 4; ++j) {
                Time current_time = static_cast<Time>(j);
                size_t current_hour = (kStartHour + j + (kStepHour * j)) + kHourDays * i;
                day.first[current_time] = Weather(weather_json["hourly"]["temperature_2m"][current_hour],
                                                  weather_json["hourly"]["apparent_temperature"][current_hour],
                                                  weather_json["hourly"]["windspeed_10m"][current_hour],
                                                  weather_json["hourly"]["visibility"][current_hour],
                                                  weather_json["hourly"]["precipitation"][current_hour],
                                                  weather_json["hourly"]["precipitation_probability"][current_hour],
                                                  weather_json["hourly"]["weathercode"][current_hour]);
                std::stringstream ss1;
                ss1 << weather_json["hourly"]["time"][kStartHour + kHourDays * i];
                day.second = ss1.str().substr(1, ss1.str().size() - 8);
                ss1.clear();
            }
            forecast_.push_back(day);
        }
    } else {
        for (int i = 0; i < kNumberDays; ++i) {
            City::Day day;
            for (int j = 0; j < 4; ++j) {
                Time current_time = static_cast<Time>(j);
                day.first[current_time] = Weather();
                day.second = "No date";
            }
            forecast_.push_back(day);
        }
    }
}
