#include "config.h"
#include <SoftwareSerial.h>

SoftwareSerial mySerial(12,14); // RX, TX


//String inputString="";

String inputString="";

AdafruitIO_Feed *liveupdate = io.feed("liveupdate");
//AdafruitIO_Feed *system1 = io.feed("system1");
//AdafruitIO_Feed *system2 = io.feed("system2");
//AdafruitIO_Feed *system3 = io.feed("system3");

void setup() {
  
  Serial.begin(115200);
  mySerial.begin(9600);
 while(! Serial);
 
 
 Serial.print("Connecting to Adafruit IO");

 io.connect();
 
 while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  // we are connected
  Serial.println();
  Serial.println(io.statusText());
 
  }

void loop() {
  
  io.run();

  if(mySerial.available())
  {  
    
    inputString=mySerial.readString();
    Serial.println(inputString);
    liveupdate->save(inputString);
  }
//    Serial.println(inputString);
   // liveupdate->save("welcome to child transportation");
    delay(3000);
}
