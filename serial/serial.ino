void setup()
{
  Serial.begin(9600);
}
void loop()
{
  Serial.print(digitalRead(2));
  Serial.print(" ");
  Serial.print(digitalRead(3));
  Serial.print(" ");
  Serial.print(digitalRead(4));
  Serial.print(" ");
  Serial.println(digitalRead(5));
  delay(500);
}