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
//    Serial.println("DISCONNECTED");
  }
}

