#pragma once
#include "ofMain.h"
#include "Being.h"
#include "Tree.h"


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
    void updateBeingsSpeed(int ms);
    void speedUp();
    void slowDown();
    void giveBirths();
    void decimate(int percentage);
    void impregnate(int percentage);
    void infertilize(int percentage);
    void fertilize(int percentage);


    ofTrueTypeFont		font;
    vector<Being> beings;
    vector<Tree> trees;
    //Being being();

    int yearInMs;
    int startTime;
    int currentTime;
    int timeElapsed;
    int year;
    int birthsToGive;
    int alives;

};
