void forward()
{
  while (for_flag != 1)
  {

    //    digitalWrite(led, LOW);
    //    digitalWrite(led1, HIGH);
    //    delay(100);
    //       digitalWrite(led, LOW);
    //    digitalWrite(led1, HIGH);
    //    delay(100);

    sensorState0 = digitalRead(sensorPin0);
    sensorState1 = digitalRead(sensorPin1);
    sensorState2 = digitalRead(sensorPin2);
    sensorState3 = digitalRead(sensorPin3);
    sensorState4 = digitalRead(sensorPin4);
    sensorState5 = digitalRead(sensorPin5);

    Serial.print( sensorState0);
    Serial.print("\t");
    Serial.print( sensorState1);
    Serial.print("\t");
    Serial.print( sensorState2);
    Serial.print("\t");
    Serial.print( sensorState3);
    Serial.print("\t");
    Serial.print( sensorState4);
    Serial.print("\t");
    Serial.println( sensorState5);

    // check if the pushbutton is pressed. If it is, the sensorState is HIGH:
    if (sensorState0 == 0 && sensorState1 == 0 && sensorState2 == 1 && sensorState3 == 1 && sensorState4 == 0 && sensorState5 == 0)

    {
      analogWrite(PWM1, Speed);
      digitalWrite(motorp, HIGH);
      digitalWrite(motorn, LOW);
      analogWrite(PWM2, Speed);
      digitalWrite(motorp1, HIGH);
      digitalWrite(motorn1, LOW);
      Serial.println("forward");

    }
    else if ((sensorState0 == 0 && sensorState1 == 0 && sensorState2 == 0 && sensorState3 == 1 && sensorState4 == 0  && sensorState5 == 0) ||
             (sensorState0 == 0 && sensorState1 == 0 && sensorState2 == 0 && sensorState3 == 1 && sensorState4 == 0  && sensorState5 == 0) ||
             (sensorState0 == 0 && sensorState1 == 0 && sensorState2 == 0 && sensorState3 == 0 && sensorState4 == 0  && sensorState5 == 1) ||
             (sensorState0 == 0 && sensorState1 == 0 && sensorState2 == 0 && sensorState3 == 0 && sensorState4 == 0  && sensorState5 == 1) ||
             (sensorState0 == 0 && sensorState1 == 0 && sensorState2 == 0 && sensorState3 == 0 && sensorState4 == 0  && sensorState5 == 0) ||
             (sensorState0 == 0 && sensorState1 == 0 && sensorState2 == 0 && sensorState3 == 1 && sensorState4 == 0  && sensorState5 == 1) ||
             (sensorState0 == 0 && sensorState1 == 0 && sensorState2 == 0 && sensorState3 == 1 && sensorState4 == 0  && sensorState5 == 1) ||
             (sensorState0 == 0 && sensorState1 == 0 && sensorState2 == 0 && sensorState3 == 0 && sensorState4 == 0  && sensorState5 == 1) ||
             (sensorState0 == 1 && sensorState1 == 0 && sensorState2 == 0 && sensorState3 == 0 && sensorState4 == 0  && sensorState5 == 1) ||
             (sensorState0 == 0 && sensorState1 == 0 && sensorState2 == 1 && sensorState3 == 1 && sensorState4 == 0  && sensorState5 == 0) ||
             (sensorState0 == 1 && sensorState1 == 0 && sensorState2 == 0 && sensorState3 == 0 && sensorState4 == 0  && sensorState5 == 1) )
    { 
      analogWrite(PWM2, Speed1);
      digitalWrite(motorp1, LOW);
      digitalWrite(motorn1, LOW);
      analogWrite(PWM1, Speed);
      digitalWrite(motorp, HIGH);
      digitalWrite(motorn, LOW);

    }
    else if ((sensorState0 == 0 && sensorState1 == 0 && sensorState2 == 1 && sensorState3 == 0 && sensorState4 == 0 && sensorState5 == 0) ||
             (sensorState0 == 0 && sensorState1 == 1 && sensorState2 == 1 && sensorState3 == 0 && sensorState4 == 0 && sensorState5 == 0) ||
             (sensorState0 == 1 && sensorState1 == 1 && sensorState2 == 0 && sensorState3 == 0 && sensorState4 == 0 && sensorState5 == 0) ||
             (sensorState0 == 1 && sensorState1 == 0 && sensorState2 == 0 && sensorState3 == 0 && sensorState4 == 0 && sensorState5 == 0) ||
             (sensorState0 == 1 && sensorState1 == 0 && sensorState2 == 1 && sensorState3 == 0 && sensorState4 == 0 && sensorState5 == 0) ||
             (sensorState0 == 0 && sensorState1 == 1 && sensorState2 == 0 && sensorState3 == 0 && sensorState4 == 0 && sensorState5 == 0) ||
             (sensorState0 == 1 && sensorState1 == 1 && sensorState2 == 1 && sensorState3 == 0 && sensorState4 == 0 && sensorState5 == 0) ||
             (sensorState0 == 1 && sensorState1 == 0 && sensorState2 == 0 && sensorState3 == 0 && sensorState4 == 0 && sensorState5 == 0) ||
             (sensorState0 == 1 && sensorState1 == 0 && sensorState2 == 0 && sensorState3 == 0 && sensorState4 == 0 && sensorState5 == 1) ||
             (sensorState0 == 0 && sensorState1 == 1 && sensorState2 == 1 && sensorState3 == 1 && sensorState4 == 0 && sensorState5 == 0))
    {
      analogWrite(PWM1, Speed1);

      digitalWrite(motorp, LOW);
      digitalWrite(motorn, LOW);
      analogWrite(PWM2, Speed);
      digitalWrite(motorp1, HIGH);
      digitalWrite(motorn1, LOW);

    }
    else if ((sensorState0 == 1 && sensorState1 == 1 && sensorState2 == 1 && sensorState3 == 1 && sensorState4 == 0 && sensorState5 == 1) ||
             (sensorState0 == 0 && sensorState1 == 0 && sensorState2 == 0 && sensorState3 == 0 && sensorState4 == 0 && sensorState5 == 0))
    {
      delay(280);

      digitalWrite(motorp, HIGH);
      digitalWrite(motorn, HIGH);
      digitalWrite(motorp1, HIGH);
      digitalWrite(motorn1, HIGH);

      Serial.println("stop");

      for_flag = 1;
    //  check();
     // for_flag = 1;
     //while(1);
     //left();

    }
    /*       else if((sensorState0 == 0 && sensorState1 == 0 && sensorState2 == 0 && sensorState3 == 0 && sensorState4 == 0 && sensorState5 == 0))
       {
              delay(280);
         digitalWrite(motorp, HIGH);
         digitalWrite(motorn, LOW);
         digitalWrite(motorp1, LOW);
         digitalWrite(motorn1, HIGH);
         Serial.println("stop");
         for_flag = 1;
       }*/
  }

}
void left()
{ //   digitalWrite(led, LOW);
  //    digitalWrite(led1, HIGH);
  sensorState0 = digitalRead(sensorPin0);
  //sensorState1 = digitalRead(sensorPin1);
  while (sensorState0 != 1 )
  {
    sensorState0 = digitalRead(sensorPin0);
    analogWrite(PWM2, 60);
    digitalWrite(motorp1, LOW);
    digitalWrite(motorn1, HIGH);
    analogWrite(PWM1, 60);
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
    // delay(50);
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
  ble_serial.println("0x01teach0x1dF0x04");
  //delay(2000);
  readAck();
  if (ack == '1')
  {
    forward();
  }
  ack = '\0';
  for_flag = 0;
  //data='\0';
}

void right()

{ // digitalWrite(led, LOW);
  //digitalWrite(led1, HIGH);

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
    //   Serial.println(count);

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
  ble_serial.print("0x01teach0x1dF0x04");
  readAck();
  if (ack == '1')
  {
    forward();
  }
  ack = '\0';
  flag = 0;
  //  data='\0';
}
void stop_()
{
  //digitalWrite(led, LOW);
  //igitalWrite(led1, HIGH);
  analogWrite(PWM2, 80);
  digitalWrite(motorp1, HIGH);
  digitalWrite(motorn1, HIGH);
  analogWrite(PWM1, 80);
  digitalWrite(motorp, HIGH);
  digitalWrite(motorn, HIGH);

}
void left1()
{ sensorState0 = digitalRead(sensorPin0);
  //sensorState1 = digitalRead(sensorPin1);
  while (sensorState0 != 1 )
  {
    sensorState0 = digitalRead(sensorPin0);
    analogWrite(PWM2, 60);
    digitalWrite(motorp1, LOW);
    digitalWrite(motorn1, HIGH);
    analogWrite(PWM1, 60);
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

    analogWrite(PWM2, 60);

    digitalWrite(motorp1, LOW);
    digitalWrite(motorn1, HIGH);
    analogWrite(PWM1, 60);
    digitalWrite(motorp, HIGH);
    digitalWrite(motorn, LOW);

  }
  // delay(10);
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
  //forward();
  //  for_flag = 0;
  //data='\0';
}

void right1()

{ // digitalWrite(led, LOW);
  //digitalWrite(led1, HIGH);

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
    Serial.println(count);

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
  // delay(10);
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

  for_flag = 0;
  //  forward();
  //   flag = 0;
  //  data='\0';
}
void go_back()
{
  //digitalWrite(led, LOW);
  //digitalWrite(led1, HIGH);

  analogWrite(PWM1, 255);
  digitalWrite(motorp, LOW);
  digitalWrite(motorn, HIGH);
  analogWrite(PWM2, 255);
  digitalWrite(motorp1, LOW);
  digitalWrite(motorn1, HIGH);
  delay(1200);
  analogWrite(PWM1, 255);
  digitalWrite(motorp, HIGH);
  digitalWrite(motorn, HIGH);
  analogWrite(PWM2, 255);
  digitalWrite(motorp1, HIGH);
  digitalWrite(motorn1, HIGH);


}
void go_forward()
{

  //digitalWrite(led, LOW);
  //digitalWrite(led1, HIGH);
  //delay(100);
  //digitalWrite(led, LOW);
  //digitalWrite(led1, HIGH);
  //delay(100);

  analogWrite(PWM1, 255);
  digitalWrite(motorp, HIGH);
  digitalWrite(motorn, LOW);
  analogWrite(PWM2, 255);
  digitalWrite(motorp1, HIGH);
  digitalWrite(motorn1, LOW);
  delay(1200);
  analogWrite(PWM1, 255);
  digitalWrite(motorp, HIGH);
  digitalWrite(motorn, HIGH);
  analogWrite(PWM2, 255);
  digitalWrite(motorp1, HIGH);
  digitalWrite(motorn1, HIGH);
}
void go_right()
{
  //    digitalWrite(led, LOW);
  //    digitalWrite(led1, HIGH);
  analogWrite(PWM1, 180);
  digitalWrite(motorp, LOW);
  digitalWrite(motorn, HIGH);
  analogWrite(PWM2, 180);
  digitalWrite(motorp1, HIGH);
  digitalWrite(motorn1, LOW);
  delay(600);
  analogWrite(PWM1, 250);
  digitalWrite(motorp, HIGH);
  digitalWrite(motorn, HIGH);
  analogWrite(PWM2, 250);
  digitalWrite(motorp1, HIGH);
  digitalWrite(motorn1, HIGH);

}
void go_left()
{
  //      digitalWrite(led, LOW);
  //    digitalWrite(led1, HIGH);

  analogWrite(PWM1, 180);
  digitalWrite(motorp, HIGH);
  digitalWrite(motorn, LOW);
  analogWrite(PWM2, 180);
  digitalWrite(motorp1, LOW);
  digitalWrite(motorn1, HIGH);
  delay(600);
  analogWrite(PWM1, 250);
  digitalWrite(motorp, HIGH);
  digitalWrite(motorn, HIGH);
  analogWrite(PWM2, 250);
  digitalWrite(motorp1, HIGH);
  digitalWrite(motorn1, HIGH);

}
void go_stop()
{
  //    digitalWrite(led, LOW);
  //    digitalWrite(led1, HIGH);
  analogWrite(PWM1, 250);
  digitalWrite(motorp, HIGH);
  digitalWrite(motorn, HIGH);
  analogWrite(PWM2, 250);
  digitalWrite(motorp1, HIGH);
  digitalWrite(motorn1, HIGH);
}
void wrong_left()
{ sensorState0 = digitalRead(sensorPin0);
  //sensorState1 = digitalRead(sensorPin1);
  while (sensorState0 != 1 )
  {
    digitalWrite(led, HIGH);
    digitalWrite(led1, LOW);
    sensorState0 = digitalRead(sensorPin0);
    analogWrite(PWM2, 100);
    digitalWrite(motorp1, LOW);
    digitalWrite(motorn1, HIGH);
    analogWrite(PWM1, 100);
    digitalWrite(motorp, HIGH);
    digitalWrite(motorn, LOW);
    Serial.println(count);
  }
  sensorState2 = digitalRead(sensorPin2);
  sensorState3 = digitalRead(sensorPin3);
  sensorState4 = digitalRead(sensorPin4);
  while (sensorState2 != 1 && sensorState3 != 1 )
  {

    sensorState2 = digitalRead(sensorPin2);
    sensorState3 = digitalRead(sensorPin3);
    analogWrite(PWM2, 120);
    digitalWrite(motorp1, HIGH);
    digitalWrite(motorn1, LOW);
    analogWrite(PWM1, 120);
    digitalWrite(motorp, LOW);
    digitalWrite(motorn, HIGH);
  }

  analogWrite(PWM2, 80);
  digitalWrite(motorp1, HIGH);
  digitalWrite(motorn1, HIGH);
  analogWrite(PWM1, 80);
  digitalWrite(motorp, HIGH);
  digitalWrite(motorn, HIGH);
  Serial.println("out");
  for_flag = 0;
}
void wrong_right()
{

  sensorState5 = digitalRead(sensorPin5);
  //sensorState1 = digitalRead(sensorPin1);
  while (sensorState5 != 1 )
  {
    digitalWrite(led, LOW);
    digitalWrite(led1, HIGH);
    sensorState5 = digitalRead(sensorPin5);
    analogWrite(PWM2, 100);
    digitalWrite(motorp1, HIGH);
    digitalWrite(motorn1, LOW);
    analogWrite(PWM1, 100);
    digitalWrite(motorp, LOW);
    digitalWrite(motorn, HIGH);
    Serial.println(count);
  }
  sensorState2 = digitalRead(sensorPin2);
  sensorState3 = digitalRead(sensorPin3);
  while (sensorState2 != 1 && sensorState3 != 1 )
  {
    sensorState2 = digitalRead(sensorPin2);
    sensorState3 = digitalRead(sensorPin3);
    analogWrite(PWM2, 120);
    digitalWrite(motorp1, LOW);
    digitalWrite(motorn1, HIGH);
    analogWrite(PWM1, 120);
    digitalWrite(motorp, HIGH);
    digitalWrite(motorn, LOW);
  }
  analogWrite(PWM2, 80);
  digitalWrite(motorp1, HIGH);
  digitalWrite(motorn1, HIGH);
  analogWrite(PWM1, 80);
  digitalWrite(motorp, HIGH);
  digitalWrite(motorn, HIGH);
  Serial.println("out");
  for_flag = 0;
}
void go_dance()
{
  analogWrite(PWM1, 180);
  digitalWrite(motorp, LOW);
  digitalWrite(motorn, HIGH);
  analogWrite(PWM2, 180);
  digitalWrite(motorp1, HIGH);
  digitalWrite(motorn1, LOW);
  delay(2400);
  analogWrite(PWM1, 250);
  digitalWrite(motorp, HIGH);
  digitalWrite(motorn, HIGH);
  analogWrite(PWM2, 250);
  digitalWrite(motorp1, HIGH);
  digitalWrite(motorn1, HIGH);
  analogWrite(PWM1, 180);
  digitalWrite(motorp, HIGH);
  digitalWrite(motorn, LOW);
  analogWrite(PWM2, 180);
  digitalWrite(motorp1, LOW);
  digitalWrite(motorn1, HIGH);
  delay(2400);
  analogWrite(PWM1, 250);
  digitalWrite(motorp, HIGH);
  digitalWrite(motorn, HIGH);
  analogWrite(PWM2, 250);
  digitalWrite(motorp1, HIGH);
  digitalWrite(motorn1, HIGH);

}

void go_right1()
{
  //    digitalWrite(led, LOW);
  //    digitalWrite(led1, HIGH);
  analogWrite(PWM1, 180);
  digitalWrite(motorp, LOW);
  digitalWrite(motorn, HIGH);
  analogWrite(PWM2, 180);
  digitalWrite(motorp1, HIGH);
  digitalWrite(motorn1, LOW);
  delay(300);
  analogWrite(PWM1, 250);
  digitalWrite(motorp, HIGH);
  digitalWrite(motorn, HIGH);
  analogWrite(PWM2, 250);
  digitalWrite(motorp1, HIGH);
  digitalWrite(motorn1, HIGH);

}
void go_left1()
{
  //      digitalWrite(led, LOW);
  //    digitalWrite(led1, HIGH);

  analogWrite(PWM1, 180);
  digitalWrite(motorp, HIGH);
  digitalWrite(motorn, LOW);
  analogWrite(PWM2, 180);
  digitalWrite(motorp1, LOW);
  digitalWrite(motorn1, HIGH);
  delay(300);
  analogWrite(PWM1, 250);
  digitalWrite(motorp, HIGH);
  digitalWrite(motorn, HIGH);
  analogWrite(PWM2, 250);
  digitalWrite(motorp1, HIGH);
  digitalWrite(motorn1, HIGH);

}

