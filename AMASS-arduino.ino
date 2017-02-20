
#define CUSTOM_SETTINGS
#define INCLUDE_ACCELEROMETER_SENSOR_SHIELD
#define INCLUDE_GPS_SHIELD
#define INCLUDE_SMS_SHIELD


/* Include 1Sheeld library. */
#include <OneSheeld.h>

/* A name for the LED on pin 13. */
int ledPin = 13;
boolean isent = false;
boolean isMessageSent = false;
float lat ;
float lon ;
char charlat [10];
char charlon [10];
char readings [80];

void setup()
{
  /* Start communication. */
  OneSheeld.begin();
  /* Set the LED pin as output. */
  pinMode(ledPin,OUTPUT);
}

void loop()
{
  /* Check X-axis acceleration. */
  if(AccelerometerSensor.getX() > 8)
  {
    digitalWrite(ledPin,HIGH);
    Camera.setFlash(ON);
    Camera.frontCapture();
    isent = true;
   
      if(isent = true)
      {
      Facebook.postLastPicture("This person has stolen my car of reg 12345");
      isent = false;
      }

      if (!isMessageSent)
      {
        lat = GPS.getLatitude(); lon = GPS.getLongitude();
        dtostrf(lat, 7, 3, charlat); dtostrf(lon, 7, 3, charlon);
        strcat(readings, "GPS Coordinates of your car : \n");
        strcat(readings, "latitude is : "); strcat (readings, charlat);
        strcat(readings, "\nLongitude is : "); strcat (readings, charlon);
        SMS.send("0863967689", readings);
        isMessageSent = true;
      }
      else
      {
         isMessageSent = false;
      }
       OneSheeld.delay(5000);
   
  }
  else
  {  
    digitalWrite(ledPin,LOW);
  }

  /* Y axis maybe???? keeps glitching on phone and freaking out causing mis readings?? */
 
}
