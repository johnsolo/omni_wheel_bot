void ble_read()
{
  if (flag == 0)
  {
    //while(count<4)
    while (ble_serial.available())
    { //Serial.println("available");
      ble_input[i]  = (char)ble_serial.read();
      if (ble_char != 1)
      {
        mode_input   +=  ble_input[i];
        Serial.println(mode_input);
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
      }
    }
  }
}
