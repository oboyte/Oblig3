#ifndef ROM_H
#define ROM_H

class Room
{
    double width = 0;
    double height = 0;
public:
    Room() = default;
    Room(double wid, double len);

    double get_area() const;
    double get_width() const;
    double get_height() const;
};

#endif // ROM_H
