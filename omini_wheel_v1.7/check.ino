void check()
{ int left ,right;
  Serial.println("check");
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
  
  if (sensorState0 == 0 && sensorState1 == 0 && sensorState2 == 1 && sensorState3 == 1 && sensorState4 == 0 && sensorState5 == 0)
  { 
    Serial.println("norob"); 
    
  }
  else
  {
      
    Serial.println("correction measure activated");
    while(sensorState0 != 0 && sensorState1 != 0 && sensorState2 != 1 && sensorState3 != 1 && sensorState4 != 0 && sensorState5 != 0)
    {
  sensorState0 = digitalRead(sensorPin0);
  sensorState1 = digitalRead(sensorPin1);
  sensorState2 = digitalRead(sensorPin2);
  sensorState3 = digitalRead(sensorPin3);
  sensorState4 = digitalRead(sensorPin4);
  sensorState5 = digitalRead(sensorPin5);
      left =  sensorState0+sensorState1+sensorState2;
      right=  sensorState3+sensorState4+sensorState5;
      Serial.print(left);
      Serial.print(right);
      if(left>right)
      {
        Serial.println("left correct");
            analogWrite(PWM1, Speed1);

      digitalWrite(motorp, LOW);
      digitalWrite(motorn, LOW);
      analogWrite(PWM2, Speed);
      digitalWrite(motorp1, HIGH);
      digitalWrite(motorn1, LOW);
  
      }
      else
      {
        Serial.println("right correct");
              analogWrite(PWM2, Speed1);
      digitalWrite(motorp1, LOW);
      digitalWrite(motorn1, LOW);
      analogWrite(PWM1, Speed);
      digitalWrite(motorp, HIGH);
      digitalWrite(motorn, LOW);
        
      }
    }
  
    }
}

