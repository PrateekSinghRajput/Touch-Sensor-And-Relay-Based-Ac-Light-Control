
//Prateek
//www.justdoelectronics.com

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

int touchPin = 2;
int relayPin = 3;

int val = 0;
int lightON = 0;
int touched = 0;

void setup() {
  lcd.begin(16, 2);
  lcd.print(" Touch Based");
  lcd.setCursor(0, 1);
  lcd.print("Door Lock System");
  Serial.begin(9600);
  pinMode(touchPin, INPUT);
  pinMode(relayPin, OUTPUT);
}

void loop() {

  val = digitalRead(touchPin);

  if (val == HIGH && lightON == LOW) {

    touched = 1 - touched;
    delay(100);
  }

  lightON = val;

  if (touched == HIGH) {
    Serial.println("Light ON");
    lcd.clear();
    lcd.print("Status:  OFF");
    lcd.setCursor(0, 1);
    lcd.print("Touch to ON");
    digitalWrite(relayPin, LOW);

  } else {
    Serial.println("Light OFF");
    lcd.clear();
    lcd.print("Status:  ON");
    lcd.setCursor(0, 1);
    lcd.print("Touch to OFF");
    digitalWrite(relayPin, HIGH);
  }

  delay(100);
}
