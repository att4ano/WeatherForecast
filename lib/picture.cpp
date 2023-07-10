#include "picture.h"

ftxui::Element DrawPicture(uint16_t weather_code, StatusCode status_code) {
    ftxui::Element picture_element;
    if (status_code == StatusCode::OK) {
        if (weather_code == 0) {
            picture_element = flex(ftxui::vbox({
                                                       ftxui::text(weather_code_[weather_code]),
                                                       ftxui::text("       \\   /      "),
                                                       ftxui::text("        .-.        "),
                                                       ftxui::text("     ― (   ) ―    "),
                                                       ftxui::text("        `-’        "),
                                                       ftxui::text("       /   \\      ")
                                               }));
        } else if (weather_code == 1) {
            picture_element = flex(ftxui::vbox({
                                                       ftxui::text(weather_code_[weather_code]),
                                                       ftxui::text("     \\__/"),
                                                       ftxui::text("  ___/  \\(.__.)     "),
                                                       ftxui::text("     \\__(---)-)-).   "),
                                                       ftxui::text("    / (_.__.__)__)    ")
                                               }));
        } else if (weather_code == 2) {
            picture_element = flex(ftxui::vbox({
                                                       ftxui::text(weather_code_[weather_code]),
                                                       ftxui::text("   (._).           "),
                                                       ftxui::text("  (_._)_) .(__) .   "),
                                                       ftxui::text("         (_.)_._)  ")
                                               }));
        } else if (weather_code == 3) {
            picture_element = flex(ftxui::vbox({
                                                       ftxui::text(weather_code_[weather_code]),
                                                       ftxui::text("         (.__.)     "),
                                                       ftxui::text("     .-(---)-)-).   "),
                                                       ftxui::text("     (_.__.__)__)    ")
                                               }));
        } else if (weather_code == 51 || weather_code == 53 || weather_code == 55 || weather_code == 61 ||
                   weather_code == 63) {
            picture_element = flex((ftxui::vbox({
                                                        ftxui::text(weather_code_[weather_code]),
                                                        ftxui::text("   .(__).           "),
                                                        ftxui::text("  (_._)_)  .(_)).  "),
                                                        ftxui::text("  ' ' ' ' (_.)_._) "),
                                                        ftxui::text("   ' ' '   '  '  '   "),
                                                        ftxui::text("          '  '   ' ")
                                                })));
        } else if (weather_code == 56 || weather_code == 57 || weather_code == 66 || weather_code == 67) {
            picture_element = flex((ftxui::vbox({
                                                        ftxui::text(weather_code_[weather_code]),
                                                        ftxui::text("   .(__).           "),
                                                        ftxui::text("  (_._)_)  .(_)).  "),
                                                        ftxui::text("  ' * ' ' (_.)_._) "),
                                                        ftxui::text("   * ' *   *  '  *   "),
                                                        ftxui::text("          '  *   ' ")
                                                })));
        } else if (weather_code == 65 || weather_code == 80 || weather_code == 81 || weather_code == 82) {
            picture_element = flex(ftxui::vbox({
                                                       ftxui::text(weather_code_[weather_code]),
                                                       ftxui::text("         .--_.      "),
                                                       ftxui::text("     .(-( --- ).    "),
                                                       ftxui::text("    (___.__)__)    "),
                                                       ftxui::text("     / /  /  /     "),
                                                       ftxui::text("     / /   /      ")
                                               }));
        } else if (weather_code == 67) {
            picture_element = flex(ftxui::vbox({
                                                       ftxui::text(weather_code_[weather_code]),
                                                       ftxui::text("         .--_.      "),
                                                       ftxui::text("     .(-( --- ).    "),
                                                       ftxui::text("    (___*__)_*)    "),
                                                       ftxui::text("     / / */ /     "),
                                                       ftxui::text("     / */ */     ")
                                               }));
        } else if (weather_code == 71 || weather_code == 73) {
            picture_element = flex(ftxui::vbox({
                                                       ftxui::text(weather_code_[weather_code]),
                                                       ftxui::text("   .(_).          "),
                                                       ftxui::text("  (_*_)_) (_(__)   "),
                                                       ftxui::text("  *   *  (_.)_*_)  "),
                                                       ftxui::text("     *    *    *   "),
                                                       ftxui::text("        *    *     ")
                                               }));
        } else if (weather_code == 75 || weather_code == 85 || weather_code == 86) {
            picture_element = flex(ftxui::vbox({
                                                       ftxui::text(weather_code_[weather_code]),
                                                       ftxui::text("         .--.      "),
                                                       ftxui::text("     .(-( --- ).    "),
                                                       ftxui::text("    (*__*__)*_)    "),
                                                       ftxui::text("    * *  * * *     "),
                                                       ftxui::text("   * * * * * *     ")
                                               }));
        } else if (weather_code == 77) {
            picture_element = flex(ftxui::vbox({
                                                       ftxui::text(weather_code_[weather_code]),
                                                       ftxui::text("         .--.      "),
                                                       ftxui::text("     .(-(_---_).    "),
                                                       ftxui::text("    (___*__)__)    "),
                                                       ftxui::text("     o  0   o      "),
                                                       ftxui::text("     0 o  o  0     ")
                                               }));
        } else if (weather_code == 95 || weather_code == 96) {
            picture_element = flex(ftxui::vbox({
                                                       ftxui::text(weather_code_[weather_code]),
                                                       ftxui::text("         .--.      "),
                                                       ftxui::text("     .(-(_---_).    "),
                                                       ftxui::text("    (___.__)_.)    "),
                                                       ftxui::text("      _/  _/ /     "),
                                                       ftxui::text("    / /   /         ")
                                               }));
        } else if (weather_code == 99) {
            picture_element = flex(ftxui::vbox({
                                                       ftxui::text(weather_code_[weather_code]),
                                                       ftxui::text("         .--.      "),
                                                       ftxui::text("     .(-(_---_).    "),
                                                       ftxui::text("    (___.__)_.)    "),
                                                       ftxui::text("     0 _/  _/ /     "),
                                                       ftxui::text("    / / 0  / 0       ")
                                               }));
        }
    }
    return picture_element;
}

ftxui::Element ShowPart(Time current_time, uint16_t day_index, City& city) {
    ftxui::Element picture = DrawPicture(city.GetForecast()[day_index].first[current_time].weather_type,
                                         city.GetForecast()[day_index].first[current_time].status_code);
    std::string weather_type = weather_code_[city.GetForecast()[day_index].first[current_time].weather_type];
    std::pair<float, float> day_temperature = city.GetForecast()[day_index].first[current_time].day_temperature;
    uint16_t wind_speed = city.GetForecast()[day_index].first[current_time].wind_speed;
    uint16_t visibility = city.GetForecast()[day_index].first[current_time].visibility;
    float precipitation = city.GetForecast()[day_index].first[current_time].precipitation;
    uint16_t precipitation_probability = city.GetForecast()[day_index].first[current_time].precipitation_probability;
    std::string part_day;
    switch (current_time) {
        case Time::MORNING:
            part_day = "morning";
            break;
        case Time::NIGHT:
            part_day = "night";
            break;
        case Time::DAY:
            part_day = "day";
            break;
        case Time::EVENING:
            part_day = "evening";
            break;
    }
    ftxui::Element element = border(vbox(vcenter(hcenter(ftxui::text(part_day))), ftxui::separator(),
                                         ftxui::hbox({hcenter(vcenter(picture)),
                                         vcenter(ftxui::vbox({hcenter(ftxui::text(std::to_string(static_cast<int>(day_temperature.first)) + "°С(" + std::to_string(static_cast<int>(day_temperature.second)) + ")")),
                                         hcenter(ftxui::text(std::to_string(wind_speed) + " km/h")),
                                         hcenter(ftxui::text(std::to_string(visibility) + " m")),
                                         hcenter(ftxui::text(std::to_string(precipitation) + " mm")),
                                         hcenter(ftxui::text(std::to_string(precipitation_probability) + " %"))}))})));
    return element;
}

ftxui::Element ShowFullDay(uint16_t day_index, City& city) {
    std::string current_date = city.GetForecast()[day_index].second;
    ftxui::Element night = ShowPart(Time::NIGHT, day_index, city);
    ftxui::Element morning = ShowPart(Time::MORNING, day_index, city);
    ftxui::Element day = ShowPart(Time::DAY, day_index, city);
    ftxui::Element evening = ShowPart(Time::EVENING, day_index, city);
    ftxui::Element element = vbox(hcenter(ftxui::text("date " + current_date)),
                           hbox(night, morning, day, evening));
    return element;
}

ftxui::Element ShowCityDay(City& city, uint16_t amount_of_days) {
    ftxui::Elements tmp;

    for (size_t i = 0 ; i < amount_of_days; ++i) {
        tmp.push_back(flex(ShowFullDay(i, city)));
    }

    ftxui::Element final_element = border(vbox(hcenter(ftxui::text(city.GetName())), ftxui::separator(), vbox(tmp)));
    return final_element;
}
