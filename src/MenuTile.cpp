///////////////////////////////////////////////////////
///CLASS - MenuTile
///
///
///////////////////////////////////////////////////////
#include "MenuTile.h"

MenuTile::MenuTile(){

}
///////////////////////////////////////////////////////
///GETS AND SETS
///////////////////////////////////////////////////////

void MenuTile::setup(string name){
    //Receives the name of the tile
    this-> name = name;
    //Loads the image with that name
    tile.load(name+".png");
    //determines its own size
    myWidth = tile.getWidth();


}
///////////////////////////////////////////////////////
///UPDATE
///////////////////////////////////////////////////////

void MenuTile::update(){



}
///////////////////////////////////////////////////////
///DRAW
///////////////////////////////////////////////////////

//draws itself
void MenuTile::draw(){
    ofSetColor(255);
    tile.draw(x,y);

}



///////////////////////////////////////////////////////
///GETS AND SETS
///////////////////////////////////////////////////////
//returns the name of the tile
string MenuTile::getName(){
    //Files can't have / on name so it corrects it
    if(name== "StartStop Rain"){
        return "Start/Stop Rain";
    }
    return name;

}

float MenuTile::getWidth(){

    return myWidth;

}
//function to receive the potision from the Menu class
void MenuTile::setPosition(float x, float y){
    this->x=x;
    this->y = y;

}


///////////////////////////////////////////////////////
///OTHERS
///////////////////////////////////////////////////////

//if this tile is selected, it loads the selected image, that starts with a "s"
void MenuTile::select(){

    tile.load("s"+name+".png");

}
//if this tile is unselected, it loads the unselected image, that is just the name with no "s"
void MenuTile::unSelect(){

    tile.load(name+".png");

}


