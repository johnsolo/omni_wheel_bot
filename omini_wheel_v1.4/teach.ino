///////////////////////////////////////////////////////////////////TEACH MODE/////////////////////////////////////////////////////////////////////////////// 
void teach()
{ int start_flag = 0;
  serial_flush();
  while (teach_flag != 0)
  { //Serial.println("again");
    state_();
    rf_read();
    // Serial.print( "RFID_Data:::");
    // Serial.println( RFID_Data);
    //delay(500);
    if (RFID_Data == "START")
    {
      Serial.println("start");
      ble_serial.println("0x01teach0x1dK0x04");
      //delay(2000);
      readAck();
      if(ack=='1')
      {
      forward();
      }
      for_flag = 0;

      RFID_Data = "";
      count1 = 0;
      start_flag = 1;
    }
    else if (RFID_Data == "LEFT" && start_flag == 1)
    {
      Serial.println("Left");
      ble_serial.println("0x01teach0x1dL0x04");
  //    delay(2000);
          readAck();
      if(ack=='1')
      {
      left();
      }
      for_flag = 0;

      RFID_Data = " ";
      count1 = 0;
    }
    else if (RFID_Data == "FORWARD" && start_flag == 1)
    {
      Serial.println("forward");
      // encoder(motorp, motorn, 1, 0, 8,);
      ble_serial.println("0x01teach0x1dF0x04");
      //delay(2000);
            readAck();
      if(ack=='1')
      {
      forward();
      }
      for_flag = 0;


      RFID_Data = " ";
      count1 = 0;
    }
    else if (RFID_Data == "STOP" && start_flag == 1)
    {
      Serial.println("stop");
      //ble_serial.println("0x01teach0x1dstop successful0x04");
      ble_serial.println("0x01teach0x1dS0x04");
      //encoder(motorp, motorn, 0, 1, 8);
      //delay(2000);
            readAck();
      if(ack=='1')
      {
      stop_();
      }
      RFID_Data = "\0";
      count1 = 0;
    }
    else if (RFID_Data == "RIGHT" && start_flag == 1)
    {
      Serial.println("right");
      ble_serial.println("0x01teach0x1dR0x04");
      delay(2000);
      right();
      for_flag = 0;


      RFID_Data = "\0";
      count1 = 0;
    }
    else if (RFID_Data == "17004454A2" && start_flag == 1)
    {
      Serial.println("exit");
      ble_serial.println("0x01teach0x1dE0x04");
      teach_flag = 0;
      RFID_Data = "";
      count1 = 0;
    }
    else if (start_flag == 0)
    {
      count1 = 0;
      RFID_Data = "";
    }
  }
  teach_flag = 1;
  RFID_Data = "";
}

