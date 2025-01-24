# Thermometer-Arduino

note* Har skapat mitt mini-projekt i TinkerCAD som ej stödjer wifi-modul(ESP8266, esp32) eller nätverksstöd. Valde därför att simulera en API i min kod istället samt skriva en kod utan simulering.

Rapport

Simulerad Temperaturmätare med LCD och RGB LED i Tinkercad

Beskrivning:
I detta projekt har jag skapat en temperaturmätare som använder en simulerad API för att hämta och visa temperaturvärden på en LCD-skärm. Projektet innefattar en Arduino Uno, en LCD 16x2 för visning av temperatur, och en RGB LED som ändrar färg beroende på temperaturens värde. Huvudsyftet är att simulera ett system där temperaturdata hämtas från en API och använder det för att styra en enhet, i detta fall en LCD och RGB LED. Eftersom Tinkercad inte kan koppla till externa API:er för att hämta data, valde jag att härma detta genom att använda hårdkodade temperaturvärden och skapa en logik som skulle kunna efterlikna scenariot uppgiften sökte.

Komponenter och deras funktioner
- Arduino Uno R3: Styr systemet.
- LCD 16x2 Display: En LCD-skärm för att visa data. Den ansluts till Arduino via digitala pinnar och nyttjar en potentiometer för att justera kontrasten.

- RGB LED: Används för att visa temperaturen visuellt . LED:n byter färg beroende på den simulerade temperaturdatan:
  - Blå om temperaturen är under 10°C (kallt).
  - Grön om temperaturen är mellan 10°C och 25°C (behaglig temperatur).
  - Röd om temperaturen är över 25°C (varmt).
- Potentiometer: För att justera LCD:ns kontrast.

  
Funktioner
Projektet är uppbyggt så att det simulerar en temperaturavläsning. I koden definieras en array apiData[] med kodade temperaturvärden, som systemet "hämtar" för att sedan visa på LCD-skärmen. LCD:n visar både ett meddelande om att data har hämtats från en API-källa och själva svaret den fick. Vid varje temperaturavläsning kontrolleras värdet och RGB LED:n ändrar färg enligt följande logik:
- Om temperaturen är under 10°C sätts RGB LED:n till blått för att indikera kallt.
- Om temperaturen är mellan 10°C och 25°C sätts RGB LED:n till grönt för att indikera en behaglig temperatur.
- Om temperaturen är över 25°C sätts RGB LED:n till rött för att indikera värme.

Varje temperatur visas på LCD:n i 3 sekunder innan nästa hämtas. 

Motiv
Jag valde att skapa en temperaturmätare med en RGB LED som visuellt indikerar temperaturförändringar för att göra det både informativt och visuellt tilltalande. Eftersom Tinkercad inte stödjer API-åtkomst eller Wi-Fi-kommunikation valde jag att använda simulerad temperaturdata, vilket ändå gör det möjligt att testa och demonstrera grundläggande logik och hårdvara i en "verklig" miljö.
