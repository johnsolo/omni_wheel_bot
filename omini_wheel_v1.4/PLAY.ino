///////////////////////////////////////////////////////////////////////PLAY-MODE////////////////////////////////////////////////////////////////////////////////////
void play()
{
  Serial.println("enter into the play");
  //delay(10);
  // ble_serial.println("0x01play0x1dstart listening0x04");

  memset (ble_input, '\0', sizeof(ble_input));
  serial_flush();
  //i=0;
  while (play_flag != 0 )
  {
    state_();
    ble_char = 1;
    ble_read();
    direction_();
  }
  play_flag = 1;
  Serial.println("EXIT PLAY");
  serial_flush();
  ble_char = 0;
}



