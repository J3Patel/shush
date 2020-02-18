// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;

// defines variables
long duration;
int distance;
int cal_dist=0;
int timer=0;
void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(8, OUTPUT); // Sets the echoPin as an Input
digitalWrite(8, HIGH);
Serial.begin(9600); // Starts the serial communication
delay(5000);
}

void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
//delay(50);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance = duration*0.034/2;

delay(100);

// Prints the distance on the Serial Monitor

Serial.println(distance);

  if (cal_dist == 0) {
    if (timer != 100){
      timer++;
      return;  
    }
    
    cal_dist = distance;
  } else {
    if (distance < cal_dist - 10)  {
      if (distance < 15) {
        makeCloseSound();
      }
      makeSound();   
      delay(5000); 
    } 
  }
}

void makeCloseSound() {
  
}

void makeSound() {
  digitalWrite(8, LOW);
  Serial.print("Sound");  
  delay(1000);
  digitalWrite(8, HIGH);
}
