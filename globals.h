#ifndef GLOBALS_H_INCLUDED
#define GLOBALS_H_INCLUDED



#endif // GLOBALS_H_INCLUDED

bool quit = false;
int blocksMissed=0;
int xpeople=0;
bool showPeople=false;

int cheatsleft=3;
bool moved=false;
bool firstBlock=true;
bool thirdBlock=false;
int height;
int numBlocks=0;
int peoplePopulation=0;

SDL_Rect movingPeople;
SDL_Rect comboMeter;

//The surfaces
SDL_Surface *square = NULL;
SDL_Surface *crane = NULL;
SDL_Surface *people = NULL;
SDL_Surface *screen = NULL;
SDL_Surface *message = NULL;
SDL_Surface *platform = NULL;
SDL_Surface *background = NULL;
SDL_Surface *squarecut = NULL;
SDL_Surface *missedBlocks=NULL;
SDL_Surface *numberblocks=NULL;
SDL_Surface *population=NULL;
SDL_Surface *combo=NULL;  // denotes combo meter
SDL_Surface *mainmenu = NULL;
SDL_Surface *instruct = NULL;
SDL_Surface *newHigh = NULL;
SDL_Surface* cheatsLeft = NULL;
SDL_Surface *previousHigh = NULL;
SDL_Surface *messagePrompt = NULL;

//The font
TTF_Font *font = NULL;

//The event structure
SDL_Event event;
