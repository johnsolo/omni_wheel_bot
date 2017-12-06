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
        digitalWrite(led, HIGH);
      digitalWrite(led1, HIGH);
      digitalWrite(led2,LOW);
      FLAG=0;
//    Serial.println("DISCONNECTED");
  }
  else
  {
    if(FLAG==0)
    {
     digitalWrite(led1, LOW);
   //   Serial.println("blue");
            digitalWrite(led, HIGH);
      digitalWrite(led2,HIGH);
      FLAG=1;
    }
  }
}

