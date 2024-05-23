/* Ressources utilisées :
  Timers 0 8bits :        > Moteur 1 :
    OC0A = PD6 =  D6  IO6   > Cmd_1A
    OC0B = PD5 =  D5  IO5   > Cmd_1B
  Timers 1 16bits:        > Sonar :
    ICP1 = PB0 =  D8  IO8   > US_echo
    OC1A = PB1 =  D9  IO9
    OC1B = PB2 =  D10 SS    > US_trig
  Timers 2 8bits:         > Moteur 2 :
    OC2A = PB3 =  D11 MOSI  > Cmd_2A
    OC2B = PD3 =  D3  IO3   > Cmd_2B
*/

#ifndef connexions_robot_arduino_uno_h
  #define connexions_robot_arduino_uno_h

  #include <Arduino.h>

  #define PIN_Moteur_Droit_Recul 6  //Moteur Droit Recul pin 5
  #define PIN_Moteur_Droit_Avance 5  //Moteur Droit Avance pin 6
  #define PIN_Moteur_Gauche_Recul 11  //moteur gauche recul 3
  #define PIN_Moteur_Gauche_Avance 3 //moteur gauche Avance Pin 11 
                    //
  #define PIN_LED 13 //Connection de la LED sur la PIN 13 de l'arduino
  #define PIN_BP 12 //Bouton poussoir
  #define PIN_AN0 A0 //Capteur IR lisible en analogique ou logique
  #define PIN_AN1 A1 //
  #define PIN_AN2 A2
  #define PIN_AN3 A3

  #define PIN_D0 7   //Capteur IR lisible en logique
  #define PIN_D1 4
  #define PIN_BATT A4 //Image de la tension de la Batterie

  
  const int seuil =250; // seuil de détection de la ligne
  

  



  void init_pin(void);

#endif