void do_mode()
{
  Serial.println("enter into the do");
  memset (ble_input, '\0', sizeof(ble_input));
  int start_flag,stop_flag=1,forward_flag;
  serial_flush();
   while (do_flag != 0)
  {
    ble_char = 1;
    ble_read();
    if (flag == 1)
    {
      for (i = 0; i < count; i++)
      { Serial.println(count);
        switch (path[i])
        {
            Serial.print(path[i]);
          case 'f':
            //     rfid_read();
            //     if (input == input)

            // Serial.println("forward");

            //     encoder(motorp, motorn, 1, 0);
            rf_read();
            if (RFID_Data == "FORWARD" && start_flag == 1 && stop_flag==0 || forward_flag==1)
            {
              Serial.println("forward");
              // encoder(motorp, motorn, 1, 0, 8,2);
              for_flag = 0;
              forward();
              for_flag = 0;
              forward_flag=0;
              ble_serial.println("0x01do0x1dforward successful0x04");

              RFID_Data = "\0";
              count1 = 0;
            }
            else
            {
              if (start_flag == 1 && stop_flag==0)
              {
                ble_serial.println("0x01do0x1dwrong path0x04");
              }
              else if(start_flag == 0)
              {
                ble_serial.println("0x01do0x1dsay start0x04");
              }
            }

            break;
          case 'b':
            Serial.println("back");
            //  encoder(motorp, motorn, 0, 1);
            rf_read();
            if (RFID_Data == "1700453BD6" && start_flag == 1)
            {
              Serial.println("back");
              ble_serial.println("0x01do0x1dback successful0x04");
              //encoder(motorp, motorn, 0, 1, 8);
              RFID_Data = "\0";
              count1 = 0;
            }
            else
            {
              if (start_flag == 1)
              {
                ble_serial.println("0x01do0x1dsay start0x04");
              }
            }
            break;
          case 'l':
            Serial.println("left");
            //   encoder(motorp1, motorn1, 0, 1);
            rf_read();
            if (RFID_Data == "LEFT" && start_flag == 1 && stop_flag==0)
            {
              Serial.println("Left");
              left1();
              ble_serial.println("0x01do0x1dleft successful0x04");
              RFID_Data = "\0";
              forward_flag=1;
              count1 = 0;
            }
            else
            {
                  if (start_flag == 1 && stop_flag==0)
              {
                ble_serial.println("0x01do0x1dwrong path0x04");
              }
              else if(start_flag == 0)
              {
                ble_serial.println("0x01do0x1dsay start0x04");
              }
            }
            break;
          case 'r':
            Serial.println("right");
            //  encoder(motorp1, motorn1, 0, 1);
            rf_read();
            if (RFID_Data == "RIGHT" && start_flag == 1&& stop_flag==0)
            {
              Serial.println("right");
              right1();
              ble_serial.println("0x01do0x1dright successful0x04");
              RFID_Data = "\0";
              forward_flag=1;
              count1 = 0;
            }
            else
            {
        if (start_flag == 1 && stop_flag==0)
              {
                ble_serial.println("0x01do0x1dwrong path0x04");
              }
              else if(start_flag == 0)
              {
                ble_serial.println("0x01do0x1dsay start0x04");
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
              ble_serial.println("0x01do0x1dexit successful0x04");
              do_flag = 0;
              RFID_Data = "";
              count1 = 0;
            }
            else
            {
              {
                ble_serial.println("0x01do0x1dsay start0x04");
              }
            }
            break;
          case 's':
            Serial.println("stop play");
            //do_flag = 0;
            rf_read();
            if (RFID_Data == "STOP" && start_flag == 1 && stop_flag==0)
            {
              Serial.println("stop");
              stop_();
              stop_flag=1;
              ble_serial.println("0x01do0x1dstop successful0x04");
              // do_flag = 0;
              RFID_Data = "";
              count1 = 0;
            }
            else
            {
       if (start_flag == 1 && stop_flag==0)
              {
                ble_serial.println("0x01do0x1dwrong pathx04");
              }
              else if(start_flag == 0)
              {
                ble_serial.println("0x01do0x1dsay start0x04");
              }
            }
            break;
          case 'k':
            rf_read();
            if (RFID_Data == "START" && stop_flag==1)
            {
              Serial.println("start");
              forward();
              for_flag = 0;
              ble_serial.println("0x01do0x1dstart successful0x04");
              RFID_Data = "\0";
              count1 = 0;
              start_flag = 1;
              stop_flag=0;
            }
            else if (start_flag == 1 && stop_flag==0)
              {
                ble_serial.println("0x01do0x1dwrong pathx04");
              }
              else if(start_flag == 0)
              {
                ble_serial.println("0x01do0x1dsay start0x04");
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
  do_flag = 1;
  Serial.println(flag);
  serial_flush();
  ble_char = 0;


}

