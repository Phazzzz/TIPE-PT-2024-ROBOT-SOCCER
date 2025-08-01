#include <FlexiTimer2.h>
#include <digitalWriteFast.h>

//SETUP DES CONSTANTES

//Globales
    int v = 255; //vitesse (en bit)

    volatile float pi = 3.141592653589793;


// Période d'échantillonnage en ms
    volatile long temps_initiale = millis(); //(en milliseconde)
    volatile long temps_precedent;
    volatile double T_echant = 10; // 1ms de période d'échantillionage 

//Encodeurs : N° de pin Arduino /  N° de pin d'interruption
    const int Encodeur1A = 2; const int interrupt_Enco1A = 0; 
    const int Encodeur1B = 3; const int interrupt_Enco1B = 1;

    const int Encodeur2A = 18; const int interrupt_Enco2A = 5;
    const int Encodeur2B = 19; const int interrupt_Enco2B = 4;

    const int Encodeur3A = 20; const int interrupt_Enco3A = 3;
    const int Encodeur3B = 21; const int interrupt_Enco3B = 2;



    volatile long ticks1 = 0; volatile long ticks1_offset = 0;
    volatile long ticks2 = 0; volatile long ticks2_offset = 0;
    volatile long ticks3 = 0; volatile long ticks3_offset = 0;
    

//Moteurs :
    const int Mot_1_Sens = 50 ;
    const int Mot_1_PWM = 8 ;

    const int Mot_2_Sens = 51 ;
    const int Mot_2_PWM = 10 ;

    const int Mot_3_Sens = 52 ;
    const int Mot_3_PWM = 12 ;


    volatile double omega1;
    volatile double omega2;
    volatile double omega3;


void setup() {

    Serial.begin(9200); 
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
        attachInterrupt(interrupt_Enco1A, Codeur_Interupt_1A, CHANGE);
        attachInterrupt(interrupt_Enco1B, Codeur_Interupt_1B, CHANGE);

        attachInterrupt(interrupt_Enco2A, Codeur_Interupt_2A, CHANGE);
        attachInterrupt(interrupt_Enco2B, Codeur_Interupt_2B, CHANGE);

        attachInterrupt(interrupt_Enco3A, Codeur_Interupt_3A, CHANGE);
        attachInterrupt(interrupt_Enco3B, Codeur_Interupt_3B, CHANGE);

    //Moteurs
        pinMode(Mot_1_Sens,OUTPUT);
        pinMode(Mot_1_PWM, OUTPUT);

        pinMode(Mot_2_Sens,OUTPUT);
        pinMode(Mot_2_PWM, OUTPUT);

        pinMode(Mot_3_Sens,OUTPUT);
        pinMode(Mot_3_PWM, OUTPUT);



        digitalWrite(Mot_1_PWM, v );
        analogWrite(Mot_1_Sens, HIGH);

        digitalWrite(Mot_2_PWM, LOW );
        analogWrite(Mot_2_Sens, LOW);

        digitalWrite(Mot_3_PWM, v );  
        analogWrite(Mot_3_Sens, HIGH);


        FlexiTimer2::set(T_echant, T_echant/1000., Gestion_Moteurs); // résolution timer = 1 ms
        FlexiTimer2::start();


}


void loop() {

    if ( (millis() - temps_initiale) > 2500) {

        digitalWrite(Mot_1_PWM, 0 );  
        digitalWrite(Mot_1_Sens, LOW);

        digitalWrite(Mot_2_PWM, 0 );  
        digitalWrite(Mot_2_Sens, LOW);

        digitalWrite(Mot_3_PWM, 0 );  
        digitalWrite(Mot_3_Sens, LOW);
        
    }

}


void print_data() {
    
    Serial.println("------------------------------");
    Serial.print("Temps : "); Serial.println( (millis() - temps_initiale) ) ;
    Serial.println("------------------------------");
    Serial.println("         | Vitesse");
    Serial.println("------------------------------");
    Serial.print("Moteur 1 | "); Serial.print( omega1 ); Serial.println(" rad/seconde");
    Serial.println("------------------------------");
    Serial.print("Moteur 3 | "); Serial.print( omega3 ); Serial.println(" rad/seconde");
    Serial.println("------------------------------") ;
    Serial.println(" ");

}

void Gestion_Moteurs() {
    Moteur1();
    Moteur3();
}



void Moteur1() {
    

    ticks1_offset = ticks1;    
    Serial.println(ticks1_offset);
    ticks1 = 0;

    omega1 = ( (2*pi) / 544) * (ticks1_offset / T_echant ) *1000 ;



}

void Moteur3() {
    

    ticks3_offset = ticks3;    
    Serial.println(ticks3_offset);
    ticks3 = 0;

    omega3 = ( (2*pi) / 544) * (ticks3_offset / T_echant ) *1000 ;



}

//Fonctions de comptage des incrémentations des Encodeurs

    void Codeur_Interupt_1A() {
        Serial.print("Codeur_Interupt_1A");
        
        if (digitalReadFast(Encodeur1A) == digitalReadFast(Encodeur1B)) {
            ticks1--;
        }

        else {
            ticks1++;
        }
    }

    void Codeur_Interupt_1B() {
        Serial.println("Codeur_Interupt_1B");
        
        if (digitalReadFast(Encodeur1A) == digitalReadFast(Encodeur1B)) {
            ticks1++;
        }

        else {
            ticks1--;
        }
    }

    void Codeur_Interupt_2A() {
        Serial.println("Codeur_Interupt_2A");
        
        if (digitalReadFast(Encodeur2A) == digitalReadFast(Encodeur2B)) {
            ticks2--;
        }

        else {
            ticks2++;
        }
    }

    void Codeur_Interupt_2B() {
        Serial.println("Codeur_Interupt_2B");
        
        if (digitalReadFast(Encodeur2A) == digitalReadFast(Encodeur2B)) {
            ticks2++;
        }

        else {
            ticks2--;
        }
    }

    void Codeur_Interupt_3A() {

        Serial.println("Codeur_Interupt_3A");
        if (digitalReadFast(Encodeur3A) == digitalReadFast(Encodeur3B)) {
            ticks3--;
        }

        else {
            ticks3++;
        }
    }

    void Codeur_Interupt_3B() {
        Serial.println("Codeur_Interupt_3B");
        
        if (digitalReadFast(Encodeur3A) == digitalReadFast(Encodeur3B)) {
            ticks3++;
        }

        else {
            ticks3--;
        }
    }
    



