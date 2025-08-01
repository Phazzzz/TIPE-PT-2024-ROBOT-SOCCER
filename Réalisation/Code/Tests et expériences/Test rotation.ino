
//SETUP CONSTANTES



//Encodeurs :
    const int Encodeur1B = A0;
    const int Encodeur1J = A1;

    const int Encodeur2B = A4;
    const int Encodeur2J = A5;

    const int Encodeur3B = A7;
    const int Encodeur3J = A8;


//Moteurs :
    const int Mot_1_Sens = 22 ;
    const int Mot_1_PWM = 8 ;

    const int Mot_2_Sens = 23 ;
    const int Mot_2_PWM = 10 ;

    const int Mot_3_Sens = 24 ;
    const int Mot_3_PWM = 12 ;


//Variables

volatile int V = 50;

void setup() {

//Encodeurs
    pinMode(Encodeur1B, INPUT);
    pinMode(Encodeur1J, INPUT);

    pinMode(Encodeur2B, INPUT);
    pinMode(Encodeur2J, INPUT);

    pinMode(Encodeur3B, INPUT);
    pinMode(Encodeur3J, INPUT);



//Moteurs
    pinMode(Mot_1_Sens, OUTPUT);
    pinMode(Mot_1_PWM, OUTPUT);

    pinMode(Mot_2_Sens, OUTPUT);
    pinMode(Mot_2_PWM, OUTPUT);

    pinMode(Mot_3_Sens, OUTPUT);
    pinMode(Mot_3_PWM, OUTPUT);


    digitalWrite(Mot_1_PWM,LOW);
    digitalWrite(Mot_1_Sens,LOW);

    digitalWrite(Mot_2_PWM,LOW);
    digitalWrite(Mot_2_Sens,LOW);


    digitalWrite(Mot_3_PWM,LOW);
    digitalWrite(Mot_3_Sens,LOW);


Serial.begin(9600); 

}

 void loop() {


//Sens
    digitalWrite(Mot_1_Sens, HIGH); 
    digitalWrite(Mot_2_Sens, HIGH);
    digitalWrite(Mot_3_Sens, HIGH);

//Vitesse
    analogWrite(Mot_1_PWM, V);
    analogWrite(Mot_2_PWM, V);
    analogWrite(Mot_3_PWM, V);

delay(3000);

//Arret
    digitalWrite(Mot_1_Sens, LOW); 
    digitalWrite(Mot_2_Sens, LOW);
    digitalWrite(Mot_3_Sens, LOW);

delay(4000);



 }


