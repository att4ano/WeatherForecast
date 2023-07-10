#include "lib/launch.h"

int main(int argc, char** argv) {
    if (argc > 0) {
        std::ifstream file(argv[1]);
        if (file.is_open()) {
            RunForecast(file);
            return EXIT_SUCCESS;
        } else {
            std::cerr << "Could not open the file";
            return EXIT_FAILURE;
        }
    }
}
