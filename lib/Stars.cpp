#include "Stars.h"

Stars::Stars() {}

void Stars::init() {
    int _num = rand() % 84 + 1;  // random number from 22 to 46
    _x = _num;
    _y = 0;
    
    _velocity.x = 0;
    _velocity.y = 1;

}

void Stars::draw(N5110 &lcd) {
    lcd.setPixel( _x+5, _y);
    lcd.setPixel( _x+4, _y+1);
    lcd.setPixel( _x+5, _y+1, 0);
    lcd.setPixel( _x+6, _y+1);
    lcd.setPixel( _x+3, _y+2);
    lcd.setPixel( _x+4, _y+2, 0);
    lcd.setPixel( _x+5, _y+2, 0);
    lcd.setPixel( _x+6, _y+2, 0);
    lcd.setPixel( _x+7, _y+2);
    lcd.setPixel( _x, _y+3);
    lcd.setPixel( _x+1, _y+3);
    lcd.setPixel( _x+2, _y+3);
    lcd.setPixel( _x+3, _y+3, 0);
    lcd.setPixel( _x+4, _y+3, 0);
    lcd.setPixel( _x+5, _y+3, 0);
    lcd.setPixel( _x+6, _y+3, 0);
    lcd.setPixel( _x+7, _y+3, 0);
    lcd.setPixel( _x+8, _y+3);
    lcd.setPixel( _x+9, _y+3);
    lcd.setPixel( _x+10, _y+3);
    lcd.setPixel( _x+1, _y+4);
    lcd.setPixel( _x+2, _y+4, 0);
    lcd.setPixel( _x+3, _y+4, 0);
    lcd.setPixel( _x+4, _y+4, 0);
    lcd.setPixel( _x+5, _y+4, 0);
    lcd.setPixel( _x+6, _y+4, 0);
    lcd.setPixel( _x+7, _y+4, 0);
    lcd.setPixel( _x+8, _y+4);
    lcd.setPixel( _x+9, _y+4);
    lcd.setPixel( _x+2, _y+5);
    lcd.setPixel( _x+3, _y+5, 0);
    lcd.setPixel( _x+4, _y+5, 0);
    lcd.setPixel( _x+5, _y+5);
    lcd.setPixel( _x+6, _y+5, 0);
    lcd.setPixel( _x+7, _y+5, 0);
    lcd.setPixel( _x+8, _y+5);
    lcd.setPixel( _x+2, _y+6);
    lcd.setPixel( _x+3, _y+6);
    lcd.setPixel( _x+4, _y+6);
    lcd.setPixel( _x+6, _y+6);
    lcd.setPixel( _x+7, _y+6);
    lcd.setPixel( _x+8, _y+6);
    lcd.setPixel( _x+2, _y+7);
    lcd.setPixel( _x+8, _y+7);
}

void Stars::update(){   
    _y += _velocity.y;
    if (_y > 48) {
        _x = rand() % 84 + 1;  // random number from 22 to 46
        _y = 0;
    }  
}

void Stars::set_velocity(Position2D v){
    _velocity.x = v.x;
    _velocity.y = v.y;
}

void Stars::set_pos(Position2D p) {
    _x = p.x;
    _y = p.y;
}

Position2D Stars::get_velocity(){ return {_velocity.x,_velocity.y}; }

Position2D Stars::get_pos() { return {_x,_y}; }


