

#include <EEPROM.h>
#include <OneWire.h>
#include <EEPROM.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "OneButton.h"
#include "max6675.h"


//////////  устройства  ////////////////////////////

#define encoderPin1      2
#define encoderPin2      3
#define VENT             5
#define MOTOR            6
#define LAMP             7
#define BEEPER           10
#define LED              13
#define SENSOR_IN        15
#define SENSOR_OUT       16
#define SENSOR_ROOM      17

#define thermoSO         8
#define thermoCS         9
#define thermoSCK        14

MAX6675 thermocouple(thermoSCK, thermoCS, thermoSO);

////////////////////////////////////////////////

LiquidCrystal_I2C lcd(0x27, 16, 2);

////////  кнопки  ////////////////////

OneButton menu(4, true);
OneButton pusk(11, true);

////////  датчики темп - ры  /////////////////////

OneWire ds1(SENSOR_IN );
OneWire ds2(SENSOR_OUT);
OneWire ds3(SENSOR_ROOM);




//////////  энеодер  ///////////////////////

volatile int lastEncoded = 0;
volatile long encoderValue = 0;
long lastencoderValue = 0;
int lastMSB = 0;
int lastLSB = 0;

int val;
int val_old = 0;

//////////////////////////////////////////////////////

byte A = 0;
byte pos = 0;
byte state = 0;
/*
0 - ожидание
1 - розжиг
2 - нагрев
3 - поддержка
4 - выжигание
100 - аварии
200 - спящий режим
*/

unsigned long ignition_Millis = 0;
int count_ignition = 0;
int count_flame = 0;

unsigned long heat_Millis = 0;
int count_heat = 0;

unsigned long support_Millis = 0;
int count_support = 0;

unsigned long reburn_Millis = 0;
int count_reburn = 0;

unsigned long previousMillis_temp = 0;
int temp_in = 25;
int temp_out = 25;
int temp_room = 18;
int temp_flame = 0;
int temp_counter = 0;

byte beeper_state = 0;
byte error_state_in = 0;
byte error_state_out = 0;
byte error_state_temp = 0;
byte error_state_flame = 0;

byte flame_state = 0;
long beep_count = 0;

byte start_flag = 0;

////////  настраиваемые переменные  ////////////////////

byte vent_wait = 10;         //// обороты вентилятора в %
byte vent_ignition = 10;
byte vent_heat = 10;
byte vent_support = 10;
byte vent_reburn = 10;

byte screw_ignition = 10;    //// время работы шнека в сек
byte screw_heat = 10;
byte screw_support = 10;
byte screw_interval = 10;    //// интервал вкл. шнека в сек

byte time_ignition = 10;     //// время розжига в мин
byte time_lamp_on = 10;      //// время вкл лампы в сек
byte time_lamp = 10;         //// время работы лампы в мин
byte time_flame = 10;        //// время фиксации пламени в сек
byte time_reburn = 10;        //// время выжигания в мин

byte beeper_on_off = 0;      //// вкл или выкл зуммер

byte temp_max = 85;           //// макс. температура (аварийная)
byte temp_control = 20;       //// выставленная температура (уставка)
byte temp_gist = 2;           //// гистерезис температуры

int temp_flame_control = 50;  //// температура фиксации пламени
int temp_flame_max = 300;     //// макс. температура котла (аварийная)

//////////  кириллица //////////////////////////

uint8_t tochki[8] = {
  B0, B00000, B0, B0, B0, B0, B10101
};
uint8_t bukva_P[8] = {
  0x1F, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11
};
uint8_t bukva_Ya[8] = {
  B01111, B10001, B10001, B01111, B00101, B01001, B10001
};
uint8_t bukva_L[8] = {
  0x3, 0x7, 0x5, 0x5, 0xD, 0x9, 0x19
};
uint8_t bukva_Lm[8] = {
  0, 0, B01111, B00101, B00101, B10101, B01001
};
uint8_t bukva_Mz[8] = {
  0x10, 0x10, 0x10, 0x1E, 0x11, 0x11, 0x1E
};
uint8_t bukva_I[8] = {
  0x11, 0x13, 0x13, 0x15, 0x19, 0x19, 0x11
};
uint8_t bukva_D[8] = {
  B01111, B00101, B00101, B01001, B10001, B11111, 0x11
};
uint8_t bukva_G[8] = {
  B11111, B10001, B10000, B10000, B10000, B10000, B10000
};
uint8_t bukva_IY[8] = {
  B01110, B00000, B10001, B10011, B10101, B11001, B10001
};
uint8_t bukva_Z[8] = {
  B01110, B10001, B00001, B00010, B00001, B10001, B01110
};
uint8_t bukva_ZH[8] = {
  B10101, B10101, B10101, B11111, B10101, B10101, B10101
};
uint8_t bukva_Y[8] = {
  B10001, B10001, B10001, B01010, B00100, B01000, B10000
};
uint8_t bukva_B[8] = {
  B11110, B10000, B10000, B11110, B10001, B10001, B11110
};
uint8_t bukva_CH[8] = {
  B10001, B10001, B10001, B01111, B00001, B00001, B00001
};
uint8_t bukva_IYI[8] = {
  B10001, B10001, B10001, B11001, B10101, B10101, B11001
};
uint8_t bukva_TS[8] = {
  B10010, B10010, B10010, B10010, B10010, B10010, B11111, B00001
};
uint8_t bukva_SH[8] = {
  B10101, B10101, B10101, B10101, B10101, B10101,  B11111
};
uint8_t bukva_F[8] = {
  B11111, B10101, B10101, B11111, B00100, B00100,  B00100
};
uint8_t bukva_III[8] = {
  B10001, B10001, B10001, B11101, B10101, B10101, B11101
};


////////////////////  мал буквы  /////////////////////////////////

uint8_t bukva_b[8] = {
  B00111, B01000, B10000, B11110, B10001, B10001, B01110
};
uint8_t bukva_v[8] = {
  B00000, B00000, B11110, B10001, B11110, B10001, B11110
};
uint8_t bukva_g[8] = {
  B00000, B00000, B11111, B10000, B10000, B10000, B10000
};
uint8_t bukva_d[8] = {
  B11100, B00010, B00001, B01111, B10001, B10001, B01110
};
uint8_t bukva_z[8] = {
  B00000, B00000, B10101, B10101, B01110, B10101, B10101
};
uint8_t bukva_ze[8] = {
  B00000, B00000, B11110, B00001, B00110, B00001, B11110
};
uint8_t bukva_i[8] = {
  B00000, B00000, B10001, B10001, B10011, B10101, B11001
};
uint8_t bukva_k[8] = {
  B00000, B00000, B10010, B10100, B11000, B10100, B10010
};
uint8_t bukva_l[8] = {
  B00000, B00000, B00111, B00101, B00101, B10101, B01001
};
uint8_t bukva_m[8] = {
  B00000, B00000, B10001, B11011, B10101, B10001, B10001
};
uint8_t bukva_n[8] = {
  B00000, B00000, B10001, B10001, B11111, B10001, B10001
};
uint8_t bukva_p[8] = {
  B00000, B00000, B11111, B10001, B10001, B10001, B10001
};
uint8_t bukva_t[8] = {
  B00000, B00000, B11111, B00100, B00100, B00100, B00100
};
uint8_t bukva_f[8] = {
  B00000, B00000, B00100, B01110, B10101, B01110, B00100
};
uint8_t bukva_ts[8] = {
  B00000, B00000, B10001, B10001, B10001, B11111, B00001
};
uint8_t bukva_ch[8] = {
  B00000, B00000, B10001, B10001, B11111, B00001, B00001
};
uint8_t bukva_scha[8] = {
  B00000, B00000, B10101, B10101, B10101, B10101, B1111
};
uint8_t bukva_tscha[8] = {
  B00000, B00000, B10101, B10101, B10101, B11111, B00001
};
uint8_t bukva_e[8] = {
  B00000, B00000, B01110, B10001, B00110, B10001, B01110
};
uint8_t bukva_yu[8] = {
  B00000, B00000, B10010, B10101, B11101, B10101,  B10010
};
uint8_t bukva_iya[8] = {
  B00000, B00000, B01111, B10001, B01111, B01001, B10001
};
uint8_t bukva_iii[8] = {                             ////  мал ы
  B00000, B00000, B10001, B11001, B10101, B10101, B11001
};


byte gradus[8] = {
  B01100,
  B10010,
  B10010,
  B01100,
  B00000,
  B00000,
  B00000
};



void setup()
{
  vent_wait = EEPROM.read(21);
  vent_ignition = EEPROM.read(22);
  vent_heat = EEPROM.read(23);
  vent_support = EEPROM.read(24);
  vent_reburn = EEPROM.read(25);
  screw_ignition = EEPROM.read(26);
  screw_heat = EEPROM.read(27);
  screw_support = EEPROM.read(28);
  time_lamp_on = EEPROM.read(29);
  time_lamp = EEPROM.read(30);
  time_flame = EEPROM.read(31);
  screw_interval = EEPROM.read(32);
  time_ignition = EEPROM.read(33);
  temp_max = EEPROM.read(34);
  temp_control = EEPROM.read(35);
  temp_gist = EEPROM.read(36);
  time_reburn = EEPROM.read(37);

  beeper_on_off = EEPROM.read(180);

  EEPROM.get(210, temp_flame_control);
  EEPROM.get(220, temp_flame_max);


  pinMode(MOTOR, OUTPUT);
  pinMode(LAMP, OUTPUT);
  pinMode(BEEPER, OUTPUT);
  pinMode(LED, OUTPUT);

  pinMode(encoderPin1, INPUT_PULLUP);
  pinMode(encoderPin2, INPUT_PULLUP);
  attachInterrupt(0, updateEncoder, CHANGE);
  attachInterrupt(1, updateEncoder, CHANGE);

  menu.attachClick(Click);
  menu.attachLongPressStart(LongPressStart);
  pusk.attachClick(PUSK);

  lcd.init();
  lcd.backlight();
  lcd.clear();

  ZASTAVKA_1();
  delay(2000);
  lcd.clear();
  ZASTAVKA_2();
  delay(1500);
  lcd.clear();

  previousMillis_temp = millis();

  //Serial.begin(9600);
}

void loop()
{
  menu.tick();
  pusk.tick();

  //Serial.println(state);

  /////////////////////////////////////////////////
  ///////////  температура раз в 3 сек  ///////////
  /////////////////////////////////////////////////

  if (millis() - previousMillis_temp > 3000)
  {
    temp_in = (int)getTemp1();
    temp_out = (int)getTemp2();
    temp_room = (int)getTemp3();

    temp_flame = (int)thermocouple.readCelsius();

    if (start_flag == 0)
    {
      start_flag = 1;
    }

    previousMillis_temp = millis();
  }


  if (start_flag == 1)
  {

    ////////////////////////////////////////////
    //// аварийная ситуация перегрев воды //////
    ////////////////////////////////////////////

    if (temp_in >= temp_max)
    {
      error_state_temp = 1;

      if (state == 2 || state == 3)
      {
        beeper_state = 1;
        reburn_Millis = millis();
        digitalWrite(MOTOR, LOW);
        state = 4;
      }
      if (state == 1)
      {
        digitalWrite(MOTOR, LOW);
        count_ignition = 0;
        flame_state = 0;
        state = 0;
      }
    }

    ///////////  проблема с датчиком темп в котле ////////

    if (temp_in == -1000)
    {
      error_state_in = 1;

      if (state == 2 || state == 3)
      {
        beeper_state = 1;
        reburn_Millis = millis();
        digitalWrite(MOTOR, LOW);
        state = 4;
      }
      if (state == 1)
      {
        digitalWrite(MOTOR, LOW);
        count_ignition = 0;
        flame_state = 0;
        state = 0;
      }
    }

    ///////////////////////////////////////////////////////
    ///////////  перегрев котла  //////////////////////////
    ///////////////////////////////////////////////////////

    if (temp_flame >= temp_flame_max)
    {
      error_state_flame = 1;

      if (state == 2 || state == 3)
      {
        beeper_state = 1;
        reburn_Millis = millis();
        digitalWrite(MOTOR, LOW);
        state = 4;
      }
      if (state == 1)
      {
        digitalWrite(MOTOR, LOW);
        count_ignition = 0;
        flame_state = 0;
        state = 0;
      }
    }
  }


  ////////////  бибикалка  //////////////////

  if (beeper_state == 1)
    BEEP();
  else
    noTone(BEEPER);

  /////////// светодиод  //////////////////////

  if (temp_flame >= temp_flame_control)
  {
    digitalWrite(LED, LOW);
  }
  if (temp_flame < temp_flame_control)
  {
    digitalWrite(LED, HIGH);
  }

  /////////////////////////////////////////

