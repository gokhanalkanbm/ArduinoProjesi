#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
int lm35Pin = A8;
int mq4 = A9;
int ldrPin = A10;
int ldrPin2 = A11;
int sicaklikArttir = 30 ;
int sicaklikAzalt = 31;
int gazAc = 32;
int gazKapat = 33 ;
int oda_1_Ac = 34 ;
int oda_1_Kapat = 35;
int oda_2_Ac = 36 ;
int oda_2_Kapat = 37;
void setup() 
{
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  Serial.begin(9600);
  pinMode(sicaklikArttir,OUTPUT); 
  pinMode(sicaklikAzalt,OUTPUT);
  pinMode(gazAc,OUTPUT);
  pinMode(gazKapat,OUTPUT);
  pinMode(oda_1_Ac,OUTPUT);
  pinMode(oda_1_Kapat,OUTPUT);
  pinMode(oda_2_Ac,OUTPUT);
  pinMode(oda_2_Kapat,OUTPUT); 
  digitalWrite(gazAc,HIGH);
  digitalWrite(oda_1_Kapat,HIGH);
  digitalWrite(oda_2_Kapat,HIGH); 
  Serial2.begin(9600);
}
 
void loop() {
  if(Serial.available()>0)
  {
    String gelen_veri = Serial.readString();
    //lcd.print(gelen_veri);
    if(gelen_veri=="g-open")
    {
      lcd.setCursor(0,0);
      lcd.print("gaz acik");  
      delay(1000);
      lcd.clear();
      digitalWrite(gazAc,HIGH);
      digitalWrite(gazKapat,LOW);
    }   
    else if(gelen_veri=="g-close")
    { 
      lcd.setCursor(0,0);
      lcd.print("gaz kapali");  
      delay(1000);
      lcd.clear();
      digitalWrite(gazAc,LOW);
      digitalWrite(gazKapat,HIGH);
    }
    else if(gelen_veri.substring(0,6)=="arttir")
    { 
      lcd.setCursor(0,0);
      gelen_veri.remove(0,7);
      lcd.print(gelen_veri);
      lcd.print("C arttir");
      delay(1000);
      lcd.clear();
      for (int i =1 ;i<=(gelen_veri).toInt();i++)
      {
        digitalWrite(sicaklikArttir,HIGH);
        delay(500);
        digitalWrite(sicaklikArttir,LOW);
        delay(500);
      }
    }
    else if(gelen_veri.substring(0,5)=="azalt")
    { 
      lcd.setCursor(0,0);
      gelen_veri.remove(0,6);
      lcd.print(gelen_veri);
      lcd.print("C azalt");  
      delay(1000);
      lcd.clear();
      for (int i =1 ;i<=(gelen_veri).toInt();i++)
      {
        digitalWrite(sicaklikAzalt,HIGH);
        delay(500);
        digitalWrite(sicaklikAzalt,LOW);
        delay(500);
      }
    }
     else if(gelen_veri.substring(0,4)=="oda1")
    { 
      lcd.setCursor(0,0);
      gelen_veri.remove(0,5);
      if(gelen_veri =="1")
      {
        lcd.print("Oda1 acik");
        digitalWrite(oda_1_Ac,HIGH); 
        digitalWrite(oda_1_Kapat,LOW);
      }
      else if (gelen_veri=="0")
      {
        lcd.print("oda1kapali") ;
        digitalWrite(oda_1_Ac,LOW); 
        digitalWrite(oda_1_Kapat,HIGH);
      }  
      delay(1000);
      lcd.clear();
    }
    else if(gelen_veri.substring(0,4)=="oda2")
    { 
      lcd.setCursor(0,0);
      gelen_veri.remove(0,5);if(gelen_veri =="1")
      {
        lcd.print("Oda2 acik");
        digitalWrite(oda_2_Ac,HIGH); 
        digitalWrite(oda_2_Kapat,LOW);
      }
      else if (gelen_veri=="0")
      {
        lcd.print("oda2kapali");
        digitalWrite(oda_2_Ac,LOW); 
        digitalWrite(oda_2_Kapat,HIGH);
      }  
      delay(1000);
      lcd.clear();
    }
  } if(Serial2.available()>0)
  {
    String gelen_veri = Serial2.readString();
    //lcd.print(gelen_veri);
    if(gelen_veri=="gopen")
    {
      lcd.setCursor(0,0);
      lcd.print("gaz acik");  
      delay(1000);
      lcd.clear();
      digitalWrite(gazAc,HIGH);
      digitalWrite(gazKapat,LOW);
    }   
    else if(gelen_veri=="gclose")
    { 
      lcd.setCursor(0,0);
      lcd.print("gaz kapali");  
      delay(1000);
      lcd.clear();
      digitalWrite(gazAc,LOW);
      digitalWrite(gazKapat,HIGH);
    }
    else if(gelen_veri.substring(0,6)=="arttir")
    { 
      lcd.setCursor(0,0);
      gelen_veri.remove(0,6);
      lcd.print(gelen_veri);
      lcd.print("C arttir");
      delay(1000);
      lcd.clear();
      for (int i =1 ;i<=(gelen_veri).toInt();i++)
      {
        digitalWrite(sicaklikArttir,HIGH);
        delay(500);
        digitalWrite(sicaklikArttir,LOW);
        delay(500);
      }
    }
    else if(gelen_veri.substring(0,5)=="azalt")
    { 
      lcd.setCursor(0,0);
      gelen_veri.remove(0,5);
      lcd.print(gelen_veri);
      lcd.print("C azalt");  
      delay(1000);
      lcd.clear();
      for (int i =1 ;i<=(gelen_veri).toInt();i++)
      {
        digitalWrite(sicaklikAzalt,HIGH);
        delay(500);
        digitalWrite(sicaklikAzalt,LOW);
        delay(500);
      }
    }
     else if(gelen_veri.substring(0,4)=="oda1")
    { 
      lcd.setCursor(0,0);
      gelen_veri.remove(0,4);
      if(gelen_veri =="1")
      {
        lcd.print("Oda1 acik");
        digitalWrite(oda_1_Ac,HIGH); 
        digitalWrite(oda_1_Kapat,LOW);
      }
      else if (gelen_veri=="0")
      {
        lcd.print("oda1kapali") ;
        digitalWrite(oda_1_Ac,LOW); 
        digitalWrite(oda_1_Kapat,HIGH);
      }  
      delay(1000);
      lcd.clear();
    }
    else if(gelen_veri.substring(0,4)=="oda2")
    { 
      lcd.setCursor(0,0);
      gelen_veri.remove(0,4);if(gelen_veri =="1")
      {
        lcd.print("Oda2 acik");
        digitalWrite(oda_2_Ac,HIGH); 
        digitalWrite(oda_2_Kapat,LOW);
      }
      else if (gelen_veri=="0")
      {
        lcd.print("oda2kapali");
        digitalWrite(oda_2_Ac,LOW); 
        digitalWrite(oda_2_Kapat,HIGH);
      }  
      delay(1000);
      lcd.clear();
    }
  }
  sicaklikOlc();
  Serial.println("-");
  gazOlc();
  Serial.println("-");
  ldrOlc1();
  Serial.println("-");
  ldrOlc2();
  Serial.println("-");
  delay(1000);
}
void sicaklikOlc()
{
  int sicaklikVolt = analogRead(lm35Pin);
  int sicaklikC = sicaklikVolt / 9.31;
  lcd.setCursor(0,1);
  lcd.print("s:");
  lcd.print(sicaklikC);
  Serial.println(sicaklikC);
  Serial2.println("sicaklik=");
  Serial2.println(sicaklikC);
}
void gazOlc()
{
  int sensorValue = analogRead(mq4);
  lcd.setCursor(4,1);
  lcd.print("g:");
  lcd.print(sensorValue);
  Serial.println(sensorValue);
  Serial2.println("gaz="); 
  Serial2.println(sensorValue);
}
void ldrOlc1()
{
    int ldrDeger = analogRead(ldrPin);
    lcd.setCursor(10,0);
    lcd.print("o1:");
    lcd.print(ldrDeger);
    Serial.println(ldrDeger);
    Serial2.println("Oda1=");
    Serial2.println(ldrDeger);
    
}void ldrOlc2()
{
    int ldrDeger = analogRead(ldrPin2);
    lcd.setCursor(10,1);
    lcd.print("o2:");
    lcd.print(ldrDeger);
    Serial.println(ldrDeger);
    Serial2.println("Oda2=");
    Serial2.println(ldrDeger);
    
}

