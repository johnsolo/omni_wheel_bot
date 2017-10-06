void rf_read()
{
  if (count1 < 1 )
  {
    if (Serial1.available())
    {
    //  Serial1.begin(9600);

        RFID_Data = Serial1.readString();
        RFID_Data = RFID_Data.substring(0, 10);

        count1++;
        //delay();

     }
      //Serial.end();
       Serial.println(RFID_Data);
      // Serial.println( count1);

      // Serial.print(input.length());

    
  }
    flag = 1;
  count1 = 0;
}
