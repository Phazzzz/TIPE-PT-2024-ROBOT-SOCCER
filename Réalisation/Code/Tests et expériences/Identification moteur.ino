#include <FlexiTimer2.h>
#include <digitalWriteFast.h>

//SETUP DES CONSTANTES

//Globales
    int v = 150; //vitesse (en bit)
    volatile double omega;

    volatile float pi = 3.141592653589793;


// Période d'échantillonnage en ms
    unsigned long temps_initiale = millis(); //(en milliseconde)
    unsigned long temps_precedent;
    volatile double T_echant = 10; // 1ms de période d'échantillionage 

//Encodeurs : N° de pin Arduino /  N° de pin d'interruption
    const int Encodeur1A = 2;  
    const int Encodeur1B = 3; 

    const int Encodeur2A = 18; 
    const int Encodeur2B = 19; 

    const int Encodeur3A = 20; 
    const int Encodeur3B = 21; 

    volatile long ticks = 0;
    long ticks_offset = 0;

//Moteurs :
    const int Mot_1_Sens = 50 ;
    const int Mot_1_PWM = 8 ;

    const int Mot_2_Sens = 51 ;
    const int Mot_2_PWM = 10 ;

    const int Mot_3_Sens = 52 ;
    const int Mot_3_PWM = 12 ;




void setup() {

    Serial.begin(9600); 
    Serial.flush();



    //Encodeurs
        pinMode(Encodeur1A, INPUT); 
        pinMode(Encodeur1B, INPUT);

        pinMode(Encodeur2A, INPUT);
        pinMode(Encodeur2B, INPUT);

        pinMode(Encodeur3A, INPUT);
        pinMode(Encodeur3B, INPUT);


        // activation des résistances de pullup
        digitalWrite(Encodeur1A, HIGH);  
        digitalWrite(Encodeur1B, HIGH);  

        digitalWrite(Encodeur2A, HIGH);  
        digitalWrite(Encodeur2B, HIGH);
        
        digitalWrite(Encodeur3A, HIGH);  
        digitalWrite(Encodeur3B, HIGH);


        //Initialiation des interruptions
        attachInterrupt(digitalPinToInterrupt(Encodeur2A), Codeur_Interupt_2A, CHANGE);
        attachInterrupt(digitalPinToInterrupt(Encodeur2B), Codeur_Interupt_2B, CHANGE);


    //Moteurs
        pinMode(Mot_1_Sens, OUTPUT);
        pinMode(Mot_1_PWM, OUTPUT);

        pinMode(Mot_2_Sens, OUTPUT);
        pinMode(Mot_2_PWM, OUTPUT);

        pinMode(Mot_3_Sens, OUTPUT);
        pinMode(Mot_3_PWM, OUTPUT);



        digitalWrite(Mot_1_PWM, LOW );
        analogWrite(Mot_1_Sens, LOW);

        digitalWrite(Mot_2_PWM, v );
        analogWrite(Mot_2_Sens,HIGH);

        digitalWrite(Mot_3_PWM, LOW );  
        analogWrite(Mot_3_Sens, LOW);


        FlexiTimer2::set(T_echant, T_echant/1000., moteur); // résolution timer = 1 ms
        FlexiTimer2::start();



}


void loop() {


    Serial.print("Temps : "); Serial.println( (millis() - temps_initiale) ) ;
    Serial.print("ticks = "); Serial.println(ticks);
    Serial.print("ticks_offset = "); Serial.println(ticks_offset) ;    
    Serial.print("Vitesse : "); Serial.print( omega ); Serial.println("rad/seconde"); 
    Serial.println(" ");


  if ( (millis() - temps_initiale) > 5000) {

    digitalWrite(Mot_2_PWM, 0 );  
    digitalWrite(Mot_2_Sens, LOW);
    
    }

}




void moteur() {
    
    ticks_offset = ticks;    
    ticks = 0;

    omega = ( (2*pi) / 544) * (ticks_offset / T_echant ) *1000 ;

}




void Codeur_Interupt_2A() {
    
        
        if (digitalReadFast(Encodeur2A) == digitalReadFast(Encodeur2B)) {
            ticks--;
        }

        else {
            ticks++;
        }

}

void Codeur_Interupt_2B() {
    
    
    if (digitalReadFast(Encodeur2A) == digitalReadFast(Encodeur2B)) {
            ticks++;
        }

        else {
            ticks--;
        }
    
}






