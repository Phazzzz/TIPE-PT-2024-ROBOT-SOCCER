
const int EncoderV = A1;
const int EncoderJ = A2;
int C1=0 ;
int C2=0 ;

const int A1A=3;
const int A1B=24;

void setup() {

pinMode(A1A, OUTPUT);
pinMode(A1B, OUTPUT);

Serial.begin(9600); 
}
 
void loop() {

digitalWrite(A1A,HIGH);
delay(5000);
C1=analogRead(EncoderV);
C2=analogRead(EncoderJ);
Serial.print("Valeur de C1 ");
Serial.println(C1);
Serial.print("Valeur de C2 ");
Serial.println(C2);
digitalWrite(A1A,LOW);

delay(5000);

digitalWrite(A1B,HIGH);
C1=analogRead(EncoderV);
C2=analogRead(EncoderJ);
Serial.print("Valeur de C1 ");
Serial.println(C1);
Serial.print("Valeur de C2 ");
Serial.println(C2);
digitalWrite(A1B,LOW);
delay(10000);
}














