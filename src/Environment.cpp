///////////////////////////////////////////////////////
///CLASS - Environment
///
///
///////////////////////////////////////////////////////
#include "Environment.h"

Environment::Environment(){

    font.loadFont("franklinGothic.otf", 9);
    //inicial time of the program
    startTime = ofGetElapsedTimeMillis();
    //how many miliseconds an year will last, it will be passed to all the other objects
    yearInMs = 1000;
    //stores the year
    year = 0;
    //sets the gravity
    gravity = 3.9;
    //sets the wind
    wind = 0.5;
    //stores the rain state
    raining = false;
    //the maximum number of trees
    maxNOfTrees = 10;
    //how many years in a day
    yearsInDay==30;
    //auxiliar variable, probably not used anymore
    lastYearChecked=0;

    //colors for night and day
    nightColor.r=72;
    nightColor.g=48;
    nightColor.b=120;

    dayColor.r=160;
    dayColor.g=216;
    dayColor.b=241;

    //dayColor(160, 216, 241);
    //current perios, 1 for day and -1 for night
    currentPeriod = 1;

    //Inicial beings
    for(int i = 0 ;i<10;i++){
    Being b;
    //b.setup(ofGetHeight(),ofGetWidth(),ofGetHeight()-70,yearInMs, beings);
    b.setup(ofGetHeight(),ofGetWidth(),ofGetHeight()-70,yearInMs,gravity);
    beings.push_back(b);
    }
    //Inicial trees
    for(int i = 0 ;i<1;i++){
    Tree t;
    t.setup(ofGetHeight(),ofGetWidth(),ofGetHeight()-70,yearInMs);
    trees.push_back(t);
    }
    //inicial clouds
    for(int i = 0 ;i<ofRandom(4,15);i++){
    Cloud c;
    c.setup(ofGetHeight(),ofGetWidth(),ofGetHeight()-70,yearInMs,wind,gravity);
    clouds.push_back(c);
    }


    birthsToGive = 0;


}

///////////////////////////////////////////////////////
///UPDATE
///////////////////////////////////////////////////////

void Environment::update(){

    //updates the tiime variables
    currentTime = ofGetElapsedTimeMillis();
    timeElapsed = currentTime - startTime;
    year = timeElapsed/yearInMs;

    //background changing acording to day or night
    if(currentPeriod==1){
        //ofBackground(72, 48, 120);
        ofBackground(160, 216, 241);

    }else if(currentPeriod==-1){
        ofBackground(72, 48, 120);

    }

    //checks in every new year is it has to change the period
    //changes each 30 years
    if(lastYearChecked!=year && year%30==0){
        currentPeriod = -currentPeriod;

    }
    lastYearChecked=(int)year;


    //the environment  update job
    //descriptions of the functions on top of them in OTHERS section bellow

    guideStarving();

    feedStarving();

    giveBirths();

    updateClouds();

    updateBeings();

    updateTrees();

    updateMeteors();

    addTreesWithRain();


}

///////////////////////////////////////////////////////
///DRAW
///////////////////////////////////////////////////////

void Environment::draw(){


        ofSetColor(0,150,0);
        //draws the floor
        ofRect(0,ofGetHeight()-70,ofGetWidth(),70);

        //the environment  draw job
        //descriptions of the functions on top of them in OTHERS section bellow
        drawClouds();
        drawTrees();
        drawBeings();
        drawMeteors();

        ofSetColor(0);
        //sets current year
        currentYear = ofToString(year);

        //descriptions of the functions on top of them in OTHERS section bellow
        loopOnBeings();
        loopOnMeteors();

        //sets current alives  number to be draw by another class
        alivess = ofToString(alives);
        //font.drawString("Beings Alive: "+alivess, 30, 25);


}

///////////////////////////////////////////////////////
///OTHERS
///////////////////////////////////////////////////////
//loops the beings vector and draws them all
void Environment::drawBeings(){
    for(int i = 0;i<beings.size() ;i++){

        beings[i].draw();
    }

}
//loops the beings vector and updates them all
void Environment::updateBeings(){
    for(int i = 0;i<beings.size() ;i++){

        beings[i].update();
    }

}
//loops the trees vector and draws them all
void Environment::drawTrees(){
    for(int i = 0;i<trees.size() ;i++){

        trees[i].draw();
    }

}
//loops the trees vector and updates them all
void Environment::updateTrees(){
    for(int i = 0;i<trees.size() ;i++){

        trees[i].update();
    }

}
//loops the clouds vector and draws them all
void Environment::drawClouds(){
    for(int i = 0;i<clouds.size() ;i++){

        clouds[i].draw();
    }

}
//loops the clouds vector and updates them all
void Environment::updateClouds(){
    for(int i = 0;i<clouds.size() ;i++){

        clouds[i].update();
    }

}
//loops the meteors vector and draws them all
void Environment::drawMeteors(){
    for(int i = 0;i<meteors.size() ;i++){

        meteors[i].draw();
    }

}
//loops the meteors vector and updates them all
void Environment::updateMeteors(){
    for(int i = 0;i<meteors.size() ;i++){

        meteors[i].update();
    }

}
//not yet fully implemented, not in use
void Environment::slowDown(){
    yearInMs = yearInMs*10;
    updateBeingsSpeed(yearInMs);



}
//not yet fully implemented, not in use
void Environment::speedUp(){
    yearInMs = yearInMs/10;
    updateBeingsSpeed(yearInMs);

}
//not yet fully implemented, not in use
void Environment::updateBeingsSpeed(int ms){
    for(int i = 0 ;i<beings.size();i++){
        beings[i].setYearInMs(ms);
    }


}

//decimates the population acording to a given percentage
void Environment::decimate(int percentage){
    for(int i = 0 ;i<beings.size();i++){
        if(beings[i].isAlive()&&ofRandom(100)<percentage){
            //the beings will not be killed all together
            //they will be killed in a certain amout of years that is defined by the number of beings alive
            //more details on the killSlowly function descriptio on the class Being
            beings[i].killSlowly(alives);

        }
    }


}

//impregnates the beings acording to a given percentage
void Environment::impregnate(int percentage){
    for(int i = 0 ;i<beings.size();i++){
        if(beings[i].isAlive()&&ofRandom(100)<percentage){
            beings[i].impregnate();

        }
    }


}
//make it rain, loops the clouds vector and turns rain on
void Environment::rain(){
    for(int i = 0 ;i<clouds.size();i++){

            clouds[i].rain();

    }
    //updates raining state
    raining = true;


}
//stop rain, loops the clouds vector and turns rain off
void Environment::stopRain(){
    for(int i = 0 ;i<clouds.size();i++){

            clouds[i].stopRain();

    }
    //updates raining state
    raining =false;


}
//make part of the population infertile acording to a given percentage
void Environment::makeInfertile(int percentage){
    for(int i = 0 ;i<beings.size();i++){
        if(beings[i].isAlive()&&ofRandom(100)<percentage){
            beings[i].makeInfertile();

        }
    }


}

//make part of the population fertile acording to a given percentage
void Environment::makeFertile(int percentage){
    for(int i = 0 ;i<beings.size();i++){
        if(beings[i].isAlive()&&ofRandom(100)<percentage){
            beings[i].makeFertile();

        }
    }


}

//creates and adds one being in the beings vector
void Environment::addBeing(){
    Being b;
    b.setup(ofGetHeight(),ofGetWidth(),ofGetHeight()-70,yearInMs,gravity);
    beings.push_back(b);


}
//adds a  new meteor to the meteors vector
void Environment::addMeteor(){
    Meteor m;
    m.setup(ofGetHeight(),ofGetWidth(),ofGetHeight()-70,yearInMs,gravity);
    meteors.push_back(m);


}


//inverts the gravity, loops on the beings vector updating all their gravities
void Environment::invertGravity(){
    gravity = -gravity;
    for(int i = 0 ;i<beings.size();i++){
        if(beings[i].isAlive()){
            beings[i].setGravity(gravity);

        }
    }

}
//if the being is ready to give birth (one year pregnant) it will add a new  being to the vector
void Environment::giveBirths(){
    int size = beings.size();
    for(int i =0; i<size;i++){
        if(beings[i].isChildReady()){
            birthsToGive++;
            Being b;
            b.setup(ofGetHeight(),ofGetWidth(),ofGetHeight()-70,yearInMs,gravity);
            //the child will be born on the mother/father position
            b.setX(beings[i].getX());
            b.setY(beings[i].getY());
            beings.push_back(b);
            //tells the being that the child was removed
            beings[i].removeChild();
        }

    }
}

bool Environment::isRaining(){
    return raining;

}
string Environment::getCurrentYear(){
    return currentYear;

}
string Environment::getAlives(){
    return alivess;

}

void Environment::guideStarving(){

    for(int i = 0 ;i<beings.size();i++){
        if(beings[i].isStarving()){
            float x = discoverCloseTreeX(beings[i].getX());

            if(!beings[i].isTreeLock()){
            beings[i].setCloseTreeX(x);
            }


        }

    }


}

//once a being is designated to a tree it will only receive another one if that tree is removed
//this function removes the loch and sets the being with no tree to go
void Environment:: removeLock(float x){
    for(int i = 0 ;i<beings.size();i++){
        if(beings[i].isAlive() && beings[i].isTreeLock() && beings[i].getCloseTreeX()==x){
            beings[i].removeTreeLock();
            beings[i].setCloseTreeX(-1);
        }

    }


}

//it has a chance of adding a new tree  if its raining
void Environment:: addTreesWithRain(){

    if(raining&&ofRandom(1000)>990&&trees.size()<maxNOfTrees){
        Tree t;
        t.setup(ofGetHeight(),ofGetWidth(),ofGetHeight()-70,yearInMs);
        trees.push_back(t);

    }


}
//not returning the closest one, sinc treeLock is in use
//it will simply give a random tree to feed from among the existing ones to the being
float Environment::discoverCloseTreeX(float x){
    if(trees.size()>0){
    float index = ofRandom(0,trees.size());
    return trees[index].getX();
    }else{
        //case where there  is no tree
        return -1;
    }


}
//will feed the being it the being is starving and  in front of its designated tree

void Environment::feedStarving(){

    for(int i = 0 ;i<beings.size();i++){
        if(beings[i].isStarving() && beings[i].isOnTree()){
            for(int j = 0 ;j<trees.size();j++){
                if(trees[j].getX()==beings[i].getCloseTreeX()){
                    if(!trees[j].isEmpty()){
                        //removes an apple from the tree
                        trees[j].eatApple();
                        //tells the being it has been feeded
                        beings[i].feed();
                    }

                }

            }

        }

    }


}

//loops on the beings removing the ones that have been dead for 5 years and also counts the alives
void Environment::loopOnBeings(){

    alives=0;
    int j= 0;
    while ( j < beings.size() ) {
        if ( !beings[j].isAlive()  && beings[j].getYearsDead()>=5 ||!beings[j].isAlive()  && beings[j].getAgesStarving()>=beings[j].getMaxAgesStarving()+5) {
            beings.erase( beings.begin() + j );
        } else if (beings[j].isAlive()) {
            ++j;
            alives++;
        }else{
            ++j;
        }
    }



}

//loops on the meteors to do the killing of trees and  beings
void Environment::loopOnMeteors(){
    for(int i = meteors.size()-1;i>=0;i--){
        if(!meteors[i].isAlive()){
            float x = meteors[i].getX();
            //loop on the beings to remove the ones hit by the meteors
            for(int z=0;z<beings.size();z++){
                float beingX = beings[z].getX();
               if (x < beingX && beingX < x+meteors[i].getWidth() &&beings[z].isAlive()){
                   beings[z].kill();

               }

            }
            //loops on trees ans remove the ones hit by the meteor
            int j= 0;
            while ( j < trees.size() ) {
                float treeX = trees[j].getX();
                if (x < treeX+trees[j].getWidth()/2 && treeX+trees[j].getWidth()/2 < x+meteors[i].getWidth()) {
                    trees.erase(trees.begin() + j );
                    removeLock(treeX);
                } else{
                    ++j;
                }
            }
            //removes the meteors that have been on the floor for more than 2 years
            if (meteors[i].getYearsDead()>=2) {
                            meteors.erase( meteors.begin() + i );
                        }

        }

    }


}


