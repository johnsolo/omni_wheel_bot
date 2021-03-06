/*
   Author   : John solomon J
   Date     : 1/09/2017
   Project  : teacher project
*/
//software serial pins
#include<SoftwareSerial.h>
#include <SPI.h>
#include <MFRC522.h>
#include <CapacitiveSensor.h>
//#include <Servo.h>
SoftwareSerial ble_serial(10, 11);
int rl_flag = 0;
bool Degree_flag=0;
//Servo head;
char prev_mile;
bool start_tile_special,special_flag=0;
//SoftwareSerial serial(12, 13);
#define RST_PIN         5         // Configurable, see typical pin layout above
#define SS_PIN          53         // Configurable, see typical pin layout above
void state_();
void mode_switch();
void recharge();
void readAck();
void yellow_color();
void red_color();
void blue_color();
void white_color();
void green_color();
void serial_flush();
void direction_();
void error_action();
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance
//Servo head;
bool blue_trig;
static int right_count, left_count;
const int sensorPin0 = 23;     // the number of the pushbutton pin
const int sensorPin1 = 22;
const int sensorPin2 = 25;
const int sensorPin3 = 24;
const int sensorPin4 = 27;
const int sensorPin5 = 26;    // the number of the LED pin   // the number of the LED pin
const int sensorPin6 = 34;
const int sensorPin7 = 35;

static int FLAG, flag1;
int connect_state;
bool special_tile=0;
#define motorp  30
#define motorn  31
#define motorp1 32
#define motorn1 33
#define PWM1    12
#define PWM2    13
#define Speed   180
#define Speed1  180
#define state   9
//LED'S for listening
#define blue     4
#define red      3
#define green    2
// variables w.ill change:
//String special_tile[]={"@","#","$","!"};
int trigger_flag, prev_flag = 1, trigger, forward_flag;
int sensorState0, sensorState1, sensorState2, sensorState3, sensorState4, sensorState5, sensorState6, sensorState7; // variable for reading the pushbutton status
//input from bluetooth
char ble_input[100], path[100];
int i = 0, count = 0, count1 = 0;
String input, mode_input, password, RFID_Data, RFID_data1, RFID_data2;
//making ble read charcter only for different modes we flag so that extra lines can be elimnated
bool flag = 0, ble_char = 0, play_flag = 1, teach_flag = 1, learn_flag = 1, do_flag = 1, learn_do_flag = 1, code_flag = 1, switch_flag = 0;
static int inc;
//connection establisment
bool set_, auth_flag = 1;
String packet;
bool for_flag;
void ble_read();
char ack;
static int counter;
int button_flag, button_pin;
static bool listener = 0;
int ins_count;

CapacitiveSensor   cs_4_2 = CapacitiveSensor(6, 7);
void setup()
{ mfrc522.PCD_Init();
  Serial.begin(9600);
  ble_serial.begin(9600);
  cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
  ////////////////////////////////////////////////////RF-CARD READING PART////////////////////////////////////////////////////////
  SPI.begin();                                                  // Init SPI bus
  //mfrc522.PCD_Init();                                              // Init MFRC522 card
  //Serial.println(F("Read personal data on a MIFARE PICC:"));    //shows in serial that it is ready to read
  ///////////////////////////////////////////////////////servo///////////////////////////////////////////////////////////////////////
  // head.attach(1);
  ///////////////////////////////////////////////////MOTOR PART//////////////////////////////////////////////////////////////////////
  cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
  pinMode(motorp, OUTPUT);
  pinMode(motorn, OUTPUT);
  pinMode(motorp1, OUTPUT);
  pinMode(motorn1, OUTPUT);
  pinMode(state, INPUT);
  pinMode(PWM1, OUTPUT);
  pinMode(PWM2, OUTPUT);
  pinMode(21, INPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  //////////////////////////////////////////////////////////SENSOR INPUTS////////////////////////////////////////////////////////////
  /*
    1. We have to make make sensor pins as output and make it HIGH for 10 millis second
    2. Then make sensor pins as input_pull up to read again
  */
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
  pinMode(sensorPin6, OUTPUT);
  digitalWrite(sensorPin6, HIGH);
  delayMicroseconds(10);
  pinMode(sensorPin6, INPUT_PULLUP);
  pinMode(sensorPin7, OUTPUT);
  digitalWrite(sensorPin7, HIGH);
  delayMicroseconds(10);
  pinMode(sensorPin7, INPUT_PULLUP);
}
void loop()
{ ////////////////////////////////////////////////////////////////////////////AUTH FOR FUTURE//////////////////////////////////////////////////////////////////////////////////////////////
  state_();// flag=0;
  if (listener == 0)
  {
    button_state();
  }
  if ((auth_flag == 1 && button_flag == 1) || switch_flag == 1) //auth flag
  {
    ble_read();
    mode_switch();
  }

}

