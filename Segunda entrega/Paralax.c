#include "simpletools.h"                      // Include simpletools header
#include "abdrive.h"                          // Include abdrive header
#include "ping.h"                             // Include ping header

int derecha=0;


void turn_right()
{
	drive_speed(0,0);
    drive_goto(15,15);   
    drive_goto(28,-28);               
    drive_goto(55,55);
}

void turn_left()
{
	pause(5);
    drive_speed(0,0);   
    drive_goto(-28,28);                                                       
    pause(5);
}

void seguir_pared()
{
  
  drive_speed(60, 60);

	if (ping_cm(6)>15)
	{
   
		turn_right();
		derecha+=1;

	}
 
	if (ping_cm(8)<9)
 
	{
		drive_speed(0,0);
		turn_left();
        derecha=0;
	}
	

	if (derecha>5)
 
	{

		while (ping_cm(8)>5)
		{
			drive_speed(60, 60);
			derecha=0;

		}
  
		if (ping_cm(8)<5)
		{
			drive_speed(0,0);    
			turn_left();				
			derecha=0;
		}

	}

}


//PROGRAMA PRINCIPAL :)

int main()
{
 
while (1)
{
	seguir_pared();
} 
} 

