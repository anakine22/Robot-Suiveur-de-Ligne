#include "actions_complexes.h"
#include "actions_elementaires.h"
#include "fonctions_test.h"



void suivre_ligne(void){
  
    unsigned int Capt1, Capt2, Capt3, Capt4, Capt5, Capt6;
    unsigned int Capteur_IR1 = Capt5 = analogRead(PIN_AN0);
    unsigned int Capteur_IR2 = Capt4 = analogRead(PIN_AN1);
    unsigned int Capteur_IR3 = Capt3 = analogRead(PIN_AN2);
    unsigned int Capteur_IR4 = Capt2 = analogRead(PIN_AN3);

    unsigned int Capteur_IR5 = Capt6 = digitalRead(PIN_D0);
    unsigned int Capteur_IR6 = Capt1 = digitalRead(PIN_D1);

      //*********************************************|Correction gauche|*******************************************
      if(Capteur_IR4 <700 && Capteur_IR4 > 450 && Capteur_IR3<400 && Capteur_IR2 >500){
      analogWrite(PIN_Moteur_Gauche_Avance, 230);
      analogWrite(PIN_Moteur_Droit_Avance, 245);
      }     
      //***********************************************Correction droite******************************************
    if(Capteur_IR1 <700 && Capteur_IR1 > 450 && Capteur_IR2<400 && Capteur_IR3 >500 ){ 
      analogWrite(PIN_Moteur_Gauche_Avance, 245);
      analogWrite(PIN_Moteur_Droit_Avance, 230);   
       
      } 
      //******************************************|VIRAGE GAUCHE|**************************************************
    if(Capteur_IR4 < 400 && Capteur_IR5 ==1){
      do{
        analogWrite(PIN_Moteur_Gauche_Avance, 0);
        analogWrite(PIN_Moteur_Droit_Avance, 255);
        }
      while( Capteur_IR5 ==0 && Capteur_IR1 <100); 
    }
     

      //******************************************|VIRAGE DROIT|**************************************************
    if(Capteur_IR1 < 100 ){
      do{
        analogWrite(PIN_Moteur_Gauche_Avance, 255);
        analogWrite(PIN_Moteur_Droit_Avance, 0);
        }
      while(Capteur_IR1>100 );
    //******************************************|LIGNE DROITE|**************************************************      
  }

  else if(Capteur_IR2< 300 && Capteur_IR3 < 300 && Capteur_IR4 > 700 ){
    analogWrite(PIN_Moteur_Gauche_Avance, 245);
    analogWrite(PIN_Moteur_Droit_Avance, 245);


      //************************************|360Â°|****************************************
      if(Capteur_IR5 == 0 && Capteur_IR6 == 1 && Capteur_IR1<300 && Capteur_IR4 > 500){
    tourner_sur_soit();//360Ã‚Â°V2 |||||||||
  }
    //**************************************|RACCOURCIE|**********************************
  else if(Capteur_IR6 ==0  ){
            coupure_moteur(); 
        analogWrite(PIN_Moteur_Gauche_Avance, 255);
        analogWrite(PIN_Moteur_Droit_Avance, 255);
        delay(150);
    raccourcie();
  }
}
        if(Capteur_IR1 > 900 && Capteur_IR2 > 900 && Capteur_IR3 > 900 && Capteur_IR4 > 900){
    analogWrite(PIN_Moteur_Gauche_Avance, 245);
    analogWrite(PIN_Moteur_Droit_Avance, 245);
    delay(50);
      if(Capteur_IR1 > 900 && Capteur_IR2 > 900){
        while(1){
          coupure_moteur();
        }
      }
  }
}

