////////////////////////////////////////////////////////////////PLAY-MODE//////////////////////////////////////////////////////////////////////////////////////////
void play()
{working();
  ble_serial.println("play");
 readAck();
 trigger_flag==1;
 if (ack == '1')
 {
  
  
      
}
    ack='\0';
  //delay(10);
  // ble_serial.println("0x01play0x1dstart listening0x04");

  memset (ble_input, '\0', sizeof(ble_input));
  serial_flush();
  //i=0;
  while (play_flag != 0 )
  {
    state_();
    ble_char = 1;
   //delay(1000);
   if(listener==0)
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

