void contingency()
{
    if(listener==1)
    {
         if(ble_input[i]!='P')

      {Serial.println("entering the loop");
      //  ble_read();
        delay(1);
        counter++;
        Serial.print("counter");
        Serial.println(counter);
        if(counter>=200)
        {
          
         listener=0;
         if(inc>0)
         {
          ble_serial.print("listen2");
          Serial.print("listen2=");
          Serial.println(inc);
          inc=0;
          Serial.print("listen2=");
          Serial.println(inc);
         // cont=0;
       
         }
            digitalWrite(blue, LOW);
      Serial.println("red");
            digitalWrite(red, HIGH);
      digitalWrite(green,HIGH);
         Serial.println("exiting the loop");
//         counter=0;
//         inc=0;
//         cont=0;
         }
      }
    }
      
}

