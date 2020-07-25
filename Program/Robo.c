#include "labE.h"
#include "labE_usound.h"

int main (void){
   
   initPIC32 ();
   uSound_init();
   int ValueAnalog, i, Count = 0, Rotate = 1;
   
   while(STOP == 0){
   }
   
   while (TRUE){
	//Desvio de obstaculos continuo	
	  delay_ms(10);
      uSound_burst(600/25);
      
      while ((i = uSound_get_delay()) < 100) {
		  ValueAnalog = analog(Analog7);
	  }
	   
	  if(ValueAnalog > 750) {
		setSpeed(-100, -100);
		delay_ms(250);
		setSpeed(0,0);
		delay_ms(250);
		Rotate = Rotate + 1;
		
		if(Rotate%2 == 1){
			setSpeed(0,100);
			delay_ms(500);
		}
		
		else{
			setSpeed(100,0);
			delay_ms(500);
		}
	  }
		
	  else if(ValueAnalog > 500) {
		setSpeed(0,75);
		delay_ms(250);
		setSpeed(0,0);
	  }
		
	  else{
		setSpeed(75,75);
	  }
	  
	  //Estacionar 
	  if(START == 1){
		  Count = 1;
	  }
 
	  while(Count == 1){
		  delay_ms(10);
          uSound_burst(600/25);
      	
		  while ((i = uSound_get_delay()) < 100) {
			ValueAnalog = analog(Analog7);
		  }
	   
		  if(ValueAnalog > 900) { 
			setSpeed(0,0);
			delay_ms(250);
			setSpeed(-50,50);
			delay_ms(1700);
			setSpeed(0,0);	
		  }
		  
		  if(START == 1){
			Count = 0;
		  }
	  }
    }
  return (0);
}