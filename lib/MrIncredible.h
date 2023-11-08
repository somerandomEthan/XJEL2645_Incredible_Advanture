#ifndef MRINCREDIBLE_H
#define MRINCREDIBLE_H

#include "mbed.h"
#include "N5110.h"
#include "Utils.h"  

class MrIncredible
{
public:

    MrIncredible();
    void init(); 
    void draw(N5110 &lcd);
    void update(DigitalIn &buttonA, DigitalIn &buttonB, DigitalIn &buttonC, DigitalIn &buttonD);
    Position2D get_pos();

private:

    int _x;
    int _y;


};
#endif