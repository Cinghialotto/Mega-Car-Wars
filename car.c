/***********************************************************

 MEGA CAR WARS

 CAR.C
***********************************************************/

#include "inc/car.h"

// LIBS ///////////////////////////////////////////////////



// DATA ///////////////////////////////////////////////////

// Handler
struct t_car car;

// FUNCTIONS //////////////////////////////////////////////

//---------------------------------------------------------
// INIT
//---------------------------------------------------------
void Car_init(u8 posx, u8 posy, u8 angle)
{
	car.posx = FIX32(posx);
	car.posy = FIX32(posy);
	car.angle = angle;
}

