#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED



#endif // TIMER_H_INCLUDED

Timer::Timer()
{
    //Initialize the variables
    startTicks = 0;

}

void Timer::start()
{
    //Get the current clock time
    startTicks = SDL_GetTicks();
}

int Timer::get_ticks()
{
    //Return the current time minus the start time
    return SDL_GetTicks() - startTicks;
}



