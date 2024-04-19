//IoT
#include <ArduinoBLE.h>
//#include "thingProperties.h"

// servo motor 
#include <Servo.h>
Servo myservo;
int pos = 0;

// utlrasonic sensor code
const int trigPin = 8;
const int echoPin = 10;
long duration;
int distanceCm, distanceInch;

// LCD code
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3 ,2);
const int switchPin = 6;

void setup() {
  // ultrasonic sensor code
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);

  // LCD code
  lcd.begin(16,2);
  lcd.print("My name is:");
  lcd.setCursor(0,1);
  lcd.print("Pillys");

  // servo code
  myservo.attach(1);

  //IoT code
  //Serial.begin(9600);

 // delay(1500);
 // initProperties();

  //ArduinoCloud.begin(ArduinoIoTPreferredConnection);
 // setDebugMessageLevel(2);
  //ArduinoCloud.printDebugInfo();

 // while (ArduinoCloud.connected() != 1) {
   // ArduinoCloud.update();
   // delay(500);
 // }
}

void loop() {
  // ultrasonic sensor code
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distanceCm = duration * 0.034 / 2;
  distanceInch = duration * 0.0133 / 2;

  Serial.print("Distance: ");
  Serial.print(distanceCm);
  Serial.print(" cm/");
  Serial.print(distanceInch);
  Serial.println(" in");
  delay(1000);

  // servo code
  if (distanceInch < 8){
   for (pos = 0; pos <= 180; pos += 1) {
      myservo.write(pos);
      delay(15); }
    for (pos = 180; pos >= 0; pos -= 1) {
      myservo.write(pos);
      delay(15); }
    delay(15000);
      }

}
