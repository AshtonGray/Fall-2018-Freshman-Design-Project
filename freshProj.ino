#include <Servo.h>
#include <math.h>

Servo myservo;  // create servo object to control a servo

int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin
int v = 15; //initial velocity
int result = 0;

void setup() {
  Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 90);     // scale it to use it with the servo (value between 0 and 180)
  myservo.write(val);                  // sets the servo position according to the scaled value
 
  //Serial.println(val);
  result = (sq(v)*(sin(val*PI/90)))/(9.8);
  Serial.print(result);
  Serial.println(" meters"); 
  Serial.print(val);
  Serial.println(" degrees");
  delay(15);                           // waits for the servo to get there
}
