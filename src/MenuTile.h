#pragma once
#include "ofMain.h"


class MenuTile{
public:
    MenuTile();
    void setup(string name);
    void update();
    void draw();
    void select();
    void unSelect();
    void setPosition(float x, float y);


    float getWidth();
    string getName();



    ofImage tile;
    bool selected;

    float myHeight;
    float myWidth;
    float x;
    float y;


    string name;



};

