void silence()
{
 // trigger_flag=0;  
         trigger=1;
       //   inc=0;
          listener=0;
             analogWrite(blue, 255);
             Serial.println("red");
             analogWrite(green, 0);
             analogWrite(red, 0);
            
}

