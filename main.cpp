#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <format>

#include "rom.h"
#include "building.h"

void read_file(std::ifstream &file, std::vector<Building> &buildings) {
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
        bool found_building = false;
        for (auto &bld : buildings) {
            // Sjekk om byggningen eksisterer eller ikke.
            if (bld.get_ID() == split_line[2]) { // Hvis eksisterer, insert rommet inn i byggningen
                bld.insert_room(new_room);
                found_building = true;
                break;
            }
        }
        if (!found_building) {
            Building new_building(split_line[2], { new_room }); // Ellers, lag ny byggning med (hittil) 1 rom.
            buildings.push_back(new_building);
        }
    }
}

void write_file(std::vector<Building> &buildings) {
    for (auto &building : buildings) {
        std::string filename = std::format("{}.txt", building.get_ID());
        std::ofstream output_file(filename, std::ios::out);

        output_file << "Number of rooms: " << building.get_room_amount() << '\n'
                    << "Number of cleaners: " << building.get_cleaners() << '\n'
                    << "Area: " << building.get_area();
    }
}

int main()
{
    std::ifstream input_file("../../input.txt", std::ios::in);

    std::vector<Building> Buildings { };
    if (!input_file.is_open()) std::cout << "Failed to open file.\n";
    else {
        read_file(input_file, Buildings);
    }
    write_file(Buildings);
    return 0;
}
