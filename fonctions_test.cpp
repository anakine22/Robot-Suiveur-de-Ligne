#include "fonctions_test.h"
  
void test_led_en_boucle(void){
  while(1){
    digitalWrite(PIN_LED, HIGH);  // turn the LED on (HIGH is the voltage level)
    delay(PERIODE_BLINK/2);                      // wait in ms
    digitalWrite(PIN_LED, LOW);   // turn the LED off by making the voltage LOW
    delay(PERIODE_BLINK/2);                      // wait in ms
  }
}

//Fonction de test de la liaison série UART entre la carte Arduino et le PC
void test_uart_en_boucle(void){


  Serial.println("Bonjour");
  delay(2000);
  while(1)
{
  Serial.println("Utile pour débugger");
  if(digitalRead(PIN_LED)==LOW){
    digitalWrite(PIN_LED, HIGH);
    Serial.println("ON");
    
  }else{
    digitalWrite(PIN_LED,LOW);
    Serial.println("OFF");
  }  
  delay(2000);
  }
}

//Fonction de....................
void test_bouton_poussoir_en_boucle(void){
  Serial.println("Test lecture BP");
  delay(2000);
  bool buttonState;
  while(1){
    do{
      buttonState = digitalRead(PIN_BP);
    }
    while(buttonState !=0);
    Serial.println("BP relache");
    digitalWrite(PIN_LED, LOW);
    do{
      buttonState = digitalRead(PIN_BP);
    }
    while(buttonState !=1);
    Serial.println("BP appuye");
    digitalWrite(PIN_LED, HIGH);    
  }
}

//Fonction de..........
void test_attendre_START_en_boucle(void){
  Serial.println("Test attendre START");  
  delay(2000);
  
  unsigned char i=0;
  while(1){
    attendre_START();
    Serial.print("Bouton START appuye "); 
    i++;
    Serial.print(i); 
    Serial.println(" fois"); 
  }
}

void test_niveau_batterie(void){
  while(1)  
  { 
    Serial.println("Mettre l'interrupteur sur ON");
    Serial.println("Appuyer sur START");
    attendre_START();
    affiche_tention_batterie();
    Serial.println("appuyer sur START pour démarrer");
    attendre_START();
  }
}

void test_capteurs_IR_logique(void){
while(1){

attendre_START();

    float Capteur_IR1 = analogRead(PIN_AN0);
    float Capteur_IR2 = analogRead(PIN_AN1);
    float Capteur_IR3 = analogRead(PIN_AN2);
    float Capteur_IR4 = analogRead(PIN_AN3);

    float Capteur_IR5 = digitalRead(PIN_D0);
    float Capteur_IR6 = digitalRead(PIN_D1);
    
  Serial.println("Capteur_IR1 = " +String(Capteur_IR1));   
  Serial.println("Capteur_IR2 = " +String(Capteur_IR2));  
  Serial.println("Capteur_IR3 = " +String(Capteur_IR3));  
  Serial.println("Capteur_IR4 = " +String(Capteur_IR4));  
  Serial.println("Capteur_IR5 = " +String(Capteur_IR5));  
  Serial.println("Capteur_IR6 = " +String(Capteur_IR6));  
  Serial.println("_____________________");     

  delay(3000);}

}

void test_moteur(){
  while(1){
  Serial.println("appuyer sur START pour démarrer");
  attendre_START();
  tourner_a_droite();
  Serial.println("appuyer sur START pour démarrer");
  attendre_START();
  tourner_a_gauche();

  Serial.println("appuyer sur START pour démarrer");
  attendre_START();
  tourner_sur_soit();
  attendre_START();
  avance();
  attendre_START();
  recul();

  }

}



//Fonction de test de la détection d'obstacle
//Cette fonction appelle les fonctions : obstacle_present() et obstacle_absent()
void test_sonar_en_boucle(SonarVDA sonar, int nb_cm_min, int nb_cm_max, void (*userFunc)(void), void (*userFunc2)(void)){
  Serial.println("Test du programme SONAR"); // print fonctionne aussi mais println permet de sauter une ligne à la fin
  sonar.set_trigger(nb_cm_min, nb_cm_max, userFunc, userFunc2); 
	 //Si un objet vient d'être détecté à moins de SEUIL_PRESENT cm alors la fonction "obj_present()" est appelée
	 //Si l'objet n'est plus détecté au dela de SEUIL_ABSENT cm alors la fonction "obj_absent()" est appelée
  sonar.start(); // On démarre les mesures d'obstacle
  while(1){
    Serial.println(sonar.get_last_measure());//on affiche la dernière mesure faite par le sonar
    delay(1000);//pause d'1 seconde
    if(digitalRead(PIN_BP)==1) { //Test de l'arrêt et de la remise en route du sonar
        sonar.stop();
        do{;
        }while(digitalRead(PIN_BP)==1);
        sonar.start();
    }
  }
}
