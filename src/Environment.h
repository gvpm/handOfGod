#pragma once
#include "ofMain.h"
#include "Being.h"
#include "Tree.h"
#include "Cloud.h"
#include "Meteor.h"


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
    void updateMeteors();
    void drawMeteors();

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
    bool isRaining();

    void addMeteor();

    void setGravity();
    void invertGravity();

    string getCurrentYear();
    string getAlives();

    string currentYear;
    string alivess;



    ofTrueTypeFont		font;
    vector<Being> beings;
    vector<Tree> trees;
    vector<Cloud> clouds;
    vector<Meteor> meteors;
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
