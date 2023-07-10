#include "cpr/cpr.h"
#include "nlohmann/json.hpp"
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include "ftxui/screen/box.hpp"
#include "ftxui/component/component.hpp"
#include "ftxui/component/screen_interactive.hpp"

#include <thread>
#include <chrono>
#include <windows.h>
#include <iostream>

const static int kNumberDays = 7;
constexpr static int kStartHour = 2;
constexpr static int kStepHour = 6;

static std::map<uint16_t, std::string> weather_code_ = {
        {0,  "Clear"},
        {1,  "Mainly clear"},
        {2,  "Partly cloudy"},
        {3,  "Overcast"},
        {45, "Fog"},
        {48, "Fog"},
        {51, "Drizzle"},
        {53, "Drizzle"},
        {55, "Drizzle"},
        {56, "Freezing drizzle"},
        {57, "Freezing drizzle"},
        {61, "Rain"},
        {63, "Rain"},
        {65, "Rain"},
        {66, "Freezing rain"},
        {67, "Freezing rain"},
        {71, "Snow fall"},
        {73, "Snow fall"},
        {75, "Snow fall"},
        {77, "Snow grain"},
        {80, "Rain shower"},
        {81, "Rain shower"},
        {82, "Rain shower"},
        {85, "Snow showers"},
        {86, "Snow showers"},
        {95, "Thunderstorm"},
        {96, "Thunderstorm"},
        {99, "Thunderstorm"}
};

enum class StatusCode {
    OK,
    NOT_OK
};
