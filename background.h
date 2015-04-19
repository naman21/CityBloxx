#ifndef BACKGROUND_H_INCLUDED
#define BACKGROUND_H_INCLUDED



#endif // BACKGROUND_H_INCLUDED


//The offsets of the background
int bgX = 0, bgY = 750;

//Show the background
void applyBackground()
{
    apply_surface( bgX, bgY, background, screen );
    apply_surface( bgX, bgY- background->h, background, screen );
}

//Check if the background has gone too far
void checkBackground()
{
    if( bgY >= background->h )
    {
        //Reset the offset
        bgY = 1500;
    }
}

 //Scroll background
void scrollBackground()
{

    bgY += 60;
}
