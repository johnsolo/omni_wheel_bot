/////////////////////////////////////////////////////////////////////////////FOR PLAY MODE ONLY/////////////////////////////////////////////////////////////////////////////
void direction_()
{ //Serial.println("direction");
  if (flag == 1)                              //flag set to enable for ble read
  {
    for (i = 0; i < count; i++)
    { //Serial.println(count);
      //  Serial.print("play_in");
      // Serial.print(path[2]);
      switch (path[i])
      {
        case 'd':
                  Serial.println("dance");
          // encoder(motorp1, motorn1, 0, 1, teeth,encoder1);
          //ble_serial.println("0x01play0x1dL0x04");
          //  readAck();
          //if (ack == '1')
            {
          //delay(2000);
          go_dance();
          ack='\0';
            }
          for_flag = 0;

          break;
           case 'w':
                  Serial.println("dance");
          // encoder(motorp1, motorn1, 0, 1, teeth,encoder1);
          //ble_serial.println("0x01play0x1dL0x04");
          //  readAck();
          //if (ack == '1')
            {
          //delay(2000);
          go_left1();
          delay(100);
          go_right1();
          
          ack='\0';
            }
          for_flag = 0;

          break;
        case 'f':
        case 'k':
          {
            Serial.println("CONT:forward");
          //  ble_serial.println("0x01play0x1dF0x04");
         //   readAck();
         //   Serial.print( "path of zero    ");
            Serial.println(ack);
         //   if (ack == '1')
            {
           //   Serial.println("its here ");
              go_forward();
              //delay(100);
              //go_forward();
              for_flag = 0;
              ack='\0';
            }
          }
          break;
        case 's':
          Serial.println("stop");
          // encoder(motorp, motorn, 0, 1, teeth,encoder2);
          //ble_serial.println("0x01play0x1dS0x04");
          //readAck();
            //  if (ack == '1')
            {
          go_stop();
             for_flag = 0;
              ack='\0';
            }
          break;
        case 'l':
          Serial.println("left");
          // encoder(motorp1, motorn1, 0, 1, teeth,encoder1);
          //ble_serial.println("0x01play0x1dL0x04");
          //  readAck();
          //if (ack == '1')
            {
          //delay(2000);
          go_left();
          ack='\0';
            }
          for_flag = 0;

          break;

        case 'r':
          //Serial.println("right");
          //ble_serial.println("0x01play0x1dR0x04");
          // encoder(motorp1, motorn1, 1, 0,teeth, encoder1);
          //delay(2000);
            //readAck();
            //Serial.println(ack);
                //    if (ack == '1')
            {
          go_right();
            }
          for_flag = 0;
          //  ble_serial.println("0x01play0x1dright successful0x04");
          break;

        case 'e':
          Serial.println("EXIT play");
          ble_serial.println("0x01play0x1dE0x04");
          // encoder(motorp1, motorn1, 1, 1, teeth,encoder2);
          // encoder(motorp, motorn, 1, 1, teeth,encoder1);
          play_flag = 0;
          break;
        case 'b':
                  Serial.println("back");
          //ble_serial.println("0x01play0x1dB0x04");
          // encoder(motorp1, motorn1, 1, 0,teeth, encoder1);
          //delay(2000);
            //readAck();
            
            Serial.println(ack);
              //      if (ack == '1')
            {
         go_back();
            }
        
        default:
          Serial.println("invalid");
          // Serial.println(path[i]);
          break;
      }
      //ble_serial.println("0x01play0x1dstart listening0x04");
    }
    //Serial.println("done");
    flag = 0;
    count = 0;
    i = 0;
    ble_input[i] = '\0';
  
  }
}  
