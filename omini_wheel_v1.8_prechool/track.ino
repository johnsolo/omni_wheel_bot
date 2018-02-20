////////////////////////////////////////////////////////////////////////track-MODE/////////////////////////////////////////////////////////////////////////////////////////////////////
void track_mode()
{ int j, ins_count, i;
  serial_flush();
  Serial.println("enter into the track ");
  ble_serial.print("track");
  readAck();
  if (ack == 'Z')
  {
    yellow_color();
  }
  ack = '\0'; 
  static int starttile = 1, startwrong = 0;
  
  // readAck();

  trigger = 1;
  memset (ble_input, '\0', sizeof(ble_input));//SET THE ENTIRE ARRAY TO NULL
  int start_flag = 0, stop_flag = 1, forward_flag;
  while (track_flag != 0)
  {
    state_();
    ble_char = 1;
    // Serial.println("reading");
    rf_read();
    //    Serial.print("start flag=");
    //    Serial.print(startwrong);
    //
    //    Serial.println(start_flag);
    if (  RFID_Data != "START" && startwrong == 0 && start_flag == 0) {
      Serial.println("wrong cmd");
      if (startwrong == 0)
      {
        delay(1200);
        ble_serial.print("0x01track0x1dI0x04");
        startwrong = 1;

        //starttile=1;
      }

    }
    else if (RFID_Data == "START" && start_flag == 0 && starttile == 1)
    {
      delay(1200);
      ble_serial.print("0x01track0x1dST0x04");
      starttile = 0;
      //  startwrong=0;
    }
    button_state();
    ble_read();

    //   ble_read();
    if (flag == 1)
    {
      for (i = 0; i < count; i++)
      { //Serial.println(count);
        Serial.print("command in thelist to be executed :");
        Serial.println(path[i]);
        switch (path[i])
        {
          //Serial.println(i);

          case 'f':
            Serial.println("forward");
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
              ble_serial.print("0x01track0x1dFS0x04");
              //readAck();

              RFID_Data = "\0";
              count1 = 0;
              //;
              //ins_count++;
            }
            else
            {

              { int j = 0, k;
                ble_serial.print("0x01track0x1dW0x04");
                               red_color();
              wrong_left();
              wrong_right();
              wrong_left();
                // RFID_Data = "\0";
                // i=0;

                //ins_count=0;
                readAck();
                if (ack == 'Z')
                {
                  yellow_color();

count=0;
                }
                ack = '\0';
                readAck();
                if (ack == '1')
                {
                  blue_color();


                }

                ack = '\0';
                while (path[j] != '\0')
                {
                  path[j] = '\0';
                  j++;
                }
                j = 0;
                Serial.println("out");
                trigger = 1;
                listener = 0;
              }

              break;
            case 'b':
              Serial.println("back");
              rf_read();
              if (RFID_Data == "1700453BD6" && start_flag == 1)
              {
                Serial.println("back");
                //ble_serial.println("0x01track0x1dback successful0x04");
                //encoder(motorp, motorn, 0, 1, 8);
                RFID_Data = "\0";
                count1 = 0;
                //ins_count++;
              }
              else
              {
                if (start_flag == 1)
                {
                  ble_serial.println("0x01track0x1dI0x04");
                }
              }
              break;
            case 'l':
              Serial.println("left");
              //;
              //   encoder(motorp1, motorn1, 0, 1);
              rf_read();
              if (RFID_Data == "LEFT" && start_flag == 1 && stop_flag == 0)
              {
                Serial.println("Left");
                green_color();
                left1();
                delay(1000);
                ble_serial.print("0x01track0x1dLS0x04");

                RFID_Data = "\0";
                forward_flag = 1;
                count1 = 0;
                //ins_count++;
              }
              else
              {
                if (start_flag == 1 && stop_flag == 0)
                {
                  ble_serial.print("0x01track0x1dW0x04");
                  //RFID_Data = "\0";
                                 red_color();
              wrong_left();
              wrong_right();
              wrong_left();
                  ins_count = 0;
                  // RFID_Data = "\0";


                  trigger = 1;
                  listener = 0;
                  readAck();
                  if (ack == 'Z')
                  {
                    yellow_color();

count=0;
                  }
                  ack = '\0';
                  readAck();
                  if (ack == '1')
                  {
                    blue_color();


                  }
                  ack = '\0';
                  while (path[j] != '\0')
                  {

                    Serial.println(path[j]);
                    path[j] = '\0';
                    j++;
                  }
                  j = 0;

                }

              }
              break;
            case 'r':
              //  //;
              Serial.println("right");
              //  encoder(motorp1, motorn1, 0, 1);
              rf_read();

              if (RFID_Data == "RIGHT" && start_flag == 1 && stop_flag == 0)
              {
                Serial.println("right");
                green_color();
                right1();
                delay(1000); ble_serial.print("0x01track0x1dRS0x04");

                RFID_Data = "\0";
                forward_flag = 1;
                count1 = 0;
                ins_count++;
              }
              else
              {

                { ins_count = 0;
                  Serial.println("wrong cmd0");
                  ble_serial.print("0x01track0x1dW0x04");
                                 red_color();
              wrong_left();
              wrong_right();
              wrong_left();
                  //RFID_Data = "\0";
                  if (ack == 'Z')
                  {
                    yellow_color();
                  count=0;

                  }
                  ack = '\0';
                  readAck();
                  if (ack == '1')
                  {
                    blue_color();


                  }
                  ack = '\0';
                  while (path[j] != '\0')
                  {
                    path[j] = '\0';
                    j++;
                  }
                  j = 0;
                  trigger = 1;
                  listener = 0;

                }

              }
              break;

            case 'e':
              Serial.println("exit play");
              track_flag = 0;
              rf_read();
              if (start_flag == 1)
              {
                Serial.println("Exit");
                ble_serial.print("0x01track0x1dE0x04");

                track_flag = 0;
                RFID_Data = "";
                count1 = 0;
                button_flag = 0;
                trigger = 1;
                inc = 0;
                listener = 0;
              }

              break;
            case 's':
              Serial.println("stop track");
              //track_flag = 0;
              rf_read();
              if (RFID_Data == "STOP" && start_flag == 1 && stop_flag == 0)
              {
                Serial.println("stop");
                green_color();
                stop_();
                stop_flag = 1;
                startwrong = 0;
                starttile = 1;
                start_flag = 0;
                ble_serial.print("0x01track0x1dSS0x04");
                readAck();
                if (ack == 'Z')
                {
                  yellow_color();


                }
                ack = '\0';
                readAck();
                if (ack == '1')
                {
                  trigger = 1;
                  listener = 0;
                  blue_color();
                }
                ack = '\0';

                // track_flag = 0;
                RFID_Data = "";
                count1 = 0;
                ins_count++;
              }
              else
              {

                { ins_count = 0;
                  ble_serial.print("0x01track0x1dW0x04");
                                 red_color();
              wrong_left();
              wrong_right();
              wrong_left();
                  if (ack == 'Z')
                  {
                    yellow_color();
                    count=0;

                  }
                  ack = '\0';
                  readAck();
                  if (ack == '1')
                  {
                    blue_color();


                  }
                  ack = '\0';
                  while (path[j] != '\0')
                  {
                    path[j] = '\0';
                    j++;
                  }
                  j = 0;

                  trigger = 1;
                  listener = 0;
                  //                  button_state();
                }

              }
              break;
            case 'k':
              //;
              rf_read();
              if (RFID_Data == "START" && stop_flag == 1)
              {
                Serial.println("start");
                for_flag = 0;
                green_color();
                forward();
                delay(1000);
                for_flag = 0;
                ble_serial.print("0x01track0x1dKS0x04");

                RFID_Data = "\0";
                count1 = 0;
                ins_count++;
                start_flag = 1;
                stop_flag = 0;
              }
              else
              { ins_count = 0;
                ble_serial.print("0x01track0x1dW0x04");
                // RFID_Data = "\0";
                               red_color();
              wrong_left();
              wrong_right();
              wrong_left();
                 if (ack == 'Z')
                  {
                    yellow_color();
                    count=0;


                  }
                  ack = '\0';
                  readAck();
                  if (ack == '1')
                  {
                    blue_color();


                  }
 ack = '\0';
                while (path[j] != '\0')
                {
                  path[j] = '\0';
                  j++;
                }
                j = 0;
                
                trigger = 1;
                listener = 0;
                //button_state();
              }

              break;
            default:
              Serial.println("invalid");
              Serial.println(path[i]);
              trigger = 1;
              listener = 0;
              break;
            }


        }
      }

      // Serial.println("trackne");
      flag = 0;
      count = 0;
      i = 0;
      ble_input[i] = '\0';
      trigger = 1;
      listener = 0;
    }
  }

  track_flag = 1;
  
  serial_flush();
  ble_char = 0;
  start_flag = 0;
  starttile = 1;
  startwrong = 0;

}

