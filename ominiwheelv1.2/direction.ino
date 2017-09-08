void direction_()
{
  if (flag == 1)
  {
    for (i = 0; i < count; i++)
    { Serial.println(count);
      switch (ble_input[i])
      {
          Serial.print(ble_input[i]);
        case 'f':
          //     rfid_read();
          //     if (input == input)
          {
            Serial.println("forward");

            encoder(motorp, motorn, 1, 0, 32);
          }
          break;
        case 'b':
          Serial.println("back");
          encoder(motorp, motorn, 0, 1, 32);
          break;
        case 'l':
          Serial.println("left");
          encoder(motorp1, motorn1, 0, 1, 32);
          break;
        case 'r':
          Serial.println("right");
          encoder(motorp1, motorn1, 0, 1, 32);
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

  }
}
