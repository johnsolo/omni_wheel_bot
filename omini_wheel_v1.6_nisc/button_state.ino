void button_state()
{button_pin = digitalRead(8);
Serial.println(button_pin);
  if(button_pin==0)
  {
 ble_serial.println("listen");
 Serial.println("listen");
 button_flag=0;
  }
}

