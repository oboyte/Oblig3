#ifndef BUILDING_H
#define BUILDING_H

#include <vector>
#include <string>
#include <cmath>

#include "rom.h"

class Building
{
    std::string const building_id { };
    std::vector<Room> rooms = { };
    int amount_of_cleaners = 1; // Default på 1
    double areal = 0;

    void update_area();
    void update_cleaners();

public:
    Building() = default;
    Building(std::string const &id, std::vector<Room> const &room_list);

    double get_area(); // Få total areal i byggningen.
    int get_cleaners();
    int get_room_amount();
    void insert_room(Room &room);
    std::string get_ID() const;
};

#endif // BUILDING_H
