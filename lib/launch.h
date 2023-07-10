#include "picture.h"

void Update(Parser& parser, const nlohmann::json& json);

void Output(Parser& parser);

void RunForecast(std::ifstream& file);
