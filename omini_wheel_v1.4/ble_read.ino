//////////////////////////////////////////////////////////READING DATA FROM BLE///////////////////////////////////////////////////////////////////////////
/*
   FORMAT FOR SENDING AND RECEIVING :: 0x01 MODE 0x1d INSTRUCTION 0x04// NO SPACES INBETWEEN
   0X01 :: START OF TEXT
   0x1d :: GROUP SEPERATOR
   0X04 :: END OF TEXT
   BLE_CHAR IS USED TO READ MODE AND INSTRUCTIONS SEPERATE FOR MODE SELECTION AND FOR GIVING COMMANDS
*/
void ble_read()
{ int j = 0;

  if (flag == 0)
  {
    //while(count<4)
    while (ble_serial.available())

    {

      digitalWrite(led, LOW);

      digitalWrite(led1, HIGH);
      //Serial.println("available");
      ble_input[i]  = (char)ble_serial.read();
     // Serial.println(ble_input[i]);
      i++;
      delay(7);
    }
    delay(500);
    digitalWrite(led, HIGH);
    digitalWrite(led1, LOW);


    if (ble_char == 0)
    {
      i = 0;
      // Serial.println("in");

      if (ble_input[i] == (char)0x01)
      {
        i++;
        while (ble_input[i] != (char)0x04 )
        {
          if (ble_input[i] != (char)0x1d && ble_input[i] != (char)0x04)
          {
            mode_input += (char)ble_input[i];
            Serial.print("control=");
            Serial.println(mode_input);
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
      { // Serial.println("in");

        i++;
        while (ble_input[i] != (char)0x1d)
        {
          mode_input += (char)ble_input[i];
          //      Serial.print("control=");
          //      Serial.println(mode_input);
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
    //flag = 1;
  }

}









