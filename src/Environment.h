#pragma once
#include "ofMain.h"
#include "Being.h"
#include "Tree.h"
#include "Cloud.h"


class Environment
{
public:
    Environment();
    void update();
    void draw();

    void drawBeings();
    void updateTrees();
    void drawTrees();
    void updateBeings();
    void updateClouds();
    void drawClouds();

    void updateBeingsSpeed(int ms);
    void speedUp();
    void slowDown();
    void giveBirths();
    void decimate(int percentage);
    void impregnate(int percentage);
    void makeInfertile(int percentage);
    void makeFertile(int percentage);
    void addBeing();
    void rain();
    void stopRain();

    void setGravity();
    void invertGravity();



    ofTrueTypeFont		font;
    vector<Being> beings;
    vector<Tree> trees;
    vector<Cloud> clouds;
    //Being being();

    float wind;
    float gravity;
    int yearInMs;
    int startTime;
    int currentTime;
    int timeElapsed;
    int year;
    int birthsToGive;
    int alives;

    bool raining;

};
