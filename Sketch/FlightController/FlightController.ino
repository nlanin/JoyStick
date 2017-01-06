// Program used to test the USB Joystick library when used as 
// a Flight Controller on the Arduino Leonardo or Arduino 
// Micro.
//
// Matthew Heironimus
// 2016-05-29 - Original Version
//------------------------------------------------------------

#include "Joystick.h"
#include <Wire.h>
#include <Adafruit_ADS1015.h>

/*Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, 
  JOYSTICK_TYPE_MULTI_AXIS, 32, 0,
  true, true, false, false, false, false,
  true, true, false, false, false);*/

Joystick_ Joystick;

Adafruit_ADS1115 Ads;

 int16_t  pAds0;
 int16_t  pAds1;
 int  pXAxis;
 int  pYAxis;
 
 float pRange = 20000;
 float pMaxAdsValue = 32768;

void setup() {

  

  Joystick.setXAxisRange(0, pRange);
  Joystick.setYAxisRange(0, pRange);
  Joystick.setZAxisRange(0, pRange);
  Joystick.setThrottleRange(0, 255);
  Joystick.setRudderRange(0, 255);
  Serial.begin(115200);

  //Ads.setGain(GAIN_ONE);
  Ads.begin();
  
  Joystick.begin();
  
}

void loop() {
  
  pAds0 = Ads.readADC_SingleEnded(0);
  pAds1 = Ads.readADC_SingleEnded(1);

  //pAds0 = analogRead(0);
  //pAds1 = analogRead(1);
 
if (pAds0 < 0)
{
  pXAxis = 0;
}
else 
{
  pXAxis = pAds0 * ( pRange / pMaxAdsValue );
}

if (pAds1 < 0)
{
  pYAxis = 0;
}
else 
{
  pYAxis = pAds1 * ( pRange / pMaxAdsValue );
}
  
  Joystick.setXAxis(pXAxis);
  Joystick.setYAxis(pYAxis);

}

