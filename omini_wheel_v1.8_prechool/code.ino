////////////////////////////////////////////////////////////////////////code-MODE/////////////////////////////////////////////////////////////////////////////////////////////////////
void code_mode()
{
  
  int j, i, spec_count;
  bool finish_flag = 0;
  serial_flush();
  
  RFID_Data = "\0";
 // int right_count, left_count;
  //Serial.println("enter into the code ");
  ble_serial.print("code");
  readAck();
  if (ack == 'Z')
  {
    yellow_color();
  }
  ack = '\0';
    readAck();
  if (ack == '1')
  {
    yellow_color();
  }
  ack = '\0';
  static int starttile = 1, startwrong = 0;
  trigger = 1;
  memset (ble_input, '\0', sizeof(ble_input));//SET THE ENTIRE ARRAY TO NULL
  int start_flag = 0, stop_flag = 1;
  while (code_flag != 0)
  {

    state_();

    if (listener == 0)
    {
      button_state();
      if ( start_flag != 1 )
      {
       RFID_Data = "\0";
      }
    }
    ble_char = 1;
    ble_read();
    
    //delay(100);
    rf_read();

    // Serial.println("reading");
    //  delay(500);
    // rf_read();


    if ( RFID_Data != "\0"&& RFID_Data != "START" && startwrong == 0 && start_flag == 0) {
      Serial.println("wrong cmd");
      if (startwrong == 0)
      {
        //delay(1200);
        //ble_serial.print("0x01code0x1dI0x04");
        readAck();
        if (ack == 'Z')
        {
          yellow_color();

          count = 0;
        }
        ack = '\0';
        readAck();
        if (ack == '1')
        {
         blue_color();


        }
        ack = '\0';

        RFID_Data = "\0";
        starttile=1;
      }
    }

    else if (RFID_Data == "START" && start_flag == 0 && starttile == 1)
    {
      delay(1200);
      ble_serial.print("0x01code0x1dST0x04");
        readAck();
      if (ack == 'Z')
      {
        yellow_color();

        count = 0;
      }
      ack = '\0';
      readAck();
      if (ack == '1')
      {
        //.blue_color();


      }
      ack = '\0';
       startwrong = 1;
      starttile = 0;
      //  startwrong=0;
     // RFID_Data = "\0";
    }


    //   ble_read();
    if (flag == 1)
    {
      for (i = 0; i < count; i++)
      { //Serial.println(count);
        //      Serial.print("command in thelist to be executed :");
        //     // Serial.println(path[i]);
        //      Serial.println(count);

        switch (path[i])
        {
          //Serial.println(i);

          case 'f':
            Serial.println("forward");
            rl_flag = 0;
            rf_read();
            Serial.println(  RFID_Data );
                      Serial.print("right_count");
          Serial.println(right_count);

            if ((RFID_Data == "FORWARD" && start_flag == 1) || forward_flag == 1 ||
                ((((prev_mile == 'l' && RFID_Data == "LEFT") || (prev_mile == 'r' && RFID_Data == "RIGHT")) && (RFID_Data != "START" || RFID_Data != "STOP"))
                 && ((left_count < 2 && left_count >0 ) || (right_count < 2 && right_count > 0) )))
            {
                   
              for_flag = 0;
              green_color();
              forward();
              delay(1000);
              for_flag = 0;
              forward_flag = 0;
              ble_serial.print("0x01code0x1dFS0x04");
              //readAck();

              RFID_Data = "\0";
              count1 = 0;
              //;
              //  rl_flag=0;
              ins_count++;
            }
            //Special tile reading starts
            else if (RFID_Data == "!")
            {//listener =0;
              special_tile=1;
              ble_serial.print("0x01code0x1d!0x04");
              while (ack != '!')
              {
                readAck();
                if (ack == 'Z')
                {
                  yellow_color();
                }
                if (ack == 'O')
                {
                  white_color();
                }
                if (ack == 'P')
                {
                  blue_color();
                  
                }
                Serial.print("Ack for special  tile");
                Serial.println(ack);
                {


                  if (ack == 'W')
                  {
                    spec_count++;
                    Serial.println("wrong");
                    if (spec_count < 3) {
                      ble_serial.print("0x01code0x1dlis0x04");
                    }
                    else if (spec_count == 3)
                    {
                      break;
                    }
                  }
                }
              }
              Serial.print("came out ");
              Serial.println(ack);
              if (spec_count == 3)
              {

                ble_serial.print("0x01code0x1ddead0x04");


                ack = '\0';
                readAck();
                if (ack == 'Z')
                {
                  yellow_color();
                }
                ack = '\0';
                readAck();
                if (ack == '1')
                {
                  //yellow_color();

                  //count = 0;
                }
                ack = '\0';
                Serial.println("error_action");
                red_color();
                error_action();
              }
              else if (ack == '!')
              {

                Serial.println("correct action");
                ins_count++;
                for_flag = 0;
                green_color();
                forward();
                delay(1000);
                ble_serial.print("0x01code0x1dSFS0x04");
                for_flag = 0;
              }
              ack = '\0';
              spec_count = 0;
              RFID_Data = "\0" ;
              special_tile=0;            }
               else if (RFID_Data == "$")
            {special_tile=1;
              ble_serial.print("0x01code0x1d$0x04");
              while (ack != '$')
              {
                readAck();
                if (ack == 'Z')
                {
                  yellow_color();
                }
                if (ack == 'O')
                {
                  white_color();
                }
                if (ack == 'P')
                {
                  blue_color();
                }
                Serial.print("Ack for special  tile");
                Serial.println(ack);
                {


                  if (ack == 'W')
                  {
                    spec_count++;
                    Serial.println("wrong");
                    if (spec_count < 3) {
                      ble_serial.print("0x01code0x1dlis0x04");
                    }
                    else if (spec_count == 3)
                    {
                      break;
                    }
                  }
                }
              }
              Serial.print("came out ");
              Serial.println(ack);
              if (spec_count == 3)
              {

                ble_serial.print("0x01code0x1ddead0x04");


                ack = '\0';
                readAck();
                if (ack == 'Z')
                {
                  yellow_color();
                }
                ack = '\0';
                readAck();
                if (ack == '1')
                {
                  //yellow_color();

                  //count = 0;
                }
                ack = '\0';
                Serial.println("error_action");
                red_color();
                error_action();
                
              }
              else if (ack == '$')
              {

                Serial.println("correct action");
                ins_count++;
                for_flag = 0;
                green_color();
                forward();
                ble_serial.print("0x01code0x1dSFS0x04"); readAck();
                if (ack == 'Z')
                {
                  yellow_color();
                }
                ack = '\0';
                readAck();
                if (ack == '1')
                {
                  //yellow_color();

                  //count = 0;
                }
                
                for_flag = 0;
              }
              ack = '\0';
              spec_count = 0;
              RFID_Data = "\0" ;
              special_tile=0;
            }
            else if (RFID_Data == "%")
            { special_tile=1;
              ble_serial.print("0x01code0x1d%0x04");
              while (ack != '%')
              {
                readAck();
                if (ack == 'Z')
                {
                  yellow_color();
                }
                if (ack == 'O')
                {
                  white_color();
                }
                if (ack == 'P')
                {
                  blue_color();
                }
                Serial.print("Ack for special  tile");
                Serial.println(ack);
                {


                  if (ack == 'W')
                  {
                    spec_count++;
                    Serial.println("wrong");
                    if (spec_count < 3) {
                      ble_serial.print("0x01code0x1dlis0x04");
                    }
                    else if (spec_count == 3)
                    {
                      break;
                    }
                  }
                }
              }
              Serial.print("came out ");
              Serial.println(ack);
              if (spec_count == 3)
              {

                ble_serial.print("0x01code0x1ddead0x04");


                ack = '\0';
                readAck();
                if (ack == 'Z')
                {
                  yellow_color();
                }
                ack = '\0';
                readAck();
                if (ack == '1')
                {
                  //yellow_color();

                  //count = 0;
                }
                ack = '\0';
                Serial.println("error_action");
                red_color();
                error_action();
                
              }
              else if (ack == '%')
              {

                Serial.println("correct action");
                ins_count++;
                for_flag = 0;
                green_color();
                forward();
                delay(1000);
                ble_serial.print("0x01code0x1dSFS0x04");
                for_flag = 0;
              }
              ack = '\0';
              spec_count = 0;
              RFID_Data = "\0" ;
              special_tile=0;
            }
            
            else
            {

              { int j = 0, k;
                ble_serial.print("0x01code0x1dW0x04");

                // RFID_Data = "\0";
                // i=0;

                //ins_count=0;
                readAck();
                if (ack == 'Z')
                {
                  yellow_color();

                  // count = 0;
                }
                ack = '\0';

                readAck();
                if (ack == '1')
                {
                  blue_color();


                }
                red_color();
                error_action();
                //start_flag = 0 ;starttile = 1;
                ack = '\0';
                while (path[j] != '\0')
                {
                  path[j] = '\0';
                  j++;
                }
                j = 0;

                //Serial.println("out");
                //  trigger = 1;
                listener = 0;
              }

              break;
            case 'b':
              Serial.println("back");
              rf_read();
              if (RFID_Data == "1700453BD6" && start_flag == 1)
              {
                Serial.println("back");
                //ble_serial.println("0x01code0x1dback successful0x04");
                //encoder(motorp, motorn, 0, 1, 8);
                RFID_Data = "\0";
                count1 = 0;
                //ins_count++;
              }
              else
              {
                if (start_flag == 1)
                {
                  ble_serial.println("0x01code0x1dI0x04");
                }
              }
              break;
            case 'l':
              Serial.println("left");
              //;
              //   encoder(motorp1, motorn1, 0, 1);
              rf_read();
              Serial.println(RFID_Data);
              if ((RFID_Data == "LEFT" && start_flag == 1 && stop_flag == 0 && prev_mile != 'l') || (prev_mile == 'l' && path[0] != 'l' && RFID_Data == "LEFT"))
              {
                //("Left");
                green_color();
                rl_flag = 1;
                left1();
                delay(1000);
                ble_serial.print("0x01code0x1dLS0x04");
                left_count++;
                RFID_Data = "\0";
                forward_flag = 1;
                count1 = 0;
                ins_count++;
              }
              else
              {
                if (start_flag == 1 )
                {
                  ble_serial.print("0x01code0x1dW0x04");

                  //                 listener = 0;
                  count = 0;
                  readAck();
                  if (ack == 'Z')
                  {
                    yellow_color();
                  }
                  ack = '\0';
                  readAck();
                  if (ack == '1')
                  {
                    blue_color();


                  }
                  ack = '\0';
                  red_color();
                  error_action();
                  //start_flag = 0 ;starttile = 1;
                  while (path[j] != '\0')
                  {

                    //Serial.println(path[j]);
                    path[j] = '\0';
                    j++;
                  }
                  j = 0;

                }
                trigger = 1;

              }
              break;
            case 'r':
              //  //;
              Serial.println("right");
              //  encoder(motorp1, motorn1, 0, 1);
              rf_read();

              if ((RFID_Data == "RIGHT" && start_flag == 1 && prev_mile != 'r' && stop_flag == 0) || (prev_mile == 'r' && path[0] != 'r' && RFID_Data == "RIGHT") )
              {
                //("right");
                green_color();
                right1();
                delay(1000); ble_serial.print("0x01code0x1dRS0x04");
                rl_flag = 1;
                RFID_Data = "\0";
                forward_flag = 1;
                count1 = 0;
                right_count++;
                ins_count++;
              }
              else
              {

                {
                  Serial.println("wrong cmd0");
                  ble_serial.print("0x01code0x1dW0x04");
                  // red_color();
                  count = 0;
                  //RFID_Data = "\0";
                  readAck();
                  if (ack == 'Z')
                  {
                    yellow_color();


                  }
                  ack = '\0';
                  readAck();
                  if (ack == '1')
                  {
                    blue_color();


                  }
                  ack = '\0';
                  red_color();
                  error_action();
                  //start_flag = 0 ;starttile = 1;

                  while (path[j] != '\0')
                  {
                    path[j] = '\0';
                    j++;
                  }

                  j = 0;


                  // trigger = 1;
                  listener = 0;

                }

              }
              break;
            case 'e':
              Serial.println("exit play");
              // code_flag = 0;
              //rf_read();
              // if (start_flag == 1)
              {
                Serial.println("Exit");
                ble_serial.print("0x01code0x1dE0x04");
                readAck();
                if (ack == 'Z')
                {
                  yellow_color();
                }
                ack = '\0';
                readAck();
                if (ack == '1')
                {


                  blue_color();
                }
                ack = '\0';


                code_flag = 0;
                RFID_Data = "";
                count1 = 0;
                button_flag = 0;
                trigger = 1;
                inc = 0;
                listener = 0;
              }

              break;
            case 's':
              Serial.println("stop code");
              //code_flag = 0;
              rf_read();
              if (RFID_Data == "STOP" && start_flag == 1 )
              {
                //("stop");
                green_color();
                stop_();
                stop_flag = 1;
                finish_flag = 1;
                starttile = 1;
                start_flag = 0;
                ble_serial.print("0x01code0x1dfi0x04");
                readAck();
                if (ack == 'Z')
                {
                  yellow_color();
                }
                ack = '\0';
                readAck();
                                if (ack == '1')
                {
                  //yellow_color(
                green_color();
                for_flag=0;
                forward();
                for_flag=1;
                listener=0;
                }
                ack = '\0';
            blue_color();
               
                while (path[j] != '\0')
                {
                  path[j] = '\0';
                  j++;
                }
                j = 0;
                // code_flag = 0;
                RFID_Data = "\0";
                count1 = 0;
                ins_count++;

              }
              else
              {
                {
                  ble_serial.print("0x01code0x1dW0x04");
                  readAck();
                  if (ack == 'Z')
                  {
                    yellow_color();
                    count = 0;

                  }
                  ack = '\0';
                  readAck();
                  if (ack == '1')
                  {
                    blue_color();


                  }
                  ack = '\0';
                  red_color();
                  error_action();
                  //start_flag = 0 ;starttile = 1;
                  while (path[j] != '\0')
                  {
                    path[j] = '\0';
                    j++;
                  }
                  j = 0;
                  listener = 0;
                }
              }
              break;
            case 'k':
              //;
              rf_read();
              Serial.print("start=");
              Serial.println(RFID_Data);
              if (RFID_Data == "START" )
              {

                for_flag = 0;
                green_color();
                forward();
                delay(1000);
                for_flag = 0;
                ble_serial.print("0x01code0x1dKS0x04");

                RFID_Data = "\0";
                count1 = 0;
                ins_count++;
                start_flag = 1;
                stop_flag = 0;
              }
              else
              { //ins_count = 0;
                ble_serial.print("0x01code0x1dW0x04");
                // RFID_Data = "\0";
                count = 0;
                if (ack == 'Z')
                {
                  yellow_color();

                }
                ack = '\0';
                readAck();
                if (ack == '1')
                {
                  blue_color();
                }
                ack = '\0';
                error_action();

                while (path[j] != '\0')
                {
                  path[j] = '\0';
                  j++;
                }
                j = 0;

                // trigger = 1;
                listener = 0;
                //button_state();
              }

              break;
            default:
              //Serial.println("invalid");
              //Serial.println(path[i]);
              // trigger = 1;
              listener = 0;
              break;
            }

        }
        Serial.print("what is the count value=");
        Serial.println(count);
       Serial.print("what is the ins_count value=");
        Serial.println(ins_count);
        if (ins_count == count && ins_count > 0)
        { prev_mile == '\0';
          prev_mile = path[count - 1];
          Serial.println("prev_mile");
          Serial.println(prev_mile);
          right_count = 0;
          left_count = 0;
        }
      }
      flag = 0;
      count = 0;
      i = 0;
      ble_input[i] = '\0';
      trigger = 1;
      listener = 0;
      ins_count = 0;
    }
  }
  code_flag = 1;
  // serial_flush();
  ble_char = 0;
  start_flag = 0;
  starttile = 1;
  startwrong = 0;
  delay(10);
  Serial.println();
  ble_serial.println("j");
}

