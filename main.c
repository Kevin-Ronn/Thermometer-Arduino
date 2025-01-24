#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define RGB_RED 9
#define RGB_GREEN 10
#define RGB_BLUE 11

void setup() {
  // Initiera LCD
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Starting...");

  // Initiera RGB LED
  pinMode(RGB_RED, OUTPUT);
  pinMode(RGB_GREEN, OUTPUT);
  pinMode(RGB_BLUE, OUTPUT);
}

void loop() {
  // Simulerad data från "API"
  String apiData[] = {
    "Temp: 18C",
    "Temp: 25C",
    "Temp: 30C",
    "Temp: 5C",
    "Temp: 12C"
  };

  // Loopa genom simulerad data
  for (int i = 0; i < 5; i++) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("API Response:");
    lcd.setCursor(0, 1);
    lcd.print(apiData[i]);

    // Styr RGB LED baserat på temperaturen i datan
    int temp = extractTemp(apiData[i]);
    if (temp < 10) {
      setColor(0, 0, 255); // Blå för kallt
    } else if (temp <= 25) {
      setColor(0, 255, 0); // Grön för behagligt
    } else {
      setColor(255, 0, 0); // Röd för varmt
    }

    delay(3000); // 3 sekunder innan nästa "API-anrop"
  }
}

int extractTemp(String data) {
  // Ta värdet från "API-svaret"
  int tempIndex = data.indexOf("Temp: ");
  if (tempIndex != -1) {
    String tempString = data.substring(tempIndex + 6, data.indexOf("C"));
    return tempString.toInt();
  }
  return 0; 
}

void setColor(int red, int green, int blue) {
  analogWrite(RGB_RED, red);
  analogWrite(RGB_GREEN, green);
  analogWrite(RGB_BLUE, blue);
}
