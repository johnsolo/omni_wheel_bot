void play()
{
  Serial.println("enter into the play");
  memset (ble_input, '\0', sizeof(ble_input));
  serial_flush();
  while (play_flag != 0)
  {
    ble_char = 1;
    ble_read();
    direction_();
  }
  play_flag = 1;
  Serial.println(flag);
  serial_flush();
  ble_char = 0;
}



