#ifndef COMBOMETER_H_INCLUDED
#define COMBOMETER_H_INCLUDED



#endif // COMBOMETER_H_INCLUDED

//Fills the combometer
void refillCombo()
{
    comboMeter.w=combo->w;
}

//Decreases the combometer gradually
void decreaseCombo()
{
    if(comboMeter.w>30)
    {
        comboMeter.w-=4;
    }
}

//Displays the combometer on screen
void displayCombo()
{
    apply_surface( (screen->w- combo->w)/2 , 5, combo, screen, &comboMeter );

}
