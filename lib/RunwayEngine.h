#ifndef RUNWAYENGINE_H
#define RUNWAYENGINE_H

#include "mbed.h"
#include "N5110.h"
#include "Stars.h"
#include "Holes.h"
#include "JackJack.h"
#include "Utils.h"
#include "MrIncredible.h"

class RunwayEngine {
    public:
        RunwayEngine();  // pass in the lcd object from the main file
        void init();
        struct Result update(UserInput input,DigitalIn &buttonA, DigitalIn &buttonB, DigitalIn &buttonC, DigitalIn &buttonD);
        void draw(N5110 &lcd);
    private:
        void check_boundary();
        void check_fall();
        void check_scores();
        Holes _hole1;
        Holes _hole2;
        Stars _star1;
        JackJack _player2;
        MrIncredible _player1;
        int _lives;
        int _scores;
};

#endif