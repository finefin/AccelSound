// Example which uses the MMA_7455 library
// Moritz Kemper, IAD Physical Computing Lab
// moritz.kemper@zhdk.ch
// ZHdK, 03/04/2012
// Released under Creative Commons Licence

#define SPK_PIN1 5
#define POT_PIN1 A1

#include <Wire.h> //Include the Wire library
#include <MMA_7455.h> //Include the MMA_7455 library
#include <NewTone.h> // NewTone ist eine Bibliothek, die es uns ermöglicht, mit einfachen Befehlen Töne zu generieren
#include "sfx.h"    // Die Soundeffekte können in der sfx.h angepasst werden

int potiRead = 0;

MMA_7455 mySensor = MMA_7455(); //Make an instance of MMA_7455

char xVal, yVal, zVal; //Variables for the values from the sensor

void setup()
{
  Serial.begin(9600);
  // Set the sensitivity you want to use
  // 2 = 2g, 4 = 4g, 8 = 8g
  mySensor.initSensitivity(2);
  // Calibrate the Offset, that values corespond in
  // flat position to: xVal = -30, yVal = -20, zVal = +20
  // !!!Activate this after having the first values read out!!!
 // mySensor.calibrateOffset(60, 70, 170);


  pinMode(POT_PIN1, INPUT);
}

void loop()
{
  xVal = mySensor.readAxis('x'); //Read out the 'x' Axis
  yVal = mySensor.readAxis('y'); //Read out the 'y' Axis
  zVal = mySensor.readAxis('z'); //Read out the 'z' Axis

  potiRead = analogRead (POT_PIN1);
 Serial.print("potiread: "); Serial.println(potiRead);
 
  /* Display current axis values */
  /*Serial.print("X: ");    Serial.print(xVal, DEC);
    Serial.print("\tY: ");  Serial.print(yVal, DEC);
    Serial.print("\tZ: ");  Serial.print(zVal, DEC);
    Serial.println();*/

/*
  int zwitscherFaktor = abs(xVal);
  int amplitude = abs(yVal);
  int basisHoehe = abs(zVal * 10);
*/
  //sndfxSine(SPK_PIN1, potiRead, amplitude, basisHoehe, potiRead*10, potiRead);

 // accSound (SPK_PIN1,  abs(xVal*100),  abs(yVal*100),  abs(zVal*100),  potiRead) ;
  
  
  sndfxSine (SPK_PIN1,  abs(xVal*100),  abs(yVal*100),  abs(zVal*100),  potiRead*0.1, potiRead) ;

//   sndfxSine(SPK_PIN1, potiRead, potiRead, basisHoehe, potiRead*10,  potiRead);

  //sndfxUP(SPK_PIN1, potiRead*10, zVal, yVal);

 // delay(500);

}


long stringToLong(String value) {
  long outLong = 0;
  long inLong = 1;
  int c = 0;
  int idx = value.length() - 1;
  for (int i = 0; i <= idx; i++) {

    c = (int)value[idx - i];
    outLong += inLong * (c - 48);
    inLong *= 10;
  }

  return outLong;
}
