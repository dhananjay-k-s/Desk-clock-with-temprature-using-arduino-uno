#include <DHT.h>
#include <DS3231.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ctype.h>

//Configure DHT11 Sensor
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

//Configure I2C 16x2 LCD Display
LiquidCrystal_I2C lcd(0x27, 16, 2); // Changed to 16x2

//Configure DS321 Real Time Clock
DS3231  rtc(6, 7);


void setup()
{
  //Start LCD Screen
  lcd.init(); // Initialize the LCD
  lcd.backlight(); // Turn on the backlight

  //Start Temperature Sensor
  dht.begin();

  //Start Clock
  rtc.begin();

  //The following lines can be uncommented to set the date and time
  //rtc.setDOW(SATURDAY);     // Set Day-of-Week to SUNDAY
  //rtc.setTime(22,55, 0);     // Set the time to 12:00:00 (24hr format)
  //rtc.setDate(17, 5, 2025);   // Set the date to January 1st, 2014

}
void to_upper(char *str) {
  for (int i = 0; str[i] != '\0'; i++) {
    if (islower(str[i])) {
      str[i] = toupper(str[i]);
    }
  }
}


void loop()
{
  //2 Second Delay to Allow DHT11 to Calibrate
  //delay(1000);

  //Standard LCD Print Out
  //lcd.clear();
   lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(1, 0);
  lcd.print(rtc.getTimeStr());
  lcd.setCursor(6, 0);
  lcd.print("   ");
  lcd.setCursor(11, 0);
  int tempC = (int)dht.readTemperature(); 
  lcd.print(tempC); 
  lcd.print(" C");


  lcd.setCursor(1, 1);
  char dow1[20];
  strcpy(dow1, rtc.getDOWStr()); // Copy the string
  to_upper(dow1); // Now you can pass dow1 to your function
  lcd.print(dow1); // Print the copied string
  delay(5000);

  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(1, 0);
  lcd.print(rtc.getTimeStr());
  lcd.setCursor(6, 0);
  lcd.print("   ");
  lcd.setCursor(11, 0);
  tempC = (int)dht.readTemperature(); 
  lcd.print(tempC); 
  lcd.print(" C");

  //lcd.clear();
  lcd.setCursor(1, 1);
  lcd.print(rtc.getDateStr());
   lcd.setCursor(5, 1);
  lcd.print(rtc.getDateStr());
  lcd.setCursor(3, 1);
  lcd.print(" th ");
  lcd.print(rtc.getMonthStr(FORMAT_SHORT));
  lcd.print(" ");
 
  delay (5000);
  lcd.setCursor(0, 1);
  lcd.print("                ");
  
  int u=0;
  while(u<=5){
    lcd.setCursor(1, 0);
    lcd.print(rtc.getTimeStr());
    lcd.setCursor(6, 0);
    lcd.print("   ");
    lcd.setCursor(11, 0);
    tempC = (int)dht.readTemperature(); 
    lcd.print(tempC); 
    lcd.print(" C");

    lcd.setCursor(1, 1);
    lcd.print("Time ");
    lcd.print(rtc.getTimeStr());
    u=u+1;
    delay(1000);
  }

  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(1, 0);
  lcd.print(rtc.getTimeStr());
  lcd.setCursor(6, 0);
  lcd.print("   ");
  lcd.setCursor(11, 0);
  tempC = (int)dht.readTemperature(); 
  lcd.print(tempC); 
  lcd.print(" C");

  lcd.setCursor(1, 1);
  lcd.print("TEMP ");
  lcd.print(dht.readTemperature());
  lcd.print("C");
  delay(5000);

  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(1, 0);
  lcd.print(rtc.getTimeStr());
  lcd.setCursor(6, 0);
  lcd.print("   ");
  lcd.setCursor(11, 0);
  tempC = (int)dht.readTemperature(); 
  lcd.print(tempC); 
  lcd.print(" C");

  lcd.setCursor(1, 1);
  lcd.print("HUM ");
  lcd.print(dht.readHumidity());
  lcd.print("%");
  delay(5000);


 
}