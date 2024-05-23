#include "connexions_robot_arduino_uno.h"

void init_pin(void){    
  pinMode(PIN_LED, OUTPUT); // initialize digital pin LED_BUILTIN as an output.  
  pinMode(PIN_BP, INPUT); // make the pushbutton's pin an input.
  pinMode(PIN_BATT, INPUT); //initialisation en entrée de la lecture du niveau de tension de la batterie

  pinMode(PIN_AN0, INPUT);
  pinMode(PIN_AN1, INPUT);
  pinMode(PIN_AN2, INPUT);
  pinMode(PIN_AN3, INPUT);

  pinMode(PIN_D0, INPUT);
  pinMode(PIN_D1, INPUT);

  pinMode(PIN_Moteur_Droit_Recul, OUTPUT);
  pinMode(PIN_Moteur_Droit_Avance, OUTPUT);
  pinMode(PIN_Moteur_Gauche_Recul, OUTPUT);
  pinMode(PIN_Moteur_Gauche_Avance, OUTPUT);
}
