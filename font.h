#ifndef FONT_H_INCLUDED
#define FONT_H_INCLUDED



#endif // FONT_H_INCLUDED

stringstream BLOCKSMISSED;
stringstream CHEATSLEFT;
stringstream POPULATION;
stringstream NUMBERBLOCKS;
stringstream PREVIOUSHIGH;
stringstream NEWHIGH;

/* Left side texts displayed on screen
   It is first rendered then applied on screen */
void DisplaySideTexts(){

        BLOCKSMISSED.str("");
        BLOCKSMISSED.clear();
        BLOCKSMISSED<<"Blocks Missed: "<<blocksMissed;
        missedBlocks=TTF_RenderText_Solid(font,BLOCKSMISSED.str().c_str(),colorWhite);

        CHEATSLEFT.str("");
        CHEATSLEFT.clear();
        CHEATSLEFT<<"Cheats Left: "<<cheatsleft;
        cheatsLeft=TTF_RenderText_Solid(font,CHEATSLEFT.str().c_str(),colorWhite);

        POPULATION.str("");
        POPULATION.clear();
        POPULATION<<"Population: "<<peoplePopulation;
        population=TTF_RenderText_Solid(font,POPULATION.str().c_str(),colorWhite);

        NUMBERBLOCKS.str("");
        NUMBERBLOCKS.clear();
        NUMBERBLOCKS<<"Tower Height: "<<numBlocks;
        numberblocks=TTF_RenderText_Solid(font,NUMBERBLOCKS.str().c_str(),colorWhite);

        PREVIOUSHIGH.str("");
        PREVIOUSHIGH.clear();
        PREVIOUSHIGH<<"Highest Population: "<<highScore;
        previousHigh=TTF_RenderText_Solid(font,PREVIOUSHIGH.str().c_str(),colorWhite);

        NEWHIGH.str("");
        NEWHIGH.clear();
        NEWHIGH<<"CONGRATS!! New Highest Population: "<<peoplePopulation;
        newHigh=TTF_RenderText_Solid(font,NEWHIGH.str().c_str(),colorWhite);

        apply_surface(40,200,population,screen);
        apply_surface(40,300,numberblocks,screen);
        apply_surface(40,400,cheatsLeft,screen);
        apply_surface(40,500,missedBlocks,screen);
        apply_surface(40,100,previousHigh,screen);

}

//Display GAME OVER and New Higher Population, if scored
void DisplayFinalTexts(){
     if(scoredHigh)
        {
            newHigh=TTF_RenderText_Solid(font,NEWHIGH.str().c_str(),colorRed);
            apply_surface((SCREEN_WIDTH-newHigh->w)/2,(SCREEN_HEIGHT-newHigh->h)/2-100,newHigh,screen);
        }

        message=TTF_RenderText_Solid(font,"GAME OVER",colorWhite);
        apply_surface((SCREEN_WIDTH-message->w)/2,(SCREEN_HEIGHT-message->h)/2+100,message,screen);
}
