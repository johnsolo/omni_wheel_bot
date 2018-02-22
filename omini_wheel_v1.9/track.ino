////////////////////////////////////////////////////////////////////////DO-MODE/////////////////////////////////////////////////////////////////////////////////////////////////////
void track_mode()
{ int j;
  Serial.println("enter into the track");
  ble_serial.print("track");
  trigger = 1;
  memset (ble_input, '\0', sizeof(ble_input));//SET THE ENTIRE ARRAY TO NULL
  int start_flag, stop_flag = 1, forward_flag;
  serial_flush();

  while (track_flag != 0)
  {
    state_();
    
    ble_char = 1;
   // Serial.println("reading");
    ble_read();
  //  button_state();

    if (flag == 1)
    {
      for (i = 0; i < count; i++)
      { Serial.println(count);
        switch (path[i])
        {
            Serial.print(path[i]);
          case 'f':
            rf_read();
            if (RFID_Data == "FORWARD" && start_flag == 1 && stop_flag == 0 || forward_flag == 1)
            {
              Serial.println("forward");
              // encoder(motorp, motorn, 1, 0, 8,2);
              for_flag = 0;
                green_color();
              forward();
              delay(1000);
              for_flag = 0;
              forward_flag = 0;
              ble_serial.print("0x01do0x1dFS0x04");
               readAck();
                    
              RFID_Data = "\0";
              count1 = 0;
            }
            else
            {
              if (start_flag == 1 && stop_flag == 0)
              {int j=0,k;
                ble_serial.print("0x01do0x1dW0x04");
   readAck();
                    if (ack == 'Z')
      {
        yellow_color();
        
       
      }
      ack='\0';
              readAck();
                    if (ack == '1')
      {
              blue_color();
        
       
      }
      ack='\0';
//                k=sizeof(ble_input);
//                Serial.print("john");
      //          Serial.println(k);
//                for(j=0;j<=count;j++)
//                {
//                  path[j]='\0' ;       
//                }
      
                Serial.println("out");
                        trigger=1;
            listener = 0;
     //       button_state();
              }
              else if (start_flag == 0)
              {
                ble_serial.print("0x01do0x1dI0x04");
                 readAck();
                    if (ack == 'Z')
      {
        yellow_color();
        
       
      }
      ack='\0';
              readAck();
                    if (ack == '1')
      {
              blue_color();
        
       
      }
      ack='\0';
              //  blue_color();
                listener = 0;
                
              }
            }
            break;
          case 'b':
            Serial.println("back");
            rf_read();
            if (RFID_Data == "1700453BD6" && start_flag == 1)
            {
              Serial.println("back");
              //ble_serial.println("0x01do0x1dback successful0x04");
              //encoder(motorp, motorn, 0, 1, 8);
              RFID_Data = "\0";
              count1 = 0;
            }
            else
            {
              if (start_flag == 1)
              {
                ble_serial.println("0x01do0x1dI0x04");
              }
            }
            break;
          case 'l':
            Serial.println("left");
            //   encoder(motorp1, motorn1, 0, 1);
            rf_read();
            if (RFID_Data == "LEFT" && start_flag == 1 && stop_flag == 0)
            {
              Serial.println("Left");
                green_color();
              left1();
              delay(1000);
               ble_serial.print("0x01do0x1dLS0x04");
               
              RFID_Data = "\0";
              forward_flag = 1;
              count1 = 0;
            }
            else
            {
              if (start_flag == 1 && stop_flag == 0)
              {
                ble_serial.print("0x01do0x1dW0x04");
                
                           while(path[j]!='\0')
      {
        j++;
      }
                        trigger=1;
          listener = 0;
           readAck();
                    if (ack == 'Z')
      {
        yellow_color();
        
       
      }
      ack='\0';
              readAck();
                    if (ack == '1')
      {
              blue_color();
        
       
      }
      ack='\0';
    //button_state();
              }
              else if (start_flag == 0)
              {
                ble_serial.print("0x01do0x1dI0x04");
              }
            }
            break;
          case 'r':
            Serial.println("right");
            //  encoder(motorp1, motorn1, 0, 1);
            rf_read();

            if (RFID_Data == "RIGHT" && start_flag == 1 && stop_flag == 0)
            {
              Serial.println("right");
                green_color();
              right1();
              delay(1000); ble_serial.print("0x01do0x1RS0x04");
              
                    if (ack == '1')
      {
              blue_color();
        
       
      }
      ack='\0';
              RFID_Data = "\0";
              forward_flag = 1;
              count1 = 0;
            }
            else
            {
              if (start_flag == 1 && stop_flag == 0)
              {
                ble_serial.print("0x01do0x1dW0x04");
                      while(path[j]!='\0')
      {
        j++;
      }
                 
                        trigger=1;
          listener = 0;
    //button_state();
              }
              else if (start_flag == 0)
              {
                ble_serial.print("0x01do0x1dI0x04");
                 readAck();
                    if (ack == 'Z')
      {
        yellow_color();
        
       
      }
      ack='\0';
              readAck();
                    if (ack == '1')
      {
              blue_color();
        
       
      }
      ack='\0';
              }
            }
            break;

          case 'e':
            Serial.println("exit play");
            do_flag = 0;
            rf_read();
            if (start_flag == 1)
            {
              Serial.println("Exit");
              ble_serial.print("0x01do0x1dE0x04");
               
              track_flag = 0;
              RFID_Data = "";
              count1 = 0;
              button_flag = 0;
          trigger=1;
          inc = 0;
          listener = 0;
            }
            else
            {
              {
                ble_serial.print("0x01do0x1dI0x04");
              }
            }
            break;
          case 's':
            Serial.println("stop do");
            //do_flag = 0;
            rf_read();
            if (RFID_Data == "STOP" && start_flag == 1 && stop_flag == 0)
            {
              Serial.println("stop");
                green_color();
              stop_();
              stop_flag = 1;
              
              ble_serial.print("0x01do0x1dSS0x04");
              readAck();
                    if (ack == 'Z')
      {
        yellow_color();
        
       
      }
      ack='\0';
              readAck();
                    if (ack == '1')
      {
              blue_color();
      }
      ack='\0';
              
              // do_flag = 0;
              RFID_Data = "";
              count1 = 0;
            }
            else
            {
              if (start_flag == 1 && stop_flag == 0)
              {
                ble_serial.print("0x01do0x1dW0x04");
                      while(path[j]!='\0')
      {
        j++;
      }
                               
                        trigger=1;
                        listener = 0;
      //                  button_state();
              }
              else if (start_flag == 0)
              {
                ble_serial.print("0x01do0x1dI0x04");
              }
            }
            break;
          case 'k':
            rf_read();
            if (RFID_Data == "START" && stop_flag == 1)
            {
              Serial.println("start");
              for_flag = 0;
                green_color();
              forward();
              delay(1000);
              for_flag = 0;
              ble_serial.print("0x01do0x1dKS0x04");
               
              RFID_Data = "\0";
              count1 = 0;
              start_flag = 1;
              stop_flag = 0;
            }
            else if (start_flag == 1 && stop_flag == 0)
            {
              ble_serial.print("0x01do0x1dW0x04");
             while(path[j]!='\0')
      {
        j++;
      }                      
                      trigger=1;
          listener = 0;
    //button_state();
            }
            else if (start_flag == 0)
            {
              ble_serial.println("0x01do0x1dI0x04");
            }

            break;
          default:
            Serial.println("invalid");
            Serial.println(path[i]);
            break;
        }
      }
      // Serial.println("done");
      flag = 0;
      count = 0;
      i = 0;
      ble_input[i] = '\0';
    }
  }
  track_flag = 1;
  Serial.println(flag);
  serial_flush();
  ble_char = 0;
}

