#include "Menu.h"

Menu::Menu(){

    MenuTile m1;
    m1.setup("Meteor");
    tiles.push_back(m1);
    MenuTile m2;
    m2.setup("Add Being");
    tiles.push_back(m2);
    MenuTile m3;
    m3.setup("Decimate");
    tiles.push_back(m3);


    currentIndex = 0;

    float firstX;
    float menuY = ofGetHeight()/3;

    float menuSize;
    float tileSize = tiles[0].getWidth();

    menuSize = tileSize*tiles.size();

    firstX = (ofGetWidth()-menuSize)/2;

    for(int i = 0; i<tiles.size();i++){
        tiles[i].setPosition(firstX+(tileSize*i),menuY);
    }



    /*

    font.loadFont("franklinGothic.otf", 30);
    font2.loadFont("franklinGothic.otf", 10);

    options.push_back("Decimate");
    options.push_back("Impregnate");
    options.push_back("Make Infertile");
    options.push_back("Make Fertile");
    options.push_back("Add Being");
    options.push_back("Invert Gravity");
    options.push_back("Start/Stop Rain");
    options.push_back("Meteor");



    currentIndex = options.size()/2;
    currentSelection = options[currentIndex];
    previousIndex = currentIndex-1;
    nextIndex = currentIndex+1;

    */

    open = false;


}
void Menu::update(){
    currentTime = ofGetElapsedTimeMillis();

}
void Menu::draw(){


    if(open){
    for(int i = 0; i<tiles.size();i++){
        tiles[i].draw();
    }


        if(currentTime-lastOpenTime>1000){
            open = false;

        }
    }





    /*
    string menu;

    for(int i = 0; i<options.size();i++){
        if(i!=0){
            menu +="   -   "+options[i];
        }else{
           menu +=options[i];
        }

    }
    font2.drawString(menu,ofGetWidth()/4,ofGetHeight()/4);


    font.drawString(options[previousIndex]+"    >>"+currentSelection+"<<    "+options[nextIndex], ofGetWidth()/4, ofGetHeight()/2);

*/

}

void Menu::swipeRight(){

    lastOpenTime = currentTime;
    open = true;

    tiles[currentIndex].unSelect();
    currentIndex ++;
    if(currentIndex >tiles.size()-1){
        currentIndex = 0;
    }
    tiles[currentIndex].select();
    currentSelection = tiles[currentIndex].getName();


    /*

    previousIndex = currentIndex;
    currentIndex = nextIndex;
    nextIndex = currentIndex+1;

    if(nextIndex >options.size()-1){
        nextIndex = 0;
    }

    currentSelection = options[currentIndex];
    */



}
void Menu::swipeLeft(){

    lastOpenTime = currentTime;
    open = true;

    tiles[currentIndex].unSelect();
    currentIndex --;
    if(currentIndex <0){
        currentIndex = tiles.size()-1;
    }
    tiles[currentIndex].select();
    currentSelection = tiles[currentIndex].getName();

    /*

    nextIndex = currentIndex;
    currentIndex = previousIndex;
    previousIndex = currentIndex-1;

    if(previousIndex <0){
        previousIndex = options.size()-1;
    }

    currentSelection = options[currentIndex];
    */


}

string Menu::select(){
    return currentSelection;

}



