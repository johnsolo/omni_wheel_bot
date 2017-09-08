void mode_switch()
{
  if (flag == 1)
  {
    if (mode_input == "do$")
    {
      // Serial.print(mode_input);
      Serial.println("do");
      flag = 0;
      do_mode();
    }
    else if (mode_input == "teach$")
    {
      Serial.print(mode_input);
      Serial.println("teach");
      teach();
    }
    else if (mode_input == "learn$")
    {
      Serial.print(mode_input);
      Serial.println("learn");
      learn();
    }
    else if (mode_input == "play$")
    {
      Serial.print(mode_input);
      Serial.println("play");

      play();
    }
  }
  flag = 0;
  count = 0;
  i = 0;
  mode_input = "";
}


