#ifndef UTILS_H
#define UTILS_H

struct Position2D {
  int x;
  int y;  
};

enum Direction {
    CENTRE,  // 0
    N,       // 1
    NE,      // 2
    E,       // 3
    SE,      // 4
    S,       // 5
    SW,      // 6
    W,       // 7
    NW      // 8
};

enum Temperature {
    HOT,
    ALRIGHT,
    COLD
};

enum GlareDenfense {
    GOOD,
    BAD
};

struct UserInput {
    Direction d;
    float mag;
    Temperature T;
    GlareDenfense G;
};

struct Vector2D {
  float x;
  float y;  
};

struct Polar {
    float mag;
    float angle;
};

struct Result {
    int lives;
    int scores;
};
    
#endif