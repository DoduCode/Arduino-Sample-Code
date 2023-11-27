
#include<Servo.h>

Servo micro_servo;

int pos = 0;

const int servo_pin = 7;
const int trig_pin = 2;
const int echo_pin = 3;

float duration, distance;

void setup() {
  // put your setup code here, to run once:
  pinMode(servo_pin,OUTPUT);
  pinMode(trig_pin,OUTPUT);
  pinMode(echo_pin,INPUT);
  Serial.begin(9600);
  micro_servo.attach(servo_pin);
}

void loop() {
  // put your main code here, to run repeatedly:

  for(pos = 0;pos<=180; pos++)
  {
    micro_servo.write(pos);
    delay(50);
    read_ultrasonic_distance(pos);
  }
  for(pos = 180;pos >= 0; pos--)
  {
    micro_servo.write(pos);
    delay(50);
    read_ultrasonic_distance(pos);
  }
  delay(200);
}


void read_ultrasonic_distance(int angle)
{
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);

  duration = pulseIn(echo_pin, HIGH);
  distance = (duration * 0.0343)/2;
  Serial.print(angle);
  Serial.print(",");
  Serial.println(distance);
}
