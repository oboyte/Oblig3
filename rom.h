#ifndef ROM_H
#define ROM_H

class Room
{
    double width = 0;
    double length = 0;
public:
    Room() = default;
    Room(double wid, double len);

    double get_area() const;
};

#endif // ROM_H
