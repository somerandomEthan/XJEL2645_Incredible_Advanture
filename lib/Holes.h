#ifndef HOLES_H
#define HOLES_H

#include "mbed.h"
#include "N5110.h"
#include "Utils.h"  // for Position

/** Holes Class
@author Yusen Liu, University of Leeds
@Self-generating Holes in the Incredible Adventure game
@date April 2021
*/ 

class Holes
{

public:
    Holes();
    void init(int y);
    void draw(N5110 &lcd);
    void update();
    /// accessors and mutators
    void set_velocity(Position2D v);
    Position2D get_velocity();
    Position2D get_pos();
    void set_pos(Position2D p);
    
private:

    Position2D _velocity;
    int _x;
    int _y;
};
#endif