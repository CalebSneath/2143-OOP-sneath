///////////////////////////////////////////////////////////////////////////////
// 
// Author:           Caleb Sneath
// Email:            ansengor@yahoo.com
// Label:            P01
// Title:            Game: Game
// Course:           CMPS 2143
// Semester:         Spring 2021
//
// Description:
//       This program creates a game using SFML and several classes.
//       I called the game "Asteroid Dodger". Using the arrow keys,
//       players can play for as long as they want. The player controls a
//       shape, and must dodge asteroids that look like other shapes.
//       When the asteroid leaves the screen, the player gains a point. 
//       When players hit an asteroid, they lose 20 points. Asteroids
//       randomly spawn, and the game gets harder over time.
//       
// Usage: 
//      - Ensure compiler is setup correctly, uses G++, and that all files are
//          in the correct folder, including arial.ttf.
//      - Open command terminal, navigate to the P01 directory. Type the following
//          -  g++ -c main.cpp
//          -  g++ main.o -o main -lsfml-graphics -lsfml-window -lsfml-system
//          -  main.exe
//      - The game should now play. Move up with the up or 'w' key.
//      - Move down with the down or 's' key.
//      
// Files:            
//      main.cpp    : driver program 
//      arial.ttf   : font libray
//obtained from: https://github.com/zyedidia/SFML.jl/blob/master/assets/arial.ttf
//      assorted dll files: various sfml libraries.
//      
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include<cmath>
#include<string>
#include <SFML/Graphics.hpp>

using namespace std;

/**
 * Figure
 * 
 * Description:
 *      This struct stores all variables needed to 
 *      reatain the size, color, and shape of
 *      things. It also has support for printing this shape
 *      if a window is passed to it. Currently supports
 *      squares, circles, and rectangles.
 * Usage: 
 * 
 *      Figure():                                   // Default constructor,
 *                                                  // Makes a small blue circle
 *      Figure (char inShape, char inColor, float inScale)// Nondefault constructor,
 *                                                  // accepts abbreviations for 
 *                                                  // type of shape, color, and
 *                                                  // a float for the 
 *                                                  // multiplicative scale.
 *                                                  // of a matching size.
 *      drawShape(float xPos, float yPos, const char &thisShape, const char 
 *      &thisColor, const float &thisScale, sf::RenderWindow &importWindow)
 *                                                  // Given coordinates, a window
 *                                                  // variable of the SFML 
 *                                                  // RenderWindow format,
 *                                                  // and certain items which 
 *                                                  // this struct can already 
 *                                                  // store), prints the 
 *                                                  // shape to screen. 
 *      char thisShape;                             // Stores abbreviation for type 
 *                                                  // of shape. Currently supports 
 *                                                  // s for square, c for circle, 
 *                                                  // and r for rectangle
 *      char thisColor;                             // Stores abbreviation for color
 *                                                  // Supports b for blue, r for 
 *                                                  // red, g for green, and y for 
 *                                                  // yellow.
 *      float thisScale;                            // The multiplicative scale of a 
 *                                                  // height for a shape
 *      sf::RenderWindow &importWindow              // This shows up throughout
 *                                                  // the program a lot. It's 
 *                                                  // just the main window being 
 *                                                  // passed from "main" 
 *                                                  // to all methods that need to 
 *                                                  // draw to the window
 */
struct Figure {
    
    char thisShape;//c circle, r rectangle, s square
    char thisColor;//b blue, r red, g green, y yellow
    float thisScale;

    Figure()
    {
        thisShape = 'c';
        thisColor = 'b';
        thisScale = 1;
        sf::CircleShape thisFigure(200.f);
        thisFigure.setFillColor(sf::Color::Blue);
    }
    Figure (char inShape, char inColor, float inScale)
    {
        thisShape = inShape;
        thisColor = inColor;
        thisScale = inScale;

    }


    void drawShape(float xPos, float yPos, const char &thisShape,
    const char &thisColor, const float &thisScale, 
    sf::RenderWindow &importWindow)
    {

        if(thisShape == 'c')//Make a circle
        {
            //Adjust the size by the scale
            sf::CircleShape thisFigure(200.f*thisScale);

            if(thisColor == 'b')//Make it blue
            {
                thisFigure.setFillColor(sf::Color::Blue);
            }
            else if (thisColor == 'r')//Make it red
            {
                thisFigure.setFillColor(sf::Color::Red);
            }
            else if(thisColor == 'g')//Make it green
            {
                thisFigure.setFillColor(sf::Color::Green);
            }
            else//Make it yellow
            {
                thisFigure.setFillColor(sf::Color::Yellow);
            }

            //Draw it so the window will show it this frame
            //Xpos, yPos are screen coordinates. yPos seems
            //to be inverted in practice
            thisFigure.setPosition(xPos, yPos);
            importWindow.draw(thisFigure);
        }
        else if(thisShape == 'r')//Make a rectangle
        {
            sf::RectangleShape thisFigure(sf::Vector2f(100.f*
            (thisScale), 200.f*(thisScale)));

            if(thisColor == 'b')//Make it blue
            {
                thisFigure.setFillColor(sf::Color::Blue);
            }
            else if (thisColor == 'r')//Make it red
            {
                thisFigure.setFillColor(sf::Color::Red);
            }
            else if(thisColor == 'g')//Make it green
            {
                thisFigure.setFillColor(sf::Color::Green);
            }
            else//Make it yellow
            {
                thisFigure.setFillColor(sf::Color::Yellow);
            }
            
            thisFigure.setPosition(xPos, yPos);
            importWindow.draw(thisFigure);
        }
        else//Make a square
        {
            sf::RectangleShape thisFigure(sf::Vector2f(
                200.f*(thisScale), 200.f*(thisScale)));

            if(thisColor == 'b')//Make it blue
            {
                thisFigure.setFillColor(sf::Color::Blue);
            }
            else if (thisColor == 'r')//Make it red
            {
                thisFigure.setFillColor(sf::Color::Red);
            }
            else if(thisColor == 'g')//Make it green
            {
                thisFigure.setFillColor(sf::Color::Green);
            }
            else//Make it yellow
            {
                thisFigure.setFillColor(sf::Color::Yellow);
            }
            
            thisFigure.setPosition(xPos, yPos);
            importWindow.draw(thisFigure);
        }


    }



};


/**
 * Motion
 * 
 * Description:
 *      This struct stores all variables needed to 
 *      detail simple linear 2D motion. This includes XY positions as well
 *      as velocities. Additionally, it is bundled with a method to update
 *      the positions in accordance with its stored velocity.
 * Usage: 
 * 
 *      Motion()                                    // Default constructor,
 *                                                  // Makes a motionless value
 *                                                  // with a randomized 
 *                                                  // y coordinate
 *      Motion(float beginXPos, float beginYPos)    // Nondefault constructor
 *                                                  // sets initial position to 
 *                                                  // passed X and Y values
 *      void updatePositions()                      // Updates x and y positions
 *                                                  // stored within struct by
 *      float xPosition;                            // Simple x/y coordinates
 *      float yPosition;                            // respectively
 *                                                  // Note: Y value seems to 
 *                                                  // be inverted for SFML.
 *      float xVelocity;                            // X/Y distance moved at 
 *      float yVelocity;                            // current speed in one cycle
 *                                                  // respectively. 
 */
struct Motion {
    float xPosition;
    float yPosition;
    float xVelocity;
    float yVelocity;
    Motion()//Default constructor, used for debris
    {
        yPosition = (rand() % 800);  // starting loc y
        xPosition = 400;//Start just offscreen to right
        yVelocity = 0;
        xVelocity = -0;
    }
    Motion(float beginXPos, float beginYPos)
    {
        xPosition = beginXPos;
        yPosition = beginYPos;
        yVelocity = 0;
        xVelocity = 0;
    }
    void updatePositions()//How things move this frame
    {
        xPosition = (xPosition + xVelocity);
        yPosition = (yPosition + yVelocity);
    }


};

/**
 * PlayerItem
 * 
 * Description:
 *      This class handles most of the code necessary to handle the player's
 *      icon and inputs in game. It is composed of two other structs as well,
 *      Motion and Figure, as it has both. 
 * 
 *      Specifically, this class handles key presses, the player's movement,
 *      cases where the player bumps into a wall, and the drawing of the player.
 *      It does not handle impacts with debris, the debris itself does that.
 * Usage: 
 *  Public:
 *     PlayerItem()                                 // Default constructor
 *                                                  // Results in small blue
 *                                                  // circle player
 *     PlayerItem(char custShape, char custColor, float custScale)//Nondefault
 *                                                  // player object. Can be 
 *                                                  // used in the future to 
 *                                                  // modify program to support 
 *                                                  // player customization.
 *      Figure PlayerFigure;                        // Object of struct Figure,
 *                                                  // by default a blue circle.
 *      Motion PlayerMotion;                        // Object of struct Motion,
 *                                                  // Generally stands still 
 *                                                  // unless keys are pressed or
 *                                                  // walls are bumped into. X 
 *                                                  // position is currently locked
 *                                                  // at 200.
 *  Private:
 *      void WallCollision()                        // Handles player bumping 
 *                                                  // into wall. Simply pushes
 *                                                  // back in bounds by adjusting
 *                                                  // y values if outside range.
 *                                                  // Currently it takes the scale
 *                                                  // of the player's shape into
 *                                                  // account as well as the size
 *                                                  // (since circles use radius
 *                                                  // instead of height)
 *      RegisterKeyStrokes()                        // Checks for SFML events 
 *                                                  // where the player's up, down,
 *                                                  // w(same outcome as up), or
 *                                                  // s(same outcome as down) key
 *                                                  // is pressed. If so, sets 
 *                                                  // yVelocity to + or - 5. If 
 *                                                  // not,resets it back to 0.
 *                                                  // Makes a motionless value
 *                                                  // with a randomized y coord.
 *      PlayerCycle(sf::RenderWindow &importWindow) // Handles all actions player
 *                                                  // object must do in a single 
 *                                                  // game cycle and calls methods
 *                                                  // in correct order.
 * Modification Opportunities                       // 1. The nondefault constructor
 *                                                  // is almost in a state to allow
 *                                                  // most player attributes to be 
 *                                                  // customized.
 *                                                  // 2. Left/right support can be 
 *                                                  // easily added by copy/pasting
 *                                                  // the up/down controls and 
 *                                                  // tweaking respective button
 *                                                  // and XY coordinate entries.
 *                                                  // 3. 2 player support can be 
 *                                                  // added by having a second 
 *                                                  // player object, assigning 
 *                                                  // each a value, and then
 *                                                  // modifying RegisterKeyStrokes
 *                                                  // to instead have an if 
 *                                                  // statement to let one player
 *                                                  // control with up/down, one
 *                                                  // with s/w
 */
class PlayerItem {
private:
                        //Note:The coordinates
    void WallCollision()//are inverted
    {
        if (PlayerMotion.yPosition < 0)//base radius is 200
        {                             // this is up bound
            PlayerMotion.yPosition = 0;
        }
        else if((PlayerMotion.yPosition > //Circle low bound
        (800-(400*PlayerFigure.thisScale)) && 
        PlayerFigure.thisShape == 'c'))//If player's position - radius
        {                               //is less than screen bottom
            PlayerMotion.yPosition = (800-(400*PlayerFigure.thisScale));
        }
        else if(PlayerMotion.yPosition > //Other low bound
        (800-(200*PlayerFigure.thisScale)))
        {   
            PlayerMotion.yPosition = (800-(200*PlayerFigure.thisScale));
        }//Needed a second upper bound because circle has
         //radius (height/2) while others just have height
    }

    //Changes velocity with player input.
    //Doesn't cause issues with collision because of the
    //order the two are called
    void RegisterKeyStroke()
    {
        //Move up if up or w is pressed, just got up
        //if player is being weird and mashing multiple
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
            || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                PlayerMotion.yVelocity = -5;
            }//Move down if down or s is pressed
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
                || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                PlayerMotion.yVelocity = 5;
            }
        else
            {   //Don't move anymore if key is released
                PlayerMotion.yVelocity = 0;
            }   
    }       


public:
    Figure PlayerFigure;//Has both
    Motion PlayerMotion;    
    
    PlayerItem()
    {   //default is a small blue circle
        PlayerFigure.thisScale = 0.3;
        PlayerFigure.thisColor = 'b';
        PlayerFigure.thisShape = 'c';
    }
    PlayerItem(char custShape, char custColor, 
    float custScale)
    {
        //set attributes to inputs
        PlayerFigure.thisScale = custScale;
        PlayerFigure.thisColor = custColor;
        PlayerFigure.thisShape = custShape;
    }
    void PlayerCycle(sf::RenderWindow &importWindow)
    {
        RegisterKeyStroke();
        PlayerMotion.xPosition = 200;//Player can't move 
                            //sideways currently to
        WallCollision();            //Modify, remove this
        PlayerMotion.updatePositions();


        PlayerFigure.drawShape(PlayerMotion.xPosition, 
        PlayerMotion.yPosition, PlayerFigure.thisShape, 
        PlayerFigure.thisColor, PlayerFigure.thisScale, 
        importWindow);
    }

};

/**
 * Debris
 * 
 * Description:
 *      This class handles most of the code necessary to handle the main
 *      obstacles in the game, the debris. For a variety of reasons, 
 *      debris isn't made with dynamic memory allocation. Instead, it 
 *      just uses an old game dev trick of moving "inactive" debris off
 *      the screen and toggling it into an "inactive" state. All debris 
 *      created near the start of the program still exists, it is just reused
 *      and recycled as needed.
 * 
 *      This class adds support for reusing and deactivating debris, a 
 *      boolean method to tell when to score/remove points, detection for
 *      when a player hit an asteroid, support for randomizing debris
 *      speed by a certain percent, as well as support for insuring that 
 *      debris get faster as the game progresses to make it more difficult
 *      as well as potentially point rewarding to play longer.
 * Usage: 
 *  Public:
 *     Debris()                                     // Default constructor
 *                                                  // Results in small blue
 *                                                  // circle debris offstage
 *                                                  // and inactive
 *     Debris(char custShape, char custColor, float custScale)//Nondefault
 *                                                  // constructon. Can be 
 *                                                  // used in the future to 
 *                                                  // modify program to support 
 *                                                  // customization customization.
 *
 *  Private:
 *      Figure DebrisFigure;                        // Object of struct Figure,
 *                                                  // by default a red square.
 *      Motion DebrisMotion;                        // Object of struct Motion,
 *                                                  // Generally stands still 
 *                                                  // until activated, then moves
 *                                                  // left at at least five 
 *                                                  // pixels per cycle, with a 
 *                                                  // bonus variance based on 
 *                                                  // chance and game length* 
 *      bool debrisCollisionCheck(float playX, float playY)// Handles player bumping 
 *                                                  // into this debris. Calls
 *                                                  // method to deactivate this
 *                                                  // debris so player can't use 
 *                                                  // it to get any more points 
 *                                                  // until it is reset and also
 *                                                  // to ensure the player doesn't
 *                                                  // recur more than one penalty
 *                                                  // per crash. Returns true if
 *                                                  // a crash occurs, so other 
 *                                                  // functions such as a score
 *                                                  // counter can know to 
 *                                                  // react accordingly.
 *      bool debrisScoreCheck()                     // Checks if debris left the 
 *                                                  // screen and needs to be reset.
 *                                                  // Resets debris and returns 1
 *                                                  // if so, for similar reasons
 *                                                  // as above.
 *      debrisActiveSwitch()                        // Toggles debris between active
 *                                                  // and inactive states. Active 
 *                                                  // debris moves across screen
 *                                                  // like normal, potentially 
 *                                                  // altering score. Inactive
 *                                                  // still exists, but it won't
 *                                                  // do its full cycle, it is off
 *                                                  // the screen to the right, and 
 *                                                  // it (shouldn't) qualify for 
 *                                                  // any conditions changing score 
 *      debrisCycle(sf::RenderWindow &importWindow, int &thisLoop)
 *                                                  // Handles all actions this 
 *                                                  // debris object must do in a 
 *                                                  // single game cycle and calls 
 *                                                  // methods in correct order.
 *  * Modification Opportunities                    // 1. The nondefault constructor
 *                                                  // is almost in a state to allow
 *                                                  // most debris attributes to be 
 *                                                  // customized.
 *                                                  // 2. Currently, debris checks 
 *                                                  // if it would collide with the
 *                                                  // player. I now believe it is 
 *                                                  // prudent to separate *all* 
 *                                                  // collision checks into a 
 *                                                  // separate class called by
 *                                                  // the game cycle each cycle
 *                                                  // 3. Collision detection 
 *                                                  // assumes two squares. As
 *                                                  // stated above, a dedicated
 *                                                  // class that tracks all objects
 *                                                  // might be better at solving 
 *                                                  // dealing with collisions
 */
class Debris {
private:
        Figure DebrisFigure;//Has both
        Motion DebrisMotion;
        int randSpeedFactor = 1;
        int debrisCreationLoop = 0;



public:
    bool debrisActive = 0;
    Debris()
    {
        DebrisMotion.xVelocity = 0;
        DebrisMotion.xPosition = 1000;
        DebrisMotion.yPosition = 300;
        debrisCreationLoop = 0;
        debrisActive = 0;
        DebrisFigure.thisScale = 0.6;
        DebrisFigure.thisShape = 's';
        DebrisFigure.thisColor = 'r';
        randSpeedFactor = rand() % 11;
    }
    Debris(char custShape, char custColor, 
    float custScale)
    {
        DebrisMotion.xVelocity = 0;
        DebrisMotion.xPosition = 1000;
        DebrisMotion.yPosition = 300;
        debrisCreationLoop = 0;
        debrisActive = 0;
        DebrisFigure.thisScale = custScale;
        DebrisFigure.thisShape = custShape;
        DebrisFigure.thisColor = custColor;
        randSpeedFactor = rand() % 11;
    }
    //Game gets harder, processes this game cycle
    void debrisCycle(sf::RenderWindow &importWindow, int &thisLoop)
    {

        debrisCreationLoop = thisLoop;

        DebrisMotion.updatePositions();
        //Randomness can about double speed, loop slowly grows debris speed
        DebrisMotion.xVelocity = -5 *(1+(0.2*randSpeedFactor * thisLoop/6000));
        //Speed will change for next cycle, not this one.
        DebrisFigure.drawShape(DebrisMotion.xPosition, 
        DebrisMotion.yPosition, DebrisFigure.thisShape, 
        DebrisFigure.thisColor, DebrisFigure.thisScale, 
        importWindow);
    }
    //When asteroid hits player
    bool debrisCollisionCheck(float playX, float playY)
    {

        float differenceX, differenceY;
        differenceX = playX - DebrisMotion.xPosition;
        differenceY = playY - DebrisMotion.yPosition;
        
        //pow 2 must be used because both the player and the debris
        //scaling affect must be taken into account for determining
        // the distance between them.
        if((differenceX<350*pow(DebrisFigure.thisScale,2))&&(differenceX > 
        -350*pow(DebrisFigure.thisScale,2))&&(differenceY < 350 *
        pow(DebrisFigure.thisScale,2)&&(differenceY > -350 * 
        pow(DebrisFigure.thisScale,2))))//Check all coordinates are within 350
        {                       //* shape's scale meaning they touch.
                                //Technically it'd actually be 400, but
                                //350 gives the player a small buffer
                                //and works better for circles.
            debrisActiveSwitch();//Destroy (deactivate this asteroid)
            return true;        //so no points for the player.
        }

        return false;

    }
    bool debrisScoreCheck()//Deactivate offscreen eventually
    {
        if ((DebrisMotion.xPosition) <= -200)//Deactivate if more than
        {                                   //200 off the screen
            debrisActiveSwitch();
            return true;
        }
        else//Otherwise do nothing different
        {
             return false;
        }
    }

    void debrisActiveSwitch()//Activates or deactivate
    {                             //this debris
        if ((debrisActive == 1))//Deactivate if active
        {   //Now shouldn't affect game until reactivated
            debrisActive = 0;         
            DebrisMotion.xPosition = 1000;
            DebrisMotion.yPosition = 400;
            DebrisMotion.xVelocity = 0;
            DebrisMotion.yVelocity = 0;
        }
        else//Activate if inactive;
        {
            debrisActive = 1;
            DebrisMotion.xPosition = 1000;
            DebrisMotion.yPosition = (rand() % 800);
            DebrisMotion.xVelocity = -5;
        }
    }

};

/**
 * GameCycle
 * 
 * Description:
 *      This class handles the backdrop of ensuring every process fires 
 *      exactly once for each cycle of the game, in the correct order for
 *      that cycle. It additionally generates or activates each game entity
 *      as necessary. Additionally, it alone keeps track of the score.
 * Usage: 
 *  Public:
 *     int currentLoop                              // Stores which cycle
 *                                                  // this is to allow it
 *                                                  // to get harder.
 *     GameCycle()                                  // Default constructor
 *                                                  // Results in a bunch 
 *                                                  // of small blue circles
 *                                                  // for player and red
 *                                                  // squares for debris
 *     Debris(char custShape, char custColor, float custScale)//Nondefault
 *                                                  // constructon. Can be 
 *                                                  // used in the future to 
 *                                                  // modify program to support 
 *                                                  // customization customization.
 *     GameCycle(char playShape, char playColor, float, playScale, int playX, 
 *     int playY, char debShape, char debColor, float debScale, int debX, int debY)
 *                                                  // This long header of a 
 *                                                  // constructor will be the
 *                                                  // basis for allowing 
 *                                                  // customization in the future
 *                                                  // currently it doesn't 
 *                                                  // every get called though.
 *      void handlePlayer(sf::RenderWindow &importWindow)//Calls player method
 *                                                  // to begin doing its
 *                                                  // cycle work when time
 *      handleDebris(sf::RenderWindow &importWindow)// Calls a specific
 *                                                  // Debris object's method 
 *                                                  // to begin doing its cycle
 *                                                  // work when time
 *  newCycle(sf::RenderWindow &importWindow, sf::Font scoreFont)//Begins
 *                                                  // Queing up each cycle 
 *                                                  // action in right order.
 *                                                  // Also increments cycle
 *                                                  // counter and schedules 
 *                                                  // debris spawn (activation)
 *                                                  // checks.
 *
 *  Private:
 *      spawnDebris()                               // Randomly spawns debris
 *                                                  // if there is an inactive one
 *                                                  // On average, debris spawns
 *                                                  // faster later in the game,
 *                                                  // as well as if there are
 *                                                  // more inactive debris 
 *                                                  // because the upper bound
 *                                                  // (and therefore average)
 *                                                  // of the random roll 
 *                                                  // increments as well as
 *                                                  // each inactive debris makes
 *                                                  // another check each cycle.
 *      PlayerItem activePlayer;                    // The actual object of the 
 *                                                  // player class.
 *      Debris debrisList[10];                      // 10 Debris objects exist at
 *                                                  // all times during gameplay,
 *                                                  // whether active or inactive.
 *                                                  // This has desirable technical
 *                                                  // as well as gameplay effects.
 *                                                  // Technicalwise, it avoids any
 *                                                  // difficulties associated with
 *                                                  // dynamic memory allocation.
 *                                                  // Gameplaywise, it does 
 *                                                  // three things:
 *                                                  // One, it has a tendency to 
 *                                                  // make the asteroids 
 *                                                  // occasionally spawn in 
 *                                                  // "clumped waves".  This ends
 *                                                  // up being more fun than a 
 *                                                  // completely random barrage 
 *                                                  // of asteroids, as players
 *                                                  // must finely thread the needle
 *                                                  // if a wave spawn at a similar 
 *                                                  // time with no opening.
 *                                                  // Two, it is more fair. With
 *                                                  // absolutely no cap on 
 *                                                  // asteroid generation, there
 *                                                  // are numerous instances where
 *                                                  // a tide of asteroids spawn 
 *                                                  // without gaps. In this case, 
 *                                                  // the player straight up has 
 *                                                  // no choice but to lose points.
 *                                                  // With only ten, this only 
 *                                                  // happens with the unlikely 
 *                                                  // outcome that all ten 
 *                                                  // respawn at the same 
 *                                                  // time in a fairly even 
 *                                                  // distribution across the 
 *                                                  // debris y-coordinates.
 *                                                  // Finally, it autorgulates 
 *                                                  // gameplay, avoiding slumps
 *                                                  // by increasing spawn rate
 *                                                  // during slow times, and 
 *                                                  // letting up on the player
 *                                                  // during hard times.
 *      printScore(sf::RenderWindow &importWindow, sf::Font scoreFont)// A
 *                                                  // method to print
 *                                                  // the score to the screen.
 *      printScore(sf::RenderWindow &importWindow, 
 *      sf::Font scoreFont, int scoreX, int scoreY) // An overload of the above 
 *                                                  // method. This one lets the 
 *                                                  // user to pass not just font,
 *                                                  // but also the XY coordinates
 *                                                  // of where the score should
 *                                                  // be printed.
 * Modification Opportunities                       // 1. The nondefault constructor
 *                                                  // can be completed and 
 *                                                  // implemented to allow 
 *                                                  // full customization
 *                                                  // 2. A separate collision
 *                                                  // class might actually be a
 *                                                  // good idea, and would 
 *                                                  // exist here as an object
 * 
 * */
class GameCycle {
public:
    int currentLoop = 0;
    GameCycle()
    {

    }

    //UNUSED, modify to finish adding customization
    GameCycle(char playShape, char playColor, float 
    playScale, int playX, int playY, char 
    debShape, char debColor, float debScale, 
    int debX, int debY)
    {
        PlayerItem activePlayer(playShape, playColor, playScale);
        activePlayer.PlayerMotion.xPosition = playX;
        activePlayer.PlayerMotion.yPosition = playY;

        /*int arrayCounter;
        for(arrayCounter = 0; arrayCounter<10;arrayCounter++)
        {
            //Expandable: Future customization support
        }*/
    }


    void handlePlayer(sf::RenderWindow &importWindow)
    {
        activePlayer.PlayerCycle(importWindow);
    }
    void handleDebris(sf::RenderWindow &importWindow)
    {   
        int arrayCounter;
        for(arrayCounter = 0; arrayCounter<10;arrayCounter++)
        {
            if(debrisList[arrayCounter].debrisActive == 1)
            {
                debrisList[arrayCounter].debrisCycle(
                importWindow,currentLoop);
            }

            if(debrisList[arrayCounter].debrisCollisionCheck( 
                activePlayer.PlayerMotion.xPosition,
                activePlayer.PlayerMotion.yPosition) == true)
            {
                score = score - 20;
            }

            if(debrisList[arrayCounter].debrisScoreCheck())
            {
                score++;
            }
        }
    }
    void spawnDebris()
    {
        int arrayCounter;
        for(arrayCounter = 0; arrayCounter<10;arrayCounter++)
        {
            if(debrisList[arrayCounter].debrisActive == 0)
            {
                if ((rand() % (30000+currentLoop/100))>29900)
                {
                    debrisList[arrayCounter].debrisActiveSwitch();
                }
            }
        }
    }
    void newCycle(sf::RenderWindow &importWindow, 
    sf::Font scoreFont)
    {
        currentLoop++;
        spawnDebris();
        handlePlayer(importWindow);
        handleDebris(importWindow);
        printScore(importWindow, scoreFont);
    }

private:
    PlayerItem activePlayer;
    Debris debrisList[10];
    int score = 0;

    void printScore(sf::RenderWindow &importWindow, 
    sf::Font scoreFont)
    {
        //Make a score string so SFML can use it
        string holdScore = to_string(score);

        int scoreX = 25, scoreY = 750;//Y is inverted
        //These coordinates will print to left/bottom of screen
        sf::Text ScoreDisplay;
        ScoreDisplay.setFont(scoreFont);//Picks the font
        ScoreDisplay.setString(holdScore);//Loads score as text
        ScoreDisplay.setCharacterSize(30);
        ScoreDisplay.setFillColor(sf::Color::White);
        ScoreDisplay.setStyle(sf::Text::Bold);
        ScoreDisplay.setPosition(scoreX, scoreY);
        importWindow.draw(ScoreDisplay);
    }

    //Customization overload of above
    void printScore(sf::RenderWindow &importWindow, 
    sf::Font scoreFont, int scoreX, int scoreY)
    {
        //Make a score string so SFML can use it
        string holdScore = to_string(score);

        sf::Text ScoreDisplay;
        ScoreDisplay.setFont(scoreFont);
        ScoreDisplay.setString(holdScore);
        ScoreDisplay.setCharacterSize(30);
        ScoreDisplay.setFillColor(sf::Color::White);
        ScoreDisplay.setStyle(sf::Text::Bold);
        ScoreDisplay.setPosition(scoreX, scoreY);
        importWindow.draw(ScoreDisplay);
    }
    

};

/**
 * Main
 * Creates the window, loads files such as the font library, and 
 * contains the game within a while loop.
 * 
 * Modification Opportunities                       // 1. Before moving on
 *                                                  // to the game loop,
 *                                                  // allow the user to 
 *                                                  // input by text or
 *                                                  // a file some info
 *                                                  // for customization.
 */
int main()
{
    //This makes a font for displaying text.
    sf::Font gameFont;//This sets up a font with arial text, and shows
    if (!gameFont.loadFromFile("arial.ttf"))// an error if it fails.
    {
        cout << "Error: Install may be incorrect." << endl;
        cout << "Now font file was found in local directory" << endl;
    }

    //Opens the window for game, for now titled "Asteroid Dodger"
    sf::RenderWindow asteroidDodger(sf::VideoMode(800, 800), "Asteroid Dodger");
    asteroidDodger.setFramerateLimit(60);   //Limits framerate because someone
                                            //asked in class
   
    //Clears any junk on screen if it wasn't wiped last SFML run
    asteroidDodger.clear(sf::Color::Black);
    GameCycle runningCycle;

    //Run until the player closes it, then close it
    while (asteroidDodger.isOpen())
    {
        sf::Event event;
        while (asteroidDodger.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                asteroidDodger.close();
        }

        //Start a new frame/loop
        runningCycle.newCycle(asteroidDodger, gameFont);

        //Drawing only ques it up, this actually shwos it
        asteroidDodger.display();
        asteroidDodger.clear(sf::Color::Black);
        //Screen must be cleared after drawing so last 
        //frame's stuff doesn't show up this frame.

    }
    return 0;
}
