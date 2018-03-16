#include "simpletools.h"                      // Include simpletools header
#include "abdrive.h"                          // Include abdrive header
#include "ping.h"                             // Include ping header

int derecha=0;

void camino()
{
	while !(ping_cm(8)<5)
	{
		drive_speed(-25,26);
		pause(5);
		drive_speed(256, 256);
	}

}

void turn_right()
{
	drive_speed(26, -25);
	pause(5);
}

void turn_left()
{
	drive_speed(-25,26);
	pause(5);
}

void seguir_pared()
{
	if !(ping_cm(7)<5)
	{
		turn_right();
		drive_speed(256, 256);
		derecha++;

	}
	else if !(ping_cm(8)<5)
	{
		drive_speed(256, 256);
	}
	else
	{
		turn_left();
		derecha=0;
	}

	if (derecha>5)
	{

		while !(ping_cm(8)<5)
		{
			drive_speed(256, 256);

		}
		if ping_cm(8)<5
		{
			turn_left();
			derecha=0;
		}

	}

}


//PROGRAMA PRINCIPAL :)
camino();
while true
{
	seguir_pared();
}
