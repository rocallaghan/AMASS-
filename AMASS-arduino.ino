#define CUSTOM_SETTINGS
#define INCLUDE_ACCELEROMETER_SENSOR_SHIELD
#define INCLUDE_GPS_SHIELD
#define INCLUDE_SMS_SHIELD
#define INCLUDE_INTERNET_SHIELD
#define INCLUDE_TERMINAL_SHIELD



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
char readings1 [80];
HttpRequest requestx ("http://richardmocallaghan.000webhostapp.com/firebaseTest.php?arduino_data=");
HttpRequest requesty ("http://richardmocallaghan.000webhostapp.com/firebaseTesty.php?arduino_data=");






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

        requestx.addParameter("arduino_data",charlon);  
        requesty.addParameter("arduino_data",charlat);  
        Internet.performGet(requestx);
        Internet.performGet(requesty);
      
       
       
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
}
 
