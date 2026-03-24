#include "building.h"

Building::Building(std::string const &id, std::vector<Room> const &room_list) : building_id {id}, rooms {room_list} {
    update_area();
    update_cleaners();
}

void Building::update_area() {
    areal = 0; // Reset area
    for (const auto i : rooms) {
        areal += i.get_area();
    }
}

void Building::update_cleaners() {
    int cleaner_criteria1 = 1; // Følger krav1 til antall renholdere: sjekker areal.
    int cleaner_criteria2 = 0; // Følger krav2 til antall renholdere: sjekker antallrom

    double areal_copy = get_area();
    double exponent = std::log10(areal_copy);
    double mantissa = areal_copy / std::pow(10, exponent);

    cleaner_criteria1 = std::ceil((mantissa * exponent) / 15); // Hver 15ende kvadratmeter skal ha en vasker

    // Krav2:
    for (const auto i : rooms) {
        cleaner_criteria2 += 1;
    }

    // Hvis krav1 > krav2, sett krav1 til amount of cleaners, ellers sett krav2.
    amount_of_cleaners = (cleaner_criteria1 > cleaner_criteria2) ? cleaner_criteria1 : cleaner_criteria2;
}

int Building::get_cleaners() const { return amount_of_cleaners; }
double Building::get_area() const { return areal; }

