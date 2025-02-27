#define sensor1 2 // Left-most sensor
#define sensor2 3 // Left sensor
#define sensor3 4 // Right sensor
#define sensor4 5 // Right-most sensor

#define motorA1 6
#define motorA2 7
#define motorB1 8
#define motorB2 10
#define speedA 9
#define speedB 11
// motor control line follower robot
void setup()
{
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
  pinMode(sensor4, INPUT);

  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  pinMode(speedA, OUTPUT);
  pinMode(speedB, OUTPUT);

  analogWrite(speedA, 100); // Set motor speed (0-255)
  analogWrite(speedB, 100);
}

void loop()
/*************  ✨ Codeium Command 🌟  *************/
{
  // Read sensor values
  int s1 = digitalRead(sensor1);
  int s2 = digitalRead(sensor2);
  int s3 = digitalRead(sensor3);
  int s4 = digitalRead(sensor4);

  /**
   * Control logic for robot movement:
   * - Move Forward when both middle sensors (s2 and s3) detect black
   * - Turn Left when left-most sensor (s1) detects black
   * - Turn Right when right-most sensor (s4) detects black
   * - Stop when all sensors detect white
   */

  // Move Forward
  if (s2 == 0 && s3 == 0)
  {
    forward();
  }
  // Turn Left
  else if (s1 == 0)
  {
    turnLeft();
  }
  // Turn Right
  else if (s4 == 0)
  {
    turnRight();
  }
  // Stop (if all sensors detect white)
  else
  {
    stopRobot();
  }
}
/******  0aadf9b0-cbc8-4e35-9d84-051c18dcf0a7  *******/
{
  stopRobot();
}
}

void forward()
{
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
}

void turnLeft()
{
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
}

void turnRight()
{
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, HIGH);
}

void stopRobot()
{
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, LOW);
}