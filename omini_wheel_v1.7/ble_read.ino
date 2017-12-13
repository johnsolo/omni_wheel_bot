//+++++///////////////////////////////////////////////////////////////////////////////READING DATA FROM BLE///////////////////////////////////////////////////////////////////////////
/*
   FORMAT FOR SENDING AND RECEIVING :: 0x01 MODE 0x1d INSTRUCTION 0x04// NO SPACES IN-BETWEEN
   0X01 :: START OF TEXT
   0x1d :: GROUP SEPERATOR
   0X04 :: END OF TEXT
   BLE_CHAR IS USED TO READ MODE AND INSTRUCTIONS SEPERATE FOR MODE SELECTION AND FOR GIVING COMMANDS
*/
void ble_read()
{ int j = 0;
  if (flag == 0)
  {
    while (ble_serial.available())
    {
      ble_input[i]  = (char)ble_serial.read();
      Serial.println(ble_input[i]);
      if (ble_input[i] == 'Z')                        //ACK FROM TTS
      {    
        working();
      }
      if (ble_input[i] == 'O')                        //INDICATES START OF LISTENER
      {
        digitalWrite(blue, LOW);
        Serial.println("red");
        digitalWrite(green, HIGH);
        digitalWrite(red, LOW);
        listener = 1;
      }
      if (listener == 1)                          
      {
        if (ble_input[i] == 'P')                      //INDICATES END OF LISTENER
        {
          if (trigger == 0 && inc < 3)
          {
            Serial.print("inc=");
            Serial.println(inc);
            ble_serial.print("listenMode");           //ONLY FOR RECEIVEING MODES AUTOMATICALLY
            inc++;
          }
          else if (trigger == 0 && inc > 3)
          {
            Serial.println("second time");
            digitalWrite(blue, HIGH);
            Serial.println("red");
            digitalWrite(green, LOW);
            digitalWrite(red, LOW);
          }
          Serial.println("rece loop");        
          counter = 0;
          listener = 0;
          if (trigger == 1)
          {
            digitalWrite(blue, HIGH);
            Serial.println("red");
            digitalWrite(green, LOW);
            digitalWrite(red, LOW);
          }
        }
        Serial.println("out loop");
      }
      i++;
      delay(7);                                         
    }
 //////////////////////////////////////////////////////////////////////////////////////Algo for receving packets from APP/////////////////////////////////////////////////////////////////////////////////////
    if (ble_char == 0  )
    {
      i = 0;
      if (ble_input[i] == (char)0x01)
      {
        i++;
        while (ble_input[i] != (char)0x04 )
        {
          if (ble_input[i] != (char)0x1d && ble_input[i] != (char)0x04)
          {
            mode_input += (char)ble_input[i];        
            i++;
          }
        }
      }
      flag = 1;
    }
    else if (ble_char == 1)
    {
      i = 0;
      if (ble_input[i] == (char)0x01)
      { 
        i++;
        while (ble_input[i] != (char)0x1d)
        {
          mode_input += (char)ble_input[i];
          i++;
        }
        i++;
        while (ble_input[i] != (char)0x04)
        {
          path[j] = (char)ble_input[i];
          Serial.print("APP:");
          Serial.println(path[j]);
          i++;
          j++;
          count++;
        }
        flag = 1;
      }
    }
  }

}









