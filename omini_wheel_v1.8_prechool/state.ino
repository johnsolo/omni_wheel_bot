/////////////////////////////////////////////FINDING WHEATHER BLE IS CONNECTED OR DISCONNECTED///////////////////////////////////////////////////////////
void state_()
{ int j = 0;
  connect_state = digitalRead(state);
  //Serial.println(connect_state);
  if (connect_state == 0)
  {
    play_flag = 0;
    do_flag = 0;
    teach_flag = 0;
    learn_flag = 0;
    code_flag = 0;
    red_color();
    for (int fadeValue = 0 ; fadeValue <= 100; fadeValue += 5) {
      // sets the value (range from 0 to 255):
      //   analogWrite(blue, fadeValue);
      analogWrite(red, fadeValue);
      // wait for 30 milliseconds to see the dimming effect
      delay(30);
    }
    for (int fadeValue = 100 ; fadeValue >= 0; fadeValue -= 5) {
      // sets the value (range from 0 to 255):
      //  analogWrite(blue, fadeValue);
      analogWrite(red, fadeValue);
      // wait for 30 milliseconds to see the dimming effect
      delay(30);
    }
    //
    FLAG = 0;
    //   ble_serial.print("connected");
    Serial.println("DISCONNECTED");
    trigger = 0;
    flag1 = 1;
  }
  else
  { if (flag1 == 1)
    {
      Serial.println("connceted");
      delay(1000);
      ble_serial.print("c");
      flag1 = 0;
      Serial.println("connceted1");
      trigger = 0;
      listener = 0;
    }
    if (FLAG == 0)
    {
      blue_color();
      FLAG = 1;
    }

  }
}

