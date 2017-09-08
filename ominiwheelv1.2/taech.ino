void teach()
{
  while (teach_flag != 0)
  {
    rf_read();
    if (input == "290090EE8A")
    {
      Serial.println("Left");
      input = "";
    }
    else if (input == "170045375E")
    {
      Serial.println("forward");
      encoder(motorp, motorn, 1, 0, 8);

      input = "";
    }
    else if (input == "sfsf")
    {
      Serial.println("back");
      encoder(motorp, motorn, 0, 1, 8);
      input = "";
    }
    else if (input == "sdfdsfb")
    {
      Serial.println("right");
      input = "";
    }
    else if (input == "17005F160A")
    {
      Serial.println("stop");
      input = "";
      teach_flag = 0;
    }
  }
  teach_flag = 1;
}

