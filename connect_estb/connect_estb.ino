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
int i = 0, count = 0, count1 = 0, steps = 0;
String input, mode_input;
//making ble read charcter only for different modes we flag so that extra lines can be elimnated
bool flag = 0, ble_char = 0, play_flag = 1, teach_flag = 1, learn_flag = 1, do_flag = 1;
//connection establisment
bool set_, check;
int value, a;
String password;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  ble_serial.begin(38400);

}

void loop()
{ flag=0;
  set_=0;
 ble_read();
 mode_input="";
 i=0;
 switch(ble_input[i])
  {
    
    case 'a': 
      set_ = 1;
      
      while (flag != 1)
      {
        ble_read();
      }
      mode_input="";
      flag=0;
   //   delay(5000);
      break;
    case 'b':
    {  set_ = 0;
      flag=0; 
      ble_char=0;
       while (flag != 1)
      {
      ble_read();
      }
      for (int MemoryAddr = 0; MemoryAddr < 5; MemoryAddr++)
      {
        value = EEPROM.read(MemoryAddr);
        char MyCharacter = char(value);
        password += MyCharacter;
        Serial.println(MyCharacter);
      }
      if(mode_input==password)
      {
        ble_serial.println("Success");
      }
      else
      {
        Serial.println("failure");
      }
      break;
    }
  }
}


