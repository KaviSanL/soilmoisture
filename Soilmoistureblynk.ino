/*Smart Plant Watering System With New BLYNK 
@SayanElectronics */

//include libraries
#define BLYNK_TEMPLATE_ID "TMPL3pmld2bg9"
#define BLYNK_TEMPLATE_NAME "Soil"
#define BLYNK_AUTH_TOKEN "iJ0hY3a8T1EAm7IZd3Mo9T-wTvQwnsAo"
//#include <LiquidCrystal_I2C.h>
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

//Initialize the LCD display
//LiquidCrystal_I2C lcd(0x27, 16, 2);

char auth[] = BLYNK_AUTH_TOKEN;//Enter your Auth token
char ssid[] = "WiFi SSID";//Enter your WIFI name
char pass[] = "WiFi Password";//Enter your WIFI password

BlynkTimer timer;
//bool Relay = 0;

//Define component pins
#define sensor A0
//#define waterPump D3

void setup() {
  Serial.begin(9600);
  //pinMode(waterPump, OUTPUT);
  //digitalWrite(waterPump, HIGH);
  //lcd.init();
  //lcd.backlight();

  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);

  //lcd.setCursor(1, 0);
  //lcd.print("System Loading");
  /*for (int a = 0; a <= 15; a++) {
    lcd.setCursor(a, 1);
    lcd.print(".");
    delay(500);
  }
  lcd.clear();
*/
  //Call the function
  timer.setInterval(100L, soilMoistureSensor);
}

//Get the button value
/*BLYNK_WRITE(V1) {
  Relay = param.asInt();

  if (Relay == 1) {
    digitalWrite(waterPump, LOW);
    lcd.setCursor(0, 1);
    lcd.print("Motor is ON ");
  } else {
    digitalWrite(waterPump, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("Motor is OFF");
  }
}
*/
//Get the soil moisture values
void soilMoistureSensor() {
  int value = analogRead(sensor);
  value = map(value, 0, 1024, 0, 100);
  value = (value - 100) * -1;

  Blynk.virtualWrite(V0, value);
 // lcd.setCursor(0, 0);
 // lcd.print("Moisture :");
  //lcd.print(value);
  //lcd.print(" ");

}

void loop() {
  Blynk.run();//Run the Blynk library
  timer.run();//Run the Blynk timer
}
