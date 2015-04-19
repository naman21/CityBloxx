#ifndef STARTBUTTONS_H_INCLUDED
#define STARTBUTTONS_H_INCLUDED



#endif // STARTBUTTONS_H_INCLUDED


char clickedButton;

// Displays HOW TO PLAY until instructions is true
bool  instructions=true;

//Mouse click
int xClick=0;
int yClick=0;

//Handle mouse events to select a button
void button_handle_events()
{
    //The mouse offsets
    int x = 0, y = 0;

    if( SDL_PollEvent( &event ) )
    {
        //If a mouse button was pressed
        if( event.type == SDL_MOUSEBUTTONDOWN )
        {
            //If the left mouse button was pressed
            if( event.button.button == SDL_BUTTON_LEFT )
            {
                //Get the mouse offsets
                xClick = event.button.x;
                yClick = event.button.y;
            }
        }
    }
}

//Run a loop to get user click
void checkClick()
{

//Defined the coordinates of button
    Button play(459,320,331,80);
    Button howtoplay(459,430,331,61);
    Button exit(459,570,331,59);

//Sets the char value of clickedButton
    while(clickedButton==NULL)
    {

        button_handle_events();

        if( ( xClick > play.box.x ) && ( xClick < play.box.x + play.box.w ) && ( yClick > play.box.y ) && ( yClick < play.box.y + play.box.h ) )
        {
            clickedButton='a';
        }
        else if ( ( xClick > howtoplay.box.x ) && ( xClick < howtoplay.box.x + howtoplay.box.w ) && ( yClick > howtoplay.box.y ) && ( yClick < howtoplay.box.y + howtoplay.box.h ) )
        {
            clickedButton='b';
        }
        else if ( ( xClick > exit.box.x ) && ( xClick < exit.box.x + exit.box.w ) && ( yClick > exit.box.y ) && ( yClick < exit.box.y + exit.box.h ) )
        {
            clickedButton='c';
        }
    }

//Compare the char value to know which button was pressed
    switch(clickedButton)
    {

    case 'c': clean_up();

    case 'b':
        apply_surface( 0, 0, instruct, screen);
        SDL_Flip(screen);

// Displays HOW TO PLAY until instructions is true
        while(instructions)
        {
            if( SDL_PollEvent( &event ) )
            {
                if( event.type == SDL_KEYDOWN )
                {
                    if( event.key.keysym.sym==SDLK_RETURN ) instructions=false;

                }
            }

        }

    case 'a':
        ;
    }
}


// Displays HOW TO PLAY until instructions is true
Button::Button( int x, int y, int w, int h )
{
    box.x = x;
    box.y = y;
    box.w = w;
    box.h = h;

}




