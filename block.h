#ifndef BLOCK_H_INCLUDED
#define BLOCK_H_INCLUDED"
#endif // BLOCK_H_INCLUDED


//The constructor
Dot::Dot()
{
    //Initialize the offsets
    dot.x = 850;
    dot.y = 80;

    //Initialize the velocity
    xVel = 30, speed=30;
    yVel = 0;
}

/* Function to handle keyboard inputs related to the block
   It included spacebar and down key pressed                */
void Dot::handle_input()
{
    if( event.type == SDL_KEYDOWN )
    {
        //Adjust the velocity
        switch( event.key.keysym.sym )
        {

        case SDLK_SPACE:
            if (xVel!=0)
            {   speed = xVel;
                xVel=0;
                yVel =20;
            } break;

        case SDLK_DOWN :
            if(dot.y==80 && speed>=16 && cheatsleft>0)
            {
                speed=speed-8;
                xVel=speed;
                cheatsleft--;
            }
            break;
        }
    // end switch
    }
}

void Dot::reset(){

    //Initialize the location of dot
    dot.x =  850 ;
    dot.y = 80;

    //Sets y velocity of block to 0
    xVel =speed;
    yVel = 0;
}

//Moves the dot
void Dot::move()
{
    //Move the dot left or right
    dot.x+= xVel;

    //Flying people to dot
    if(showPeople && xpeople<xTop){
        xpeople+=10;
    }
    else{
        xpeople=0;
        showPeople=false;
    }
    //If the dot went too far to the left or right
    if( ( dot.x < 495 ) || ( dot.x + DOT_WIDTH > 1300 ) )
    {
        //move back
        xVel = -xVel;
    }

    //If the dot went too far down
    if( dot.y > height )
    {
        //move back
        yVel=0;
    }

    //Move the dot up or down
    else dot.y += yVel;
}


void Dot::speedIncrease(){
    if (speed<speedMax) {
    speed=speed+10;}
    else speed=speedMax;
}

void Dot::speedDecrease(){

    if(speed>=30){
    speed=speed-8;}
}

//Checks the collision with a certain accuracy
bool Dot::checkCollision(float inaccuracy){
    if(abs(dot.x-xTop)<DOT_WIDTH*inaccuracy) return true;
    else return false;
}

    //Shows the dot and crane on the screen
void Dot::show(SDL_Surface *sq)
{

    //Holds offsets
    SDL_Rect dotRect;

    //Get offsets
    dotRect.x = dot.x;
    dotRect.y = dot.y;

    //Holds offsets
    SDL_Rect craneRect;

    //Get offsets
    craneRect.x = dot.x+DOT_WIDTH/2-crane->w/2;
    craneRect.y = 0;


    //Blit
    SDL_BlitSurface(crane, NULL,screen, &craneRect);
    SDL_BlitSurface( sq, NULL, screen, &dotRect );
}

    /* Increases the population (proportionate to the accuracy of fall)
       100% accurate fall results in population increases of 100         */
void Dot::increaseScore(){

    for(int i=100; i>abs(dot.x-xTop);i--)
    {
        if(comboMeter.w>30)peoplePopulation+=2;
        else peoplePopulation++;
    }

}


