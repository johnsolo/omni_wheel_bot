# include<SoftwareSerial.h>
#include <EEPROM.h>
// motor 1
# define motorp   4
# define motorn   5
// motor 2
# define motorp1  6
# define motorn1  7
// encoder 1
# define encoder1 8
// encoder 2
# define encoder2 9
//software serial pins
SoftwareSerial ble_serial(10, 11);
//input from bluetooth
char ble_input[100];
int i = 0, count = 0, count1 = 0, steps = 0, current_pos;
String input, mode_input;
//making ble read charcter only for different modes we flag so that extra lines can be elimnated
bool flag = 0, ble_char = 0, play_flag = 1, teach_flag = 1, learn_flag = 1, do_flag = 1;
//connection establisment
bool set_, check, login_flag;
int value, a;
String password, user_input;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  ble_serial.begin(9600);

}

void loop()
{
  flag = 0;
  ble_read();

  if (mode_input == "sp")
  {
    Serial.println("done");
    mode_input = "";
    user_input = "";

    i = 0;
    flag = 0;
    login_flag = 0;
    ble_input[i] = '\0';

  }
  //Serial.println(flag);

  if (mode_input == "rp")
  { for (int MemoryAddr = 0; MemoryAddr < 4; MemoryAddr++)
    {
      value = EEPROM.read(MemoryAddr);
      char MyCharacter = char(value);
      password += MyCharacter;

    }
    Serial.print("password");
    Serial.println(password);
    if (user_input == password)
    {
      ble_serial.println("success");
      login_flag = 1;
    }
    else
    {
      ble_serial.println("failure");
    }
    mode_input = "";
    user_input = "";
    password = "";
    i = 0;
    flag = 0;
    ble_input[i] = '\0';
  }

}


