#include<SoftwareSerial.h>
#include<Servo.h>

Servo servo;
int bttx = 9;    //tx of bluetooth module is connected to pin 9 of arduino
int btrx = 10;    //rx of bluetooth module is connected to pin 10 of arduino
SoftwareSerial bluetooth(bttx,btrx);

const int ledPIN = 13;
int planets[9]={1, 2, 3, 4, 5, 6, 7, 8, 9};

void setup()
{
  servo.attach(11);        // servo is connected to pin 11 of arduino
  Serial.begin(9600);
  bluetooth.begin(9600);

  Serial.begin(9600);    //iniciar puerto serie
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
  digitalWrite(ledPIN , LOW);    // poner el Pin en LOW
  delay(1000);                   // esperar un segundo

}

void switchOffLights()
{
  for (int i = 1; i <= sizeof(planets) / sizeof(planets[0]); i++) {
    digitalWrite(i , LOW);    // poner el Pin en LOW
  }
}
