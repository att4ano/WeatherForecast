add_library(WeatherForecast libs.h weather.h city.h weather.cpp city.cpp parser.h parser.cpp picture.h picture.cpp launch.h launch.cpp)

target_link_libraries(WeatherForecast PRIVATE cpr::cpr)
target_link_libraries(WeatherForecast PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(WeatherForecast PRIVATE ftxui::dom ftxui::component ftxui::screen)