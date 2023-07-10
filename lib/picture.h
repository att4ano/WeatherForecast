#include "parser.h"

ftxui::Element DrawPicture(uint16_t weather_code);

ftxui::Element ShowPart(Time current_time, uint16_t day_index, City& city);

ftxui::Element ShowFullDay(uint16_t day_index, City& city);

ftxui::Element ShowCityDay(City& city, uint16_t amount_of_days);
