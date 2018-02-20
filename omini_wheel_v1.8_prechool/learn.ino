///////////////////////////////////////////////////////////////LEARN MODE/////////////////////////////////////////////////////////////////////////////////////////
void learn()
{ ble_serial.print("learn");
  memset (ble_input, '\0', sizeof(ble_input));
  int start_flag, stop_flag = 1, forward_flag;
  serial_flush();
  trigger = 1;
  analogWrite(green, 150);
  analogWrite(blue, 0);
  analogWrite(red, 255);
  readAck();
  if (ack == '1')
  {

  }
  ack = '\0';
  while (learn_flag != 0)
  {
    state_();
    ble_char = 1;
    ble_read();
    button_state();

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
              working();
              for_flag = 0;
              forward();
              for_flag = 0;
              forward_flag = 0;
              ble_serial.print("0x01learn0x1dFS0x04");
              readAck();
              if (ack == 'Z')
              {
                yellow_color();
              }
              ack = '\0';
              RFID_Data = "\0";
              count1 = 0;
            }
            else
            {
              if (start_flag == 1 && stop_flag == 0)
              {
                ble_serial.println("0x01learn0x1dW0x04");
                wrong_left();
                wrong_right();
                wrong_left();

              }
              else
              {
                ble_serial.println("0x01learn0x1dI0x04");
                if (ack == 'Z')
                {
                  yellow_color();
                }
                ack = '\0';
                if (ack == '1')
                {
                  blue_color();
                }
                ack = '\0';
              }
            }

            break;
          case 'b':
            Serial.println("back");
            //  encoder(motorp, motorn, 0, 1);
            working();
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
                ble_serial.println("0x01learn0x1dI0x04");
                if (ack == 'Z')
                {
                  yellow_color();
                }
                ack = '\0';
                if (ack == '1')
                {
                  blue_color();
                }
                ack = '\0';
              }
            }
            break;
          case 'l':
            Serial.println("left");
            //   encoder(motorp1, motorn1, 0, 1);

            rf_read();

            if (RFID_Data == "LEFT" && start_flag == 1 && stop_flag == 0)
            { working();
              Serial.println("Left");
              left1();
              ble_serial.print("0x01learn0x1dLS0x04");
              readAck();
              if (ack == 'Z')
              {
                yellow_color();
              }
              ack = '\0';
              RFID_Data = "\0";
              forward_flag = 1;
              count1 = 0;
            }
            else
            {
              if (start_flag == 1 && stop_flag == 0)
              {
                red_color();
                ble_serial.println("0x01learn0x1dW0x04");
                wrong_left();
                wrong_right();
                wrong_left();

              }
              else
              {
                ble_serial.println("0x01learn0x1dI0x04");
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
              working();
              //                   head.write(90);
              //               delay(500);
              //             head.write(0);
              //                delay(500);
              right1();


              ble_serial.print("0x01learn0x1dRS0x04");
              readAck();
              if (ack == 'Z')
              {
                yellow_color();
              }
              ack = '\0';
              RFID_Data = "\0";
              forward_flag = 1;
              count1 = 0;
            }
            else
            {
              if (start_flag == 1 && stop_flag == 0)
              {
                ble_serial.println("0x01learn0x1dW0x04");
                wrong_right();
                wrong_left();
                wrong_right();

              }
              else
              {
                ble_serial.println("0x01learn0x1dI0x04");
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
              }
            }
            break;

          case 'e':
            Serial.println("exit play");
            learn_flag = 0;
            listener = 0;
            trigger = 0;
            rf_read();
            if (start_flag == 1)
            {
              Serial.println("Exit");


              ble_serial.print("0x01learn0x1dES0x04");

              readAck();
              if (ack == 'Z')
              { Serial.println("z came");
                yellow_color();
              }
              ack = '\0';

              readAck();

              if (ack == '1')
              {
                Serial.println("1 came");
                blue_color();
              }
              ack = '\0';

              RFID_Data = "";
              count1 = 0;
            }
            else
            {
              {
                ble_serial.print("0x01learn0x1dI0x04");

                readAck();
                while (ack != 'Z')
                {
                  yellow_color();
                }
                ack = '\0';

                readAck();
                while (ack != '1')
                {
                  blue_color();
                }
                ack = '\0';
              }
            }
            break;
          case 's':
            Serial.println("stop play");
            //learn_flag = 0;
            rf_read();
            if (RFID_Data == "STOP" && start_flag == 1 && stop_flag == 0)
            {
              Serial.println("stop");
              stop_();
              stop_flag = 1;
              ble_serial.print("0x01learn0x1dSS0x04");
              // learn_flag = 0;
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
              RFID_Data = "";
              count1 = 0;
            }
            else
            {
              if (start_flag == 1 && stop_flag == 0)
              {
                red_color();
                ble_serial.print("0x01learn0x1dW0x04");
                wrong_right();
                wrong_left();
                wrong_right();
              }
              else
              {
                ble_serial.print("0x01learn0x1dI0x04");

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
              }
            }
            break;
          case 'k':
            rf_read();
            if (RFID_Data == "START" && stop_flag == 1)
            {
              Serial.println("start");
              //                            head.write(90);
              //               delay(500);
              //             head.write(0);
              //                delay(500);
              working();
              forward();
              for_flag = 0;


              ble_serial.print("0x01learn0x1dKS0x04");
              readAck();
              if (ack == 'Z')
              {
                yellow_color();
              }
              ack = '\0';
              RFID_Data = "\0";
              count1 = 0;
              start_flag = 1;
              stop_flag = 0;
            }
            else if ( stop_flag == 1)
            {
              red_color();
              ble_serial.println("0x01learn0x1dW0x04");

              wrong_left();
              wrong_right();
              wrong_left();

            }
            else if (start_flag == 0)
            {

              ble_serial.println("0x01learn0x1dI0x04");
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
            }
            else if (start_flag == 0 && stop_flag == 0)
            {
             
              ble_serial.println("0x01learn0x1dW0x04");

            }

            break;
          case 'w':
            red_color();
            wrong_left();
            wrong_right();
            wrong_left();

            break;
          case '!':
            rf_read();
            Serial.print("rfid");
            Serial.println(RFID_Data);
            Serial.println("stop_flag value=");
            Serial.print(stop_flag);
            if (RFID_Data == "!" && stop_flag == 0)
            {
              Serial.println("special");
              //                            head.write(90);
              //               delay(500);
              //             head.write(0);
              //                delay(500);
              working();
              forward();
              for_flag = 0;


              ble_serial.print("0x01learn0x1dKS0x04");
              readAck();
              if (ack == 'Z')
              {
                yellow_color();
              }
              ack = '\0';
              RFID_Data = "\0";
              count1 = 0;
              start_flag = 1;
              stop_flag = 0;
            }
            else if ( stop_flag == 1)
            {
              red_color();
              ble_serial.println("0x01learn0x1dW0x04");

              wrong_left();
              wrong_right();
              wrong_left();

            }
            else if (start_flag == 0)
            {

              ble_serial.println("0x01learn0x1dI0x04");
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
            }
            else if (start_flag == 0 && stop_flag == 0)
            {
              red_color();
              ble_serial.println("0x01learn0x1dW0x04");
              wrong_left();
              wrong_right();
              wrong_left();
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
  flag = 0;  //Serial.println(flag);

  serial_flush();
  ble_char = 0;
  delay(10);
  ble_serial.println("j");
}

