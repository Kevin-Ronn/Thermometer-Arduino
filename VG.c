#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <WiFi.h>           
#include <HTTPClient.h>

// WiFi-inställningar
const char* ssid = "WiFi_Namn";          // WiFi-nätverk
const char* password = "WiFi_Lösenord";  // WiFi-lösen

// API-inställningar
const char* apiEndpoint = "http://worldtimeapi.org/api/timezone/Europe/Stockholm";

// Initiera LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define RGB_RED 9
#define RGB_GREEN 10
#define RGB_BLUE 11

void setup() {
  // Starta LCD
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Connecting...");

  // Starta WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    lcd.setCursor(0, 1);
    lcd.print(".");
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("WiFi connected");
  delay(1000);
}

void loop() {
  // Kontrollera WiFi-status
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;

    // Begäran till API:et
    http.begin(apiEndpoint);
    int httpCode = http.GET();

    if (httpCode > 0) {
      String payload = http.getString();

      // Visa datan på LCD (datum/tid från API:et)
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Data:");
      lcd.setCursor(0, 1);

      // Begränsa text för LCD:n
      if (payload.length() > 16) {
        lcd.print(payload.substring(0, 16));
      } else {
        lcd.print(payload);
      }

      // Indikera att allt är som det ska
      setColor(0, 255, 0); // Grön
    } else {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Error: ");
      lcd.setCursor(0, 1);
      lcd.print(httpCode);

      // Indikera fel
      setColor(255, 0, 0); // Röd
    }

    http.end();
  } else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("WiFi Lost!");
    setColor(255, 255, 0); // Gul
  }

  delay(10000); // Uppdatera var 10:e sekund
}

void setColor(int red, int green, int blue) {
  analogWrite(RGB_RED, red);
  analogWrite(RGB_GREEN, green);
  analogWrite(RGB_BLUE, blue);
}
