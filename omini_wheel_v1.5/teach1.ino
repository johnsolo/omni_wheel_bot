/////////////////////////////////////////////////////////////////////////////////////////////TEACH MODE/////////////////////////////////////////////////////////////////////////////// 
void teach1()
{ teach_flag=1;
  int start_flag = 0,stop_flag=1;
  memset (ble_input, '\0', sizeof(ble_input));
  serial_flush();
  while (teach_flag != 0)
  { 
    rf_read();
    ble_char=1;
    flag=0;
    path[0]='\0';
    ble_read();
    state_(); 
       switch(path[0])
    {
      case 'e' : Serial.println("exit........");
                 //ble_serial.println("0x01teach0x1dE0x04");
                  teach_flag=0;                
                  break;
      default: break;
    }
      if (RFID_Data == "START")
    {
      Serial.println("start");
      ble_serial.print("0x01teach10x1dK0x04");
      //delay(2000);
      //readAck();
      //if(ack=='1')
      {
      forward();
      delay(1000);
      }
      for_flag = 0;
      RFID_Data = "";
      count1 = 0;
      stop_flag=0;
      start_flag = 1;
    }
    else if (RFID_Data == "LEFT" && start_flag == 1)
    {
      Serial.println("Left");
      ble_serial.print("0x01teach10x1dL0x04");
  //    delay(2000);
  //        readAck();
    //  if(ack=='1')
      {
      left2();
       delay(1000);
      }
      for_flag = 0;

      RFID_Data = " ";
      count1 = 0;
    }
    else if (RFID_Data == "FORWARD" && start_flag == 1 )
    {
      Serial.println("forward");
      // encoder(motorp, motorn, 1, 0, 8,);
      ble_serial.print("0x01teach10x1dF0x04");
      //delay(2000);
   //         readAck();
     // if(ack=='1')
      {
      forward();
       delay(1000);
      }
      for_flag = 0;
      RFID_Data = " ";
      count1 = 0;
    }
    else if (RFID_Data == "STOP" && start_flag == 1)
    {
      Serial.println("stop");
      //ble_serial.println("0x01teach0x1dstop successful0x04");
      ble_serial.print("0x01teach10x1dD0x04");
      //encoder(motorp, motorn, 0, 1, 8);
      //delay(2000);
         //   readAck();
      //if(ack=='1')
      {
      stop_();
      stop_flag=1;
      }
      delay(50);
       ble_serial.print("0x01teach10x1dA0x04");
      RFID_Data = "\0";
      count1 = 0;
    }
    else if (RFID_Data == "RIGHT" && start_flag == 1 )
    {
      Serial.println("right");
      ble_serial.print("0x01teach10x1dR0x04");
      //delay(2000);
  //       readAck();
    //  if(ack=='1')
      {
      right2();
      delay(1000);
      }
      for_flag = 0;
      RFID_Data = "\0";
      count1 = 0;
    }
    else if (RFID_Data == "17004454A2" && start_flag == 1)
    {
      Serial.println("exit");
      ble_serial.print("0x01teach10x1dE0x04");
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
  Serial.println("out of teach");
  ble_char=0;
}
///this mode is only for for learn and teach mode  

