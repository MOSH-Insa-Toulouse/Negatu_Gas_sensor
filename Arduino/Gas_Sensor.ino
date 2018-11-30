/*
 * Author: Negatu Michael

 * This program is meant to be used with an Arduino UNO conencted to an RNxx3 radio module.
 * It will most likely also work on other compatible Arduino or Arduino compatible boards, like The Things Uno, but might need some slight modifications.
 * Write the device address, network (session) key, and app (session) key to the values that are registered via the TTN dashboard.

 * Connect the RN2xx3 as follows:
 * RN2xx3 -- Arduino
 * Uart TX -- 10
 * Uart RX -- 11
 * Reset -- 12
 * Vcc -- 3.3V
 * Gnd -- Gnd
 * LED -- 2
 * Gas Sensor -- A1
  */


include <rn2xx3.h>
#include <SoftwareSerial.h>
#include <TheThingsNetwork.h>

const byte gasSensor = A1; //set the sensor to pin A1
const byte RX = 10;
const byte TX = 11;
const byte LED = 2;


// Set your DevAddr, NwkSKey, AppSKey and the frequency plan
//Change the device address, network (session) key, and app (session) key to the values that are registered via the TTN dashboard.
//const char *devAddr = ""  
//const char *nwkSKey = ""
//const char *appSKey = ""

#define freqPlan TTN_FP_EU868
#define debugSerial Serial
SoftwareSerial loraSerial(RXPin, TXPin); // RX, TX
TheThingsNetwork ttn(loraSerial, debugSerial, freqPlan);

// the setup routine runs once when you press reset:
void setup()
{
  //output LED pin
  pinMode(LED, OUTPUT);
  pinMode(gasSensor, INPUT);


  // Open serial communications and wait for port to open:
  loraSerial.begin(57600);
  debugSerial.begin(9600);

  digitalWrite(LED, 1);
  while (!debugSerial && millis() < 10000);

  ttn.onMessage(message);

  debugSerial.println("-- STATUS");
  ttn.showStatus();

  debugSerial.println("-- JOIN");
  ttn.join(appEui, appKey);
  
  digitalWrite(LED, 0);
  delay(2000);
}

void loop()
{

  float sensor_volt;
  float sensorValue;
  int Entier;
  int Decimal;

  debugSerial.println("-- LOOP");
  
  debugSerial.print(" GAS SENSOR : ");

  sensorValue = analogRead(gasSensor);
  sensor_volt = sensorValue/1024*5.0;
  debugSerial.println(sensor_volt);
  
  Entier = (int) sensor_volt;
  Decimal = (sensor_volt - valEntiere)*100;

  byte data[2];
  data[0] = Entier;
  data[1] = Decimal;

  ttn.sendBytes(data, sizeof(data));

  
  // LED would go on if the value is high
  if(sensor_volt > 1.0) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }
}
