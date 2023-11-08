#include "Holes.h"

Holes::Holes() {}

void Holes::init(int y) {
    int _num = rand() % (38 - 22 + 1) + 22;  // random number from 22 to 38
    _x = _num;
    _y = y;// the hole always appear on the top of the screen 

    if (_x >= 22 && _x<=30) { // diagonal down left
        _velocity.x = -1;
        _velocity.y = 1;
    } else if (_x >= 30 && _x<=38) { // straightly downwards
        _velocity.x = 0;
        _velocity.y = 1;
    } else { // diagonal down right
        _velocity.x = 1;
        _velocity.y = 1;
    }
}

// all the holes have the same size and we use random numbers to determine which one is self generated to make the game more fancinating
void Holes::draw(N5110 &lcd) {
    int _i = rand() % 100 + 1;  // generating random numbers
    // use _i to generating random types of hole array
    if (_i <= 50) { // type 1
        const int _hole_image [10][17] =   {
            { 0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0 },
            { 0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0 },
            { 0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0 },
            { 0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0 },
            { 0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
            { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
            { 0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0 },
            { 0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0 },
            { 0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0 },
            { 0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0 },
        };
        lcd.drawObject(_x,_y,10,17,(int *)_hole_image);// 2 image have the same size thus using the same command is ok
    } else  { //type 2
        const int _hole_image [10][17] =   {
            { 1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0 },
            { 1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0 },
            { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0 },
            { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
            { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
            { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0 },
            { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0 },
            { 0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0 },
            { 0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0 },
            { 0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0 },
        };
        lcd.drawObject(_x,_y,10,17,(int *)_hole_image);// 2 image have the same size thus using the same command is ok
    }
}

void Holes::update(){
    _x += _velocity.x;
    _y += _velocity.y;
    // check if the hole goes off the screen 
    if (_y > 48) {
        _x = rand() % (38 - 22 + 1) + 22;  // random number from 22 to 38
        _y = 0;
        //int _i = rand() % 100 + 1;  // generating random numbers
        if (_x >= 22 && _x<=30) { // diagonal down left
            _velocity.x = -1;
            _velocity.y = 1;
        } else if (_x >= 30 && _x<=38) { // straightly downwards
            _velocity.x = 0;
            _velocity.y = 1;
        } else { // diagonal down right
            _velocity.x = 1;
            _velocity.y = 1;
        }
    }  
}

void Holes::set_velocity(Position2D v){
    _velocity.x = v.x;
    _velocity.y = v.y;
}

void Holes::set_pos(Position2D p) {
    _x = p.x;
    _y = p.y;
}

Position2D Holes::get_velocity(){ return {_velocity.x,_velocity.y}; }

Position2D Holes::get_pos() { return {_x,_y}; }


