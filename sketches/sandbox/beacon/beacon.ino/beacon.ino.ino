void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
}

float light = 10;
float plusCoef = 5;

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13, HIGH);
  delay(light);
  light += plusCoef;
  digitalWrite(13, LOW);
  delay(light);

  if (light > 100) {
    plusCoef *= -1;
  }
  else if (light <= 0) {
    plusCoef *= -1;    
  }
}
