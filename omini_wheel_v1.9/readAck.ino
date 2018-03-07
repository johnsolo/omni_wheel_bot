//////////////////////////////////////////////////////////////////READING ACK FROM APP////////////////////////////////////////////////////////////////////////////////
void readAck()
{                                                                                                                                                                       
  while (1)
  {
    if ( ble_serial.available()) 
    {
      ack = ble_serial.read();
      Serial.print("APP=");
      Serial.println(ack);
      break;
    }
  }
}

