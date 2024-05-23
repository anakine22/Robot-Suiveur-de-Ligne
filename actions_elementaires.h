#ifndef actions_elementaires_h
  #define actions_elementaires_h

  #include <Arduino.h>
  #include "connexions_robot_arduino_uno.h"
  #include "SonarVDA.h"
  #include "actions_complexes.h"

  //Prototypes des fonctions 
  void attendre_START(void);
  void affiche_tention_batterie(void);

  void tourner_a_droite(void);
  void tourner_a_gauche(void);
  void tourner_sur_soit(void);
  void coupure_moteur(void);
  void avance(void);
  void recul(void);
  void evitement_obstacle(void);
  void raccourcie(void);


 

   //.......

#endif