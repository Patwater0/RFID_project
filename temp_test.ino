// Simple script for the arduino that displays a tempurature and humidity on a 12x2 lcd display using the DHT sensor

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

DHT dht(7,DHT11);

float temp = dht.readTemperature();
float humid = dht.readHumidity();

void setup() {
  // start the dht temp/humidity sensor
  dht.begin();
  
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  
  // Print a message to the LCD.
  lcd.print("Temp  | Humidity");
}

void loop() {
  // set the cursor to column 0, line 1
  lcd.setCursor(0, 1);

  // checks the temp / humidity and converts celcius to ferenheit
  temp = dht.readTemperature();
  humid = dht.readHumidity();
  temp = (temp*9/5) + 32;
  

  // print the number of seconds since reset:
  lcd.print(String(temp) + " | " + String(humid));
  
  // delay the loop 2 seconds
  delay(2000);
}
