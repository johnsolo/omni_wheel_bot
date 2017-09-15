void direction_()
{//Serial.println("direction");
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
            Serial.println("forward");
           // encoder(motorp, motorn, 1, 0, teeth);
          }
          break;
        case 'b':
          Serial.println("back");
          //encoder(motorp, motorn, 0, 1, teeth);
          break;
        case 'l':
          Serial.println("left");
         // encoder(motorp1, motorn1, 0, 1, teeth);
          break;
        case 'r':
          Serial.println("right");
          //encoder(motorp1, motorn1, 0, 1, teeth);
          break;
        case 's':
          Serial.println("stop play");
          play_flag = 0;
          break;
        default:
          Serial.println("invalid");
          Serial.println(ble_input[i]);
          break;
      }
    }
    Serial.println("done");
    flag = 0;
    count = 0;
    i = 0;
    ble_input[i]='\0';
   

  }
}
