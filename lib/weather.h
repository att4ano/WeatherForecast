#include <map>
#include "libs.h"

struct Weather {
    std::pair<float, float> day_temperature;
    uint16_t wind_speed = 0;
    uint16_t weather_type = 0;
    uint16_t visibility = 0;
    float precipitation = 0.0;
    uint16_t precipitation_probability = 0;
    StatusCode status_code;

    Weather(float temperature, float apparent_temperature, uint16_t wind_speed, uint16_t visibility,
            float precipitation, uint16_t precipitation_probability, uint16_t weather_code)
            : wind_speed(wind_speed),
              visibility(visibility),
              precipitation(precipitation),
              precipitation_probability(precipitation_probability),
              day_temperature({temperature, apparent_temperature}),
              weather_type(weather_code)
    {
        status_code = StatusCode::OK;
    }

    Weather() {
        status_code = StatusCode::NOT_OK;
    }

};
