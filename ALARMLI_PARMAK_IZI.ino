#include <Servo.h>
Servo sg90;
#include <Adafruit_Fingerprint.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3); 
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);
#include <LiquidCrystal_I2C_AvrI2C.h>
LiquidCrystal_I2C_AvrI2C lcd(0x27,16,2);
int sonuc;
void setup()
{
 pinMode(12,OUTPUT);
 pinMode(9,OUTPUT);
 pinMode(8,OUTPUT);
 pinMode(7,OUTPUT);
 pinMode(6,OUTPUT);
 pinMode(4,INPUT);
 sg90.attach(9);
 sg90.write(0);
 Serial.begin(9600);
 while (!Serial); 
 delay(100);

 lcd.begin();
 lcd.setCursor(0, 0);
 lcd.print("   ENES YASIN");
 lcd.setCursor(0, 1);
 lcd.print("   ALTIPARMAK");
 delay(2000);
 lcd.clear();

 finger.begin(57600);
  if (finger.verifyPassword()) {
   lcd.setCursor(0,0);
   lcd.print("  SENSOR TESPIT");
   lcd.setCursor(0,1);
   lcd.print("     EDILDI!");
   delay(4000);
   lcd.clear();
  } else {
   lcd.setCursor(0,0);
   lcd.print("    SENSOR ");
   lcd.setCursor(0,1);
   lcd.print("   BULUNAMADI");
   delay(4000);
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("  BAGLANTILARI");
   lcd.setCursor(0,1);
   lcd.print("  KONTROL ET !!");
   while (1) {
     delay(1);
   }
 }

  finger.getTemplateCount();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("    KAYITLI");
  lcd.setCursor(12,0);
  lcd.print(finger.templateCount); 
  lcd.setCursor(0,1);
  lcd.print("  PARMAK IZI VAR");
  delay(4000);
  lcd.clear();
  


}
 
void loop()                 
{
 getFingerprintIDez();
 delay(50);
  digitalWrite(12, LOW);
  digitalWrite(8,LOW);
  digitalWrite(6,LOW);
  sonuc=digitalRead(4);
  if(sonuc==1){
  digitalWrite(7,HIGH);
  delay(2500);
  
  }
  else{
    digitalWrite(7,LOW);
  Serial.print(sonuc);
  }
  }




int getFingerprintIDez() {
 uint8_t p = finger.getImage();
 if (p != FINGERPRINT_OK)  {
   lcd.clear();
   lcd.setCursor(0, 0);
   lcd.print("   PARMAK IZI");
   lcd.setCursor(0, 1);
   lcd.print("   BEKLENIYOR");
   return -1;
 }

 p = finger.image2Tz();
 if (p != FINGERPRINT_OK)  {
   lcd.clear();
   lcd.setCursor(0, 0);
   lcd.print("  PARMAK IZI ");
   lcd.setCursor(0, 1);
   lcd.print("  ALGILANAMADI");
   delay(3000);
   lcd.clear();
   return -1;
 }

 p = finger.fingerFastSearch();
 if (p != FINGERPRINT_OK)  {
   lcd.clear();
   lcd.setCursor(0, 0);
   lcd.print("   PARMAK IZI ");
   lcd.setCursor(0,1);
   lcd.print("    GECERSIZ");
   digitalWrite(6,HIGH);
   delay(100);
   digitalWrite(7,HIGH);
   delay(100);
   digitalWrite(8,LOW);
   delay(100);
   digitalWrite(8,HIGH);
   delay(100);
   digitalWrite(7,LOW);
   delay(100);
   digitalWrite(8,LOW);
   delay(100);
   digitalWrite(7,HIGH);
   delay(100);
   digitalWrite(8,LOW);
   delay(100);
   digitalWrite(8,HIGH);
   delay(100);
   digitalWrite(7,LOW);
   delay(100);
   digitalWrite(8,LOW);
   delay(100);
   digitalWrite(7,HIGH);
   delay(100);
   digitalWrite(8,LOW);
   delay(100);
   digitalWrite(7,LOW);
   delay(100);
   digitalWrite(8,HIGH);
   delay(100);
   digitalWrite(7,LOW);
   delay(100);
   digitalWrite(8,HIGH);
   digitalWrite(7,LOW);
   delay(100);
   digitalWrite(8,LOW);
   delay(100);
   digitalWrite(7,HIGH);
   delay(100);
   digitalWrite(8,LOW);
   delay(100);
   digitalWrite(8,HIGH);
   delay(100);
   digitalWrite(7,LOW);
   delay(100);
   digitalWrite(8,LOW);
   delay(100);
   digitalWrite(7,HIGH);
   delay(100);
   digitalWrite(8,LOW);
   delay(100);
   digitalWrite(8,HIGH);
   delay(100);
   digitalWrite(7,LOW);
   delay(100);
   digitalWrite(8,LOW);
   delay(100);
   digitalWrite(7,HIGH);
   delay(100);
   digitalWrite(8,LOW);
   delay(100);
   digitalWrite(7,LOW);
   delay(100);
   digitalWrite(8,HIGH);
   delay(100);
   digitalWrite(7,LOW);
   delay(100);
   digitalWrite(8,LOW);
   digitalWrite(7,LOW);
   digitalWrite(6,LOW);
   delay(3000);
   lcd.clear();
   return -1;
 }


  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("  PARMAK IZI #"); lcd.print(finger.fingerID); 
  lcd.setCursor(0,1);
  lcd.print("GUVENLIKORANI"); lcd.print(finger.confidence);
  delay(2500);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("      KAPI ");
  lcd.setCursor(0,1);
  lcd.print("    ACILIYOR "); 
  delay(2000);
  digitalWrite(12, HIGH);
  delay(20);
  digitalWrite(7, LOW);
  delay(20);
  digitalWrite(6,HIGH);
  delay(600);
  digitalWrite(6,LOW);
  delay(20);
  digitalWrite(8, HIGH);
  delay(1700);
  digitalWrite(8, LOW);
  delay(1000);
  sg90.write(180);
  delay(5000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("      KAPI ");
  lcd.setCursor(0,1);
  lcd.print("   KAPATILIYOR");
  delay(2000);
  sg90.write(0);
  delay(2000);
  digitalWrite(12, LOW);
  digitalWrite(6,HIGH);
  delay(500);
  digitalWrite(6,LOW);
  delay(20);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("  PARMAK IZI");
  lcd.setCursor(0,1);
  lcd.print("  BEKLENIYOR...");
return finger.fingerID; 
}
