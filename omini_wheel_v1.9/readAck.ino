//////////////////////////////////////////////////////////////////READING ACK FROM APP////////////////////////////////////////////////////////////////////////////////
void readAck()
{ while (1)
  {
    if ( ble_serial.available()) {
      ack = ble_serial.read();
      Serial.print("ack=");
      Serial.println(ack);
      break;
    }
  }
}

