const int Mot__PWM=12; //A régler
const int Mot_Sens=52; //A régler
unsigned long temps_initiale = millis(); 

void setup() {

  pinMode(Mot_Sens, OUTPUT);
  pinMode(Mot__PWM, OUTPUT);

  digitalWrite(Mot_Sens, LOW); //A régler
  analogWrite(Mot__PWM, 89); //A régler

}


void loop() {

  //L'arreter au bout de 5s 
  if ( (millis() - temps_initiale) > 3000) {

    digitalWrite(Mot_Sens, LOW);   
    analogWrite(Mot__PWM, 0);
    
    }

  
}