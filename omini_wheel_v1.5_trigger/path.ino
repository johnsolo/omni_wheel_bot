/////////////////////////////////////////////////////////////////////////////FOR PLAY MODE ONLY/////////////////////////////////////////////////////////////////////////////
void direction_()
{
  if (flag == 1)                              //flag set to enable for ble read
  {
    for (i = 0; i < count; i++)
    {
      switch (path[i])
      {
        case 'd':
          Serial.println("dance");
          {           
            working();
            go_dance();
            ble_serial.println("0x01play0x1dda0x04");
            ack = '\0';
          }
          for_flag = 0;
          break;
        case 'f':
        case 'k':
          {
            Serial.println("CONT:forward");
              working();
              go_forward();
              ble_serial.print("0x01play0x1dFS0x04");
              for_flag = 0;
              ack = '\0';         
          }
          break;
        case 'W':
          {
            Serial.println("wrong command");
            working();
            go_left1();
            delay(30);
            go_right1();
            delay(30);
            go_right1();
            delay(30);
            go_left1();
            delay(30);
            ble_serial.print("0x01play0x1dW0x04");
            for_flag = 0;
            ack = '\0';
          }
          break;

        case 'l':
          Serial.println("left");
          {           
            working();
            go_left();
            ble_serial.print("0x01play0x1dLS0x04");
            ack = '\0';
          }
          for_flag = 0;
          break;

        case 'r':
          {
            working();
            go_right();
            ble_serial.print("0x01play0x1dRS0x04");
          }
          for_flag = 0;
          break;

        case 'e':
          Serial.println("EXIT play");
          ble_serial.print("0x01play0x1dES0x04");
          play_flag = 0;
          break;
        case 'b':
          Serial.print("back");
          {
            working();
            go_back();
            ble_serial.println("0x01play0x1dBS0x04");
          }
          break;
        default:
          Serial.println("invalid");
            flag = 0;
          break;
      }
    }
    flag = 0;
    count = 0;
    i = 0;
    ble_input[i] = '\0';

  }
}
