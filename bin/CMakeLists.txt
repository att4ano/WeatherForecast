add_executable(labwork main.cpp)

target_link_libraries(labwork PRIVATE WeatherForecast)
target_link_libraries(labwork PRIVATE cpr::cpr)
target_link_libraries(labwork PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(labwork PRIVATE ftxui::dom ftxui::component ftxui::screen)
target_include_directories(labwork PRIVATE ${PROJECT_SOURCE_DIR})
