/////////////////////////////////////////////////////////////////////////////////////////ONLY FOR TEACH PRO ONLY ///////////////////////////////////////////////////////////////////////////////////////////////
void left2()
{ sensorState0 = digitalRead(sensorPin0);
  //sensorState1 = digitalRead(sensorPin1);
  while (sensorState0 != 1 )
  {
    sensorState0 = digitalRead(sensorPin0);
    analogWrite(PWM2, 80);
    digitalWrite(motorp1, LOW);
    digitalWrite(motorn1, HIGH);
    analogWrite(PWM1, 80);
    digitalWrite(motorp, HIGH);
    digitalWrite(motorn, LOW);
    Serial.println(count);
  }
  sensorState2 = digitalRead(sensorPin2);
  sensorState3 = digitalRead(sensorPin3);
  while (sensorState2 != 1 && sensorState3 != 1)
  {
    sensorState2 = digitalRead(sensorPin2);
    sensorState3 = digitalRead(sensorPin3);
    sensorState4 = digitalRead(sensorPin4);
    sensorState1 = digitalRead(sensorPin1);
    analogWrite(PWM2, 60);
    digitalWrite(motorp1, LOW);
    digitalWrite(motorn1, HIGH);
    analogWrite(PWM1, 60);
    digitalWrite(motorp, HIGH);
    digitalWrite(motorn, LOW);
    delay(50);
  }
  analogWrite(PWM2, 80);
  digitalWrite(motorp1, HIGH);
  digitalWrite(motorn1, LOW);
  analogWrite(PWM1, 80);
  digitalWrite(motorp, HIGH);
  digitalWrite(motorn, LOW);
  analogWrite(PWM2, 80);
  digitalWrite(motorp1, HIGH);
  digitalWrite(motorn1, HIGH);
  analogWrite(PWM1, 80);
  digitalWrite(motorp, HIGH);
  digitalWrite(motorn, HIGH);
  Serial.println("out");
  for_flag = 0;
  ble_serial.print("0x01teach10x1dF0x04");
  //delay(2000);
  //readAck();
  //    if(ack=='1')
  {
    forward();
  }
  ack = '\0';
  for_flag = 0;
  //data='\0';
}

void right2()
{
  sensorState5 = digitalRead(sensorPin5);
  //sensorState4 = digitalRead(sensorPin4);
  while (sensorState5 != 1)
  {
    sensorState5 = digitalRead(sensorPin5);
    analogWrite(PWM2, 60);
    digitalWrite(motorp1, HIGH);
    digitalWrite(motorn1, LOW);
    analogWrite(PWM1, 60);
    digitalWrite(motorp, LOW);
    digitalWrite(motorn, HIGH);
    //   Serial.println(count)
  }
  sensorState2 = digitalRead(sensorPin2);
  sensorState3 = digitalRead(sensorPin3);
  while (sensorState2 != 1 && sensorState3 != 1)
  {
    sensorState2 = digitalRead(sensorPin2);
    sensorState3 = digitalRead(sensorPin3);
    analogWrite(PWM2, 60);
    digitalWrite(motorp1, HIGH);
    digitalWrite(motorn1, LOW);
    analogWrite(PWM1, 60);
    digitalWrite(motorp, LOW);
    digitalWrite(motorn, HIGH);
  }
  analogWrite(PWM2, 80);
  digitalWrite(motorp1, HIGH);
  digitalWrite(motorn1, LOW);
  analogWrite(PWM1, 80);
  digitalWrite(motorp, HIGH);
  digitalWrite(motorn, LOW);
  analogWrite(PWM2, 80);
  digitalWrite(motorp1, HIGH);
  digitalWrite(motorn1, HIGH);
  analogWrite(PWM1, 80);
  digitalWrite(motorp, HIGH);
  digitalWrite(motorn, HIGH);
  flag = 0;
  ble_serial.print("0x01teach10x1dF0x04");
  //readAck();
  //if(ack=='1')
  {
    forward();
  }
  ack = '\0';
  flag = 0;
  //  data='\0';
}
//for only teach 1 mode only 
