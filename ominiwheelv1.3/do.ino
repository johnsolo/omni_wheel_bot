void do_mode()
{
  Serial.println("enter into the do");
  memset (ble_input, '\0', sizeof(ble_input));
  serial_flush();
  while (do_flag != 0)
  {
    ble_char = 1;
    ble_read();
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

              //     encoder(motorp, motorn, 1, 0);
              rf_read();
              if (input == "170045375E")
              {
                Serial.println("in_forward");
                input = "";
              }

            }
            break;
          case 'b':
            Serial.println("back");
            //  encoder(motorp, motorn, 0, 1);
            rf_read();
            if (input == "290090EE8A")
            {
              Serial.println("in_back");
              input = "";
            }
            else
            {

            }
            break;
          case 'l':
            Serial.println("left");
            //   encoder(motorp1, motorn1, 0, 1);
            rf_read();
            if (input == "290090EE8A")
            {
              Serial.println("in_Left");
              input = "";
            }
            break;
          case 'r':
            Serial.println("right");
            //  encoder(motorp1, motorn1, 0, 1);
            rf_read();
            if (input == "290090EE8A")
            {
              Serial.println("in_right");
              input = "";
            }
            break;

          case 's':
            Serial.println("stop play");
            learn_flag = 0;
            rf_read();
            if (input == "17005F160A")
            {
              Serial.println("in_stop");
              input = "";
            }
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
  learn_flag = 1;
  Serial.println(flag);
  serial_flush();
  ble_char = 0;
}

