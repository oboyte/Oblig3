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

    double get_area() const; // Få total areal i byggningen.
    int get_cleaners() const;
    void insert_room(Room &room);
};

#endif // BUILDING_H
