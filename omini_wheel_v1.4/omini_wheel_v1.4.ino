/*
   Author   : John solomon J
   Date     : 1/09/2017
   Project  : Omni Wheel bot
*/

//software serial pins
#include<SoftwareSerial.h>
SoftwareSerial ble_serial(10, 11);
SoftwareSerial serial(12, 13);

const int sensorPin0 = 2;     // the number of the pushbutton pin
const int sensorPin1 = 3;
const int sensorPin2 = 4;
const int sensorPin3 = 49;
const int sensorPin4 = 6;
const int sensorPin5 = 7;
const int ledPin = 13;      // the number of the LED pin
#define motorp  52
#define motorn  49
#define motorp1 12
#define motorn1 13
#define PWM1    9
#define PWM2    8
#define Speed   250
#define Speed1  150
// variables will change:
int sensorState0, sensorState1, sensorState2, sensorState3, sensorState4, sensorState5;   // variable for reading the pushbutton status
//input from bluetooth
char ble_input[100], path[100], Rec_Data, start = 0, finish = 0;
int i = 0, count = 0, count1 = 0;
String input, mode_input, password, RFID_Data;
//making ble read charcter only for different modes we flag so that extra lines can be elimnated
bool flag = 0, ble_char = 0, play_flag = 1, teach_flag = 1, learn_flag = 1, do_flag = 1;
//connection establisment
bool set_, auth_flag = 1;
String packet;
void setup()
{
  Serial.begin(9600);
  Serial1.begin(9600);
  ble_serial.begin(9600);
  Serial.begin(9600);
  pinMode(motorp, OUTPUT);
  pinMode(motorn, OUTPUT);
  pinMode(motorp1, OUTPUT);
  pinMode(motorn1, OUTPUT);
  pinMode(PWM1, OUTPUT);
  pinMode(PWM2, OUTPUT);
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  pinMode(sensorPin0, OUTPUT);
  digitalWrite(sensorPin0, HIGH);
  delayMicroseconds(10);
  pinMode(sensorPin0, INPUT_PULLUP);
  pinMode(sensorPin1, OUTPUT);
  digitalWrite(sensorPin1, HIGH);
  delayMicroseconds(10);
  pinMode(sensorPin1, INPUT_PULLUP);
  pinMode(sensorPin2, OUTPUT);
  digitalWrite(sensorPin2, HIGH);
  delayMicroseconds(10);
  pinMode(sensorPin2, INPUT_PULLUP);
  pinMode(sensorPin3, OUTPUT);
  digitalWrite(sensorPin3, HIGH);
  delayMicroseconds(10);
  pinMode(sensorPin3, INPUT_PULLUP);
  pinMode(sensorPin4, OUTPUT);
  digitalWrite(sensorPin4, HIGH);
  delayMicroseconds(10);
  pinMode(sensorPin4, INPUT_PULLUP);
  pinMode(sensorPin5, OUTPUT);
  digitalWrite(sensorPin5, HIGH);
  delayMicroseconds(10);
  pinMode(sensorPin5, INPUT_PULLUP);
}

void loop()
{
  if (auth_flag == 1)
  {
    ble_read();
    mode_switch();
  }
}
