#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

SoftwareSerial mySerial(10, 11);
DFRobotDFPlayerMini player;

#define SW1 2
#define SW2 3
#define SW3 4
#define SW4 5

bool lastState1 = HIGH;
bool lastState2 = HIGH;
bool lastState3 = HIGH;
bool lastState4 = HIGH;

void setup() {

  Serial.begin(9600);
  mySerial.begin(9600);

  pinMode(SW1, INPUT_PULLUP);
  pinMode(SW2, INPUT_PULLUP);
  pinMode(SW3, INPUT_PULLUP);
  pinMode(SW4, INPUT_PULLUP);

  if (!player.begin(mySerial)) {
    Serial.println("DFPlayer not found");
    while (true);
  }

  delay(1000);
  player.volume(30);

  Serial.println("System Ready");
}

void loop() {

  bool currentState1 = digitalRead(SW1);
  bool currentState2 = digitalRead(SW2);
  bool currentState3 = digitalRead(SW3);
  bool currentState4 = digitalRead(SW4);

  if (lastState1 == HIGH && currentState1 == LOW) {
    Serial.println("Playing 1");
    player.play(1);
  }

  if (lastState2 == HIGH && currentState2 == LOW) {
    Serial.println("Playing 2");
    player.play(2);
  }

  if (lastState3 == HIGH && currentState3 == LOW) {
    Serial.println("Playing 3");
    player.play(3);
  }

  if (lastState4 == HIGH && currentState4 == LOW) {
    Serial.println("Playing 4");
    player.play(4);
  }

  lastState1 = currentState1;
  lastState2 = currentState2;
  lastState3 = currentState3;
  lastState4 = currentState4;
}
