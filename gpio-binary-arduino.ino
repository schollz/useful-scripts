/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
int binaryRead[5];
int lastNumber = -1;
int countLast = 0;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  for (int pinNum = 2; pinNum <= 12; pinNum++) {
    pinMode(pinNum, OUTPUT);     
  }
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
  pinMode(A5,INPUT);
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
//  for (int pinNum = 2; pinNum <= 12; pinNum++) {
//    digitalWrite(pinNum, HIGH);   // turn the LED on (HIGH is the voltage level)
//    delay(50);               // wait for a second
//  }
//  for (int pinNum = 2; pinNum <= 12; pinNum++) {
//    digitalWrite(pinNum, LOW);   // turn the LED on (HIGH is the voltage level)
//    delay(50);               // wait for a second
//  }
  if (digitalRead(A5) == HIGH) {
    binaryRead[0] = digitalRead(A0);
    binaryRead[1] = digitalRead(A1);
    binaryRead[2] = digitalRead(A2);
    binaryRead[3] = digitalRead(A3);
    binaryRead[4] = digitalRead(A4);
  
    int total = 0;
    Serial.print(binaryRead[0]);
    Serial.print(binaryRead[1]);
    Serial.print(binaryRead[2]);
    Serial.print(binaryRead[3]);
    Serial.println(binaryRead[4]);
    for (int i=0; i<=4; i++) {
     total = total + 0.5+binaryRead[i]*pow(2,i);
    }
    if (total==lastNumber) {
       countLast++; 
    } else {
      countLast = 0;
      lastNumber = total; 
    }
    Serial.println(total);
     // for some reason the raspberry pi defaults to 28 (some array of voltages)
    // whenever GPIO control is relinquished. optimally there should be a app that is always on that can turn on and off stuff
    if (total < 28 and countLast > 5) {
      // Erase current pins
      for (int pinNum = 2; pinNum <= 12; pinNum++) {
        digitalWrite(pinNum, LOW);     
      }
      if (total>0) {
        digitalWrite(total+1,HIGH);
      }
    }
  }
  delay(50);  
}
