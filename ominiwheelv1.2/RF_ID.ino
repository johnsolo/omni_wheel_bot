void rf_read()
{
  if (count1 < 1 )
  {
    if (Serial.available())
    {
      Serial.begin(9600);
      if (Serial.available())         // Read 12 characters and store them in input array
      {
        input = Serial.readString();
        input = input.substring(1, 11);

        count1++;
        //delay();

      }
      //Serial.end();
      // Serial.println(input);
      // Serial.println( count1);

      // Serial.print(input.length());

    }

    flag = 1;
  }
  count1 = 0;
}
