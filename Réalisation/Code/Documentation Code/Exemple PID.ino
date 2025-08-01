#include <PID_v1.h>

// Defintion des pins du Driver
int motPin1 = 6;
int motPin2 = 7;

// Definition des constantes du PID
double Cons, Entree, Sortie;
double Kp = 1, Ki = 1, Kd = 1;

// DEfintion des pins de l'encodeur 
int EncoPin1 = 2;
int EncoPin2 = 3;
volatile int encoderPos = 0; //Volatile pour stocker 
                            //le paramètre dans la RAM et optimiser son utilisiation

// INITIALISATION PID
PID myPID(&Entree, &Sortie, &Cons, Kp, Ki, Kd, DIRECT);

void setup() {
  //Initialisation du moteur
  pinMode(motPin1, OUTPUT);
  pinMode(motPin2, OUTPUT);
  
  // Initilasation de la console 
  Serial.begin(9600);

  // Initialisation de l'Encodeur
  pinMode(EncoPin1, INPUT_PULLUP);
  pinMode(EncoPin2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(EncoPin1), NouvPos, CHANGE);
  //AttachInterupt permet de declencher la fonction "NouvPos" lorsque
  //La valeur de EncoPin1 change 

  // INITIALISATION PID
  Cons = 0;
  myPID.SetMode(AUTOMATIC); //Permet d'actuialiser automatiquement la nouvelle consigne 
}

void loop() {
  // RECUPERATION DE LA VALEUR ENTREE DANS LA CONSOLE
  if(Serial.available()){
    Cons = Serial.parseInt();
  }

  // RECUPERATION DE LA POSITION DU MOTEUR
  Entree = encoderPos;

  // CALCUL DE LA SORTIE PID
  myPID.Compute();

  // CONTROLE DU MOTEUR
  if(Sortie > 0){
    digitalWrite(motPin1, HIGH);
    digitalWrite(motPin2, LOW);
  }
  else if(Sortie < 0){
    digitalWrite(motPin1, LOW);
    digitalWrite(motPin2, HIGH);
  }
  else{
    digitalWrite(motPin1, LOW);
    digitalWrite(motPin2, LOW);
  }

  // ENVOI DE LA POSITION ET DE LA SORTIE PID PAR LA CONSOLE
  Serial.print("Consigne: ");
  Serial.print(Cons);
  Serial.print(" | Entree: ");
  Serial.print(Entree);
  Serial.print(" | Sortie: ");
  Serial.println(Sortie);

  delay(100);
}

void NouvPos(){
  int a = digitalRead(EncoPin1);
  int b = digitalRead(EncoPin2);
  if(a == b){
    encoderPos++; //Incrmente de 1
  }
  else{
    encoderPos--; //Decremente de 1 
  }
}
