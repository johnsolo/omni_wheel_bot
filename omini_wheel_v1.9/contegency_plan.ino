 
 
 
 
 int readQD_1() {
  pinMode (sensorPin0, OUTPUT);
  digitalWrite(sensorPin0, HIGH);
  delayMicroseconds(10);
  pinMode(sensorPin0, INPUT);
  long time = micros();
  while (digitalRead(sensorPin0) == HIGH && (micros() - time) < 3000);
  int diff = micros() - time;
  return diff;
  
}
int readQD_2() {
  pinMode (sensorPin1, OUTPUT);
  digitalWrite(sensorPin1, HIGH);
  delayMicroseconds(10);
  pinMode(sensorPin1, INPUT);
  long time = micros();
  while (digitalRead(sensorPin1) == HIGH && (micros() - time) < 3000);
  int diff = micros() - time;
  return diff;
}
int readQD_3() {
  pinMode (sensorPin2, OUTPUT);
  digitalWrite(sensorPin2, HIGH);
  delayMicroseconds(10);
  pinMode(sensorPin2, INPUT);
  long time = micros();
  while (digitalRead(sensorPin2) == HIGH && (micros() - time) < 3000);
  int diff = micros() - time;
  return diff;
}
int readQD_4() {

  pinMode (sensorPin3, OUTPUT);
  digitalWrite(sensorPin3, HIGH);
  delayMicroseconds(10);
  pinMode(sensorPin3, INPUT);
  long time = micros();
  while (digitalRead(sensorPin3) == HIGH && (micros() - time) < 3000);
  int diff = micros() - time;
  return diff;
}
int readQD_5() {
  pinMode (sensorPin4, OUTPUT);
  digitalWrite(sensorPin4, HIGH);
  delayMicroseconds(10);
  pinMode(sensorPin4, INPUT);

  long time = micros();
  while (digitalRead(sensorPin4) == HIGH && (micros() - time) < 3000);
  int diff = micros() - time;
  return diff;
}
int readQD_6() {

  pinMode (sensorPin5, OUTPUT);
  digitalWrite(sensorPin5, HIGH);
  delayMicroseconds(10);
  pinMode(sensorPin5, INPUT);
  long time = micros();
  while (digitalRead(sensorPin5) == HIGH && (micros() - time) < 3000);
  int diff = micros() - time;
  return diff;
}
