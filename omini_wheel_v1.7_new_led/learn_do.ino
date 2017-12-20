////////////////////////////////////////////////////////////////////////learndo-MODE/////////////////////////////////////////////////////////////////////////////////////////////////////
void learndo_mode()
{
  Serial.println("enter into the learn_do");
  memset (ble_input, '\0', sizeof(ble_input));//SET THE ENTIRE ARRAY TO NULL
  int start_flag, stop_flag = 1, forward_flag;
  serial_flush();
  while (learn_do_flag != 0)
  {

    state_();
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
            rf_read();
            if (RFID_Data == "FORWARD" && start_flag == 1 && stop_flag == 0 || forward_flag == 1)
            {
              Serial.println("forward");
             
              for_flag = 0;
              forward();
              delay(1000);
              for_flag = 0;
              forward_flag = 0;
              //ble_serial.println("0x01do0x1dforward successful0x04");

              RFID_Data = "\0";
              count1 = 0;
            }
            else
            {
              if (start_flag == 1 && stop_flag == 0)
              {
                ble_serial.println("0x01learndo0x1dW0x04");
              }
              else if (start_flag == 0)
              {
                ble_serial.println("0x01learndo0x1dI0x04");
              }
            }
            break;
          case 'b':
            Serial.println("back");
            rf_read();
            if (RFID_Data == "1700453BD6" && start_flag == 1)
            {
              Serial.println("back");
              //ble_serial.println("0x01learndo0x1dback successful0x04");
              //encoder(motorp, motorn, 0, 1, 8);
              RFID_Data = "\0";
              count1 = 0;
            }
            else
            {
              if (start_flag == 1)
              {
                ble_serial.println("0x01learndo0x1dI0x04");
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
              left1();
              delay(1000);
              // ble_serial.println("0x01learndo0x1dleft successful0x04");
              RFID_Data = "\0";
              forward_flag = 1;
              count1 = 0;
            }
            else
            {
              if (start_flag == 1 && stop_flag == 0)
              {
                ble_serial.println("0x01learndo0x1dW0x04");
              }
              else if (start_flag == 0)
              {
                ble_serial.println("0x01learndo0x1dI0x04");
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
              right1();
              delay(1000); //ble_serial.println("0x01learndo0x1dright successful0x04");
              RFID_Data = "\0";
              forward_flag = 1;
              count1 = 0;
            }
            else
            {
              if (start_flag == 1 && stop_flag == 0)
              {
                ble_serial.println("0x01learndo0x1dW0x04");
              }
              else if (start_flag == 0)
              {
                ble_serial.println("0x01learndo0x1dI0x04");
              }
            }
            break;

          case 'e':
            Serial.println("exit play");
            learn_do_flag = 0;
            rf_read();
            if (start_flag == 1)
            {
              Serial.println("Exit");
              ble_serial.println("0x01learndo0x1dE0x04");
              learn_do_flag = 0;
              RFID_Data = "";
              count1 = 0;
            }
            else
            {
              {
                ble_serial.println("0x01learndo0x1dI0x04");
              }
            }
            break;
          case 's':
            Serial.println("stop play");
            //learndo_flag = 0;
            rf_read();
            if (RFID_Data == "STOP" && start_flag == 1 && stop_flag == 0)
            {
              Serial.println("stop");
              stop_();
              stop_flag = 1;
              ble_serial.print("0x01learndo0x1dSS0x04");
              // learndo_flag = 0;
              RFID_Data = "";
              count1 = 0;
            }
            else
            {
              if (start_flag == 1 && stop_flag == 0)
              {
                ble_serial.print("0x01learndo0x1dW0x04");
              }
              else if (start_flag == 0)
              {
                ble_serial.println("0x01learndo0x1dI0x04");
              }
            }
            break;
          case 'k':
            rf_read();
            if (RFID_Data == "START" && stop_flag == 1)
            {
              Serial.println("start");
              for_flag = 0;
              forward();
              delay(1000);
              for_flag = 0;
              ble_serial.println("0x01learndo0x1dS0x04");
              RFID_Data = "\0";
              count1 = 0;
              start_flag = 1;
              stop_flag = 0;
            }
            else if (start_flag == 1 && stop_flag == 0)
            {
              ble_serial.println("0x01learnlearndo0x1dW0x04");
            }
            else if (start_flag == 0)
            {
              ble_serial.println("0x01learndo0x1dI0x04");
            }

            break;
          default:
            Serial.println("invalid");
            Serial.println(path[i]);
            break;
        }
      }
      // Serial.println("learndone");
      flag = 0;
      count = 0;
      i = 0;
      ble_input[i] = '\0';
    }
  }
  learn_do_flag = 1;
  Serial.println(flag);
  serial_flush();
  ble_char = 0;
}

