
  const int EncoderV = A1;
  const int EncoderJ = A2;
  int C1=0 ;
  int C2=0 ;
void setup() {
   

Serial.begin(9600);

  
}

void loop() {
  // put your main code here, to run repeatedly:
  C1=analogRead(EncoderV);
  C2=analogRead(EncoderJ);
  Serial.println(C1,C2);
  


}
