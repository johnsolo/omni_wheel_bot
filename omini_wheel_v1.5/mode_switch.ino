///////////////////////////////////////////////////////////////////////////////////MODE SELECTION/////////////////////////////////////////////////////////////////////////////////////////
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
    }
    else if (mode_input == "teach1")
    {
      teach_flag = 1;
      Serial.println("play");
      mode_input = "";
      teach1();
    }
      else if (mode_input == "learndo")
    {
      learn_do_flag = 1;
      Serial.println("play");
      mode_input = "";
      learndo_mode();
    }
    else
    {
      //Serial.println("invalid");
      mode_input = "";
    }
  }
  flag = 0;
  count = 0;
  i = 0;      
  ble_input[i] = '\0';
  mode_input = "";
}




