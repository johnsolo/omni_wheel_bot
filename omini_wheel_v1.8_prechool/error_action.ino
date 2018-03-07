void error_action()
{// 1
  int count2=0;
  bool error_flag=0;
  if(ins_count!=0)
  {

  int count;
   Serial.println( path[ins_count - 1] );
  if (path[ins_count - 1] == 'l' && ins_count == 1)
  {
    Serial.println("algo for left first activated");
    Serial.println("right");
    RFID_Data = "LEFT";
    right1();
    ins_count = 0;
    
    rl_flag=1;
  }
  if (path[ins_count - 1] == 'l' && ins_count > 0 && error_flag==0)
  {
    Serial.println("algo for left last activated");
    Serial.println("left and forward");
    left1();
    for_flag = 0;
     
      
    forward();
    for_flag = 1;
    ins_count--;
    RFID_Data ="\0";
    error_flag=1;
    Serial.print("ins_count");
    Serial.println(ins_count);
      rl_flag=0;
  }
 
  if (path[ins_count - 1] == 'r' && ins_count == 1)
  {
    Serial.println("algo for right first activated");
    Serial.println("left");
    RFID_Data = "RIGHT";
    left1();
    ins_count = 0;
    rl_flag=1;
    // forward_flag=1;
     
  }
  else if (path[ins_count - 1] == 'r' && ins_count > 0  && error_flag==0 )
  {
    Serial.println("algo for right last activated");
    Serial.println(" right and forward");
    right1();
    for_flag = 0;
    forward();
    for_flag = 1;
    // forward_flag=1;
     //ins_count=ins_count-2;
     ins_count--;
     RFID_Data ="\0";
    Serial.println(ins_count);
    error_flag=1;
    rl_flag=0;
  }
    

  else if ((ins_count-1 >0 && error_flag==0 || path[ins_count - 1] == 'f'&& path[ins_count - 1] != 'r' && path[ins_count - 1] != 'l' && error_flag==0 ))
  {
    Serial.println("algo for 180 degree");
    left1();
    left1();
    for_flag = 0;
    forward();
    for_flag = 1;
    Serial.println(ins_count);
   ins_count--;
   error_flag=1;
    RFID_Data ="\0";
      rl_flag=0;
  }
    else if ((ins_count-1 >0 && error_flag==0 || path[ins_count - 1] == 'k'&& path[ins_count - 1] != 'r' && path[ins_count - 1] != 'l' && error_flag==0 ))
  {
    Serial.println("algo for 180 degree");
    RFID_Data ="\0";
    left1();
    left1();
    for_flag = 0;
    forward();
    for_flag = 1;
    ins_count--;
     RFID_Data ="\0";
     error_flag=1;
       rl_flag=0;
    //Serial.println(ins_count);
  }
//

    for(int i=0;i<=ins_count;i++)
  {

  
    Serial.print(ins_count);
    if((path[i]=='r' || path[i]=='l') &&(path[i+1]=='f'))
    {
      Serial.print("value stored are:");
     
      count2++;
       Serial.println(count2);
      Serial.println(path[i]);
      Serial.println(path[i+1]);
      
    ///  ins_count--;
      
    }
  }

  
  ins_count=ins_count-count2;
  Serial.print("value after count");
  Serial.println(ins_count);
  
  for (int i = (ins_count); i > 0; i--)
  {// delay(500);
     RFID_Data ="\0";
    rf_read();
    Serial.print("command to be executed");
    Serial.print(i);
    Serial.print("\t");
    Serial.println(RFID_Data);
   // delay(100);
      
      if (RFID_Data == "FORWARD" )
      {
        Serial.println("forward");
        for_flag = 0;
        forward();
        for_flag = 1;
        RFID_Data ="\0";
      }
      else if (RFID_Data == "LEFT" )
      {
        Serial.println("right and forward");
       // recharge();
        right1();
        for_flag = 0;
        forward();
        for_flag = 1;
        RFID_Data ="\0";

         //forward_flag=1;

      }
      else if (RFID_Data == "RIGHT" )
      {
        Serial.println("left and forward");
        //recharge();
        left1();
        for_flag = 0;
        forward();
        for_flag = 1;
        // forward_flag=1;
        RFID_Data ="\0";
      }
  }
    if((i==0 || rl_flag!=1) && (path [0]!='r' && path[0]!='l' && rl_flag!=1))
  {
    Serial.println("i am in");
  right1();
  right1();
  RFID_Data ="\0";
  
  delay(500);
  }
  else if(path[0]=='r' && rl_flag!=1)
  {
    right1();
    RFID_Data ="\0";
  }
  else if(path[0]=='l' && rl_flag!=1)
  {
    left1();
    RFID_Data ="\0";
  }
  
 rf_read();
 if(RFID_Data == "START")
 {
    ble_serial.print("0x01code0x1dST0x04");
    readAck();
    if(ack=='z')
    {
      yellow_color();
    }
    ack='\0';
        if(ack=='1')
    {
      yellow_color();
    }
     ack='\0';
    RFID_Data ="\0";
 }
  

  ins_count = 0;
  count2=0;
   if(RFID_Data != "START")
   {
ble_serial.print("0x01code0x1dlis0x04");

   }
   
 
}
}

//  for( i=ins_count;i>0;i--)
//  {Serial.println(path[i]);
//  switch(path[i])
//   { 
//   case 'f': Serial.println("forward executed"); for_flag=0;forward();for_flag=1;break;
//   case 'r':  Serial.println("right executed");left1();for_flag=0;forward();for_flag=1;break;
//   case 'l':  Serial.println("left executed");right1();for_flag=0;forward();for_flag=1;break;
//   default:   break;
//  }
//
//  }
// 
//  Serial.print("ivalue:=");
//  Serial.println(i);
//  if(i==0|| rl_flag!=1)
//  {
//  right1();
//  right1();
//  }
//   ins_count=0;
//   
//
//}
//}

 

