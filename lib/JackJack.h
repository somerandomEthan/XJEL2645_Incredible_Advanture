#ifndef JACKJACK_H
#define MJACKJACK_H

#include "mbed.h"
#include "N5110.h"
#include "Utils.h"  

class JackJack
{
public:

    JackJack();
    void init(); 
    void draw(N5110 &lcd);
    void update(UserInput input);
    Position2D get_pos();

private:

    int _x;
    int _y;
};
#endif