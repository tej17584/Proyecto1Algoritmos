// importacion de librerias
#include "simpletools.h"                      // Include simpletools header
#include "abdrive.h"                          // Include abdrive header
#include "ping.h"                             // Include ping header

//inicializacion de variable derecha
//esta nos permite ver cuantos giros a la derecha
//llevamos y determinar si estamos en una isla
int derecha=0;
int derecha2=0;//sensor de la derecha

//metodo para girar a la derecha
void turn_right()
{
	drive_speed(0,0);
    drive_goto(15,15);   
    drive_goto(28,-28);               
    drive_goto(55,55);
}

//metodo para girar a la izquierda
void turn_left()
{
	pause(5);
    drive_speed(0,0);   
    drive_goto(-28,28);                                                       
    pause(5);
}

void seguir_pared()
{

    freqout(1, 1, 30000);                       
    derecha2 = input(2);
  
  drive_speed(60, 60);

  	//si la derecha esta libre
  	//gire a la derecha
	if (derecha2==1)
	{
   
		turn_right();
		derecha+=1;//se suma +1 a la variable, ya que llevamos +1 vuelta consecutiva

	}
 
 	//si el sensor de enfrente detecta a una distancia menor a 9cm un obstaculo...
	if (ping_cm(8)<9)
 
	{
		//se pone la velocidad en 0
		drive_speed(0,0);
		//se ejecuta el metodo para girar a la izquierda
		turn_left();
		//se reinicia la variable derecha, debido a que se rompen los giros consecutivos
        derecha=0;
	}
	

	//si hay mas de 5 giros a la derecha consecutivos
	if (derecha>5)
 	// procedimiento para salir de isla
	{
		//si esta libre enfrente va avanzar hasta que encuentre obstaculo
		while (ping_cm(8)>5)
		{
			drive_speed(60, 60);
			derecha=0;

		}
  		// si hay algo en frente gira a la izquierda
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

