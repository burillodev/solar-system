#include<SoftwareSerial.h>
#include<Servo.h>
#define DEBUG

Servo servo;
int bttx = 9;    //tx of bluetooth module is connected to pin 9 of arduino
int btrx = 10;    //rx of bluetooth module is connected to pin 10 of arduino
SoftwareSerial bluetooth(bttx,btrx);

const int ledPIN = 13;
int planets[9]={1, 2, 3, 4, 5, 6, 7, 8, 9};
//int pos = 0;

void setup()
{

  Serial.begin(9600);    //iniciar puerto serie
  servo.attach(11);        // servo is connected to pin 11 of arduino
  bluetooth.begin(9600);

  pinMode(ledPIN , OUTPUT);  //definir pin como salida
  
}
void loop()
{
  if(bluetooth.available()>0)    //if bluetooth module is transmitting data
  {
    int pos=bluetooth.read(); // store the data in pos variable
    Serial.println(pos);
    servo.write(pos);             //move servo head to the given position
  }
  digitalWrite(ledPIN , HIGH);   // poner el Pin en HIGH
  delay(1000);                   // esperar un segundo
  //digitalWrite(ledPIN , LOW);    // poner el Pin en LOW
  //delay(1000);                   // esperar un segundo
  movePlanet(45);
  movePlanet(90);
  movePlanet(135);
  movePlanet(190);
  
}

void switchOffLights()
{
  for (int i = 1; i <= sizeof(planets) / sizeof(planets[0]); i++) {
    digitalWrite(i , LOW);    // poner el Pin en LOW
  }
}

void movePlanet(int pos)
{
  int currPos = servo.read();
  Serial.println("Current pos");
  Serial.println(currPos);
  Serial.println("Pos");
  Serial.println(pos);
  
  if(currPos > pos){
    for (int i = pos; i <= currPos; i++) {
      Serial.println(i);
      servo.write(i);
      delay(25);
    }
  }else{
    for (int i = currPos; i <= pos; i++) {
      Serial.println(i);
      servo.write(i);
      delay(25);
    }
  } 
  currPos = 0;
  pos = 0;
  Serial.println("End movement");
  
  delay(2000);
}
