void read_()
{//recharge();
      for(unsigned long  i=0;i<5000;i++)
      {
   sensorState0 = digitalRead(sensorPin0);
   sensorState1 = digitalRead(sensorPin1);
   sensorState2 = digitalRead(sensorPin2);
   sensorState3 = digitalRead(sensorPin3);
   sensorState4 = digitalRead(sensorPin4);
   sensorState5 = digitalRead(sensorPin5);
    if (sensorState0 == 0 && sensorState1 == 0 && sensorState2 == 1 && sensorState3 == 1 && sensorState4 == 0 && sensorState5 == 0)

    {
      analogWrite(PWM1, Speed);
      digitalWrite(motorp, HIGH);
      digitalWrite(motorn, LOW);
      analogWrite(PWM2, Speed);
      digitalWrite(motorp1, HIGH);
      digitalWrite(motorn1, LOW);
      //("forward");

    }
    else if ((sensorState0 == 0 && sensorState1 == 0 && sensorState2 == 0 && sensorState3 == 1 && sensorState4 == 0  && sensorState5 == 0) ||
             (sensorState0 == 0 && sensorState1 == 0 && sensorState2 == 0 && sensorState3 == 1 && sensorState4 == 1  && sensorState5 == 0) ||
             (sensorState0 == 0 && sensorState1 == 0 && sensorState2 == 0 && sensorState3 == 0 && sensorState4 == 1  && sensorState5 == 1) ||
             (sensorState0 == 0 && sensorState1 == 0 && sensorState2 == 0 && sensorState3 == 0 && sensorState4 == 0  && sensorState5 == 1) ||
             (sensorState0 == 0 && sensorState1 == 0 && sensorState2 == 0 && sensorState3 == 0 && sensorState4 == 1  && sensorState5 == 0) ||
             (sensorState0 == 0 && sensorState1 == 0 && sensorState2 == 0 && sensorState3 == 1 && sensorState4 == 1  && sensorState5 == 1) ||
             (sensorState0 == 0 && sensorState1 == 0 && sensorState2 == 0 && sensorState3 == 1 && sensorState4 == 0  && sensorState5 == 1) ||
             (sensorState0 == 0 && sensorState1 == 0 && sensorState2 == 0 && sensorState3 == 0 && sensorState4 == 0  && sensorState5 == 1) ||
             (sensorState0 == 1 && sensorState1 == 0 && sensorState2 == 0 && sensorState3 == 0 && sensorState4 == 0  && sensorState5 == 1) ||
             (sensorState0 == 0 && sensorState1 == 0 && sensorState2 == 1 && sensorState3 == 1 && sensorState4 == 1  && sensorState5 == 0) ||
             (sensorState0 == 1 && sensorState1 == 0 && sensorState2 == 0 && sensorState3 == 0 && sensorState4 == 1  && sensorState5 == 1) )
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
   delayMicroseconds(1);
        
      }

      digitalWrite(motorp, HIGH);
      digitalWrite(motorn, HIGH);
      digitalWrite(motorp1, HIGH);
      digitalWrite(motorn1, HIGH);

      //("stop");

      for_flag = 1;
      //  check();
      // for_flag = 1;
      //while(1);
      //left();
}

