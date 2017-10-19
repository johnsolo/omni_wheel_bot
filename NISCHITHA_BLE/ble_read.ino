void ble_read()
{ int j = 0;
  if (flag == 0)
  {
    //while(count<4)
    while (ble_serial.available())

    {
      //Serial.println("available");
      ble_input[i]  = (char)ble_serial.read();
      //  Serial.println(ble_input[i]);
      i++;
      delay(7);
    }
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









