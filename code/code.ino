#include <Servo.h>. 

const int trigPin = 10;
const int echoPin = 11;
const int SOIL = A1;

long duration;
int distance;
Servo myServo; 
Servo myServo1;

void setup() {
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
  pinMode(SOIL, INPUT); 
  Serial.begin(9600);
  myServo.attach(12);
  myServo1.attach(9); 
}
void loop() {
  if((digitalRead(SOIL)==LOW)){
  myServo1.write(80);
}
else if((digitalRead(SOIL)==HIGH)){
  myServo1.write(-80);
}

  for(int i=0;i<=180;i++){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance();
  Serial.print(i); 
  Serial.print(","); 
  Serial.println(distance); 
  // Serial.print("."); 
  }
  for(int i=180;i>=0;i--){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance();
  Serial.print(i); 
  Serial.print(","); 
  Serial.println(distance); 
  // Serial.print("."); 
  }
  // rotataing the servo motor from 15 to 165 degrees
  // for(int i=15;i<=165;i++){  
  // myServo.write(i);
  // delay(30);
  // distance = calculateDistance();
  // Serial.print(i); 
  // Serial.print(","); 
  // Serial.print(distance); 
  // Serial.print("."); 
  // }
  // // again servo motor from 165 to 15 degrees
  // for(int i=165;i>15;i--){  
  // myServo.write(i);
  // delay(30);
  // distance = calculateDistance();
  // Serial.print(i);
  // Serial.print(",");
  // Serial.print(distance);
  // Serial.print(".");
  // }
}

int calculateDistance(){ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); 
  distance= duration*0.034/2;
  return distance;
}