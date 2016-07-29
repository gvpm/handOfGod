# handOfGod
Control a virtual environment with the palm of your hand.

OpenFrameworks @ QtCreator With SkyWriter Raspberry Pi Hat

![alt tag](https://github.com/gvpm/handOfGod/blob/master/blogpics/Example.png)

##The Concept

####The initial idea was based on 2 things:

– An environment where “beings” would born, grow and die independently.
– Interactions that would affect this environment, changing its balance somehow, and affecting and controlling the beings.

The project is called handOfGod because the way the interactions are triggered is by moving the hand on top of “The Bible”

####Why and What is the bible?

The reason why the trigger chosen was “The Bible” came from a movie from 2010 called “The Book of Eli” where Eli, the main character, travels in a post apocalyptic world with one goal, deliver this “powerful” book he has somewhere safe where it would be used in a good way.

Eli stumbles upon a city where its Mayor knows about and it is looking for a book that he believes it can give him power to rule all the other cities because contains the knowledge required to control other people.

The book is The Bible, and that is the critique. Sadly, the bible, the coran and religion in general was  used through the years by some people acting in bad faith with the sole intention of obtaining or increasing their power/influence and controlling people to act in their behalf .

##The Environment

 

####Evolution

 

Primitive state, testing simple movement

![alt tag](http://doc.gold.ac.uk/~tpapa001/wccterm2/wp-content/uploads/2016/04/1-initial-450x225.png)

Sprites added, long simulation and debugging periods

![alt tag](http://doc.gold.ac.uk/~tpapa001/wccterm2/wp-content/uploads/2016/04/2-long-test-450x253.png)

Different colors to represent different Being States

![alt tag](http://doc.gold.ac.uk/~tpapa001/wccterm2/wp-content/uploads/2016/04/4-color-e1459790442367-600x185.png)

Clouds Added

![alt tag](http://doc.gold.ac.uk/~tpapa001/wccterm2/wp-content/uploads/2016/04/5-cloud-e1459790493613-450x193.png)

Top Bar added

![alt tag](http://doc.gold.ac.uk/~tpapa001/wccterm2/wp-content/uploads/2016/04/10-apple-and-food-e1459790339315-768x33.png)

Apples on treed added, beings can now eat

![alt tag](http://doc.gold.ac.uk/~tpapa001/wccterm2/wp-content/uploads/2016/04/10-apple-and-food-2-e1459790590884-150x150.png)

Night period added

![alt tag](http://doc.gold.ac.uk/~tpapa001/wccterm2/wp-content/uploads/2016/04/11-night-450x253.png)

Interaction Menu added

![alt tag](http://doc.gold.ac.uk/~tpapa001/wccterm2/wp-content/uploads/2016/04/8-menu-tile-450x253.png)

![alt tag](http://doc.gold.ac.uk/~tpapa001/wccterm2/wp-content/uploads/2016/04/8-menu-tile-2-e1459791671174.png)

![alt tag](http://doc.gold.ac.uk/~tpapa001/wccterm2/wp-content/uploads/2016/04/8-menu-e1459791688997-450x161.png)

![alt tag](http://doc.gold.ac.uk/~tpapa001/wccterm2/wp-content/uploads/2016/04/12-final-menu-e1459790629415-768x114.png)

OSC messages added and triggers

![alt tag](http://doc.gold.ac.uk/~tpapa001/wccterm2/wp-content/uploads/2016/04/6-osc-e1459791767931-600x531.png)

##Problems Encountered

The main problems encountered were performance problems, whenever the number of beings was too high, tasks like removing their graveyards was getting slow.

Examples of solutions for problems like that:

####Problem: 

Removing the dead.
From: Removing all every 5 years.
To: Removing all older than 5 years every frame

####Problem: 

Killing a lot of beings at the same time.
From: Killing them all together.
To: Killing the desired amount over a few years.
EX:
Kill 50% of 1000 = Kill 500.
Years to kill = 1000/100=10
500/10 = 50.
Kill approximately 50 each year over 10 years

 
##Final State (For Now)

Here are some characteristics of the current state:
– One second = 1 year
– A being can give birth between the age of 12 and its death age.
– Beings have a small change to randomly get pregnant in those years.
– The death age of a being is determined on its birth and it  will be a value between 60 and 100 years.
– A being will start to be hungry after 10 years without eating and it will search for food.
– After 30 years being hungry and not being able to get food, his death age will be decreased by 1 year, each year.
– One Tree can provide  enough food for approximately 50 beings.
– One day lasts 30 years, one night lasts another 30 years.
– When pregnant, beings turn slightly red.
– Pregnancy lasts 1 year.
– Beings under 12 are smaller and  darker.
– Beings can be infertile and will not get pregnant.
– Infertile Beings are  slightly green.

 
##The Interactions

 
####Demo Video

[![IMAGE ALT TEXT HERE](https://img.youtube.com/vi/aKeAhpD8764/0.jpg)]
(https://www.youtube.com/watch?v=aKeAhpD8764)

 

The Wheel Value:
When an interaction uses the wheel value, it means that the action will be applied in the percentage defined as the current Wheel Value.

 

The Bible

To trigger the interactions, “The Bible” was created. A book was glued and carved inside to fit the Raspberry Pi with the Skywriter HAT (responsible for tracking the  movements) and an battery.
Here is the scheme used in the project.diagram

The Pi runs a python code that detects specific movements from the HAT and sends OSC messages via the router to the OSC Receiver, that is the running environment. The app then calls the respective functions according to the messages received. They functions can be: Swipe Right, Swipe Left and Select an option.

Here are some pictures of the  bible creation and testing process:

6 osc device

13 bible o13 bible i
13 bible
13 bible 9

 

 

 
To do

To tune up the world created, some depth and different levels might be added, the beings would be able to walk in more directions.

Add more features to the environment, different kinds of life and reactive objects.
