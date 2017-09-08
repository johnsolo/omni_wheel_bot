/*
   Author   : John solomon J
   Date     : 1/09/2017
   Project  : Omni Wheel bot
*/
# include<SoftwareSerial.h>
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
bool flag_sucess,flag_failure;
String password;

void setup()
{
  Serial.begin(9600);
  ble_serial.begin(38400);
  pinMode(motorp,  OUTPUT);
  pinMode(motorn,  OUTPUT);
  pinMode(motorp1, OUTPUT);
  pinMode(motorn1, OUTPUT);
  pinMode(encoder1, INPUT);
  pinMode(encoder2, INPUT);
}

void loop()
{

  ble_read();
  mode_switch();
  // ble_serial.end();

}
