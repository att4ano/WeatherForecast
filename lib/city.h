#include <iostream>
#include "weather.h"

constexpr static int  kHourDays = 24;

enum class Time {NIGHT, MORNING, DAY, EVENING};

class City {
public:
    using Day = std::pair<std::map<Time, Weather>, std::string>;
private:

    struct Coordinates {
        float latitude = 0;
        float longitude = 0;

        Coordinates() = default;

        Coordinates(float latitude, float longitude)
                : latitude{latitude}, longitude{longitude} {}

        Coordinates(const Coordinates& other) {
            latitude = other.latitude;
            longitude = other.longitude;
        }
    };

    std::string city_name_;
    Coordinates coordinates_;
    std::string country_;
    std::vector<Day> forecast_;
public:

    City() = default;

    City(std::string& city_name, float latitude, float longitude, std::string& country)
            : city_name_(city_name),
              coordinates_(Coordinates(latitude, longitude)),
              country_(country) {}

    explicit City(const nlohmann::json& city_json)
            : city_name_(city_json["name"]),
              coordinates_{city_json["latitude"], city_json["longitude"]},
              country_(city_json["country"]) {}

    City(const City& other) = default;

    void Update();

    [[nodiscard]] std::vector<Day>& GetForecast() {
        return forecast_;
    };

    [[nodiscard]] std::string GetName() const {
        return city_name_;
    }

    [[nodiscard]] Coordinates GetCoordinates() const {
        return coordinates_;
    }
};

