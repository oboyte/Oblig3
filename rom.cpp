#include "rom.h"

Room::Room(double wid, double len) : width { wid }, length { len } {
}

double Room::get_area() const {
    return width*length;
}
