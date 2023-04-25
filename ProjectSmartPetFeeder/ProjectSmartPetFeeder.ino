#define BLYNK_PRINT Serial

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>
#include <TridentTD_LineNotify.h>

#define SSID        "Folksong_TP-Link"
#define PASSWORD    "05082545"
#define LINE_TOKEN  "lG7NAY7nv5OoksWiY0mLDeVU8dV3e0mJYis4zSypC3E"
#define BLYNK_TEMPLATE_ID "TMPL6rQEQ_3bN"
#define BLYNK_TEMPLATE_NAME "Project Final 2"
#define BLYNK_AUTH_TOKEN "3y-wOUUp774JNP13aBPH81SvOxLvIOdk"

LiquidCrystal_I2C lcd(0x27,16,2);

Servo petGate;
int gateStart = 30;
int gateEnd = 141;
int gateOpenTime = 350;
int gateOpenTime2 = 160;



void setup() {
  Serial.begin(9600);
  petGate.attach(D4);
  petGate.write(gateStart);
 
  LINE.setToken(LINE_TOKEN); 
  Blynk.begin(BLYNK_AUTH_TOKEN, SSID, PASSWORD);

  pinMode(D6,OUTPUT);

  lcd.begin();
  lcd.setCursor(0,0);
  lcd.print("NIKAII's FEEDERS");

}


BLYNK_WRITE(V0)
{
   
 Serial.println(param.asInt()); 
 
 if(param.asInt()){
   tone(D6,550);

   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("Let your pet");
   lcd.setCursor(0,1);
   lcd.print("enjoy the food");

   petGate.write(gateEnd);   
   delay(gateOpenTime);
   petGate.write(gateStart);

   noTone(D6);

   LINE.notifySticker("คุณให้อาหารสัตว์เลี้ยงสำเร็จ !", 446, 1993);

   delay(3000);

   lcd.clear();
   lcd.print("NIKAII's FEEDERS");

 }
  
}


BLYNK_WRITE(V1)
{
  Serial.println(param.asInt()); 
 if(param.asInt()){
   tone(D6,550);

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Have a good time");
    lcd.setCursor(0,1);
    lcd.print("eating baby !");
  for(int i=0;i<5;i++)
  {
    
    
    petGate.write(gateEnd);
    delay(gateOpenTime2);    
    petGate.write(gateStart);
    delay(gateOpenTime2);

    

  }
  noTone(D6);
  delay(3000);

  lcd.clear();
  lcd.print("NIKAII's FEEDERS");

  LINE.notifySticker("คุณให้อาหารสัตว์เลี้ยง แบบ QUICKLY สำเร็จ !!", 6325, 10979914); 
 }
  
}

BLYNK_WRITE(V2)
{
   
 Serial.println(param.asInt()); 
 if(param.asInt()){
   tone(D6,550);

   lcd.clear();
   lcd.setCursor(0,0); 
   lcd.print("It's meal time !!");


   petGate.write(gateEnd);
   delay(gateOpenTime);
   petGate.write(gateStart);

   noTone(D6);
   delay(3000);

   lcd.clear();
   lcd.print("NIKAII's FEEDERS");

   LINE.notify("คุณให้อาหารสัตว์เลี้ยง ตามเวลาที่ตั้งไว้ สำเร็จ !!!");
   LINE.notifyPicture("https://lh3.googleusercontent.com/IZR8dR0SzvNs585XWWvxtYqEoCC132yY6RYJ6-dh87G5-FYMNuJG5AwYmPqgCkt6yyNhTeR__97014NmFQjxFvfAKXV88kOFOtF7V0g");
 }
  
}

void loop()
{
  
  Blynk.run();
}

