//////////////////////////////////////////////////////////////////READING ACK FROM APP////////////////////////////////////////////////////////////////////////////////
void readAck()
{
  while (1)
  { 
    if(special_tile==1) 
    { 
    trigger=1;
      button_state();
    }
      
    if ( ble_serial.available())
    {     
      ack = ble_serial.read();
      Serial.print("APP=");
      Serial.println(ack);
      break;
    }
  }
}

