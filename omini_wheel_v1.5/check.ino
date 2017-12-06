void check()
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
   if (sensorState0 != 0 && sensorState1 != 0 && sensorState2 != 1 && sensorState3 != 1 && sensorState4 != 0 && sensorState5 != 0)
   {
     for_flag = 0;
     forward();
   }
  
}

