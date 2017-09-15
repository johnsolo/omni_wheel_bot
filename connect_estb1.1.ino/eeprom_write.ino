void ee_write()
 {
  i++;
 while (ble_input[i] != (char)0x04)
      {
//       password+=(char)ble_input[i];
//       Serial.print("password="); 
//       Serial.println(password);
        value=(int)ble_input[i];
        if(a<255)
        {
       // Serial.println("in");
        EEPROM.write(a,value);
        a=a+1;
       i++;
      }
 }
 }
