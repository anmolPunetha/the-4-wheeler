int ENA = 9; //ENA connected to digital pin 9
int ENB = 3; //ENB connected to digital pin 3
int MOTOR_A1 = 13; // MOTOR_A1 connected to digital pin 13
int MOTOR_A2 = 12; // MOTOR_A2 connected to digital pin 12
int MOTOR_B1 = 11; // MOTOR_B1 connected to digital pin 11
int MOTOR_B2 = 10; // MOTOR_B2 connected to digital pin 10


int RIGHT = A0; // RIGHT sensor connected to analog pin A0
int LEFT = A1; // LEFT sensor connected to analog pin A1


// the setup function runs once when you press reset or power the board
void setup() {
  
pinMode(ENA, OUTPUT); // initialize ENA pin as an output
pinMode(ENB, OUTPUT); // initialize ENB pin as an output
pinMode(MOTOR_A1, OUTPUT); // initialize MOTOR_A1 pin as an output
pinMode(MOTOR_A2, OUTPUT); // initialize MOTOR_A2 pin as an output
pinMode(MOTOR_B1, OUTPUT); // initialize MOTOR_B1 pin as an output
pinMode(MOTOR_B2, OUTPUT); // initialize MOTOR_B2 pin as an output
pinMode(RIGHT, INPUT); // initialize RIGHT pin as an input
pinMode(LEFT, INPUT); // initialize ENA pin as an input

}

// the loop function runs over and over again forever
void loop() {
  
if (analogRead(RIGHT)<=35 && analogRead(LEFT)<=35) //compare the both sensor to decide the direction
{
  //MOVE FORWARD//
  
  analogWrite(ENA, 70); // set right motors speed
  analogWrite(ENB, 70); // set left motors speed
  
 
  digitalWrite(MOTOR_A1, HIGH);
  digitalWrite(MOTOR_A2, LOW);
 
  digitalWrite(MOTOR_B1, HIGH);
  digitalWrite(MOTOR_B2, LOW);
}
else if (analogRead(RIGHT)<=35 && !analogRead(LEFT)<=35) //compare the both sensor to decide the direction
{
  //LEFT
  analogWrite(ENA, 180); //set right motors speed
  analogWrite(ENB, 180); //set left motors speed
  
  digitalWrite(MOTOR_A1, LOW);
  digitalWrite(MOTOR_A2, HIGH);
  digitalWrite(MOTOR_B1, HIGH);
  digitalWrite(MOTOR_B2, LOW);
}
else if (!analogRead(RIGHT)<=35 && analogRead(LEFT)<=35) //compare the both sensor to decide the direction
{ 
  //RIGHT//
  
  analogWrite(ENA, 180); //set right motors speed
  analogWrite(ENB, 180); //set left motors speed

  
  digitalWrite(MOTOR_A1, HIGH);
  digitalWrite(MOTOR_A2, LOW);
  
  digitalWrite(MOTOR_B1, LOW);
  digitalWrite(MOTOR_B2, HIGH);
}
else if (!analogRead(RIGHT)<=35 && !analogRead(LEFT)<=35) //compare the both sensor to decide the direction
{ 
  //STOP//
  
  analogWrite(ENA, 0); //set right motors speed
  analogWrite(ENB, 0); //set left motors speed

  //stop right motors
  digitalWrite(MOTOR_A1, LOW);
  digitalWrite(MOTOR_A2, LOW);
  //stop left motors
  digitalWrite(MOTOR_B1, LOW);
  digitalWrite(MOTOR_B2, LOW);
  }
}
