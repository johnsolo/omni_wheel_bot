void error_action()
{
  rf_read();
  if (RFID_Data != "START")
  {


    Serial.print("ins_count=");
    Serial.println(ins_count);
    left1();
    left1();
    for_flag = 0;
    forward();
    for_flag = 1;
  }
  else
  {
    ins_count = 0;
  }
  for (int i = 0; i < ins_count; i++)
  {
    rf_read();
    if (RFID_Data == "LEFT")
    {for_flag = 0;
      if(i!=(ins_count-1))
      {
      right1();
      forward();
      }
      else
      {
        right1();
        right1();
      }
      for_flag = 1;
      // delay(1000);
    }
    else if (RFID_Data == "RIGHT")
    {for_flag = 0;
      if(i!=(ins_count-1))
      {
      left1();
      forward();
      }
      else
      {
        right1();
        right1();
      }
      for_flag = 1;
      //delay(1000);
    }
    else  if (RFID_Data == "START")
    {      if(i!=(ins_count-1))
      {
      right1();
      right1();
      }
      else
      {
      right1();
      right1();
      }
    
    }
    else  if (RFID_Data == "FORWARD")
    {
      for_flag = 0;
      if(i!=(ins_count-1))
      {
      forward();
      }
      else
      {
      right1();
      right1();
      }
      for_flag = 1;
    }
  }
  ins_count = 0;
}


