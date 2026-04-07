#include "rom.h"

Room::Room(double wid, double len) : width { wid }, height { len } {
}

double Room::get_area() const { return width*height; }
double Room::get_width() const { return width; }
double Room::get_height() const { return height; }
