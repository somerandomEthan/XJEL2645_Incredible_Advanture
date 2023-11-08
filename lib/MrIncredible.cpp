#include "MrIncredible.h"

// nothing doing in the constructor and destructor
MrIncredible::MrIncredible() { }

void MrIncredible::init() {
    _x = 0;  
    _y = 48 - 20; // This is the left-top point * attention * the height of the character is 20
    //_height = 20;
    //_width = 17;
}

void MrIncredible::draw(N5110 &lcd) { 
    lcd.setPixel( _x+6, _y);
    lcd.setPixel( _x+7, _y);
    lcd.setPixel( _x+5, _y+1);
    lcd.setPixel( _x+6, _y+1);
    lcd.setPixel( _x+7, _y+1);
    lcd.setPixel( _x+8, _y+1);
    lcd.setPixel( _x+13, _y+1);
    lcd.setPixel( _x+14, _y+1);
    lcd.setPixel( _x+5, _y+2);
    lcd.setPixel( _x+6, _y+2);
    lcd.setPixel( _x+7, _y+2);
    lcd.setPixel( _x+8, _y+2);
    lcd.setPixel( _x+14, _y+2);
    lcd.setPixel( _x+5, _y+3);
    lcd.setPixel( _x+6, _y+3);
    lcd.setPixel( _x+7, _y+3);
    lcd.setPixel( _x+8, _y+3);
    lcd.setPixel( _x+9, _y+3);
    lcd.setPixel( _x+14, _y+3);
    lcd.setPixel( _x+15, _y+3);
    lcd.setPixel( _x+7, _y+4);
    lcd.setPixel( _x+8, _y+4);
    lcd.setPixel( _x+9, _y+4);
    lcd.setPixel( _x+10, _y+4);
    lcd.setPixel( _x+11, _y+4);
    lcd.setPixel( _x+14, _y+4);
    lcd.setPixel( _x+15, _y+4);
    lcd.setPixel( _x+16, _y+4);
    lcd.setPixel( _x+7, _y+4);
    lcd.setPixel( _x+8, _y+4);
    lcd.setPixel( _x+6, _y+5);
    lcd.setPixel( _x+7, _y+5);
    lcd.setPixel( _x+8, _y+5);
    lcd.setPixel( _x+9, _y+5);
    lcd.setPixel( _x+10, _y+5);
    lcd.setPixel( _x+11, _y+5);
    lcd.setPixel( _x+12, _y+5);
    lcd.setPixel( _x+13, _y+5);
    lcd.setPixel( _x+14, _y+5);
    lcd.setPixel( _x+15, _y+5);
    lcd.setPixel( _x+5, _y+6);
    lcd.setPixel( _x+6, _y+6);
    lcd.setPixel( _x+7, _y+6);
    lcd.setPixel( _x+8, _y+6);
    lcd.setPixel( _x+9, _y+6);
    lcd.setPixel( _x+10, _y+6);
    lcd.setPixel( _x+11, _y+6);
    lcd.setPixel( _x+12, _y+6);
    lcd.setPixel( _x+13, _y+6);
    lcd.setPixel( _x+14, _y+6);
    lcd.setPixel( _x+15, _y+6);
    lcd.setPixel( _x+1, _y+7);
    lcd.setPixel( _x+5, _y+7);
    lcd.setPixel( _x+6, _y+7);
    lcd.setPixel( _x+7, _y+7);
    lcd.setPixel( _x+8, _y+7);
    lcd.setPixel( _x+9, _y+7);
    lcd.setPixel( _x+10, _y+7);
    lcd.setPixel( _x+11, _y+7);
    lcd.setPixel( _x+12, _y+7);
    lcd.setPixel( _x+13, _y+7);
    lcd.setPixel( _x+14, _y+7);
    lcd.setPixel( _x+15, _y+7);
    lcd.setPixel( _x, _y+8);
    lcd.setPixel( _x+1, _y+8);
    lcd.setPixel( _x+5, _y+8);
    lcd.setPixel( _x+6, _y+8);
    lcd.setPixel( _x+7, _y+8);
    lcd.setPixel( _x+8, _y+8);
    lcd.setPixel( _x+9, _y+8);
    lcd.setPixel( _x+10, _y+8);
    lcd.setPixel( _x+11, _y+8);
    lcd.setPixel( _x+12, _y+8);
    lcd.setPixel( _x+13, _y+8);
    lcd.setPixel( _x+14, _y+8);
    lcd.setPixel( _x, _y+9);
    lcd.setPixel( _x+1, _y+9);
    lcd.setPixel( _x+2, _y+9);
    lcd.setPixel( _x+3, _y+9);
    lcd.setPixel( _x+4, _y+9);
    lcd.setPixel( _x+5, _y+9);
    lcd.setPixel( _x+6, _y+9);
    lcd.setPixel( _x+7, _y+9);
    lcd.setPixel( _x+8, _y+9);
    lcd.setPixel( _x+9, _y+9);
    lcd.setPixel( _x+10, _y+9);
    lcd.setPixel( _x+11, _y+9);
    lcd.setPixel( _x+12, _y+9);
    lcd.setPixel( _x+13, _y+9);
    lcd.setPixel( _x+14, _y+9);
    lcd.setPixel( _x+2, _y+10);
    lcd.setPixel( _x+3, _y+10);
    lcd.setPixel( _x+4, _y+10);
    lcd.setPixel( _x+5, _y+10);
    lcd.setPixel( _x+8, _y+10);
    lcd.setPixel( _x+9, _y+10);
    lcd.setPixel( _x+10, _y+10);
    lcd.setPixel( _x+11, _y+10);
    lcd.setPixel( _x+12, _y+10);
    lcd.setPixel( _x+13, _y+10);
    lcd.setPixel( _x+3, _y+11);
    lcd.setPixel( _x+4, _y+11);
    lcd.setPixel( _x+9, _y+11);
    lcd.setPixel( _x+10, _y+11);
    lcd.setPixel( _x+11, _y+11);
    lcd.setPixel( _x+12, _y+11);
    lcd.setPixel( _x+13, _y+11);
    lcd.setPixel( _x+8, _y+12);
    lcd.setPixel( _x+9, _y+12);
    lcd.setPixel( _x+10, _y+12);
    lcd.setPixel( _x+11, _y+12);
    lcd.setPixel( _x+12, _y+12);
    lcd.setPixel( _x+13, _y+12);
    lcd.setPixel( _x+14, _y+12);
    lcd.setPixel( _x+7, _y+13);
    lcd.setPixel( _x+8, _y+13);
    lcd.setPixel( _x+9, _y+13);
    lcd.setPixel( _x+10, _y+13);
    lcd.setPixel( _x+11, _y+13);
    lcd.setPixel( _x+12, _y+13);
    lcd.setPixel( _x+13, _y+13);
    lcd.setPixel( _x+14, _y+13);
    lcd.setPixel( _x+6, _y+14);
    lcd.setPixel( _x+7, _y+14);
    lcd.setPixel( _x+8, _y+14);
    lcd.setPixel( _x+9, _y+14);
    lcd.setPixel( _x+10, _y+14);
    lcd.setPixel( _x+11, _y+14);
    lcd.setPixel( _x+12, _y+14);
    lcd.setPixel( _x+13, _y+14);
    lcd.setPixel( _x+14, _y+14);
    lcd.setPixel( _x+7, _y+15);
    lcd.setPixel( _x+8, _y+15);
    lcd.setPixel( _x+12, _y+15);
    lcd.setPixel( _x+13, _y+15);
    lcd.setPixel( _x+14, _y+15);
    lcd.setPixel( _x+8, _y+16);
    lcd.setPixel( _x+13, _y+16);
    lcd.setPixel( _x+14, _y+16);
    lcd.setPixel( _x+14, _y+17);
    lcd.setPixel( _x+14, _y+18);
    lcd.setPixel( _x+14, _y+19);

}

void MrIncredible::update(DigitalIn &buttonA, DigitalIn &buttonB, DigitalIn &buttonC, DigitalIn &buttonD) {
    // update x value depending on direction of movement
    // update y value depending on direction of movement
    // North is decrement as origin is at the top-left so decreasing moves up
     if (buttonB.read() == 1) { _y-=3; } 
    else if (buttonA.read() == 1) { _x+=3; }
    else if (buttonD.read() == 1) { _y+=3; } 
    else if (buttonC.read() == 1) { _x-=3                                                                       ; }
    // check the y origin to ensure that the JackJack doesn't go off screen
    if (_y < 0) { _y = 0; }
    if (_y > 48 - 20) { _y = 48 - 20; }
     // check the x origin to ensure that the JackJack doesn't go off screen
    if (_x < 0) { _x = 0; }
    if (_x > 84 - 17) { _x = 84 - 17; }
}
    



Position2D MrIncredible::get_pos() { return {_x,_y}; }

