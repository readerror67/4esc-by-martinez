// 4ESC Tester 
// imcoref

// DigitalPin9 des Arduinos mit dem 4ESC verbinden


//Zeitablauf:
//einschalten des Arduinos
//5sec warten
//LED onboard EIN
//5sec warten
//dann beginnt die Ausgabe mit jeweils 10%, 20%,  usw. gemäss Array, wobei die 10% Phasen nur lang 3sek sind
//die Schub Messung sollte immer gemacht werden wenn die LED leuchtet

#include <Servo.h> 
 
Servo martinez;
int programmAblauf[] = {100, 200, 300, 400, 500, 100, 500, 100, 700, 100, 1000, 100, 0};
int ledPin = 13;
 
void setup() 
{ 
  
  martinez.attach(9,1000,2000);  
  pinMode(ledPin, OUTPUT);
  martinez.writeMicroseconds(1000);
} 
 
void loop() 
{  
     delay (5000);
     digitalWrite(ledPin, HIGH);
     delay (500);
     digitalWrite(ledPin, LOW);
     delay (5000);
      for (int i = 0; i<13; i++)
      {
        int sdelay = 7000;
        
        digitalWrite(ledPin, HIGH);
        
        
        int thrust = 1000 + programmAblauf[i];
        martinez.writeMicroseconds(thrust);
        
        digitalWrite(ledPin, LOW);
        if (thrust < 1101)
         { 
           sdelay = 0;
         } 
        delay(3000+sdelay);
        
      }
 
  while (1) 
  {
  }    
}
