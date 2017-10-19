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
            forward();
            for_flag = 0;
            ble_serial.println("0x01play0x1dforward successful0x04");
          }
          break;
        case 's':
          Serial.println("stop");
          // encoder(motorp, motorn, 0, 1, teeth,encoder2);
          ble_serial.println("0x01play0x1dstop successful0x04");
          stop_();
          break;
        case 'l':
          Serial.println("left");
          // encoder(motorp1, motorn1, 0, 1, teeth,encoder1);
          left();
          ble_serial.println("0x01play0x1dleft successful0x04");
          break;

        case 'r':
          Serial.println("right");
          // encoder(motorp1, motorn1, 1, 0,teeth, encoder1);
          right();
          ble_serial.println("0x01play0x1dright successful0x04");
          break;

        case 'e':
          Serial.println("EXIT play");
          ble_serial.println("0x01play0x1dout of play mode0x04");
          // encoder(motorp1, motorn1, 1, 1, teeth,encoder2);
          // encoder(motorp, motorn, 1, 1, teeth,encoder1);
          play_flag = 0;
          break;
        default:
          Serial.println("invalid");
          // Serial.println(path[i]);
          break;
      }
      ble_serial.println("0x01play0x1dstart listening0x04");
   }
    //Serial.println("done");
    flag = 0;
    count = 0;
    i = 0;
    ble_input[i] = '\0';
  }
}
