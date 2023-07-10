#include "city.h"

class Parser {
    std::vector<City> cities_;
    uint32_t frequency_ = 0;
    uint32_t days_ = 0;
public:

    Parser() = default;

    Parser(uint32_t frequency, uint32_t days) : frequency_(frequency), days_(days){}

    ~Parser() = default;

    void Parse(nlohmann::json& config);

    std::vector<City>& GetCities() {
        return cities_;
    }

    [[nodiscard]] uint32_t GetAmountOfDays() const {
        return days_;
    }

    [[nodiscard]] uint32_t GetFrequency() const {
        return frequency_;
    }
};
