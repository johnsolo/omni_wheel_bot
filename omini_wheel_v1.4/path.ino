void direction_()
{ //Serial.println("direction");
  if (flag == 1)
  {
    for (i = 0; i < count; i++)
    { //Serial.println(count);
      //  Serial.print("play_in");
      // Serial.print(path[2]);
      switch (path[i])
      {

        case 'f':
          //     rfid_read();
          //     if (input == input)
          {
            Serial.println("CONT:forward");
            ble_serial.println("0x01play0x1dFx04");
            delay(2000);
            forward();
            
            for_flag = 0;

          }
          break;
                  case 'k':
          //     rfid_read();
          //     if (input == input)
          {
            Serial.println("CONT:forward");
            ble_serial.println("0x01play0x1dF0x04");
             delay(2000);
            forward();
            for_flag = 0;

          }
          break;
        case 's':
          Serial.println("stop");
          // encoder(motorp, motorn, 0, 1, teeth,encoder2);
          ble_serial.println("0x01play0x1dS0x04");
          
          stop_();
          break;
        case 'l':
          Serial.println("left");
          // encoder(motorp1, motorn1, 0, 1, teeth,encoder1);
          ble_serial.println("0x01play0x1dL0x04");
           delay(2000);
          left();
          for_flag = 0;
          
          break;

        case 'r':
          Serial.println("right");
           ble_serial.println("0x01play0x1dR0x04");
          // encoder(motorp1, motorn1, 1, 0,teeth, encoder1);
           delay(2000);
          right();
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
