#ifndef PROTOTYPES_H_INCLUDED
#define PROTOTYPES_H_INCLUDED
#endif // PROTOTYPES_H_INCLUDED

//The Dot class: Dot represents the square
class Dot
{
public:

    //The X and Y offsets of the dot
    SDL_Rect dot;

    //The velocity of the dot
    int xVel, yVel;

    //The maximum speed of horizontal motion of block
    const int speedMax=120;

    //Speed of block
    int speed;

    //To store coordinates of Top and Bottom Block
    int xTop, xBottom;

    //Initializes the variables: CONSTRUCTOR
    Dot();

    //Takes key presses and adjusts the dot's velocity
    void handle_input();

    //Moves the dot
    void move();

    //Resets the dot's coordinates and velocity after each fall
    void reset();

    //Checks the collision with a certain accuracy
    bool checkCollision(float inaccuracy);

    //Increases the horizontal motion speed of block
    void speedIncrease();

    //Decreases the horizontal motion speed of block
    void speedDecrease();

    /*  Increases the population (proportionate to the accuracy of fall)
        100% accurate fall results in population increases of 100         */
    void increaseScore();

    //Shows the dot and crane on the screen
    void show(SDL_Surface *sq);
};

//The timer class
class Timer
{
private:
    //The clock time when the timer started
    int startTicks;
    bool started;

public:
    //Initializes variables
    Timer();

    //The various clock actions
    void start();

    //Gets the timer's time
    int get_ticks();
};

//The button class: It contains code for the three buttons(PLAY, HOW TO PLAY, EXIT)
class Button
{
public:

    //The attributes of the button
    SDL_Rect box;

    //Initialize the variables
    Button( int x, int y, int w, int h );

};
