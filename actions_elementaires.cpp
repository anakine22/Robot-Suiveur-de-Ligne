#include "actions_elementaires.h"
#include "actions_complexes.h"
#include "fonctions_test.h"

void attendre_START(void){
  bool buttonState;

  //vérifier ou attendre que le bouton ne soit pas appuyé
  do
  {
    buttonState =digitalRead(PIN_BP);
  }
  while(buttonState !=0);  
  Serial.println("Bouton non appuyer");
  //attendre que le bouton soit appuyé

  do
  {
    buttonState =digitalRead(PIN_BP);
  }
  while(buttonState !=1);
  
}

void affiche_tention_batterie(void){
  

  float tension_batterie = analogRead(PIN_BATT);
  Serial.println(tension_batterie);

  tension_batterie = (tension_batterie/1023)*11,2;
  Serial.println(tension_batterie);
}  

void coupure_moteur(void){
    digitalWrite(PIN_Moteur_Droit_Avance, LOW);
    digitalWrite(PIN_Moteur_Gauche_Avance, LOW);
    digitalWrite(PIN_Moteur_Droit_Recul, LOW);
    digitalWrite(PIN_Moteur_Gauche_Recul, LOW);
}

  void tourner_a_droite(void)
  {
    analogWrite(PIN_Moteur_Droit_Avance, 2);
    analogWrite(PIN_Moteur_Gauche_Avance, 255);
    delay(10);
  }
  void tourner_a_gauche(void){
    analogWrite(PIN_Moteur_Droit_Avance, 255);
    analogWrite(PIN_Moteur_Gauche_Avance, 0);
    delay(10);
  }

  void tourner_sur_soit(void){
    analogWrite(PIN_Moteur_Gauche_Avance, 0); 
    analogWrite(PIN_Moteur_Droit_Avance, 255); 
    analogWrite(PIN_Moteur_Gauche_Recul,255);
    analogWrite(PIN_Moteur_Droit_Recul, 0);
    delay(1250);
    coupure_moteur();
    analogWrite(PIN_Moteur_Gauche_Avance, 200); 
    analogWrite(PIN_Moteur_Droit_Avance, 200); 
    delay(30);
    analogWrite(PIN_Moteur_Gauche_Avance, 0); 
    analogWrite(PIN_Moteur_Droit_Avance, 110); 
    delay(10);
  }

  void recul(void){
    coupure_moteur(); 
    analogWrite(PIN_Moteur_Gauche_Recul,200);
    analogWrite(PIN_Moteur_Droit_Recul, 200);
  }
    void avance(void){
    analogWrite(PIN_Moteur_Gauche_Avance, 200); 
    analogWrite(PIN_Moteur_Droit_Avance, 200); 
    delay(10);
  }

  void evitement_obstacle(void){
      //Lecture etat capteur infra rouge
    unsigned int Capteur_IR1 = analogRead(PIN_AN0);
    unsigned int Capteur_IR2 = analogRead(PIN_AN1);
    unsigned int Capteur_IR3 = analogRead(PIN_AN2);
    unsigned int Capteur_IR4 = analogRead(PIN_AN3);

    unsigned int Capteur_IR5 = digitalRead(PIN_D0);
    unsigned int Capteur_IR6 = digitalRead(PIN_D1);

    
    analogWrite(PIN_Moteur_Droit_Recul, 0);
    analogWrite(PIN_Moteur_Gauche_Recul, 255); 
    analogWrite(PIN_Moteur_Droit_Avance, 255);
    analogWrite(PIN_Moteur_Gauche_Avance, 0);
    delay(250);
    coupure_moteur();    
    delay(1000);
    analogWrite(PIN_Moteur_Gauche_Avance, 250); 
    analogWrite(PIN_Moteur_Droit_Avance, 250);
    delay(300);
    
    analogWrite(PIN_Moteur_Gauche_Avance, 250); 
    analogWrite(PIN_Moteur_Droit_Avance, 80);
    delay(1400);  
    
    coupure_moteur(); 
    delay(200);
    do{
    analogWrite(PIN_Moteur_Gauche_Avance, 250); 
    analogWrite(PIN_Moteur_Droit_Avance, 250);
    }while(Capteur_IR2 > 300 && Capteur_IR3 > 300 && Capteur_IR4 > 300 && Capteur_IR1 > 300 );
    delay(200);
    coupure_moteur(); 
    delay(300);
    if(Capteur_IR2 >300 && Capteur_IR3 >300){
    analogWrite(PIN_Moteur_Gauche_Avance, 250); 
    analogWrite(PIN_Moteur_Droit_Avance, 250);
    }
    coupure_moteur(); 
    delay(300);
    do{
    analogWrite(PIN_Moteur_Droit_Recul, 0);
    analogWrite(PIN_Moteur_Gauche_Recul, 255); 
    analogWrite(PIN_Moteur_Droit_Avance, 255);
    analogWrite(PIN_Moteur_Gauche_Avance, 0);
    }while(Capteur_IR2> 300 && Capteur_IR3 > 300 && Capteur_IR1 >300);
    delay(200);
    coupure_moteur();    

             
  }

void raccourcie(void){
      unsigned int Capteur_IR1 = analogRead(PIN_AN0);
    unsigned int Capteur_IR2 = analogRead(PIN_AN1);
    unsigned int Capteur_IR3 = analogRead(PIN_AN2);
    unsigned int Capteur_IR4 = analogRead(PIN_AN3);

    unsigned int Capteur_IR5 = digitalRead(PIN_D0);
    unsigned int Capteur_IR6 = digitalRead(PIN_D1);

           if(Capteur_IR6 == 0 ){
             
              
          analogWrite(PIN_Moteur_Gauche_Avance, 255);
          analogWrite(PIN_Moteur_Droit_Avance, 255);
            delay(180);
          coupure_moteur();
          analogWrite(PIN_Moteur_Gauche_Recul, 245);
          analogWrite(PIN_Moteur_Droit_Avance, 245);
            delay(310);
           
        }
        coupure_moteur();
        if(Capteur_IR5 ==1 && Capteur_IR6 == 1 && Capteur_IR2 >900 && Capteur_IR3 >900){
          analogWrite(PIN_Moteur_Gauche_Recul, 245);
          analogWrite(PIN_Moteur_Droit_Avance, 245);
          delay(310);
            
            
        }
        coupure_moteur();
                
                    
        
}
  


  
