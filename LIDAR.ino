#include "Adafruit_VL53L0X.h"

Adafruit_VL53L0X lox = Adafruit_VL53L0X();

uint8_t get_distance();

//stepper configuration

const int pin1 = 2;
const int pin2 = 4;
const int pin3 = 5;
const int pin4 = 3;
const int t = 5;
int count = 0;
float angle = 0.0;
float x = 0.0;
float y = 0.0;
int d = 0;
//prototypes
void set_low();
void fwd(int k);
void bwd(int k);
void stepper(int rotation_direction);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pin3, OUTPUT);

  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);

  while (!Serial){
    delay(1);
  }

  if(!lox.begin()){
    Serial.println("failed to boot sensor");
    while(1);
  }

  Serial.println("successfully booted sensor");

}

void loop() {
  // put your main code here, to run repeatedly:
  angle = (count/516.0) *(2*3.14);
  d = get_distance()-5; // 5cm is the distance between mirror and sensor
  x = d*cos(angle*2);
  y = d*sin(angle*2);
  Serial.print(x);
  Serial.print(" ");
  Serial.print(y);
  Serial.print(" ");
  Serial.println("0.00");
  stepper(1);
  delay(300);
}

uint8_t get_distance()
{
  VL53L0X_RangingMeasurementData_t sensorData;

  uint8_t distance;

  lox.rangingTest(&sensorData, false);

  if(sensorData.RangeStatus != 4)
  {
    distance = sensorData.RangeMilliMeter/10;

    return distance;
  }
  else
  {
    Serial.println("phase error");
  }
}

void stepper(int rotation_direction)
{
  if(rotation_direction == 1)
  {
    fwd(4);
    count += 1;
  }
  else if(rotation_direction == 0)
  {
    bwd(4);
  }
}

void set_low()
{
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
  digitalWrite(pin3, LOW);
  digitalWrite(pin4, LOW);
}

void fwd(int k)
{
  for (int i = 0; i < (k/4); i++)
  {
     digitalWrite(pin1, HIGH);
     digitalWrite(pin2, LOW);
     digitalWrite(pin3, LOW);
     digitalWrite(pin4, LOW);
     delay(t);
     set_low();

     digitalWrite(pin1, LOW);
     digitalWrite(pin2, HIGH);
     digitalWrite(pin3, LOW);
     digitalWrite(pin4, LOW);
     delay(t);
     set_low();

     digitalWrite(pin1, LOW);
     digitalWrite(pin2, LOW);
     digitalWrite(pin3, HIGH);
     digitalWrite(pin4, LOW);
     delay(t);
     set_low();
  
     digitalWrite(pin1, LOW);
     digitalWrite(pin2, LOW);
     digitalWrite(pin3, LOW);
     digitalWrite(pin4, HIGH);
     delay(t);
     set_low();
  
  }
  
}

void bwd(int k)
{
  for(int i = 0; i < (k/4); i++)
  {
     digitalWrite(pin1, LOW);
     digitalWrite(pin2, LOW);
     digitalWrite(pin3, LOW);
     digitalWrite(pin4, HIGH);
     delay(t);
     set_low();

     digitalWrite(pin1, LOW);
     digitalWrite(pin2, LOW);
     digitalWrite(pin3, HIGH);
     digitalWrite(pin4, LOW);
     delay(t);
     set_low();

     digitalWrite(pin1, LOW);
     digitalWrite(pin2, HIGH);
     digitalWrite(pin3, LOW);
     digitalWrite(pin4, LOW);
     delay(t);
     set_low();

     digitalWrite(pin1, HIGH);
     digitalWrite(pin2, LOW);
     digitalWrite(pin3, LOW);
     digitalWrite(pin4, LOW);
     delay(t);
     set_low();
  }
  
}
