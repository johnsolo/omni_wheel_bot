/////////////////////////////////////////////////////MODE SELECTION/////////////////////////////////////////////////////////////////////////////////////////
void mode_switch()
{

  if (flag == 1)
  {
    if (mode_input == "do")
    {
      // Serial.print(mode_input)
      do_flag = 1;
      Serial.println("do");
      flag = 0;

      do_mode();
    }
    else if (mode_input == "teach")
    {
      teach_flag = 1;
      Serial.print(mode_input);
      Serial.println("teach");
      teach();
      Serial.println("blue");
      //            digitalWrite(led, HIGH);
      //      digitalWrite(led2,HIGH);
    }
    else if (mode_input == "learn")
    {
      learn_flag = 1;
      Serial.print(mode_input);
      Serial.println("learn");
      learn();
    }
    else if (mode_input == "play")
    {
      play_flag = 1;
      Serial.println("play");
      mode_input = "";
      play();
      //  ble_serial.println("j");
    }
    else if (mode_input == "code")
    {
      code_flag = 1;
      Serial.println("code");
      mode_input = "";

      code_mode();
    }
    else if (mode_input == "learndo")
    {
      learn_do_flag = 1;
      Serial.println("play");
      mode_input = "";
      //      learndo_mode();
    }
    else if (mode_input == "exit")
    {
      learn_flag = 0;
      teach_flag = 0;
      do_flag = 0;
      Serial.println("exit received");

      //  flag=0;
    }
    else if (mode_input == "m")
    {
      silence();
    }
    else if (mode_input == " ")
    {
      Serial.println("invalid");

      mode_input = "";
    }

  }
  flag = 0;
  count = 0;
  i = 0;
  ble_input[i] = '\0';
  mode_input = "";
}




