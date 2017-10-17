void learn()
{ Serial.println("enter into the learn");
  memset (ble_input, '\0', sizeof(ble_input));
  int start_flag;
  serial_flush();
  while (learn_flag != 0)
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
            if (RFID_Data == "17004568DA" && start_flag == 1)
            {
              Serial.println("forward");
              // encoder(motorp, motorn, 1, 0, 8,2);
              ble_serial.println("0x01learn0x1dforward successful0x04");

              RFID_Data = "\0";
              count1 = 0;
            }
            else
            {
              if (start_flag == 1)
              {
                ble_serial.println("0x01learn0x1dsay start0x04");
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
              ble_serial.println("0x01learn0x1dback successful0x04");
              //encoder(motorp, motorn, 0, 1, 8);
              RFID_Data = "\0";
              count1 = 0;
            }
            else
            {
              if (start_flag == 1)
              {
                ble_serial.println("0x01learn0x1dsay start0x04");
              }
            }
            break;
          case 'l':
            Serial.println("left");
            //   encoder(motorp1, motorn1, 0, 1);
            rf_read();
            if (RFID_Data == "1700439404" && start_flag == 1)
            {
              Serial.println("Left");
              ble_serial.println("0x01learn0x1dleft successful0x04");
              RFID_Data = "\0";
              count1 = 0;
            }
            else
            {
              if (start_flag == 1)
              {
                ble_serial.println("0x01learn0x1dsay start0x04");
              }
            }
            break;
          case 'r':
            Serial.println("right");
            //  encoder(motorp1, motorn1, 0, 1);
            rf_read();
            if (RFID_Data == "1700456EFC" && start_flag == 1)
            {
              Serial.println("right");
              ble_serial.println("0x01learn0x1dright successful0x04");
              RFID_Data = "\0";
              count1 = 0;
            }
            else
            {
              if (start_flag == 1)
              {
                ble_serial.println("0x01learn0x1dsay start0x04");
              }
            }
            break;

          case 's':
            Serial.println("stop play");
            learn_flag = 0;
            rf_read();
            if (RFID_Data == "17004454A2" && start_flag == 1)
            {
              Serial.println("stop");
              ble_serial.println("0x01learn0x1dstop successful0x04");
              learn_flag = 0;
              RFID_Data = "";
              count1 = 0;
            }
            else
            {
              if (start_flag == 1)
              {
                ble_serial.println("0x01learn0x1dsay start0x04");
              }
            }
            break;
          case 'k':
            rf_read();
            if (RFID_Data == "59006EDA41")
            {
              Serial.println("start");
              ble_serial.println("0x01learn0x1dstart successful0x04");
              RFID_Data = "\0";
              count1 = 0;
              start_flag = 1;
            }
            else
            {
              if (start_flag == 1)
              {
                ble_serial.println("0x01learn0x1dsay start0x04");
              }
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
  learn_flag = 1;
  Serial.println(flag);
  serial_flush();
  ble_char = 0;


}

