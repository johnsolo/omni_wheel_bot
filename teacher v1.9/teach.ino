/////////////////////////////////////////////////////////////////////////////////TEACH MODE///////////////////////////////////////////////////////////////////////////////
void teach()
{
recharge();
  static int f = 0;
  // working();
  int start_flag = 0, stop_flag = 1;
  memset (ble_input, '\0', sizeof(ble_input));
  serial_flush();

  // Serial.print("teach");
  ble_serial.print("teach");
  readAck();
  if (ack == 'Z')
  {
    yellow_color();
  }
  ack = '\0';
  readAck();
  if (ack == '1')
  {

  }
  ack = '\0';
  while (teach_flag != 0)
  {
    //Serial.println("again");
    rf_read();
    ble_char = 1;
    flag = 0;
    path[0] = '\0';
    if (f == 1)
    { blue_trig = 1;
      //Serial.println("button enabled");
      trigger = 1;
      listener = 0;
      button_state();
      // listener = 1;
      trigger = 0;
      // listener=1;
      // ble_read();
      ble_read();
      // blue_color();
    }

    state_();

    switch (path[0])
    {
      case 'e' :
        //working();
        Serial.println("exit........");
        ble_serial.print("0x01teach0x1dES0x04");
        readAck();
        if (ack == 'Z')
        {
          yellow_color();
        }
        ack = '\0';
        readAck();
        if (ack == '1')
        {
          blue_color();
        }
        ack = '\0';
        teach_flag = 0;
        trigger = 0;
        break;
      default:
        break;
    }
    //Serial.println(path[0]);
    // Serial.print( "RFID_Data:::");
    // Serial.println( RFID_Data);
    //delay(500);

    if (RFID_Data == "START" && stop_flag == 1 )
    {
      //   working();
      Serial.println("start");
      ble_serial.println("0x01teach0x1dK0x04");
      //delay(2000);
      readAck();
      if (ack == 'Z')
      {
        yellow_color();
      }
      ack = '\0';
      readAck();
      if (ack == '1')
      {
        green_color();
        for_flag = 0;
        forward();
      }
      ack = '\0';
      for_flag = 0;

      RFID_Data = "";
      count1 = 0;
      stop_flag = 0;
      start_flag = 1;
    }
    else if (RFID_Data == "LEFT" && start_flag == 1)
    {
      Serial.println("Left");
      ble_serial.println("0x01teach0x1dL0x04");
     
      readAck();
      if (ack == 'Z')
      {
        yellow_color();
      }
      ack = '\0';
      readAck();
      if (ack == '1')
      { green_color();
        left();
        // forward();
      }

      ack = '\0';
      for_flag = 0;
      RFID_Data = "\0";
      count1 = 0;
    }
    else if (RFID_Data == "!" && start_flag == 1 )
    {
      //working();
      Serial.println("right");
      ble_serial.println("0x01teach0x1d!0x04");
      //delay(2000);
      readAck();
      if (ack == 'Z')
      { Serial.println("special");
        yellow_color();
      }
      ack = '\0';
      readAck();
      if (ack == '1')
      { Serial.println("special");

        // forward();
      }
      ack = '\0';
        ble_serial.println("0x01teach0x1dF0x04");
      readAck();
      if (ack == 'Z')
      { Serial.println("forward");
        yellow_color();
      }
      ack = '\0';
      readAck();
      if (ack == '1')

      { green_color();
        Serial.println("forward");
        for_flag = 0;
        forward();
        for_flag = 1;
      }
      ack = '\0';
      for_flag = 0;
      RFID_Data = "\0";
      // start_flag =0;
      stop_flag = 1;
      count1 = 0;
    }
     else if (RFID_Data == "$" && start_flag == 1 )
    {
      //working();
      Serial.println("right");
      ble_serial.println("0x01teach0x1d$0x04");
      //delay(2000);
      readAck();
      if (ack == 'Z')
      { Serial.println("special");
        yellow_color();
      }
      ack = '\0';
      readAck();
      if (ack == '1')
      { Serial.println("special");

        // forward();
      }
      ack = '\0';
       ble_serial.println("0x01teach0x1dF0x04");
      readAck();
      if (ack == 'Z')
      { Serial.println("forward");
        yellow_color();
      }
      ack = '\0';
      readAck();
      if (ack == '1')

      { green_color();
        Serial.println("forward");
        for_flag = 0;
        forward();
        for_flag = 1;
      }
      ack = '\0';
      for_flag = 0;
      RFID_Data = "\0";
      // start_flag =0;
      stop_flag = 1;
      count1 = 0;
    }
    else if (RFID_Data == "%" && start_flag == 1 )
    {
      //working();
      Serial.println("right");
      ble_serial.println("0x01teach0x1d%0x04");
      //delay(2000);
      readAck();
      if (ack == 'Z')
      { Serial.println("special");
        yellow_color();
      }
      ack = '\0';
      readAck();
      if (ack == '1')
      { Serial.println("special");

        // forward();
      }
      ack = '\0';
       ble_serial.println("0x01teach0x1dF0x04");
      readAck();
      if (ack == 'Z')
      { Serial.println("forward");
        yellow_color();
      }
      ack = '\0';
      readAck();
      if (ack == '1')

      { green_color();
        Serial.println("forward");
        for_flag = 0;
        forward();
        for_flag = 1;
      }
      ack = '\0';
      for_flag = 0;
      RFID_Data = "\0";
      // start_flag =0;
      stop_flag = 1;
      count1 = 0;
    }
    else if (RFID_Data == "FORWARD" && start_flag == 1 )
    {
      // working();
      Serial.println("forward");
      // encoder(motorp, motorn, 1, 0, 8,);
      ble_serial.println("0x01teach0x1dF0x04");
      //delay(2000);
      readAck();
      if (ack == 'Z')
      {
        yellow_color();
      }
      ack = '\0';
      readAck();
      if (ack == '1')
      {
        green_color();
        forward();
      }
      ack = '\0';
      for_flag = 0;
      RFID_Data = "\0";
      count1 = 0;
    }
    else if (RFID_Data == "STOP" && start_flag == 1)
    {
      
      //working();
      
      Serial.println("stop");
      //ble_serial.println("0x01teach0x1dstop successful0x04");
      ble_serial.print("0x01teach0x1dFI0x04");
      //encoder(motorp, motorn, 0, 1, 8);
      //delay(2000);
      f = 1;
      readAck();
      //readAck();
      if (ack == 'Z')
      {
        yellow_color();
      }
      ack = '\0';
      readAck();
      if (ack == '1')
      {
        green_color();
        stop_();
        for_flag=0;
        forward();
        for_flag=1;
        
        stop_flag = 1;
      }
      ack = '\0';
     blue_color();
  //    ble_serial.println("0x01teach0x1da0x04");

  
      start_flag = 0;
      ack = '\0';
      RFID_Data = "\0";
      count1 = 0;
    }
    else if (RFID_Data == "RIGHT" && start_flag == 1 )
    {
      //working();
      Serial.println("right");
      ble_serial.println("0x01teach0x1dR0x04");
      //delay(2000);
      readAck();
      if (ack == 'Z')
      { Serial.println("right");
        yellow_color();
      }
      ack = '\0';
      readAck();
      if (ack == '1')
      { Serial.println("right");
        green_color();
        right();
        // forward();
      }
      ack = '\0';
      for_flag = 0;
      RFID_Data = "\0";
      // start_flag =0;
      stop_flag = 1;
      count1 = 0;
    }
    else if (RFID_Data == "17004454A2" && start_flag == 1)
    {
      //working();
      Serial.println("exit");
      ble_serial.println("0x01teach0x1dE0x04");
      readAck();
      if (ack == 'Z')
      {
        yellow_color();
        //  Serial.println("ooo play");
      }
      ack = '\0';
      readAck();
      if (ack == '1')
      {
        blue_color();
        listener = 0;
        Serial.println("ooo play");
      }
      ack = '\0';
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
  // Serial.println("out of teach");
  delay(10);
  ble_serial.println("j");
  ble_char = 0;
}

