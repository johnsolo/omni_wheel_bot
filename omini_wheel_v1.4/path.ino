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
           ble_serial.println("0x01play0x1dforward successful0x04");
          }
          break;
        case 'b':
          Serial.println("back");
         // encoder(motorp, motorn, 0, 1, teeth,encoder2);
         ble_serial.println("0x01play0x1dback successful0x04");
          break;
        case 'l':
          Serial.println("left");
        // encoder(motorp1, motorn1, 0, 1, teeth,encoder1);
          ble_serial.println("0x01play0x1dleft successful0x04");
          break;
          
        case 'r':
          Serial.println("right");
         // encoder(motorp1, motorn1, 1, 0,teeth, encoder1);
         ble_serial.println("0x01play0x1dright successful0x04");
          break;
        case 's':
          Serial.println("stop play");
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
    }
    //Serial.println("done");
    flag = 0;
    count = 0;
    i = 0;
    ble_input[i] = '\0';
  }
}
