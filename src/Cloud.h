#pragma once
#include "ofMain.h"
#include "RainDrop.h"


class Cloud
{
public:
    Cloud();
    void setup(float height,float width,float floor,int yearInMs,float wind,float gravity);

    void update();
    void draw();
    void move();

    void drawRainDrops();
    void updateRainDrops();

    void setX(float x);
    void setY(float x);
    void setYearInMs(int i);
    float getX();
    float getY();
    void setWind(float wind);

    bool isRaining();
    void rain();
    void stopRain();

    float height;
    float width;
    float floor;
    int yearInMs;
    float gravity;

    float myHeight;
    float myWidth;
    float wind;

    bool raining;

     ofImage cloud;
     float x;
     float y;

     vector<RainDrop> rainDrops;



};
