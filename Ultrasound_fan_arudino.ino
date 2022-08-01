#include "SR04.h"
#define TRIG_PIN 12
#define ECHO_PIN 11
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long a;

// Define for relay

#define ENABLE 5
#define DIRA 3
#define DIRB 4
int i;

// Define buzzer

int buzzer = 2 ;//the pin of the active buzzer


void setup() {
   Serial.begin(9600);
   pinMode(ENABLE,OUTPUT);
   pinMode(DIRA,OUTPUT);
   pinMode(DIRB,OUTPUT);
   pinMode(buzzer,OUTPUT);//initialize the buzzer pin as an output
   pinMode(LED_BUILTIN, OUTPUT);
   delay(200);
}

void loop() {
  
   a=sr04.Distance();
   Serial.print(a);
   Serial.println("cm");
   delay(500);

   digitalWrite(ENABLE,HIGH);
   
   if (a < 25) {
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    delay(100);
    for (i=0;i<2;i++) 
    digitalWrite(DIRA,HIGH); //one way
    digitalWrite(DIRB,LOW);
    delay(3000);
    
    digitalWrite(DIRA,LOW);  //reverse
    digitalWrite(DIRB,HIGH);
    delay(3000);

    }
}
