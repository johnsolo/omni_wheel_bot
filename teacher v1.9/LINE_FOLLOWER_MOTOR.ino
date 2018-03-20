void forward()
{ int x, y;
  recharge();
  while (for_flag != 1)
  {
    // recharge();
    Serial.println("forward");
    //recharge();
    sensorState0 = digitalRead(sensorPin0);
    sensorState1 = digitalRead(sensorPin1);
    sensorState2 = digitalRead(sensorPin2);
    sensorState3 = digitalRead(sensorPin3);
    sensorState4 = digitalRead(sensorPin4);
    sensorState5 = digitalRead(sensorPin5);
    sensorState6 = digitalRead(sensorPin6);
    sensorState7 = digitalRead(sensorPin7);

    //
//    Serial.print( sensorState0);
//    Serial.print("\t");
//    Serial.print( sensorState1);
//    Serial.print("\t");
//    Serial.print( sensorState2);
//    Serial.print("\t");
//    Serial.print( sensorState3);
//    Serial.print("\t");
//    Serial.print( sensorState4);
//    Serial.print("\t");
//    Serial.print( sensorState5);
//    Serial.print("\t");
//    Serial.print( sensorState6);
//    Serial.print("\t");
//    Serial.println( sensorState7);
    x = sensorState0 + sensorState1 + sensorState2;
    y = sensorState3 + sensorState4 + sensorState5 ;
    // check if the pushbutton is pressed. If it is, the sensorState is HIGH:
    if (sensorState0 == 0 && sensorState1 == 0 && sensorState2 == 1 && sensorState3 == 1 && sensorState4 == 0 && sensorState5 == 0)

    {
      analogWrite(PWM1, Speed);
      digitalWrite(motorp, HIGH);
      digitalWrite(motorn, LOW);
      analogWrite(PWM2, Speed);
      digitalWrite(motorp1, HIGH);
      digitalWrite(motorn1, LOW);
    }
    else if (y > x)
    {
      analogWrite(PWM2, Speed1);
      digitalWrite(motorp1, HIGH);
      digitalWrite(motorn1, HIGH);
      analogWrite(PWM1, Speed);
      digitalWrite(motorp, HIGH);
      digitalWrite(motorn, LOW);

    }
    else if (x > y)
    {
      analogWrite(PWM1, Speed1);

      digitalWrite(motorp, HIGH);
      digitalWrite(motorn, HIGH);
      analogWrite(PWM2, Speed);
      digitalWrite(motorp1, HIGH);
      digitalWrite(motorn1, LOW);

    }
    else if ((sensorState0 == 1 && sensorState1 == 1 && sensorState2 == 1 && sensorState3 == 1 && sensorState4 == 1 && sensorState5 == 1))
    {
      while (sensorState6 != 1 && sensorState7 != 1)
      {
        // recharge();
        Serial.println("forward");
        //recharge();
        sensorState0 = digitalRead(sensorPin0);
        sensorState1 = digitalRead(sensorPin1);
        sensorState2 = digitalRead(sensorPin2);
        sensorState3 = digitalRead(sensorPin3);
        sensorState4 = digitalRead(sensorPin4);
        sensorState5 = digitalRead(sensorPin5);
        sensorState6 = digitalRead(sensorPin6);
        sensorState7 = digitalRead(sensorPin7);

        //
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
        Serial.print( sensorState5);
        Serial.print("\t");
        Serial.print( sensorState6);
        Serial.print("\t");
        Serial.println( sensorState7);
        x = sensorState0 + sensorState1 + sensorState2;
        y = sensorState3 + sensorState4 + sensorState5 ;

        if (sensorState0 == 0 && sensorState1 == 0 && sensorState2 == 1 && sensorState3 == 1 && sensorState4 == 0 && sensorState5 == 0)

        {
          analogWrite(PWM1, Speed);
          digitalWrite(motorp, HIGH);
          digitalWrite(motorn, LOW);
          analogWrite(PWM2, Speed);
          digitalWrite(motorp1, HIGH);
          digitalWrite(motorn1, LOW);
        }
        else if (y > x)
        {
          analogWrite(PWM2, Speed1);
          digitalWrite(motorp1, HIGH);
          digitalWrite(motorn1, HIGH);
          analogWrite(PWM1, Speed);
          digitalWrite(motorp, HIGH);
          digitalWrite(motorn, LOW);

        }
        else if (x > y)
        {
          analogWrite(PWM1, Speed1);

          digitalWrite(motorp, HIGH);
        digitalWrite(motorn, HIGH);
          analogWrite(PWM2, Speed);
          digitalWrite(motorp1, HIGH);
          digitalWrite(motorn1, LOW);

        }
        else if (sensorState6 == 1 && sensorState7 == 1)
        {
          // analogWrite(PWM1, Speed1);

          digitalWrite(motorp, HIGH);
          digitalWrite(motorn, HIGH);
          // analogWrite(PWM2, Speed);
          digitalWrite(motorp1, HIGH);
          digitalWrite(motorn1, HIGH);

        }

      }
      // analogWrite(PWM1, Speed1);
     // Seriali.println();
        sensorState6 = digitalRead(sensorPin6);
        sensorState7 = digitalRead(sensorPin7);
            Serial.print("\t");
        Serial.print( sensorState6);
        Serial.print("\t");
        Serial.println( sensorState7);
        if(sensorState6 ==0 && sensorState7 ==1 && Degree_flag!='1')
        { sensorState6 = digitalRead(sensorPin6);
          Serial.println("cond 1");
                  analogWrite(PWM1, 100);
    digitalWrite(motorp1, HIGH);
    digitalWrite(motorn1, LOW);
        }
        else if(sensorState6 ==1 && sensorState7 ==0 &&  Degree_flag!='1')
        {
           Serial.println("cond 2");
           while (sensorState7 !=1)
           { sensorState7 = digitalRead(sensorPin7);
        analogWrite(PWM1, 100);
    digitalWrite(motorp, HIGH);
    digitalWrite(motorn, LOW);
           }
             digitalWrite(motorp, HIGH);
    digitalWrite(motorn, HIGH);
        }
        else if(sensorState6 ==1 && sensorState7 ==1)
        {
           Serial.println("cond 3");
        }
      digitalWrite(motorp, HIGH);
      digitalWrite(motorn, HIGH);
      // analogWrite(PWM2, Speed);
      digitalWrite(motorp1, HIGH);
      digitalWrite(motorn1, HIGH);
      for_flag = 1;

    }


  }
 recharge();
  //delay(200);


  /*       else if((sensorState0 == 0 && sensorState1 == 0 && sensorState2 == 0 && sensorState3 == 0 && sensorState4 == 0 && sensorState5 == 0))
     {
            delay(280);
       digitalWrite(motorp, HIGH);
       digitalWrite(motorn, LOW);
       digitalWrite(motorp1, LOW);
       digitalWrite(motorn1, HIGH);
       //("stop");
       for_flag = 1;
     }*/
  //recharge();
}



void left()
{ //   digitalWrite(led, LOW);
  //    digitalWrite(led1, HIGH);
 // recharge();
     analogWrite(PWM2, 100);
    digitalWrite(motorp1, LOW);
    digitalWrite(motorn1, HIGH);
    analogWrite(PWM1, 100);
    digitalWrite(motorp, HIGH);
    digitalWrite(motorn, LOW);
    delay(20);
  sensorState5 = digitalRead(sensorPin5);
  //sensorState1 = digitalRead(sensorPin1);
  while (sensorState5 != 1 )
  {
    sensorState5 = digitalRead(sensorPin5);
    analogWrite(PWM2, 100);
    digitalWrite(motorp1, LOW);
    digitalWrite(motorn1, HIGH);
    analogWrite(PWM1, 100);
    digitalWrite(motorp, HIGH);
    digitalWrite(motorn, LOW);
    //(count);

  }
  sensorState6 = digitalRead(sensorPin6);
  sensorState7 = digitalRead(sensorPin7);

  while (sensorState7 != 1 && sensorState6!=1)
  {
    sensorState6 = digitalRead(sensorPin6);
    sensorState7 = digitalRead(sensorPin7);


    analogWrite(PWM2, 100);

    digitalWrite(motorp1, LOW);
    digitalWrite(motorn1, HIGH);
    analogWrite(PWM1, 100);
    digitalWrite(motorp, HIGH);
    digitalWrite(motorn, LOW);
  }
  analogWrite(PWM2, 100);
  digitalWrite(motorp1, HIGH);
  digitalWrite(motorn1, HIGH);
  analogWrite(PWM1, 100);
  digitalWrite(motorp, HIGH);
  digitalWrite(motorn, HIGH);
  //("out");
  for_flag = 0;
  ble_serial.println("0x01teach0x1dF0x04");
  //delay(2000);
  readAck();
  if (ack == 'Z')
  {
    yellow_color();
  }
  ack = '\0';
  readAck();
  if (ack == '1')
  {
    green_color();
    forward();
  }
  ack = '\0';
  for_flag = 0;
}
//recharge();
void right()

{ // digitalWrite(led, LOW);
  //digitalWrite(led1, HIGH);
  //("right in teach");
  //recharge();
      analogWrite(PWM2, 100);
    digitalWrite(motorp1, HIGH);
    digitalWrite(motorn1, LOW);
    analogWrite(PWM1, 100);
    digitalWrite(motorp, LOW);
    digitalWrite(motorn, HIGH);
    delay(20);
  sensorState0 = digitalRead(sensorPin0);
  //sensorState4 = digitalRead(sensorPin4);
  while (sensorState0 != 1)
  {
    sensorState0 = digitalRead(sensorPin0);
    analogWrite(PWM2, 100);
    digitalWrite(motorp1, HIGH);
    digitalWrite(motorn1, LOW);
    analogWrite(PWM1, 100);
    digitalWrite(motorp, LOW);
    digitalWrite(motorn, HIGH);
    //   //(count);

  }



  sensorState6 = digitalRead(sensorPin6);
  sensorState7 = digitalRead(sensorPin7);
  while (sensorState6 != 1 && sensorState7 != 1)
  {
    sensorState6 = digitalRead(sensorPin6);
    sensorState7 = digitalRead(sensorPin7);

    analogWrite(PWM2, 100);

    digitalWrite(motorp1, HIGH);
    digitalWrite(motorn1, LOW);
    analogWrite(PWM1, 100);
    digitalWrite(motorp, LOW);
    digitalWrite(motorn, HIGH);

  }
  analogWrite(PWM2, 100);
  digitalWrite(motorp1, HIGH);
  digitalWrite(motorn1, HIGH);
  analogWrite(PWM1, 100);
  digitalWrite(motorp, HIGH);
  digitalWrite(motorn, HIGH);

  flag = 0;
  ble_serial.print("0x01teach0x1dF0x04");
  // ack = '\0';
  readAck();
  Serial.print("before=");
  //(ack);
  if (ack == 'Z')
  {
    yellow_color();
  }
  ack = '\0';
  readAck();
  if (ack == '1')
  {
    green_color();
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
  analogWrite(PWM2, 100);
  digitalWrite(motorp1, HIGH);
  digitalWrite(motorn1, HIGH);
  analogWrite(PWM1, 100);
  digitalWrite(motorp, HIGH);
  digitalWrite(motorn, HIGH);

}
//recharge();
void left1()
{ // recharge();
      analogWrite(PWM2, 150);
    digitalWrite(motorp1, LOW);
    digitalWrite(motorn1, HIGH);
    analogWrite(PWM1, 150);
    digitalWrite(motorp, HIGH);
    digitalWrite(motorn, LOW);
    delay(10);
  sensorState5 = digitalRead(sensorPin5);
  //sensorState1 = digitalRead(sensorPin1);
  while (sensorState5 != 1 )
  {
    sensorState5 = digitalRead(sensorPin5);
    analogWrite(PWM2, 150);
    digitalWrite(motorp1, LOW);
    digitalWrite(motorn1, HIGH);
    analogWrite(PWM1, 150);
    digitalWrite(motorp, HIGH);
    digitalWrite(motorn, LOW);
    //(count);

  }
  delay(1);
  sensorState6 = digitalRead(sensorPin6);
  sensorState7 = digitalRead(sensorPin7);
   sensorState2 = digitalRead(sensorPin2);
  sensorState3 = digitalRead(sensorPin3);
  
  
  while (sensorState6 != 1 && sensorState7 != 1  && sensorState2 != 1 && sensorState3 != 1 )
  {
    delay(1);
    sensorState6 = digitalRead(sensorPin6);
    sensorState7 = digitalRead(sensorPin7);
     sensorState2 = digitalRead(sensorPin2);
  sensorState3 = digitalRead(sensorPin3);

    analogWrite(PWM2, 150);

    digitalWrite(motorp1, LOW);
    digitalWrite(motorn1, HIGH);
    analogWrite(PWM1, 150);
    digitalWrite(motorp, HIGH);
    digitalWrite(motorn, LOW);

  }
    
  //delay(10);
//  analogWrite(PWM2, 150);
//  digitalWrite(motorp1, HIGH);
//  digitalWrite(motorn1, LOW);
//  analogWrite(PWM1, 150);
//  digitalWrite(motorp, HIGH);
//  digitalWrite(motorn, LOW);
  analogWrite(PWM2, 150);
  digitalWrite(motorp1, HIGH);
  digitalWrite(motorn1, HIGH);
  analogWrite(PWM1, 150);
  digitalWrite(motorp, HIGH);
  digitalWrite(motorn, HIGH);
  //("out");
  for_flag = 0;
  //forward();
  //  for_flag = 0;
  //data='\0';
}

void right1()

{ // digitalWrite(led, LOW);
  //digitalWrite(led1, HIGH);
  //("right1");
  //recharge();
     analogWrite(PWM2, 150);
    digitalWrite(motorp1, HIGH);
    digitalWrite(motorn1, LOW);
    analogWrite(PWM1, 150);
    digitalWrite(motorp, LOW);
    digitalWrite(motorn, HIGH);
    delay(10);
  sensorState0 = digitalRead(sensorPin0);
  //sensorState4 = digitalRead(sensorPin4);
  while (sensorState0 != 1)
  {
    sensorState0 = digitalRead(sensorPin0);
    analogWrite(PWM2, 150);
    digitalWrite(motorp1, HIGH);
    digitalWrite(motorn1, LOW);
    analogWrite(PWM1, 150);
    digitalWrite(motorp, LOW);
    digitalWrite(motorn, HIGH);
    //(count);

  }


delay(1);
  sensorState6 = digitalRead(sensorPin6);
  sensorState7 = digitalRead(sensorPin7);
   sensorState2 = digitalRead(sensorPin2);
  sensorState3 = digitalRead(sensorPin3);
  while (sensorState6 != 1 && sensorState7 != 1 && sensorState2 != 1 && sensorState3 != 1 )
  {
    delay(1);
    sensorState6 = digitalRead(sensorPin6);
    sensorState7 = digitalRead(sensorPin7);
    sensorState2 = digitalRead(sensorPin2);
  sensorState3 = digitalRead(sensorPin3);

    analogWrite(PWM2, 150);

    digitalWrite(motorp1, HIGH);
    digitalWrite(motorn1, LOW);
    analogWrite(PWM1, 150);
    digitalWrite(motorp, LOW);
    digitalWrite(motorn, HIGH);

  }
  
  
  analogWrite(PWM2, 150);
  digitalWrite(motorp1, HIGH);
  digitalWrite(motorn1, HIGH);
  analogWrite(PWM1, 150);
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
  analogWrite(PWM1, 180);
  digitalWrite(motorp, LOW);
  digitalWrite(motorn, HIGH);
  analogWrite(PWM2, 180);
  digitalWrite(motorp1, HIGH);
  digitalWrite(motorn1, LOW);
  delay(500);
  analogWrite(PWM1, 250);
  digitalWrite(motorp, HIGH);
  digitalWrite(motorn, HIGH);
  analogWrite(PWM2, 250);
  digitalWrite(motorp1, HIGH);
  digitalWrite(motorn1, HIGH);

}
void go_left()
{


  analogWrite(PWM1, 180);
  digitalWrite(motorp, HIGH);
  digitalWrite(motorn, LOW);
  analogWrite(PWM2, 180);
  digitalWrite(motorp1, LOW);
  digitalWrite(motorn1, HIGH);
  delay(500);
  analogWrite(PWM1, 250);
  digitalWrite(motorp, HIGH);
  digitalWrite(motorn, HIGH);
  analogWrite(PWM2, 250);
  digitalWrite(motorp1, HIGH);
  digitalWrite(motorn1, HIGH);

}
void go_stop()
{

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
  analogWrite(PWM1, 180);
  digitalWrite(motorp, LOW);
  digitalWrite(motorn, HIGH);
  analogWrite(PWM2, 180);
  digitalWrite(motorp1, HIGH);
  digitalWrite(motorn1, LOW);
  delay(290);
  analogWrite(PWM1, 250);
  digitalWrite(motorp, HIGH);
  digitalWrite(motorn, HIGH);
  analogWrite(PWM2, 250);
  digitalWrite(motorp1, HIGH);
  digitalWrite(motorn1, HIGH);

}
void go_left1()
{
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
void left3()
{// recharge();
     analogWrite(PWM2, 150);
    digitalWrite(motorp1, LOW);
    digitalWrite(motorn1, HIGH);
    analogWrite(PWM1, 150);
    digitalWrite(motorp, HIGH);
    digitalWrite(motorn, LOW);
    delay(10);
  sensorState5 = digitalRead(sensorPin5);
  //sensorState1 = digitalRead(sensorPin1);
  while (sensorState5 != 1 )
  {
    sensorState5 = digitalRead(sensorPin5);
    analogWrite(PWM2, 80);
    digitalWrite(motorp1, LOW);
    digitalWrite(motorn1, HIGH);
    analogWrite(PWM1, 80);
    digitalWrite(motorp, HIGH);
    digitalWrite(motorn, LOW);
    //(count);

  }
  sensorState2 = digitalRead(sensorPin2);
 // sensorState3 = digitalRead(sensorPin3);
  while (sensorState2 != 1 )
  {
    sensorState2 = digitalRead(sensorPin2);
  //  sensorState3 = digitalRead(sensorPin3);

    analogWrite(PWM2, 80);

    digitalWrite(motorp1, LOW);
    digitalWrite(motorn1, HIGH);
    analogWrite(PWM1, 80);
    digitalWrite(motorp, HIGH);
    digitalWrite(motorn, LOW);

  }
 //  delay(10);

  analogWrite(PWM2, 80);
  digitalWrite(motorp1, HIGH);
  digitalWrite(motorn1, HIGH);
  analogWrite(PWM1, 80);
  digitalWrite(motorp, HIGH);
  digitalWrite(motorn, HIGH);
  //("out");
  for_flag = 0;
  //forward();
  //  for_flag = 0;
  //data='\0';
}
void right3()
{// recharge();
      analogWrite(PWM2, 150);
    digitalWrite(motorp1, HIGH);
    digitalWrite(motorn1, LOW);
    analogWrite(PWM1, 150);
    digitalWrite(motorp, LOW);
    digitalWrite(motorn, HIGH);
 delay(10);
  sensorState0 = digitalRead(sensorPin0);
  //sensorState1 = digitalRead(sensorPin1);
  while (sensorState0 != 1 )
  {
    sensorState0 = digitalRead(sensorPin0);
    analogWrite(PWM2, 150);
    digitalWrite(motorp1, HIGH);
    digitalWrite(motorn1, LOW);
    analogWrite(PWM1, 150);
    digitalWrite(motorp, LOW);
    digitalWrite(motorn, HIGH);
    //(count);

  }
  sensorState2 = digitalRead(sensorPin2);
  sensorState3 = digitalRead(sensorPin3);
  while (sensorState2 != 1 &&sensorState3 != 1  )
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
 //  delay(10);

  analogWrite(PWM2, 150);
  digitalWrite(motorp1, HIGH);
  digitalWrite(motorn1, HIGH);
  analogWrite(PWM1, 150);
  digitalWrite(motorp, HIGH);
  digitalWrite(motorn, HIGH);
  //("out");
  for_flag = 0;
  //forward();
  //  for_flag = 0;
  //data='\0';
}

/*new algo yet to be implemented x=s1+s2+s3;y=s4+s5+s6;
  if x>y >> left
  else if x==y >>straight
  else >> right
*/

