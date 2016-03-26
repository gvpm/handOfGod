#pragma once
#include "ofMain.h"
#include "MenuTile.h"

class Menu{
public:
    Menu();
    void update();
    void draw();

    void swipeRight();
    void swipeLeft();

    string select();

    string currentSelection;
    int currentIndex;
    int previousIndex;
    int nextIndex;

    vector<string> options;
    vector<MenuTile> tiles;
    ofTrueTypeFont		font;
    ofTrueTypeFont		font2;

    int currentTime;

    int lastOpenTime;
    bool open;

};

