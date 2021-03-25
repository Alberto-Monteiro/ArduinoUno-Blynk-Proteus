#include <BlynkSimpleStream.h>
#include <SoftwareSerial.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_I2CDevice.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET 4     // Reset pin # (or -1 if sharing Arduino reset pin)
#define NUMFLAKES 10     // Number of snowflakes in the animation example
#define LOGO_HEIGHT 16
#define LOGO_WIDTH 16
#define XPOS 0 // Indexes into the 'icons' array in function below
#define YPOS 1
#define DELTAY 2

SoftwareSerial SwSerial(2, 3); // RX, TX
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

char auth[] = "";

static const unsigned char PROGMEM logo_bmp[] = //https://marlinfw.org/tools/u8glib/converter.html
    {B00000000, B11000000,
     B00000001, B11000000,
     B00000001, B11000000,
     B00000011, B11100000,
     B11110011, B11100000,
     B11111110, B11111000,
     B01111110, B11111111,
     B00110011, B10011111,
     B00011111, B11111100,
     B00001101, B01110000,
     B00011011, B10100000,
     B00111111, B11100000,
     B00111111, B11110000,
     B01111100, B11110000,
     B01110000, B01110000,
     B00000000, B00110000};
void testDisplay();

#include "RTClib.h"
RTC_DS1307 rtc;
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

BLYNK_WRITE(V1)
{
    SwSerial.println("V1 Slider value is: ");
    SwSerial.println(param.asInt());
}

BLYNK_WRITE(V2)
{
    digitalWrite(8, param.asInt());
    SwSerial.println("LED 8.");
    if (param.asInt())
        testDisplay();
}

BLYNK_WRITE(V3)
{
    digitalWrite(9, param.asInt());
    SwSerial.println("LED 9.");
}

BLYNK_WRITE(V4)
{
    digitalWrite(10, param.asInt());
    SwSerial.println("LED 10.");
}

BLYNK_CONNECTED()
{
    Blynk.syncAll();
}

void setup()
{
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);

    SwSerial.begin(9600);
    Serial.begin(9600);

    Blynk.begin(Serial, auth);

    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3D))
    {
        SwSerial.println(F("SSD1306 allocation failed"));
        for (;;)
            ;
    }

    if (!rtc.begin())
    {
        SwSerial.println("Couldn't find RTC");
        SwSerial.flush();
        abort();
    }
    if (!rtc.isrunning())
    {
        SwSerial.println("RTC is NOT running, let's set the time!");
        rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    }
}

void loop()
{
    Blynk.run();
}

void testDisplay()
{
    DateTime now = rtc.now();
    char buffer[30] = "";
    sprintf(buffer, "%02d/%02d/%04d %02d:%02d:%02d", now.day(), now.month(), now.year(), now.hour(), now.minute(), now.second());
    SwSerial.print(buffer);
    SwSerial.println();

    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.setTextColor(SSD1306_WHITE);
    display.write(buffer);
    display.display();
}