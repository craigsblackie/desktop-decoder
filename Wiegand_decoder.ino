#include <Wire.h>
#include <Wiegand.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// These are the pins connected to the Wiegand D0 and D1 signals.
// Ensure your board supports external Interruptions on these pins
#define PIN_D0 2
#define PIN_D1 3

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// The object that handles the wiegand protocol
Wiegand wiegand;

String numCard = "";

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(115200);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  // Show initial display buffer contents on the screen --  
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  // Booting Reader Screen
  display.setCursor(00,00);
  //display.display();
  display.println("   Reader Booting");
  display.display();
  delay(9000);
  display.clearDisplay();
   //Install listeners and initialize Wiegand reader
  wiegand.onReceive(receivedData, "Card read: ");
  wiegand.onReceiveError(receivedDataError, "Card read error: ");
  wiegand.begin(Wiegand::LENGTH_ANY, false);
  
  //initialize pins as INPUT and attaches interruptions
  pinMode(PIN_D0, INPUT);
  pinMode(PIN_D1, INPUT);
  attachInterrupt(digitalPinToInterrupt(PIN_D0), pinStateChanged, CHANGE);
  attachInterrupt(digitalPinToInterrupt(PIN_D1), pinStateChanged, CHANGE);

  //Sends the initial pin state to the Wiegand library
  pinStateChanged();

}

// When any of the pins have changed, update the state of the wiegand library
void pinStateChanged() {
  wiegand.setPin0State(digitalRead(PIN_D0));
  wiegand.setPin1State(digitalRead(PIN_D1));
}

// Notifies when a card was read.
// Instead of a message, the seconds parameter can be anything you want -- Whatever you specify on `wiegand.onReceive()`
void receivedData(uint8_t* data, uint8_t bits, const char* message) {
    //Serial.print(message);
    Serial.print(bits);
    Serial.print("bits / ");
    display.clearDisplay();
    display.setCursor(00,50);
    //Print value in HEX
    uint8_t bytes = (bits+7)/8;
    for (int i=0; i<bytes; i++) {
        Serial.print(data[i] >> 4, 16);
        Serial.print(data[i] & 0xF, 16);
        display.print(data[i] >> 4, 16);
        display.print(data[i] & 0xF, 16);
    }
    display.setCursor(00,30);
    //Print number of bits
    display.print(bits);
    Serial.println();
}

// Notifies when an invalid transmission is detected
void receivedDataError(Wiegand::DataError error, uint8_t* rawData, uint8_t rawBits, const char* message) {
    //Serial.print(message);
    //Serial.print(Wiegand::DataErrorStr(error));
    Serial.print(" Raw data: ");
    Serial.print(rawBits);
    Serial.print("bits / ");
    display.clearDisplay();
    display.setCursor(00,50);
    //Print value in HEX
    uint8_t bytes = (rawBits+7)/8;
    for (int i=0; i<bytes; i++) {
        Serial.print(rawData[i] >> 4, 16);
        Serial.print(rawData[i] & 0xF, 16);
        display.print(rawData[i] >> 4, 16);
        display.print(rawData[i] & 0xF, 16);
    }
    display.setCursor(00,30);
    //Print number of bits
    display.print(rawBits);
    Serial.println();
}

void outputOLED(String displayMessage){
// Display static text
    display.println(displayMessage);
}

void titleBar() {
// Title bar disaplay
  display.setCursor(00,00);
  //display.display();
  display.println("Wiegand Decoder");
  display.display();
}

// Every few milliseconds, check for pending messages on the wiegand reader
// This executes with interruptions disabled, since the Wiegand library is not thread-safe
void loop() {
  noInterrupts();
  wiegand.flush();
  interrupts();
  //Sleep a little -- this doesn't have to run very often.
  delay(100);
  titleBar();
  display.setCursor(0,20);
  //display.display();
  outputOLED("Bit Length:");
  display.setCursor(0,40);
  display.display();
  outputOLED("HEX Value:");
}
