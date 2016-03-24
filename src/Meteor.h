#pragma once
#include "ofMain.h"

class Meteor
{
public:
    Meteor();

    void setup(float height,float width,float floor,int yearInMs,float gravity);

    void update();
    void draw();
    void move();

    void setX(float x);
    void setY(float x);
    void setYearInMs(int i);
    float getX();
    float getY();
    int getYearsDead();
    float getWidth();

    bool isAlive();


    float height;
    float width;
    float floor;
    int yearInMs;
    float gravity;

    float myHeight;
    float myWidth;

    ofImage onFire;
    ofImage meteor;

    int   appFPS;
    float sequenceFPS;
    bool  bFrameIndependent;
    vector <ofImage> imagesOnFire;

    float x;
    float y;

    bool alive;
    int currentTime;
    int deathTime;
    int birthTime;
    int timeElapsed;
    int age;
    int deathAge;

    int yearsDead;




};

