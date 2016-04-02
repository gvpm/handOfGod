#pragma once
#include "ofMain.h"

class RainDrop
{
public:
    RainDrop();

    void setup(float  x, float y,float gravity, float wind, float floor);

    void update();
    void draw();
    void move();

    bool isAlive();

///GETS AND SETS

    float getX();
    float getY();

    void setX(float x);
    void setY(float x);

///

    float x;
    float y;
    float gravity;
    float wind;
    float floor;
    bool alive;


};
