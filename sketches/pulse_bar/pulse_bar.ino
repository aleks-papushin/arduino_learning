#define CONTROL_PIN 9

int brightness = 0;

void setup()
{
  pinMode(CONTROL_PIN, OUTPUT);
}

void loop()
{
  if ( brightness < 256 )
  {
    brightness = brightness + 1;
  }
  else
  {
    brightness = 0 ;
  }
  //  brightness = (brightness + 1) % 256;

  analogWrite(CONTROL_PIN, brightness);

  delay(10);
}
