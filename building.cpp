#include "building.h"

Building::Building(std::string const &id, std::vector<Room> const &room_list) : building_id {id}, rooms {room_list} {
    update_area();
    update_cleaners();
}

void Building::insert_room(Room &room) {
    rooms.push_back(room);
}

void Building::update_area() {
    areal = 0; // Reset area
    for (const auto i : rooms) {
        areal += i.get_area();
    }
}
void Building::update_cleaners() {
    int cleaner_criteria1 = std::ceil(get_area() / 15); // Følger krav1 til antall renholdere: sjekker areal.
    int cleaner_criteria2 = std::ceil(rooms.size() / 2 ); // Følger krav2 til antall renholdere: sjekker antallrom

    // Sett amount of cleaners til største verdi av de to variablene.
    amount_of_cleaners = std::max(cleaner_criteria1, cleaner_criteria2);
}

int Building::get_cleaners() { update_cleaners(); return amount_of_cleaners; }
double Building::get_area() { update_area(); return areal; }
int Building::get_room_amount() {
    int amount = 0;
    for(auto room : rooms) {
        amount++;
    }
    return amount;
}
std::string Building::get_ID() const { return building_id; }
