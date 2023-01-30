#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define ONE_WIRE_BUS 2


OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup(void)
{
  sensors.begin();
  Serial.begin(9600);

  lcd.init();

  lcd.backlight();
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("SniperPig");
}

void loop(void)
{
  sensors.requestTemperatures();

  Serial.print("Temperature: ");
  Serial.print(sensors.getTempCByIndex(0));
  Serial.print((char)176);
  Serial.println("C | ");

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("C: ");
  lcd.print(sensors.getTempCByIndex(0));

  lcd.setCursor(0,1);
  lcd.print("F: ");
  lcd.print((sensors.getTempCByIndex(0) * 9.0) / 5.0 + 32.0);
  
  Serial.print((sensors.getTempCByIndex(0) * 9.0) / 5.0 + 32.0);
  Serial.print((char)176);//shows degrees character
  Serial.println("F");

  delay(500);
}
