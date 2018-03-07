/////////////////////////////////////////////////////FOR PLAY MODE ONLY/////////////////////////////////////////////////////////////////////////////
void direction_()
{
  //Serial.println("direction");
  if (flag == 1)                              //flag set to enable for ble read
  {
    for (i = 0; i < count; i++)
    {
      Serial.print("play_in=");
      Serial.print(path[2]);

      switch (path[i])
      {
        case 'd':
          //Serial.println("dance");
          // encoder(motorp1, motorn1, 0, 1, teeth,encoder1);
          //    ble_serial.println("0x01play0x1dL0x04");
          //  readAck();
          //if (ack == '1')
          {
            //delay(2000);
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
            //  ble_serial.println("0x01play0x1dF0x04");
            //   readAck();
            //   Serial.print( "path of zero    ");
            //Serial.println(ack);
            //   if (ack == '1')
            {
              //   Serial.println("its here ");
              working();
              go_forward();
              //delay(100);
              //go_forward();

              ble_serial.print("0x01play0x1dFS0x04");
              for_flag = 0;
              ack = '\0';
            }
          }
          break;
        case 'W':
          {
            Serial.println("wrong command");
            //  ble_serial.println("0x01play0x1dF0x04");
            //   readAck();
            //   Serial.print( "path of zero    ");
            //Serial.println(ack);
            //   if (ack == '1')


            //   Serial.println("its herered ");
            //working();
            digitalWrite(green, LOW);
            digitalWrite(blue, LOW);
            digitalWrite(red, HIGH);
            //  go_forward();
            //delay(100);
            //go_forward();
            go_left1();
            delay(100);
            go_right1();
            delay(100);
            go_right1();
            delay(100);
            go_left1();
            delay(100);


            //                  digitalWrite(blue, LOW);
            //            digitalWrite(red, HIGH);
            //      digitalWrite(green,HIGH);

            //    Serial.println("gred");
            ble_serial.print("0x01play0x1dW0x04");
            for_flag = 0;
            ack = '\0';
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
            working();
            go_left();
            ble_serial.print("0x01play0x1dLS0x04");
            ack = '\0';
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
            working();
            go_right();
            ble_serial.print("0x01play0x1dRS0x04");
          }
          for_flag = 0;
          //  ble_serial.println("0x01play0x1dright successful0x04");
          break;

        case 'e':


          // encoder(motorp1, motorn1, 1, 1, teeth,encoder2);
          // encoder(motorp, motorn, 1, 1, teeth,encoder1);
          button_flag = 1;
          play_flag = 0;
          trigger = 0;
          inc = 0;
          listener = 0;
          switch_flag = 1;



          // delay(20);
          Serial.println("EXIT play");

          ble_serial.print("0x01play0x1dES0x04");
          readAck();
          if (ack == 'Z')
          {
            analogWrite(green, 150);
            analogWrite(blue, 0);
            analogWrite(red, 255);
            Serial.println("ooo play");
          }
          ack = '\0';
          readAck();
          if (ack == '1')
          {
            blue_color();
            delay(1000);
            Serial.println("ooo play");
          }
          ack = '\0';

          //          analogWrite(green, 150);
          //          analogWrite(blue, 0);
          //          analogWrite(red, 255);
          //          delay(2000);
          //          analogWrite(blue, 255);
          //          analogWrite(red, 0);
          //          analogWrite(green, 0);
          break;
        case 'b':
          Serial.print("back");
          //ble_serial.println("0x01play0x1dB0x04");
          // encoder(motorp1, motorn1, 1, 0,teeth, encoder1);
          //delay(2000);
          //readAck();

          //Serial.println(ack);
          //      if (ack == '1'5+)
          {
            working();
            go_back();
            ble_serial.println("0x01play0x1dBS0x04");
          }
          break;
        case 'm':
          Serial.print("mute");
          {
            // working();
            //go_back();
            silence();
            ble_serial.println("0x01play0x1dmu0x04");
          }
          break;
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
