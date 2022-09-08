#include <Servo.h>

#define S0 2
#define S1 3
#define S2 4
#define S3 5
#define sensorOut 6
#define servoPin 9

Servo myservo;

int redFrequency = 0;
int greenFrequency = 0;
int blueFrequency = 0;

int sensorPin = A0; 
int sensorValue;  

int angle = 0;

//1 color, 0 material
int SortType = 1;

void Spin()
{
  //Vrati traku u nazad
    Serial.println("T");



  
  if(SortType == 1)
  {
    if(redFrequency < 30 and greenFrequency < 30 and blueFrequency < 30) //White cube
    {
      myservo.write(180);
      Serial.println("Here");
      delay(1000);
      myservo.write(-180);
    }
    else //Black
    {
      myservo.write(-180);
      Serial.println("noup    ");
      delay(1000);
      myservo.write(180);
    }
  }
  else
  {
    if(sensorValue <= 100) //Metal
    {
      myservo.write(180);
      delay(1000);
      myservo.write(-180);
    }
    else //Plastic
    {
      myservo.write(-180);
      delay(1000);
      myservo.write(180);
    }
  }
  delay(5000);
}


void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  
  pinMode(sensorOut, INPUT);
  
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);

  myservo.attach(servoPin);
  myservo.write(0);
  
  Serial.begin(9600);
}
void loop() {
  // RED
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  redFrequency = pulseIn(sensorOut, LOW);
  
  // GREEN
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  greenFrequency = pulseIn(sensorOut, LOW);
 
  // BLUE
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  blueFrequency = pulseIn(sensorOut, LOW);

  // SOIL
  sensorValue = analogRead(sensorPin); 



  Serial.println(sensorValue);
  Serial.println(redFrequency);
  Serial.println(greenFrequency);
  Serial.println(blueFrequency);

  delay(1000);
  if(redFrequency < 30 and redFrequency < 30 and blueFrequency < 30)
  {
    Spin();
  }
  if(redFrequency > 30 and redFrequency > 30 and blueFrequency > 30 and redFrequency < 60 and redFrequency < 60 and blueFrequency < 60)
  {
    Spin();
  }
//140   210
//200   240
//200   200 
}
