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

    bool isRaining();
    void rain();
    void stopRain();

///GETS AND SETS

    float getX();
    float getY();

    void setX(float x);
    void setY(float x);
    void setYearInMs(int i);
    void setWind(float wind);




///
    ofImage cloud;
    vector<RainDrop> rainDrops;

    float height;
    float width;
    float floor;
    int yearInMs;
    float gravity;

    float myHeight;
    float myWidth;
    float wind;

    bool raining;


    float x;
    float y;





};
