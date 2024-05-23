/*TP3
  CAMPION YANN
  DETOC Julien

  Sujet/titre SAE Suiveur de piste S2
  Robot numéro TP3-5
  Date dernière modification : 23/05/2023
*/

#include "connexions_robot_arduino_uno.h"
#include "fonctions_test.h"
#include "actions_elementaires.h"
#include "actions_complexes.h"
#include "SonarVDA.h"


//Réglages selon l'exécution souhaitée
#define DEBEUG  1     // mettre 1 si le robot reste relié au PC (affichage CONSOLE)
                      // SINON 0
#define TEST    0   // mettre à 1 pour lancer un des tests
                      //SINON 0

  // Sélectionner un test :
  #define TEST_LED  0
  #define TEST_UART 0
  #define TEST_BP   0
  #define TEST_attendre_START 0
  #define TEST_SONAR 0
  #define BATTERIE 0
  #define ETATLOGIQUE 1
  #define MOTEUR 0



//Paramètres de réglages
#define SEUIL_PRESENT 8  // distance en cm en dessous de laquelle un objet sera détecté
#define SEUIL_ABSENT  10  // distance en cm au dessus de laquelle un objet sera plus détecté

//Variables globales 
SonarVDA sonar; //Céation d'un objet "sonar" de classe "SonarVDA"
volatile bool obstacle_proche = false; //variable faisant le lien avec les fonction d'interruption

//Prototypes :
void test(void);
void obstacle_present(void);//Programme de gestion d'un obstacle
void obstacle_absent(void);//Programme de gestion de la disparition de l'obstacle



//****************************************************************************
//********* APPLICATIONS : setup() loop() et test() **************************
//****************************************************************************

// the setup routine runs once when you press reset:
void setup() {  
  attendre_START();//Attendre appuis Bouton pour démarrer
  if(DEBEUG){Serial.begin(9600);}// initialize serial communication at 9600 bits per second:
  init_pin();
  sonar.set_trigger(SEUIL_PRESENT, SEUIL_ABSENT, obstacle_present, obstacle_absent); 
  sonar.start(); // On démarre les mesures d'obstacle

  if(TEST){test();}
}

// the loop routine runs over and over again forever:
void loop() {  
      

  if(obstacle_proche == false){
  suivre_ligne();
  }
  else{
    coupure_moteur();//A Activer si la consigne doit arreté le robot
    /*fonction élémentaires d'évitement en cas de rencontre avec un objet*/
    //evitement_obstacle(); // A activer si on doit éviter un obstacle
    

  }

}

// Lancement de fonctions de tests 
//NB : constantes à régler en début de code selon tests désirées
void test(void){
  
  if(TEST_LED){test_led_en_boucle();}
  if(TEST_UART && DEBEUG){test_uart_en_boucle();}
  if(TEST_BP && DEBEUG){test_bouton_poussoir_en_boucle();}
  if(TEST_attendre_START && DEBEUG){test_attendre_START_en_boucle();}
  if(TEST_SONAR && DEBEUG){test_sonar_en_boucle(sonar, SEUIL_PRESENT, SEUIL_ABSENT, obstacle_present, obstacle_absent);}
  
  if(BATTERIE){test_niveau_batterie();}
  if(ETATLOGIQUE){test_capteurs_IR_logique();}
  if(MOTEUR){test_moteur();}

  
}

//****************************************************************************
//********* FONCTIONS appelées dans des programmes d'interruption ************
//****************************************************************************

//Fonction exécutée à l'apparition d'un obstacle
void obstacle_present(void){
   obstacle_proche = true;
   
   Serial.println(" Objet present");   
}

//Fonction exécutée à la disparition d'un obstacle
void obstacle_absent(void){
   obstacle_proche = false;
   Serial.println(" Objet absent");
}



//---------------------------------------------------------------------
