#include <digitalWriteFast.h>

//SETUP DES CONSTANTES / VARIABLES

//Encodeurs : N° de pin Arduino /  N° de pin d'interruption
    const int Encodeur1A = 18;  
    const int Encodeur1B = 19; 

    const int Encodeur2A = 18; 
    const int Encodeur2B = 19; 

    const int Encodeur3A = 20; 
    const int Encodeur3B = 21; 


    volatile long ticks1 = 0; volatile long ticks1_offset = 0;
    volatile long ticks2 = 0; volatile long ticks2_offset = 0;
    volatile long ticks3 = 0; volatile long ticks3_offset = 0;
    

//Moteurs :
    const int Mot_1_PWM = 8 ;
    const int Mot_1_Sens = 50 ;

    const int Mot_2_PWM = 10 ;
    const int Mot_2_Sens = 51 ;

    const int Mot_3_PWM = 12 ;
    const int Mot_3_Sens = 52 ;


    volatile double omega1;
    volatile double omega2;
    volatile double omega3;


// Variables de temps
    volatile long temps_initiale = millis(); //(en milliseconde)

    volatile long temps_precedent1; volatile long dt1;
    volatile long temps_precedent2; volatile long dt2;
    volatile long temps_precedent3; volatile long dt3;
     

//Globales
    volatile float pi = 3.141592653589793;

// Vitesse : 
    int V_robot = 240;
    int V1 = map(V_robot, 0, 255, 0, 255 ); //Sens anti-Horaire => consigne HIGH sur mot_1_Sens
    int V3 = map(V_robot, 0, 255, 0, 255 ); //Sens Horaire => consigne LOW sur mot_3_Sens

void setup() {

    Serial.begin(9600); 
    Serial.flush();

    //Encodeurs
        pinMode(Encodeur1A, INPUT); 
        pinMode(Encodeur1B, INPUT);

        //pinMode(Encodeur2A, INPUT);
        //pinMode(Encodeur2B, INPUT);

        pinMode(Encodeur3A, INPUT);
        pinMode(Encodeur3B, INPUT);


        // activation des résistances de pullup
            digitalWrite(Encodeur1A, HIGH);  
            digitalWrite(Encodeur1B, HIGH);  

            //digitalWrite(Encodeur2A, HIGH);  
            //digitalWrite(Encodeur2B, HIGH);
            
            digitalWrite(Encodeur3A, HIGH);  
            digitalWrite(Encodeur3B, HIGH);


        //Initialiation des interruptions
            attachInterrupt(digitalPinToInterrupt(Encodeur1A), Codeur_Interupt_1A, CHANGE);
            attachInterrupt(digitalPinToInterrupt(Encodeur1B), Codeur_Interupt_1B, CHANGE);


    //Moteurs
        pinMode(Mot_1_Sens, OUTPUT);
        pinMode(Mot_1_PWM, OUTPUT);

        //pinMode(Mot_2_Sens, OUTPUT);
        //pinMode(Mot_2_PWM, OUTPUT);

        pinMode(Mot_3_Sens, OUTPUT);
        pinMode(Mot_3_PWM, OUTPUT);


        digitalWrite(Mot_1_Sens, LOW);
        analogWrite(Mot_1_PWM,  250 );
        
        //digitalWrite(Mot_2_Sens,LOW);
        //analogWrite(Mot_2_PWM, 0 );
        
        digitalWrite(Mot_3_Sens, LOW);
        analogWrite(Mot_3_PWM, 110 );

}


void loop() {

    Moteur1();
    //Moteur2();
    Moteur3();

    if ( (millis() - temps_initiale) > 3000) {

        analogWrite(Mot_1_PWM, 0 );  
        digitalWrite(Mot_1_Sens, LOW);
        
        analogWrite(Mot_3_PWM, 0 );  
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


void Moteur1() {

    dt1 = millis() - temps_precedent1; 
    temps_precedent1 = millis();

    ticks1_offset = ticks1;    
    ticks1 = 0;

    omega1 = ( (2*pi) / 544) * (ticks1_offset / dt1 ) *1000 ;


}


void Moteur2() {
    
    dt2 = millis() - temps_precedent2; 
    temps_precedent2 = millis();

    ticks2_offset = ticks2;    
    ticks2 = 0;

    omega2 = ( (2*pi) / 544) * (ticks2_offset / dt2 ) *1000 ;

    

}

void Moteur3() {
    
    dt3 = millis() - temps_precedent3; 
    temps_precedent3 = millis();

    ticks3_offset = ticks3;    
    ticks3 = 0;

    omega3 = ( (2*pi) / 544) * (ticks3_offset / dt3 ) *1000 ;

    

}

//FONCTION ENCODEURS 

    void Codeur_Interupt_1A() {
            
        if (digitalReadFast(Encodeur1A) == digitalReadFast(Encodeur1B)) {
            ticks1--;
        }

        else {
            ticks1++;
        }
    
    }



    void Codeur_Interupt_1B() {
        
        if (digitalReadFast(Encodeur1A) == digitalReadFast(Encodeur1B)) {
        ticks1++;
        }

        else {
            ticks1--;
        }
    
    }


    void Codeur_Interupt_2A() {
            
        if (digitalReadFast(Encodeur2A) == digitalReadFast(Encodeur2B)) {
            ticks1--;
        }

        else {
            ticks1++;
        }
    
    }



    void Codeur_Interupt_2B() {
        
        if (digitalReadFast(Encodeur2A) == digitalReadFast(Encodeur2B)) {
        ticks1++;
        }

        else {
            ticks1--;
        }
    
    }



    void Codeur_Interupt_3A() {

        
        if (digitalReadFast(Encodeur3A) == digitalReadFast(Encodeur3B)) {
            ticks3--;
        }

        else {
            ticks3++;
        }
    }

    void Codeur_Interupt_3B() {
        
        
        if (digitalReadFast(Encodeur3A) == digitalReadFast(Encodeur3B)) {
            ticks3++;
        }

        else {
            ticks3--;
        }
    }


