#define LEFT A0
#define echopin 8 // echo pin
#define trigpin 9 // Trigger pin
#define RIGHT A3

long time;
int ENA = 5; //ENA connected to digital pin 9
int ENB = 3; //ENB connected to digital pin 3

void setup(){
pinMode(13,OUTPUT);   //left motors forward
pinMode(12,OUTPUT);   //left motors reverse
pinMode(11,OUTPUT);   //right motors forward
pinMode(10,OUTPUT);   //right motors reverse
pinMode(ENA, OUTPUT); // initialize ENA pin as an output
pinMode(ENB, OUTPUT); // initialize ENB pin as an output

Serial.begin(9600);

pinMode(RIGHT, INPUT);
pinMode(LEFT, INPUT);

pinMode(trigpin, OUTPUT);
pinMode(echopin, INPUT);

}

void loop(){
  
unsigned int distance = read_cm();
int Right_Value = digitalRead(RIGHT);
int Left_Value  = digitalRead(LEFT);

Serial.print("R= ");
Serial.print(Right_Value);
Serial.print(" L= ");
Serial.print(Left_Value);
Serial.print(" D= ");
Serial.println(distance);

if((Right_Value==1)&&(Left_Value==1)&&(distance>=10 && distance<=30)){forward();}
else if((Right_Value==0) && (Left_Value==1)){turnRight();}
else if((Right_Value==1) && (Left_Value==0)){turnLeft();}
else if((Right_Value==1) && (Left_Value==1)){stop();}
else if(distance > 5 && distance < 10){stop();}
else if(distance < 5){backward();}

delay(50);
}

long read_cm(){
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  time = pulseIn (echopin, HIGH);
  return time / 29 / 2;
}

void forward(){// turn it on going forward
  analogWrite(ENA, 100); // set right motors speed
  analogWrite(ENB, 100); // set left motors speed
  digitalWrite(13,HIGH);
  digitalWrite(11,HIGH);
}

void backward(){ // the other way
  analogWrite(ENA, 100); // set right motors speed
  analogWrite(ENB, 100); // set left motors speed
digitalWrite(12,HIGH);
digitalWrite(10,HIGH);
}

void turnRight(){ // the other right
  analogWrite(ENA, 100); // set right motors speed
digitalWrite(13,HIGH);
}

void turnLeft(){ // turn it on going left
digitalWrite(11,HIGH);
analogWrite(ENB, 100); // set left motors speed
}

void stop(){ // stopped
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
}
