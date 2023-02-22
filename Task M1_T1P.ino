int inches = 0;

int cm = 0;
int led = 13;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT); 
  digitalWrite(triggerPin, LOW);
  delay(2000);
 
  digitalWrite(triggerPin, HIGH);
  delay(1000);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);

  return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop()
{
 
  cm = 0.01723 * readUltrasonicDistance(7, 7);
 
  inches = (cm / 2.54);
  if (cm>120)
  {
    digitalWrite(led,HIGH);
    delay(2000);
    digitalWrite(led,LOW);
    delay(1000);
  }
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.println("cm");
  delay(100); 
}
