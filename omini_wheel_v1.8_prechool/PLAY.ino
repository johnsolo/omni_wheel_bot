////////////////////////////////////////////////////////////////PLAY-MODE//////////////////////////////////////////////////////////////////////////////////////////
void play()
{ memset (ble_input, '\0', sizeof(ble_input));
  serial_flush();
  trigger = 1;
  //ble_read();
 //working();
   analogWrite(green, 150);
 analogWrite(blue, 0);
  analogWrite(red, 255);
  ble_serial.println("play");
 // delay(3000);
  readAck();
  if (ack == '1')
  {
  }
  ack = '\0';
  //i=0;
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
  Serial.println("EXIT PLAY");
  serial_flush();
  ble_char = 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

