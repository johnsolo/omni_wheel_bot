void button_state()
{
 long start = millis();
 
  delay(100);
 long total1 =  cs_4_2.capacitiveSensor(15);
//  Serial.print(millis() - start);        // check on performance in milliseconds
// Serial.print("\n");                    // tab character for debug windown spacing
//  Serial.print(total1);                  // print sensor output 1

  // arbitrary delay to limit data to serial port
  long setpoint = 200;
  
  if (total1  >= setpoint && trigger_flag==0)
  {
    digitalWrite(11, LOW);
    button_flag = 1;  
    ble_serial.print("listen");
  trigger_flag=1;
    Serial.println("trigger");
   // Serial.println(count3);    
    }
  else if (total1 < setpoint)
  {
 //Serial.println("trigger0");   
trigger_flag=0;
  }
}
  

