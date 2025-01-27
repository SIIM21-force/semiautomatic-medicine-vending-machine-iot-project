/*************************************************** 
  This is an example sketch for our optical Fingerprint sensor

  Designed specifically to work with the Adafruit BMP085 Breakout 
  ----> http://www.adafruit.com/products/751

  These displays use TTL Serial to communicate, 2 pins are required to 
  interface
  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/


#include <Adafruit_Fingerprint.h>
#include <Wire.h>
#include <stdio.h>
#include <OneWire.h>
#include <DallasTemperature.h>
// On Leonardo/Micro or others with hardware serial, use those! #0 is green wire, #1 is white
// uncomment this line:


// For UNO and others without hardware serial, we must use software serial...
// pin #2 is IN from sensor (GREEN wire)
// pin #3 is OUT from arduino  (WHITE wire)
// comment these two lines if using hardware serial
#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
const int rs = 8, en = 9, d4 = 10, d5 = 11, d6 = 12, d7 = 13;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
//SoftwareSerial mySerial(6, 7);//RX,TX
#define mySerial Serial1
// Data wire is plugged into digital pin 2 on the Arduino
#define ONE_WIRE_BUS A1

// Setup a oneWire instance to communicate with any OneWire device
OneWire oneWire(ONE_WIRE_BUS);  

// Pass oneWire reference to DallasTemperature library
DallasTemperature sensors(&oneWire);

Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);
char button = 'x';
int temp = 0, i = 0;
char str[15];
//int st1,st2,st3,st4;
const int SW1=2;
const int SW2=3;
const int SW3=4;

const int mode=34;

const int voice1=22;
const int voice2=24;
const int voice3=26;
const int voice4=28;
const int voice5=30;
const int voice6=32;

const int buz=A2;

const int fsr=A0;


const int R1=44;
const int R2=46;
const int R3=48;

const int R4=50;
const int R5=52;

const int R6=7;

int fsrValue = 0;

void fsr_part(void);
void body_temp(void);


void setup()  
{
 pinMode(SW1,INPUT);
pinMode(SW2,INPUT);
pinMode(SW3,INPUT);

pinMode(mode,INPUT);

pinMode(R6,OUTPUT);

pinMode(voice1,OUTPUT);
pinMode(voice2,OUTPUT);
pinMode(voice3,OUTPUT);
pinMode(voice4,OUTPUT);
pinMode(voice5,OUTPUT);
pinMode(voice6,OUTPUT);

pinMode(R1,OUTPUT);
pinMode(R2,OUTPUT);
pinMode(R3,OUTPUT);
pinMode(R4,OUTPUT);
pinMode(R5,OUTPUT);

pinMode(buz,OUTPUT);
  
digitalWrite(buz,LOW);

digitalWrite(voice1,HIGH);
digitalWrite(voice2,HIGH);
digitalWrite(voice3,HIGH);
digitalWrite(voice4,HIGH);
digitalWrite(voice3,HIGH);
digitalWrite(voice4,HIGH);
digitalWrite(voice3,HIGH);
digitalWrite(voice4,HIGH);

digitalWrite(voice1,HIGH);
digitalWrite(voice2,HIGH);
digitalWrite(voice3,HIGH);
digitalWrite(voice4,HIGH);
digitalWrite(voice3,HIGH);
digitalWrite(voice4,HIGH);


digitalWrite(R1,LOW);
digitalWrite(R2,LOW);
digitalWrite(R3,LOW);
digitalWrite(R4,LOW);
digitalWrite(R5,LOW);

digitalWrite(R6,LOW);
  Serial.begin(9600);
  while (!Serial);  // For Yun/Leo/Micro/Zero/...
  delay(100);
  //Serial.println("\n\nAdafruit finger detect test");

  // set the data rate for the sensor serial port
  finger.begin(57600);

   lcd.begin(16,2);
  lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("VENDING MACHINE");
      lcd.setCursor(0,1);
      lcd.print("FOR MEDIKIT");
      delay(3000);
digitalWrite(R6,HIGH);
  lcd.clear();
  
  if (finger.verifyPassword()) {
  //  Serial.println("Found fingerprint sensor!");
  } else {
  //  Serial.println("Did not find fingerprint sensor :(");
    while (1) { delay(1); }
  }

  finger.getTemplateCount();
 // Serial.print("Sensor contains "); Serial.print(finger.templateCount); Serial.println(" templates");
  
}

void loop()                     // run over and over again
{
if(digitalRead(mode)==LOW)
{
  
    
   lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("AUTOMATIC MODE");
  lcd.setCursor(0,1);
  lcd.print("");
   
  delay(2000);
  fsr_part();
   body_temp();
  
  
  }
  if(digitalRead(mode)==HIGH)
{
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("MANUAL MODE");
  lcd.setCursor(0,1);
  lcd.print("");
  
  delay(2000);
  
  finger_check();
  
  
  
  }
  



}
  
void finger_check(void)
{
 while(1)
 {
  fsr_part();
 int teacher;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("PLSEASE PUT ");
    lcd.setCursor(0,1);
    lcd.print("FINGER TO ACCESS      ");
    delay(1000);
  //  Serial.print("welcome");
    teacher = getFingerprintIDez();

    if( teacher == 1 ) 
    {
       lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("FINGER MATCHED");
  lcd.setCursor(0,1);
  lcd.print("");
  delay(2000);
       digitalWrite(voice1,LOW);
      digitalWrite(voice1,LOW);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("VALID PERSON");                                                 //to print details of added item
        lcd.setCursor(0,1);
        lcd.print("NAME: AAA");
        Serial.println("VAILD PERSON NAME:AAA");
        delay(1500);
        digitalWrite(voice1,HIGH);
        digitalWrite(voice1,HIGH);
        delay(500);
        sw_check();
 
    }
    else if( teacher == 2 ) 
    {
      lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("FINGER MATCHED");
  lcd.setCursor(0,1);
  lcd.print("");
  delay(2000);
       digitalWrite(voice1,LOW);
      digitalWrite(voice1,LOW);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("VALID PERSON");                                                 //to print details of added item
        lcd.setCursor(0,1);
        lcd.print("NAME: BBB");
        Serial.println("VAILD PERSON NAME:BBB");
        delay(1500);
        digitalWrite(voice1,HIGH);
        digitalWrite(voice1,HIGH);
        delay(500);
        sw_check();
    }
    
   else if( teacher == 3 ) 
    {
        lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("FINGER MATCHED");
  lcd.setCursor(0,1);
  lcd.print("");
  delay(2000);
       digitalWrite(voice1,LOW);
      digitalWrite(voice1,LOW);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("VALID PERSON");                                                 //to print details of added item
        lcd.setCursor(0,1);
        lcd.print("NAME: CCC");
        Serial.println("VAILD PERSON NAME:CCC");
        delay(1500);
        digitalWrite(voice1,HIGH);
        digitalWrite(voice1,HIGH);
        delay(500);
        sw_check();
    }
     
    else if( teacher == 4 ) 
    {
        lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("INVALID FINGER");
  lcd.setCursor(0,1);
  lcd.print("");
  delay(2000);

    }
  }
}
 
  


void sw_check()
{
  while(1)
  {
  if(digitalRead(SW1)==HIGH)
  {
      digitalWrite(voice2,LOW);
      digitalWrite(voice2,LOW);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("DISPENSING TABLET");                                                 //to print details of added item
        lcd.setCursor(0,1);
        lcd.print("VOMIT");
        digitalWrite(R1,HIGH);
        Serial.println("TOOK VOMIT TABLET");
        delay(5000);
        digitalWrite(voice2,HIGH);
        digitalWrite(voice2,HIGH);
        digitalWrite(R1,LOW); 
        delay(500);
        
    
    break;
    
   }
if(digitalRead(SW2)==HIGH)
  {
    digitalWrite(voice3,LOW);
      digitalWrite(voice3,LOW);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("DISPENSING TABLET");                                                 //to print details of added item
        lcd.setCursor(0,1);
        lcd.print("PAIN ");
          digitalWrite(R2,HIGH);
      
        Serial.println("TOOK PAIN TABLET");
        delay(5000);
        digitalWrite(voice3,HIGH);
        digitalWrite(voice3,HIGH);
          digitalWrite(R2,LOW);
      
        delay(500);
    
    
    break;
    
   }
   if(digitalRead(SW3)==HIGH)
  {
    digitalWrite(voice4,LOW);
      digitalWrite(voice4,LOW);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("DISPENSING TABLET");                                                 //to print details of added item
        lcd.setCursor(0,1);
        lcd.print("COLD");
          digitalWrite(R3,HIGH);
      
        Serial.println("TOOK COLD TABLET");
        delay(4000);
        digitalWrite(voice4,HIGH);
        digitalWrite(voice4,HIGH);
          digitalWrite(R3,LOW);
      
        delay(500);
    
    
    break;
   }
  }
  
  
  
}
void fsr_part()
  {
    
    fsrValue = analogRead(fsr);
  float volt = ((fsrValue * 5.0)/1024)*100.0;
// Serial.println("fsr:");
//Serial.println(volt);
  if((int)volt > 80 )
  {
      digitalWrite(buz,HIGH);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("FORCE DETECTED");
      lcd.setCursor(0,1);
      lcd.print("MACHINE DAMAGE");
     // Serial.print("DRIVER FELL DOWN DETECTED");
  
      
         
  }
  if((int)volt < 80)
  {
      digitalWrite(buz,LOW);
            lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("NO FROCE");
      lcd.setCursor(0,1);
      lcd.print("ALL NORMAL");     
 //     Serial.print("DRIVER NOT FELL DOWN");
 

  }
    
         delay(2000);
    }

void body_temp()
{
   // Send the command to get temperatures
  sensors.requestTemperatures(); 

  //print the temperature in Celsius
  Serial.print("Temperature: ");
  Serial.println(sensors.getTempCByIndex(0));
 // Serial.print((char)176);//shows degrees character
 // Serial.print("C  |  ");
 lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("TEMPEARTURE         ");
  lcd.setCursor(0,1);
  lcd.print(sensors.getTempCByIndex(0));
    delay(1500);
 if(sensors.getTempCByIndex(0)>38)
 {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("TEMPEARTURE         ");
  lcd.setCursor(0,1);
  lcd.print("MORE...    ");
  Serial.println(" TEMPRATURE IS MORE ");
  digitalWrite(voice1,LOW);
      digitalWrite(voice1,LOW);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("VALID PERSON");                                                 //to print details of added item
        lcd.setCursor(0,1);
        lcd.print("NAME: DDD");
        Serial.println("VAILD PERSON NAME:DDD");
        delay(1500);
      //  digitalWrite(voice1,HIGH);
      //  digitalWrite(voice1,HIGH);
      //  delay(500);
        digitalWrite(R4,HIGH);
      //  digitalWrite(voice6,LOW);
      //  digitalWrite(voice6,LOW);
        delay(5000);
       // digitalWrite(voice6,HIGH);
      //  digitalWrite(voice6,HIGH);
        digitalWrite(R4,LOW);
        Serial.println("TOOK FEVER TABLET");
        delay(100);
        while(1);
 }
 
else {

 lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("TEMPEARTURE         ");
  lcd.setCursor(0,1);
  lcd.print("NORMAL...    ");
  Serial.println("TEMPERATURE IS NORMAL");
  delay(1500);
 }
  
  
}



/*void class1(void)
{
  while(1)
  {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("FINGER MATCHED");
  lcd.setCursor(0,1);
  lcd.print("");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("NAME:AAA");
  lcd.setCursor(0,1);
  lcd.print("PRESENT");
  Serial.println("NAME:AAA PRESENT");
  a=1;
  delay(2000);
  break;
  }
  
}
void class2(void)
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("FINGER MATCHED");
  lcd.setCursor(0,1);
  lcd.print("");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("NAME:BBB");
  lcd.setCursor(0,1);
  lcd.print("PRESENT");
  Serial.println("NAME:BBB PRESENT");
  b=1;
  delay(2000);
}
void class3(void)
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("FINGER MATCHED");
  lcd.setCursor(0,1);
  lcd.print("");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("NAME:xxx");
  lcd.setCursor(0,1);
  lcd.print("PRESENT");
  Serial.println("NAME:xxx PRESENT");
  c=1;
  delay(2000);
}
void class4(void)
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("FINGER MATCHED");
  lcd.setCursor(0,1);
  lcd.print("");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("NAME:zzz");
  lcd.setCursor(0,1);
  lcd.print("PRESENT");
  Serial.println("NAME:zzz PRESENT");
  d=1;
  delay(2000);
}

/*void class5(void)
{
 lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("INVALID STUDENT");
  lcd.setCursor(0,1);
  lcd.print("ALERT");
  Serial.println("ALERT INVALID STUDENT");
  delay(2000);
}*/


/*void class3(void)
{
  digitalWrite(buz,LOW);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(" INVALID FINGER");
  lcd.setCursor(0,1);
  lcd.print("");
  delay(2000);
  digitalWrite(buz,LOW);
   
}*/
 /* lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("ST1:");

  lcd.setCursor(6,0);
  lcd.print("ST2:");

  lcd.setCursor(0,1);
  lcd.print("ST3:");

  lcd.setCursor(6,1);
  lcd.print("ST4:");
  int temp;
  st1 = st2 = st3 = st4 = 'A';
  do
  {
    temp = getFingerprintIDez();
    if( temp == 4 ) 
    {
      lcd.setCursor(4,0);
      lcd.print('P');
      st1 = 'P';
    }
    else if( temp == 5 ) {
      lcd.setCursor(10,0);
      lcd.print('P');
      st2 = 'P';
    }
    else if( temp == 6 ) {
      lcd.setCursor(4,1);
      lcd.print('P');
      st3 = 'P';
    }
    else if( temp == 7 ) {
      lcd.setCursor(10,1);
      lcd.print('P');
      st4 = 'P';
    }
  }
  while( temp != 1 );

  sprintf(buf,"class 1 st1 %c st2 %c st3 %c st4 %c",st1,st2,st3,st4);
  Serial.print(buf);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("1 Class Over...");
  delay(2000);  
  lcd.clear();//don't ned to run this at full speed.*/
//}



uint8_t getFingerprintID() {
  uint8_t p = finger.getImage();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image taken");
      break;
    case FINGERPRINT_NOFINGER:
      Serial.println("No finger detected");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("Imaging error");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }

  // OK success!

  p = finger.image2Tz();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println("Image too messy");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println("Could not find fingerprint features");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println("Could not find fingerprint features");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }
  
  // OK converted!
  p = finger.fingerFastSearch();
  if (p == FINGERPRINT_OK) {
    Serial.println("Found a print match!");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Communication error");
    return p;
  } else if (p == FINGERPRINT_NOTFOUND) {
    Serial.println("Did not find a match");
    return p;
  } else {
    Serial.println("Unknown error");
    return p;
  }   
  
  // found a match!
  Serial.print("Found ID #"); Serial.print(finger.fingerID); 
  Serial.print(" with confidence of "); Serial.println(finger.confidence); 

  return finger.fingerID;
}

// returns -1 if failed, otherwise returns ID #
int getFingerprintIDez() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)  return -1;
  
  // found a match!
  //Serial.print("Found ID #"); Serial.print(finger.fingerID); 
 // Serial.print(" with confidence of "); Serial.println(finger.confidence);
  return finger.fingerID; 
}
