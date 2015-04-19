#ifndef SDLUTIL_H_INCLUDED
#define SDLUTIL_H_INCLUDED



#endif // SDLUTIL_H_INCLUDED

SDL_Surface *load_image(string filename )
{
    //The image that's loaded
    SDL_Surface* loadedImage = NULL;

    //The optimized surface that will be used
    SDL_Surface* optimizedImage = NULL;

    //Load the image
    loadedImage = IMG_Load(filename.c_str() );

    //If the image loaded
    if( loadedImage != NULL )
    {
        //Create an optimized surface
        optimizedImage = SDL_DisplayFormat( loadedImage );

        //Free the old surface
        SDL_FreeSurface( loadedImage );


        //If the image was optimized just fine
        if( optimizedImage != NULL )
        {
            //Map the color key
            Uint32 colorkey = SDL_MapRGB( optimizedImage->format, 0xFF, 0xFF, 0xFF );

            //Set all pixels of color R 0xFF, G 0xFF, B 0xFF to be transparent, which is white color
            SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, colorkey );
        }

    }

    //Return the optimized surface
    return optimizedImage;
}

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL )
{
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blits
    SDL_BlitSurface( source, clip, destination, &offset );
}

//Initialize all SDL subsystems
bool init()
{

    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;
    }


    //Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

    //If there was an error in setting up the screen
    if( screen == NULL|| TTF_Init() == -1 )
    {
        return false;
    }

    //Set the window caption
    SDL_WM_SetCaption( "City Blocks", NULL );

    //If everything initialized fine
    return true;
}

bool load_files()
{
    //Load the dot image
    square = load_image( "images/square.bmp" );
    crane = load_image( "images/crane.bmp" );
    squarecut = load_image( "images/squarecut.bmp" );;
    platform = load_image( "images/platform.bmp" );
    background = load_image( "images/scrollingsky.bmp" );
    people = load_image( "images/people.bmp" );
    combo=load_image("images/combo.bmp");
    mainmenu = load_image( "images/mainmenu.bmp" );
    instruct= load_image( "images/instructions.bmp" );

    //Defines the Coordinates and Dimensions of moving People(the Superboy)
    movingPeople.x=0;/////
    movingPeople.y=0;/////
    movingPeople.h=people->h;
    movingPeople.w=people->w;

    //Defines the Coordinates and Dimensions of comboMeter
    comboMeter.x=0;
    comboMeter.y=0;
    comboMeter.h=30;
    comboMeter.w=20;

    height= screen->h-(squarecut->h+square->h);

    //Open the font
    font=TTF_OpenFont("lazy.ttf",30);

    //If everything loaded fine
    return true;
}

void clean_up()
{

    //Free the surface
    SDL_FreeSurface(square );
    SDL_FreeSurface( crane );
    SDL_FreeSurface(people );
    SDL_FreeSurface( background );
    SDL_FreeSurface( message );
    SDL_FreeSurface(platform);
    SDL_FreeSurface(background);
    SDL_FreeSurface(squarecut);
    SDL_FreeSurface(missedBlocks);
    SDL_FreeSurface(cheatsLeft);
    SDL_FreeSurface(numberblocks);
    SDL_FreeSurface(population);
    SDL_FreeSurface(combo);
    SDL_FreeSurface( mainmenu );
    SDL_FreeSurface( instruct );
    SDL_FreeSurface( previousHigh );
    SDL_FreeSurface( newHigh );
    SDL_FreeSurface( messagePrompt );

    //Close the font
    TTF_CloseFont( font );

    //Quit SDL_ttf
    TTF_Quit();

    //Quit SDL
    SDL_Quit();
}


