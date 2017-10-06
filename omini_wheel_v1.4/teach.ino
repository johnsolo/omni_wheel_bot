void teach()
{int start_flag=0;
  serial_flush();
  while (teach_flag != 0)
  {    //Serial.println("again");

    rf_read();
    //delay(500);
     if (RFID_Data == "59006EDA41")
    {
      Serial.println("start");
      ble_serial.println("0x01teach0x1dstart successful0x04");
      RFID_Data = "\0";
      count1 = 0;
      start_flag=1;
    }  
    else if (RFID_Data == "1700439404" && start_flag==1)
    {
      Serial.println("Left");
      ble_serial.println("0x01teach0x1dleft successful0x04");
      RFID_Data = "\0";
      count1 = 0;
    }
    else if (RFID_Data == "17004568DA" && start_flag==1)
    {
      Serial.println("forward");
     // encoder(motorp, motorn, 1, 0, 8,);
     ble_serial.println("0x01teach0x1dforward successful0x04");

      RFID_Data = "\0";
      count1 = 0;
    }
    else if (RFID_Data == "1700453BD6" && start_flag==1)
    {
      Serial.println("back");
      ble_serial.println("0x01teach0x1dback successful0x04");
      //encoder(motorp, motorn, 0, 1, 8);
      RFID_Data = "\0";
      count1 = 0;
    }
    else if (RFID_Data == "1700456EFC" && start_flag==1)
    {
      Serial.println("right");
      ble_serial.println("0x01teach0x1dright successful0x04");
      RFID_Data = "\0";
      count1 = 0;
    }
    else if (RFID_Data == "17004454A2" && start_flag==1)
    {
      Serial.println("stop");
      ble_serial.println("0x01teach0x1dstop successful0x04");    
      teach_flag = 0;
      RFID_Data = "";
      count1 = 0;
    }
    else if (start_flag==0)
    {
      count1 = 0;
      RFID_Data = "";
    }
  }
  teach_flag = 1;
  RFID_Data = "";
}

