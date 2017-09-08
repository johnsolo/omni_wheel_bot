void ble_read()
{
  if (flag == 0)
  {
    //while(count<4)
    while (ble_serial.available())
    { //Serial.println("available");
      ble_input[i]  = (char)ble_serial.read();
      Serial.println(ble_input[i]);
      if (ble_char != 1)
      {
        mode_input   +=  ble_input[i];
        Serial.println(mode_input);
      }
      if(set_==1)
      { value=(int)ble_input[i];
        if(a<255)
        {
        Serial.println("in");
        EEPROM.write(a,value);
        a=a+1;
        }
        
      }
      delay(7);
      if (ble_input[i] != '$')
      {
        i++;
        count++;
        if (ble_char != 1)
        {
          count = 0;
        }

      }
      else
      {
        flag = 1;
        Serial.println("out");
      }
    }
  }
}
