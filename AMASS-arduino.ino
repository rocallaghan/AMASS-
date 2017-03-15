#define CUSTOM_SETTINGS
#define INCLUDE_ACCELEROMETER_SENSOR_SHIELD
#define INCLUDE_GPS_SHIELD
#define INCLUDE_SMS_SHIELD
#define INCLUDE_INTERNET_SHIELD
#define INCLUDE_TERMINAL_SHIELD
#define INCLUDE_KEYPAD_SHIELD


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
int iterations = 0;

HttpRequest requestx ("http://richardmocallaghan.000webhostapp.com/firebaseTest.php?arduino_data=");
HttpRequest requesty ("http://richardmocallaghan.000webhostapp.com/firebaseTesty.php?arduino_data=");
HttpRequest recentx ("http://richardmocallaghan.000webhostapp.com/firebaseTestrecent.php?arduino_data=");
HttpRequest recenty ("http://richardmocallaghan.000webhostapp.com/firebaseTestrecenty.php?arduino_data=");








void setup()
{
  /* Start communication. */
  OneSheeld.begin();

  /* Set the LED pin as output. */
  pinMode(ledPin, OUTPUT);

}


void loop()
{
 
  /* Check if "1" is pressed, iterate one time. */ 
  if(iterations == 0 && isOnePressed())
  {
     iterations++;
  }
  /* Check if "2" is pressed, iterate one time. */ 
  else if (iterations == 1 && isTwoPressed())
  {
     iterations++;
  }
  /* Check if "3" is pressed, iterate one time. */ 
  else if (iterations == 2 && isThreePressed())
  {
     iterations++;
  }
  /* Check if "4" is pressed, iterate one time. */
  else if(iterations == 3 && isFourPressed())
  {
     iterations++;
  }
  /* Check if any other button is pressed, reset iterations. */
  else if(isOtherButtonPressed())
  {
    iterations = 0;
  }
     
   /* Check if the number of iterations is 4, blink the LED. */
   if(iterations != 4)
   {  
     /* Check X-axis acceleration. */
     if (AccelerometerSensor.getX() > 8)
     {

        digitalWrite(ledPin, HIGH);
        Camera.setFlash(ON);
        Camera.frontCapture();
        isent = true;


       if (isent = true)
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

          requestx.addParameter("arduino_data", charlon);
          requesty.addParameter("arduino_data", charlat);
          recentx.addParameter("arduino_data", charlon);
          recenty.addParameter("arduino_data",charlat);
          Internet.performGet(requestx);
          Internet.performGet(requesty);
          Internet.performGet(recentx);
          Internet.performGet(recenty);

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

    digitalWrite(ledPin, LOW);

  }
}
else
{
   digitalWrite(ledPin, HIGH);
}
}
boolean isOnePressed(){
  return Keypad.isRowPressed(0) && Keypad.isColumnPressed(0);
}

boolean isTwoPressed(){
  return Keypad.isRowPressed(0) && Keypad.isColumnPressed(1);
}

boolean isThreePressed(){
  return Keypad.isRowPressed(0) && Keypad.isColumnPressed(2);
}

boolean isFourPressed(){
  return Keypad.isRowPressed(1) && Keypad.isColumnPressed(0);
}

boolean isOtherButtonPressed(){
  return ((Keypad.isAnyColumnPressed() || Keypad.isAnyColumnPressed()) && !isOnePressed() && !isTwoPressed() && !isThreePressed() && !isFourPressed());
}


