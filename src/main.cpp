#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
const int pinSensor = A1; //declared sensor pin
const int pinLED = 6; //declared pin buat Lampu
int upButton = 12;
int downButton = 11;
int selectButton = 10;
int menu = 1;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  digitalWrite(pinLED, HIGH);
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  pinMode(pinSensor, INPUT);
  pinMode(pinLED, OUTPUT);
  pinMode(upButton, INPUT_PULLUP);
  pinMode(downButton, INPUT_PULLUP);
  pinMode(selectButton, INPUT_PULLUP);
  updateMenu();
}

void loop() {
  if (!digitalRead(downButton)){
    menu++;
    updateMenu();
    delay(200);
    while (!digitalRead(downButton));
    //jika menekan tombol terlalu lama maka akan ditangkap dalam while loop untuk
    //mencegah skroll ke bawah
  }
  if (!digitalRead(upButton)){
    menu--;
    updateMenu();
    delay(200);
    while(!digitalRead(upButton));
  }
  if (!digitalRead(selectButton)){
    executeAction();
    updateMenu();
    delay(200);
    while (!digitalRead(selectButton));
  }
}

void updateMenu() {
  switch (menu) {
    case 0:
      menu = 4;
      updateMenu();
      break;
    case 1:
      lcd.clear();
      lcd.print(">1.Taman");
      lcd.setCursor(0, 1);
      lcd.print(" 2.Teras");
      break;
    case 2:
      lcd.clear();
      lcd.print(" 1.Taman");
      lcd.setCursor(0, 1);
      lcd.print(">2.Teras");
      break;
    case 3:
      lcd.clear();
      lcd.print(">3.Balkon");
      lcd.setCursor(0, 1);
      lcd.print(" 4.Kamar Tidur");
      break;
    case 4:
      lcd.clear();
      lcd.print(" 3.Balkon");
      lcd.setCursor(0, 1);
      lcd.print(">4.Kamar Tidur");
      break;
    case 5:
      menu = 1;
      updateMenu();
      break;
  }
}

void executeAction() {
  switch (menu) {
    case 1:
      action1();
      break;
    case 2:
      action2();
      break;
    case 3:
      action3();
      break;
    case 4:
      action4();
      break;
  }
}

void action1() {
  while(1){
      delay(400);
      int lux_ruangan = analogRead(pinSensor);
      //kondisi terang
      if(lux_ruangan >= 150){
        digitalWrite(pinLED, HIGH); //pake 'HIGH' lampu mati karena SSRnya active low
        Serial.println(lux_ruangan);
        Serial.println("Mati");
        lcd.clear();
        lcd.print("Mode:Taman");
        lcd.setCursor(0, 1);
        lcd.print("Status:Mati");
        lcd.setCursor(13, 0);
        lcd.print(lux_ruangan);
        }
      //kondisi gelap
      else if(lux_ruangan < 150) {
        digitalWrite(pinLED, LOW); //pake 'LOW' lampu hidup karena SSRnya active low
        Serial.println(lux_ruangan);
        Serial.println("Nyala");
        lcd.clear();
        lcd.print("Mode:Taman");
        lcd.setCursor(0, 1);
        lcd.print("Status:Nyala");
        lcd.setCursor(13, 0);
        lcd.print(lux_ruangan);
        }  
  }
}
void action2() {
  while(1){
      delay(400);
      int lux_ruangan = analogRead(pinSensor);
      //kondisi terang
      if(lux_ruangan >= 100){
        digitalWrite(pinLED, HIGH); //pake 'HIGH' lampu mati karena SSRnya active low
        Serial.println(lux_ruangan);
        Serial.println("Mati");
        lcd.clear();
        lcd.print("Mode:Teras");
        lcd.setCursor(0, 1);
        lcd.print("Status:Mati");
        lcd.setCursor(13, 0);
        lcd.print(lux_ruangan);
        }
      //kondisi gelap
      else if(lux_ruangan < 100) {
        digitalWrite(pinLED, LOW); //pake 'LOW' lampu hidup karena SSRnya active low
        Serial.println(lux_ruangan);
        Serial.println("Nyala");
        lcd.clear();
        lcd.print("Mode:Teras");
        lcd.setCursor(0, 1);
        lcd.print("Status:Nyala");
        lcd.setCursor(13, 0);
        lcd.print(lux_ruangan);
        }  
  }
}
void action3() {
  while(1){
      delay(400);
      int lux_ruangan = analogRead(pinSensor);
      //kondisi terang
      if(lux_ruangan >= 80){
        digitalWrite(pinLED, HIGH); //pake 'HIGH' lampu mati karena SSRnya active low
        Serial.println(lux_ruangan);
        Serial.println("Mati");
        lcd.clear();
        lcd.print("Mode:Balkon");
        lcd.setCursor(0, 1);
        lcd.print("Status:Mati");
        lcd.setCursor(13, 0);
        lcd.print(lux_ruangan);
        }
      //kondisi gelap
      else if(lux_ruangan < 80) {
        digitalWrite(pinLED, LOW); //pake 'LOW' lampu hidup karena SSRnya active low
        Serial.println(lux_ruangan);
        Serial.println("Nyala");
        lcd.clear();
        lcd.print("Mode:Balkon");
        lcd.setCursor(0, 1);
        lcd.print("Status:Nyala");
        lcd.setCursor(13, 0);
        lcd.print(lux_ruangan);
        }  
  }
}
void action4() {
  while(1){
      delay(400);
      int lux_ruangan = analogRead(pinSensor);
      //kondisi terang
      if(lux_ruangan >= 30){
        digitalWrite(pinLED, HIGH); //pake 'HIGH' lampu mati karena SSRnya active low
        Serial.println(lux_ruangan);
        Serial.println("Mati");
        lcd.clear();
        lcd.print("Mode:Kamar Tidur");
        lcd.setCursor(0, 1);
        lcd.print("Status:Mati");
        lcd.setCursor(13, 1);
        lcd.print(lux_ruangan);
        }
      //kondisi gelap
      else if(lux_ruangan < 30) {
        digitalWrite(pinLED, LOW); //pake 'LOW' lampu hidup karena SSRnya active low
        Serial.println(lux_ruangan);
        Serial.println("Nyala");
        lcd.clear();
        lcd.print("Mode:Kamar Tidur");
        lcd.setCursor(0, 1);
        lcd.print("Status:Nyala");
        lcd.setCursor(13, 1);
        lcd.print(lux_ruangan);
        }  
  }
}