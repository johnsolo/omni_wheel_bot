void button_state()
{button_pin = digitalRead(6);
//Serial.println(button_pin);
  if(button_pin==0)
  {
 ble_serial.print("listen");
 Serial.println("0x01state0x1dlisten0x04");
 button_flag=1;
  }
}


