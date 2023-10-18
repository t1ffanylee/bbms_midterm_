#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int lightdetect = A0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin
int LED_one = 2;
// int LED_two = 3;
// int LED_three = 4;
int calibrationThreshold;

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  pinMode(LED_one, OUTPUT);
  // pinMode(LED_two, OUTPUT);
  // pinMode(LED_three, OUTPUT);
  Serial.begin(9600);

  val = analogRead(lightdetect);
  calibrationThreshold = map(val, 0, 1023, 0, 180);

}

void loop() {
  val = analogRead(lightdetect);
  val = map(val, 0, 1023, 0, 180);
  //digitalWrite(LED_one, LOW);

  if (val < calibrationThreshold) { // Adjust the threshold value (90 in this example) to determine when it's considered dark
    // It's dark, so turn on the servo
    myservo.write(90); // Adjust the servo position as needed
    digitalWrite(LED_one, HIGH);
    // digitalWrite(LED_two, HIGH);
    // digitalWrite(LED_three, HIGH);
  } else {
    // It's not dark, so turn off the servo
    myservo.write(0); // Adjust the servo position as needed
    digitalWrite(LED_one, LOW);
    // digitalWrite(LED_two, LOW);
    // digitalWrite(LED_three, LOW);
  }
  
  

  // myservo.write(val); // sets the servo position according to the scaled value
  Serial.println(val);   

  // if (val > 30)
  //   digitalWrite(redLED, LOW);
  // if (val < 150)
  //   digitalWrite(greenLED, LOW);
  delay(10);                         // waits for the servo to get there
}

