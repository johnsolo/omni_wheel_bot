void error_action()
{// 1
  if(ins_count!=0)
  {
  int rl_flag=0;
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
  if (path[ins_count - 1] == 'l' && ins_count > 0)
  {
    Serial.println("algo for left last activated");
    Serial.println("left and forward");
    left1();
    for_flag = 0;
     
      
    forward();
    for_flag = 1;
    ins_count--;
    Serial.print("ins_count");
    Serial.println(ins_count);
  }
  if (path[ins_count - 1] == 'r' && ins_count == 1)
  {
    Serial.println("algo for right first activated");
    Serial.println("left");
    RFID_Data = "RIGHT";
    left1();
    ins_count = 0;
    rl_flag=1;
     forward_flag=1;
  }
  else if (path[ins_count - 1] == 'r' && ins_count > 0  )
  {
    Serial.println("algo for right last activated");
    Serial.println(" right and forward");
    right1();
    for_flag = 0;
    forward();
    for_flag = 1;
     forward_flag=1;
     //ins_count--;
    Serial.println(ins_count);
  }

  else if ((ins_count-1 >0 || path[ins_count - 1] == 'f'&& path[ins_count - 1] != 'r' && path[ins_count - 1] != 'l' ))
  {
    Serial.println("algo for 180 degree");
    left1();
    left1();
    for_flag = 0;
    forward();
    for_flag = 1;
    //Serial.println(ins_count);
    ins_count--;
    RFID_Data ="\0";
  }
    else if ((ins_count-1 >0 || path[ins_count - 1] == 'k'&& path[ins_count - 1] != 'r' && path[ins_count - 1] != 'l' ))
  {
    Serial.println("algo for 180 degree");
    RFID_Data ="\0";
    left1();
    left1();
    for_flag = 0;
    forward();
    for_flag = 1;
    //ins_count--;
    //Serial.println(ins_count);
  }
//

    for(int i=0;i<=ins_count;i++)
  {

  Serial.print("value stored are:");
    Serial.print(path[i]);
    Serial.println("");
  }
  
  
  for (int i = 0; i <ins_count; i++)
  {
    Serial.print("command to be executed");
    Serial.println(ins_count);
    
    rf_read();
      if (RFID_Data == "FORWARD" )
      {
        Serial.println("forward");
        for_flag = 0;
        forward();
        for_flag = 1;
      }
      else if (RFID_Data == "LEFT" )
      {
        Serial.println("right and forward");
        right1();
        for_flag = 0;
        forward();
        for_flag = 1;
        

         //forward_flag=1;

      }
      else if (RFID_Data == "RIGHT" )
      {
        Serial.println("left and forward");
        left1();
        for_flag = 0;
        forward();
        for_flag = 1;
        // forward_flag=1;
      }
  }
    if(i==0|| rl_flag!=1)
  {
  right1();
  right1();
 rf_read();
 if(RFID_Data == "START")
 {
    ble_serial.print("0x01code0x1dST0x04");
 }
  }

  ins_count = 0;
 
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

 

