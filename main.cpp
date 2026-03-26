#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include "rom.h"
#include "building.h"

std::vector<Building> read_file(std::ifstream file) {
    std::vector<Building> vec { };

    std::string line;
    while(std::getline(file, line)) {
        std::vector<std::string> split_line { };

        std::stringstream t(line); // Del opp strengen i flere deler
        std::string word { };
        while (t >> word) {
            split_line.push_back(word);
        }

        Room new_room(std::stod(split_line[0]), std::stod(split_line[1]));

    }


}

int main()
{


    return 0;
}
