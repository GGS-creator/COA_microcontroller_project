

#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// to make some custom characters:
byte globe[8] = {
  0b00100,
  0b01110,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00100
};

byte smiley[8] = {
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b10001,
  0b01110,
  0b00000
};

byte frownie[8] = {
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b00000,
  0b01110,
  0b10001
};

byte armsDown[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b00100,
  0b01110,
  0b10101,
  0b00100,
  0b01010
};

byte armsUp[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b10100,
  0b01110,
  0b00101,
  0b00100,
  0b01010
};

void setup() {
  // this initialize LCD and set up the number of columns and rows:
  lcd.begin(16, 2);

  // create a new character
  lcd.createChar(0, globe);
  lcd.createChar(1, smiley);
  lcd.createChar(2, frownie);
  lcd.createChar(3, armsDown);
  lcd.createChar(4, armsUp);

  // set the cursor to the top left
  lcd.setCursor(0, 0);

  // Print a message to the lcd.
  lcd.print("Hello "); // when calling lcd.write() '0' must be cast as a byte
  lcd.print(" World ");
  lcd.write(byte(0));
  lcd.write((byte)1);

}

void loop() {
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  int x=0;
  x=millis()/1000;
  lcd.print("T:");
  lcd.print(x);
  // read the potentiometer on A0:
  int sensorReading = analogRead(A0);
  // map the result to 200 - 1000:
  int delayTime = map(sensorReading, 0, 1023, 200, 1000);
  // set the cursor to the bottom row, 5th position:
  lcd.setCursor(6, 1);
  // draw the little man, arms down:
  lcd.write(3);
  delay(delayTime);
  lcd.setCursor(6, 1);
  // draw him arms up:
  lcd.write(4);
  delay(delayTime);
  lcd.setCursor(10,1);
  delay(500);
  lcd.write((byte)2);
  delay(500);
  lcd.print("->");
  delay(500);
  lcd.write((byte)1);
}
