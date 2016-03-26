#include "MenuTile.h"

MenuTile::MenuTile(){

}

void MenuTile::setup(string name){

    this-> name = name;



    tile.load(name+".png");
    myWidth = tile.getWidth();


}


void MenuTile::update(){



}

void MenuTile::draw(){
    ofSetColor(255);
    tile.draw(x,y);



}

void MenuTile::select(){

    tile.load("s"+name+".png");



}

void MenuTile::unSelect(){

    tile.load(name+".png");



}

float MenuTile::getWidth(){

    return myWidth;



}


void MenuTile::setPosition(float x, float y){
    this->x=x;
    this->y = y;



}
string MenuTile::getName(){
    //Files can't have / on name
    if(name== "StartStop Rain"){
        return "Start/Stop Rain";
    }
    return name;



}


