/////////////////////////////////////////////FINDING WHEATHER BLE IS CONNECTED OR DISCONNECTED///////////////////////////////////////////////////////////
void state_()
{
  connect_state = digitalRead(state);
  //Serial.println(connect_state);
  if (connect_state == 0)
  {
    play_flag = 0;
    do_flag = 0;
    teach_flag = 0;
    learn_flag = 0;
       digitalWrite(blue, LOW);
      digitalWrite(green, LOW);
      digitalWrite(red,HIGH);
//      delay(5000);
//      digitalWrite(led, HIGH);
//      digitalWrite(led1, HIGH);
//      digitalWrite(led2,HIGH);
//      delay(5000);
//      
      FLAG=0;
   //   ble_serial.print("connected");
   Serial.println("DISCONNECTED");
    trigger=0;
flag1=1;
  }
  else
  {if(flag1==1)
  {
         
   Serial.println("connceted");
   delay(1000);
      ble_serial.print("c");
      flag1=0;
       Serial.println("connceted1");
       trigger=0;
        listener=0; 
  }
          
    if(FLAG==0)
    {
  

     digitalWrite(red, LOW);

            digitalWrite(green, LOW);
      digitalWrite(blue,HIGH);
      FLAG=1;
     
    }
  }
}

