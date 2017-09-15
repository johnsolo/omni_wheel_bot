void ble_read()
{
  if (flag == 0)
  {
    //while(count<4)
    while (ble_serial.available())

    {
      //Serial.println("available");
      ble_input[i]  = (char)ble_serial.read();
      Serial.println(ble_input[i]);
      i++;
      delay(7);
    }
    i = 0;
    if (ble_input[i] == (char)0x01)
    { Serial.println("in");
      i++;
      while (ble_input[i] != (char)0x1d)
      {
        mode_input += (char)ble_input[i];
        Serial.print("control=");
        Serial.println(mode_input);
        i++;
      }
      if (mode_input == "sp" && login_flag == 1)
      {
        ee_write();
        flag = 1;
      }

      else
      {
        i++;
        while (ble_input[i] != (char)0x04)
        {
          user_input += (char)ble_input[i];
          Serial.print("user=");
          Serial.println(user_input);
          i++;
        }

        flag = 1;


      }
    }
  }
}

