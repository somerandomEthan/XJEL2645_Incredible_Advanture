#include "RunwayEngine.h"

RunwayEngine::RunwayEngine(){
     _lives = 4;
     _scores = 0;
    }    

void RunwayEngine::init(){
    _player1.init();
    _player2.init();
    _hole1.init (0);
    _hole2.init (-22);
    _star1.init ();
}

struct Result RunwayEngine::update(UserInput input, DigitalIn &buttonA, DigitalIn &buttonB, DigitalIn &buttonC, DigitalIn &buttonD) {   
    check_boundary();  // checking if the character stayas in the screen
    check_fall(); // checking if the character falls into the hole
    check_scores();
    
    _hole1.update();
    _hole2.update();
    _player1.update(buttonA, buttonB, buttonC, buttonD);
    _player2.update(input);
    _star1.update();
    struct Result _result;
    _result.lives = _lives;
    _result.scores = _scores;
    return _result;
}


void RunwayEngine::draw(N5110 &lcd) {
    // the left boundaries
    int _x1 = 0;
    int _y1 = 0;
    lcd.setPixel( _x1+19, _y1);
    lcd.setPixel( _x1+20, _y1);
    lcd.setPixel( _x1+18, _y1+1);
    lcd.setPixel( _x1+19, _y1+1);
    lcd.setPixel( _x1+17, _y1+2);
    lcd.setPixel( _x1+18, _y1+2);
    lcd.setPixel( _x1+16, _y1+3);
    lcd.setPixel( _x1+17, _y1+3);
    lcd.setPixel( _x1+15, _y1+4);
    lcd.setPixel( _x1+16, _y1+4);
    lcd.setPixel( _x1+14, _y1+5);
    lcd.setPixel( _x1+15, _y1+5);
    lcd.setPixel( _x1+13, _y1+6);
    lcd.setPixel( _x1+14, _y1+6);
    lcd.setPixel( _x1+12, _y1+7);
    lcd.setPixel( _x1+13, _y1+7);
    lcd.setPixel( _x1+11, _y1+8);
    lcd.setPixel( _x1+12, _y1+8);
    lcd.setPixel( _x1+10, _y1+9);
    lcd.setPixel( _x1+11, _y1+9);
    lcd.setPixel( _x1+9, _y1+10);
    lcd.setPixel( _x1+10, _y1+10);
    lcd.setPixel( _x1+8, _y1+11);
    lcd.setPixel( _x1+9, _y1+11);
    lcd.setPixel( _x1+7, _y1+12);
    lcd.setPixel( _x1+8, _y1+12);
    lcd.setPixel( _x1+6, _y1+13);
    lcd.setPixel( _x1+7, _y1+13);
    lcd.setPixel( _x1+5, _y1+14);
    lcd.setPixel( _x1+6, _y1+14);
    lcd.setPixel( _x1+4, _y1+15);
    lcd.setPixel( _x1+5, _y1+15);
    lcd.setPixel( _x1+3, _y1+16);
    lcd.setPixel( _x1+4, _y1+16);
    lcd.setPixel( _x1+2, _y1+17);
    lcd.setPixel( _x1+3, _y1+17);
    lcd.setPixel( _x1+1, _y1+18);
    lcd.setPixel( _x1+2, _y1+18);
    lcd.setPixel( _x1, _y1+19);
    lcd.setPixel( _x1+1, _y1+19);
    
    // the clouds No.1
    lcd.setPixel( _x1+9, _y1+1);
    lcd.setPixel( _x1+10, _y1+1);
    lcd.setPixel( _x1+8, _y1+2);
    lcd.setPixel( _x1+9, _y1+2);
    lcd.setPixel( _x1+10, _y1+2);
    lcd.setPixel( _x1+11, _y1+2);
    lcd.setPixel( _x1+7, _y1+3);
    lcd.setPixel( _x1+8, _y1+3);
    lcd.setPixel( _x1+9, _y1+3);
    lcd.setPixel( _x1+10, _y1+3);
    lcd.setPixel( _x1+11, _y1+3);
    lcd.setPixel( _x1+12, _y1+3);
    lcd.setPixel( _x1+6, _y1+4);
    lcd.setPixel( _x1+7, _y1+4);
    lcd.setPixel( _x1+8, _y1+4);
    lcd.setPixel( _x1+9, _y1+4);
    lcd.setPixel( _x1+10, _y1+4);
    lcd.setPixel( _x1+11, _y1+4);
    lcd.setPixel( _x1+12, _y1+4);
    lcd.setPixel( _x1+6, _y1+5);
    lcd.setPixel( _x1+10, _y1+5);
    lcd.setPixel( _x1+11, _y1+5);
    
    // the clouds No.2
    lcd.setPixel( _x1+4, _y1+7);
    lcd.setPixel( _x1+5, _y1+7);
    lcd.setPixel( _x1+3, _y1+8);
    lcd.setPixel( _x1+4, _y1+8);
    lcd.setPixel( _x1+5, _y1+8);
    lcd.setPixel( _x1+6, _y1+8);
    lcd.setPixel( _x1+2, _y1+9);
    lcd.setPixel( _x1+3, _y1+9);
    lcd.setPixel( _x1+4, _y1+9);
    lcd.setPixel( _x1+5, _y1+9);
    lcd.setPixel( _x1+6, _y1+9);
    lcd.setPixel( _x1+1, _y1+10);
    lcd.setPixel( _x1+2, _y1+10);
    lcd.setPixel( _x1+3, _y1+10);
    lcd.setPixel( _x1+4, _y1+10);
    lcd.setPixel( _x1+5, _y1+10);
    lcd.setPixel( _x1+6, _y1+10);
    lcd.setPixel( _x1+7, _y1+10);
    
    // the right boundaries
    int _x2 = 62;
    int _y2 = 0;
    lcd.setPixel( _x2, _y2);
    lcd.setPixel( _x2+1, _y2);
    lcd.setPixel( _x2+1, _y2+1);
    lcd.setPixel( _x2+2, _y2+1);
    lcd.setPixel( _x2+2, _y2+2);
    lcd.setPixel( _x2+3, _y2+2);
    lcd.setPixel( _x2+3, _y2+3);
    lcd.setPixel( _x2+4, _y2+3);
    lcd.setPixel( _x2+4, _y2+4);
    lcd.setPixel( _x2+5, _y2+4);
    lcd.setPixel( _x2+5, _y2+5);
    lcd.setPixel( _x2+6, _y2+5);
    lcd.setPixel( _x2+6, _y2+6);
    lcd.setPixel( _x2+7, _y2+6);
    lcd.setPixel( _x2+7, _y2+7);
    lcd.setPixel( _x2+8, _y2+7);
    lcd.setPixel( _x2+8, _y2+8);
    lcd.setPixel( _x2+9, _y2+8);
    lcd.setPixel( _x2+9, _y2+9);
    lcd.setPixel( _x2+10, _y2+9);
    lcd.setPixel( _x2+10, _y2+10);
    lcd.setPixel( _x2+11, _y2+10);
    lcd.setPixel( _x2+11, _y2+11);
    lcd.setPixel( _x2+12, _y2+11);
    lcd.setPixel( _x2+12, _y2+12);
    lcd.setPixel( _x2+13, _y2+12);
    lcd.setPixel( _x2+13, _y2+13);
    lcd.setPixel( _x2+14, _y2+13);
    lcd.setPixel( _x2+14, _y2+14);
    lcd.setPixel( _x2+15, _y2+14);
    lcd.setPixel( _x2+15, _y2+15);
    lcd.setPixel( _x2+16, _y2+15);
    lcd.setPixel( _x2+16, _y2+16);
    lcd.setPixel( _x2+17, _y2+16);
    lcd.setPixel( _x2+17, _y2+17);
    lcd.setPixel( _x2+18, _y2+17);
    lcd.setPixel( _x2+18, _y2+18);
    lcd.setPixel( _x2+19, _y2+18);
    lcd.setPixel( _x2+19, _y2+19);
    lcd.setPixel( _x2+20, _y2+19);
    lcd.setPixel( _x2+20, _y2+20);
    lcd.setPixel( _x2+21, _y2+20);
    
    // the sun
    lcd.setPixel( _x2+14, _y2+4);
    lcd.setPixel( _x2+15, _y2+4);
    lcd.setPixel( _x2+13, _y2+5);
    lcd.setPixel( _x2+14, _y2+5);
    lcd.setPixel( _x2+15, _y2+5);
    lcd.setPixel( _x2+16, _y2+5);
    lcd.setPixel( _x2+12, _y2+6);
    lcd.setPixel( _x2+13, _y2+6);
    lcd.setPixel( _x2+14, _y2+6);
    lcd.setPixel( _x2+15, _y2+6);
    lcd.setPixel( _x2+16, _y2+6);
    lcd.setPixel( _x2+17, _y2+6);
    lcd.setPixel( _x2+13, _y2+7);
    lcd.setPixel( _x2+14, _y2+7);
    lcd.setPixel( _x2+15, _y2+7);
    lcd.setPixel( _x2+16, _y2+7);
    lcd.setPixel( _x2+14, _y2+8);
    lcd.setPixel( _x2+15, _y2+8);
    
    
    
    
    // draw the middle sivision line, it is just a reference line thus drawn individually
    lcd.drawLine(41,0,41,84,2); // left one
    lcd.drawLine(43,0,43,84,2); // right one
    
    // draw holes and character and the obstacles
    _hole1.draw(lcd);
    _hole2.draw(lcd);
    _player1.draw(lcd);
    _player2.draw(lcd);
    _star1.draw(lcd);
}

void RunwayEngine::check_boundary() {
    Position2D player1_pos = _player1.get_pos();
    Position2D player2_pos = _player2.get_pos();
    const int map [48][84] {
        { 1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0 },
        { 0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0 },
        { 0,0,0,0,0,0,1,0,0,0,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0 },
        { 0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0 },
        { 0,0,0,1,1,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,0,1,1,1,1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0 },
        { 0,1,1,1,1,1,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0 },
        { 0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0 },
        { 0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0 },
        { 0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0 },
        { 0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0 },
        { 0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0 },
        { 1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1 },
        { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    };
    if (
        (map[player1_pos.y][player1_pos.x + 5] == 1 || map[player1_pos.y ][player1_pos.x + 17] == 1) &&
        (map[player2_pos.y + 3][player2_pos.x + 3] == 1 || map[player1_pos.y + 3][player1_pos.x + 10] == 1)
        ) {
        // reset the player
        _player1.init();
        _player2.init();
        _lives--;  // lose a life
    }
}

void RunwayEngine::check_fall() {
    // read current player and hole attributes
    Position2D hole1_pos = _hole1.get_pos();
    Position2D hole2_pos = _hole2.get_pos();
    Position2D player1_pos = _player1.get_pos();  // player1
    Position2D player2_pos = _player2.get_pos();  // player2

    // see if player has fallen into the hole by checking for overlaps
    if (
        (hole1_pos.y >= player1_pos.y) && //top
        (hole1_pos.y <= player1_pos.y + 19 ) && //bottom   20 is the height
        (hole1_pos.x >= player1_pos.x) && //left
        (hole1_pos.x <= player1_pos.x + 16 )  //right    17 is the width
    ) {
        // reset the player and hole
        _player1.init();
        _hole1. init(0);
        _hole2. init(-22);
        _lives--;  // lose a life
    } else if (
        (hole1_pos.y >= player1_pos.y) && //top
        (hole1_pos.y <= player1_pos.y + 19 ) && //bottom   20 is the height
        (hole1_pos.x + 16 >= player1_pos.x) && //left
        (hole1_pos.x + 16 <= player1_pos.x + 16 )  //right    17 is the width
    ) {
        // reset the player and hole
        _player1.init();
        _hole1. init(0);
        _hole2. init(-22);
        _lives--;  // lose a life
    } else if (
        (hole1_pos.y + 9 >= player1_pos.y) && //top
        (hole1_pos.y + 9 <= player1_pos.y + 19 ) && //bottom   20 is the height
        (hole1_pos.x + 16 >= player1_pos.x) && //left
        (hole1_pos.x + 16 <= player1_pos.x + 16 )  //right    17 is the width
    ) {
        // reset the player and hole
        _player1.init();
        _hole1. init(0);
        _hole2. init(-22);
        _lives--;  // lose a life
    
    // player2
    } else if (
        (hole1_pos.y >= player2_pos.y) && //top
        (hole1_pos.y <= player2_pos.y + 16 ) && //bottom   20 is the height
        (hole1_pos.x >= player2_pos.x) && //left
        (hole1_pos.x <= player2_pos.x + 14 )  //right    17 is the width
    ) {
        // reset the player and hole
        _player2.init();
        _hole1. init(0);
        _hole2. init(-22);
        _lives--;  // lose a life
    } else if (
        (hole1_pos.y >= player2_pos.y) && //top
        (hole1_pos.y <= player2_pos.y + 16 ) && //bottom   20 is the height
        (hole1_pos.x + 16 >= player2_pos.x) && //left
        (hole1_pos.x + 16 <= player2_pos.x + 14 )  //right    17 is the width
    ) {
        // reset the player and hole
        _player2.init();
        _hole1. init(0);
        _hole2. init(-22);
        _lives--;  // lose a life
    } else if (
        (hole1_pos.y + 9 >= player2_pos.y) && //top
        (hole1_pos.y + 9 <= player2_pos.y + 16 ) && //bottom   20 is the height
        (hole1_pos.x + 16 >= player2_pos.x) && //left
        (hole1_pos.x + 16 <= player2_pos.x + 14 )  //right    17 is the width
    ) {
        // reset the player and hole
        _player2.init();
        _hole1. init(0);
        _hole2. init(-22);
        _lives--;  // lose a life
    }
    
    else if (
        (hole2_pos.y >= player1_pos.y) && //top
        (hole2_pos.y <= player1_pos.y + 19 ) && //bottom   20 is the height
        (hole2_pos.x >= player1_pos.x) && //left
        (hole2_pos.x <= player1_pos.x + 16 )  //right    17 is the width
    ) {
        // reset the player and hole
        _player1.init();
        _hole1. init(0);
        _hole2. init(-22);
        _lives--;  // lose a life
    } else if (
        (hole2_pos.y >= player1_pos.y) && //top
        (hole2_pos.y <= player1_pos.y + 19 ) && //bottom   20 is the height
        (hole2_pos.x + 16 >= player1_pos.x) && //left
        (hole2_pos.x + 16 <= player1_pos.x + 16 )  //right    17 is the width
    ) {
        // reset the player and hole
        _player1.init();
        _hole1. init(0);
        _hole2. init(-22);
        _lives--;  // lose a life
    } else if (
        (hole2_pos.y + 9 >= player1_pos.y) && //top
        (hole2_pos.y + 9 <= player1_pos.y + 19 ) && //bottom   20 is the height
        (hole2_pos.x + 16 >= player1_pos.x) && //left
        (hole2_pos.x + 16 <= player1_pos.x + 16 )  //right    17 is the width
    ) {
        // reset the player and hole
        _player1.init();
        _hole1. init(0);
        _hole2. init(-22);
        _lives--;  // lose a life
    
    // player2
    } else if (
        (hole2_pos.y >= player2_pos.y) && //top
        (hole2_pos.y <= player2_pos.y + 16 ) && //bottom   20 is the height
        (hole2_pos.x >= player2_pos.x) && //left
        (hole2_pos.x <= player2_pos.x + 14 )  //right    17 is the width
    ) {
        // reset the player and hole
        _player2.init();
        _hole1. init(0);
        _hole2. init(-22);
        _lives--;  // lose a life
    } else if (
        (hole2_pos.y >= player2_pos.y) && //top
        (hole2_pos.y <= player2_pos.y + 16 ) && //bottom   20 is the height
        (hole2_pos.x + 16 >= player2_pos.x) && //left
        (hole2_pos.x + 16 <= player2_pos.x + 14 )  //right    17 is the width
    ) {
        // reset the player and hole
        _player2.init();
        _hole1. init(0);
        _hole2. init(-22);
        _lives--;  // lose a life
    } else if (
        (hole2_pos.y + 9 >= player2_pos.y) && //top
        (hole2_pos.y + 9 <= player2_pos.y + 16 ) && //bottom   20 is the height
        (hole2_pos.x + 16 >= player2_pos.x) && //left
        (hole2_pos.x + 16 <= player2_pos.x + 14 )  //right    17 is the width
    ) {
        // reset the player and hole
        _player2.init();
        _hole1. init(0);
        _hole2. init(-22);
        _lives--;  // lose a life
    }
}


void RunwayEngine::check_scores() {
    // read current player and star attributes
    Position2D star1_pos = _star1.get_pos();
    Position2D player1_pos = _player1.get_pos();  // player1
    Position2D player2_pos = _player2.get_pos();  // player2

    // see if player has collecred the stars
    if (
        (star1_pos.y >= player1_pos.y) && //top
        (star1_pos.y <= player1_pos.y + 19 ) && //bottom   20 is the height
        (star1_pos.x >= player1_pos.x) && //left
        (star1_pos.x <= player1_pos.x + 16 )  //right    17 is the width
    ) {
        _star1. init();
        _scores++;  // add score
        
    } else if (
        (star1_pos.y >= player1_pos.y) && //top
        (star1_pos.y <= player1_pos.y + 19 ) && //bottom   20 is the height
        (star1_pos.x + 10 >= player1_pos.x) && //left
        (star1_pos.x + 10 <= player1_pos.x + 16 )  //right    17 is the width
    ) {
        _star1. init();
        _scores++;  //add score
    }else if (
        (star1_pos.y + 7 >= player1_pos.y) && //top
        (star1_pos.y + 7 <= player1_pos.y + 19 ) && //bottom   20 is the height
        (star1_pos.x + 10 >= player1_pos.x) && //left
        (star1_pos.x + 10 <= player1_pos.x + 16 )  //right    17 is the width
    ) {
        _star1. init();
        _scores++;  // add score
    
    // player2
    } else if (
        (star1_pos.y >= player2_pos.y) && //top
        (star1_pos.y <= player2_pos.y + 16 ) && //bottom   20 is the height
        (star1_pos.x >= player2_pos.x) && //left
        (star1_pos.x <= player2_pos.x + 14 )  //right    17 is the width
    ) {
        _star1. init();
        _scores++;  // add score
    } else if (
        (star1_pos.y >= player2_pos.y) && //top
        (star1_pos.y <= player2_pos.y + 16 ) && //bottom   20 is the height
        (star1_pos.x + 16 >= player2_pos.x) && //left
        (star1_pos.x + 16 <= player2_pos.x + 14 )  //right    17 is the width
    ) {
        _star1. init();
        _scores++;  // add score
    } else if (
        (star1_pos.y + 9 >= player2_pos.y) && //top
        (star1_pos.y + 9 <= player2_pos.y + 16 ) && //bottom   20 is the height
        (star1_pos.x + 16 >= player2_pos.x) && //left
        (star1_pos.x + 16 <= player2_pos.x + 14 )  //right    17 is the width
    ) {
        _star1. init();
        _scores++;  // add score
    }
}
