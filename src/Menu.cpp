///////////////////////////////////////////////////////
///CLASS - Menu
///
///
///////////////////////////////////////////////////////
#include "Menu.h"

Menu::Menu(){

    //Creating and addind the menu tiles in the menu vector
    //It only needs the name!
    MenuTile m1;
    m1.setup("Meteor");
    tiles.push_back(m1);
    MenuTile m2;
    m2.setup("Add Being");
    tiles.push_back(m2);
    MenuTile m3;
    m3.setup("Decimate");
    tiles.push_back(m3);
    MenuTile m4;
    m4.setup("StartStop Rain");
    tiles.push_back(m4);
    MenuTile m5;
    m5.setup("Make Infertile");
    tiles.push_back(m5);
    MenuTile m6;
    m6.setup("Make Fertile");
    tiles.push_back(m6);
    MenuTile m7;
    m7.setup("Impregnate");
    tiles.push_back(m7);
    MenuTile m8;
    m8.setup("Invert Gravity");
    tiles.push_back(m8);


    currentIndex = 0;

    //variables to help on the position
    //The menu adapts itself and it will be centered if you emove or add menu options
    float firstX;
    float menuY = ofGetHeight()/3;

    float menuSize;
    float tileSize = tiles[0].getWidth();

    menuSize = tileSize*tiles.size();
    //discovers the first X of the first menu tile
    firstX = (ofGetWidth()-menuSize)/2;

    //Feeds all the menu tiles with their right positions
    for(int i = 0; i<tiles.size();i++){
        tiles[i].setPosition(firstX+(tileSize*i),menuY);
    }

    //helps on the menu timing
    open = false;


}

///////////////////////////////////////////////////////
///UPDATE
///////////////////////////////////////////////////////

void Menu::update(){
    //updates the currennt time value
    currentTime = ofGetElapsedTimeMillis();

}

///////////////////////////////////////////////////////
///DRAW
///////////////////////////////////////////////////////

void Menu::draw(){

    //draws only if menu is open
    if(open){
        //draws all the tiles
    for(int i = 0; i<tiles.size();i++){
        tiles[i].draw();
    }

        //sets open to false if menu is open for a long time
        if(currentTime-lastOpenTime>2000){
            open = false;

        }
    }




}

///////////////////////////////////////////////////////
///OTHERS
///////////////////////////////////////////////////////

//Swipe functions called by the ofApp
void Menu::swipeRight(){
    //Values to keep it open for the right time
    lastOpenTime = currentTime;
    open = true;
    //unselects the current
    tiles[currentIndex].unSelect();
    currentIndex ++;//increases the index value
    //if it reaches the end, goes to the begining
    if(currentIndex >tiles.size()-1){
        currentIndex = 0;
    }
    //selects the new one
    tiles[currentIndex].select();
    currentSelection = tiles[currentIndex].getName();




}
void Menu::swipeLeft(){
    //Values to keep it open for the right time
    lastOpenTime = currentTime;
    open = true;
    //unselects the current
    tiles[currentIndex].unSelect();
    currentIndex --;//decreases the index value
    //if it reaches the begining, goes to the end
    if(currentIndex <0){
        currentIndex = tiles.size()-1;
    }
    //selects the new one
    tiles[currentIndex].select();
    currentSelection = tiles[currentIndex].getName();


}

//returns the current selection
string Menu::select(){
    return currentSelection;

}



