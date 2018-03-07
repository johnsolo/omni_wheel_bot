////////////////////////////////////////////////////////////////PLAY-MODE//////////////////////////////////////////////////////////////////////////////////////////
void play()
{
  memset (ble_input, '\0', sizeof(ble_input));
  serial_flush();
  trigger = 1;
  analogWrite(green, 150);
  analogWrite(blue, 0);
  analogWrite(red, 255);
  ble_serial.println("play");
  while (play_flag != 0 )
  {
    state_();
    ble_char = 1;
    if (listener == 0)
    {
      button_state();
    }
    ble_read();
    direction_();
  }
  play_flag = 1;

  flag = 0;
  Serial.println("EXIT PLAY");
  ble_char = 0;

  delay(10);
  ble_serial.println("j");

}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

