void forward()
{
  while (for_flag != 1)
  {
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
    else if ((sensorState0 == 0 && sensorState1 == 0 && sensorState2 == 0 && sensorState3 == 1 && sensorState4 == 0 && sensorState5 == 0) ||
             (sensorState0 == 0 && sensorState1 == 0 && sensorState2 == 0 && sensorState3 == 1 && sensorState4 == 1  && sensorState5 == 0)||
             (sensorState0 == 0 && sensorState1 == 0 && sensorState2 == 0 && sensorState3 == 0 && sensorState4 == 1  && sensorState5 == 1)||
             (sensorState0 == 0 && sensorState1 == 0 && sensorState2 == 0 && sensorState3 == 0 && sensorState4 == 0  && sensorState5 == 1)||
             (sensorState0 == 0 && sensorState1 == 0 && sensorState2 == 0 && sensorState3 == 0 && sensorState4 == 1 && sensorState5 == 0)||
             (sensorState0 == 0 && sensorState1 == 0 && sensorState2 == 0 && sensorState3 == 1 && sensorState4 == 1 && sensorState5 == 1)||
             (sensorState0 == 0 && sensorState1 == 0 && sensorState2 == 0 && sensorState3 == 1 && sensorState4 == 0 && sensorState5 == 1))
    { analogWrite(PWM2, Speed1);

      digitalWrite(motorp1, LOW);
      digitalWrite(motorn1, LOW);
      analogWrite(PWM1, Speed);
      digitalWrite(motorp, HIGH);
      digitalWrite(motorn, LOW);

    }
    else if ((sensorState0 == 0 && sensorState1 == 0 && sensorState2 == 1 && sensorState3 == 0 && sensorState4 == 0 && sensorState5 == 0) ||
             (sensorState0 == 0 && sensorState1 == 1 && sensorState2 == 1 && sensorState3 == 0 && sensorState4 == 0 && sensorState5 == 0)||
             (sensorState0 == 1 && sensorState1 == 1 && sensorState2 == 0 && sensorState3 == 0 && sensorState4 == 0 && sensorState5 == 0)||
             (sensorState0 == 1 && sensorState1 == 0 && sensorState2 == 0 && sensorState3 == 0 && sensorState4 == 0  && sensorState5 == 0)||
             (sensorState0 == 1 && sensorState1 == 0 && sensorState2 == 1 && sensorState3 == 0 && sensorState4 == 0 && sensorState5 == 0)||
             (sensorState0 == 0 && sensorState1 == 1 && sensorState2 == 0 && sensorState3 == 0 && sensorState4 == 0 && sensorState5 == 0)||
             (sensorState0 == 1 && sensorState1 == 1 && sensorState2 == 1 && sensorState3 == 0 && sensorState4 == 0 && sensorState5 == 0))
    {
      analogWrite(PWM1, Speed1);

      digitalWrite(motorp, LOW);
      digitalWrite(motorn, LOW);
      analogWrite(PWM2, Speed);
      digitalWrite(motorp1, HIGH);
      digitalWrite(motorn1, LOW);

    }
    else if ((sensorState0 == 1 && sensorState1 == 1 && sensorState2 == 1 && sensorState3 == 1 && sensorState4 == 1 && sensorState5 == 1)
             || (sensorState0 == 0 && sensorState1 == 0 && sensorState2 == 0 && sensorState3 == 0 && sensorState4 == 0 && sensorState5 == 0))
    {
      delay(280);
      digitalWrite(motorp, HIGH);
      digitalWrite(motorn, HIGH);
      digitalWrite(motorp1, HIGH);
      digitalWrite(motorn1, HIGH);
      Serial.println("stop");
      for_flag = 1;
      //while(1);
      //left();

    }
  }

}
void left()
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

    analogWrite(PWM2, 80);

    digitalWrite(motorp1, LOW);
    digitalWrite(motorn1, HIGH);
    analogWrite(PWM1, 80);
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
  forward();
  for_flag = 0;
  //data='\0';
}

void right()

{ sensorState5 = digitalRead(sensorPin5);
  //sensorState4 = digitalRead(sensorPin4);
          while (sensorState5!=1)
          {
            sensorState5 = digitalRead(sensorPin5);
            analogWrite(PWM2, 80);
            digitalWrite(motorp1, HIGH);
            digitalWrite(motorn1, LOW);
            analogWrite(PWM1, 80);
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
  
            analogWrite(PWM2, 80);
  
            digitalWrite(motorp1, HIGH);
            digitalWrite(motorn1, LOW);
            analogWrite(PWM1, 80);
            digitalWrite(motorp, LOW);
            digitalWrite(motorn, HIGH);
  
          }
          analogWrite(PWM2, 80);
          digitalWrite(motorp1, HIGH);
          digitalWrite(motorn1, HIGH);
          analogWrite(PWM1, 80);
          digitalWrite(motorp, HIGH);
          digitalWrite(motorn, HIGH);
  
          flag = 0;  
          forward();
          flag = 0;  
  //  data='\0';
}
void stop_()
{
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

    analogWrite(PWM2, 80);

    digitalWrite(motorp1, LOW);
    digitalWrite(motorn1, HIGH);
    analogWrite(PWM1, 80);
    digitalWrite(motorp, HIGH);
    digitalWrite(motorn, LOW);

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
  //forward();
//  for_flag = 0;
  //data='\0';
}

void right1()

{ sensorState5 = digitalRead(sensorPin5);
  //sensorState4 = digitalRead(sensorPin4);
          while (sensorState5!=1)
          {
            sensorState5 = digitalRead(sensorPin5);
            analogWrite(PWM2, 80);
            digitalWrite(motorp1, HIGH);
            digitalWrite(motorn1, LOW);
            analogWrite(PWM1, 80);
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
  
            analogWrite(PWM2, 80);
  
            digitalWrite(motorp1, HIGH);
            digitalWrite(motorn1, LOW);
            analogWrite(PWM1, 80);
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
  
          for_flag = 0;  
       //  forward();
       //   flag = 0;  
  //  data='\0';
}
void back()
{
                                   
}


