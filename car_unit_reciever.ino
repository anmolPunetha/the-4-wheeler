
#include <SoftwareSerial.h>
SoftwareSerial BTSerial(5, 6); // CONNECT BT RX PIN TO ARDUINO 6 PIN | CONNECT BT TX PIN TO ARDUINO 5 PIN

char tiltDirection;
int motorInput1 = 13;
int motorInput2 = 12;
int motorInput3 = 11;
int motorInput4 = 10;

void setup() {

  pinMode(motorInput1, OUTPUT);
  pinMode(motorInput2, OUTPUT);
  pinMode(motorInput3, OUTPUT);
  pinMode(motorInput4, OUTPUT);

  digitalWrite(motorInput1, LOW);
  digitalWrite(motorInput2, LOW);
  digitalWrite(motorInput3, LOW);
  digitalWrite(motorInput4, LOW);

  Serial.begin(115200);      // Serial communication is activated at 38400 baud/s.
  BTSerial.begin(38400);    // HC-05 default speed in AT command more
}

void loop() {
  if (BTSerial.available()) {   // Witing for data incoming from the other XBee module
    tiltDirection = BTSerial.read();
    if(tiltDirection == 'F'){
      Serial.println("Backword");
      forward();
      
    }else if(tiltDirection == 'B'){
      Serial.println("Forward");
      reverse();
    }else if(tiltDirection == 'R'){
      Serial.println("Left");
      left();
    }else if(tiltDirection == 'L'){
      Serial.println("Right");
      right();
    }else if(tiltDirection == 'S'){
      Serial.println("stopcar");
      stopcar();
    }
  }
}

void forward()
{
  /*The pin numbers and high, low values might be different depending on your connections */
  digitalWrite(motorInput1, LOW);
  digitalWrite(motorInput2, HIGH);
  digitalWrite(motorInput3, LOW);
  digitalWrite(motorInput4, HIGH);
}
void reverse()
{
  /*The pin numbers and high, low values might be different depending on your connections */
  digitalWrite(motorInput1, HIGH);
  digitalWrite(motorInput2, LOW);
  digitalWrite(motorInput3, HIGH);
  digitalWrite(motorInput4, LOW);
}
void right()
{
  /*The pin numbers and high, low values might be different depending on your connections */
  digitalWrite(motorInput1, LOW);
  digitalWrite(motorInput2, HIGH);
  digitalWrite(motorInput3, LOW);
  digitalWrite(motorInput4, LOW);
}
void left()
{
  /*The pin numbers and high, low values might be different depending on your connections */
  digitalWrite(motorInput1, LOW);
  digitalWrite(motorInput2, LOW);
  digitalWrite(motorInput3, LOW);
  digitalWrite(motorInput4, HIGH);
}

void stopcar() {
  digitalWrite(motorInput1, LOW);
  digitalWrite(motorInput2, LOW);
  digitalWrite(motorInput3, LOW);
  digitalWrite(motorInput4, LOW);
}
