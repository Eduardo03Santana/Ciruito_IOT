// C++ code
//
int alarmOnOff = 0;

void setup()
{
  pinMode(8, INPUT);
  pinMode(10, INPUT);
  pinMode(13, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
  pinMode(2, OUTPUT);

  digitalWrite(11, HIGH);
  // opMode 0 = Security; 1 = Light
  alarmOnOff = 0;
}

void loop()
{
  if (digitalRead(8) == 0) {
    if (digitalRead(10) == 1) {
      alarmOnOff = 1;
      digitalWrite(13, HIGH);
      digitalWrite(11, LOW);
      while (alarmOnOff == 1) {
        if (digitalRead(8) == 1) {
          alarmOnOff = 0;
          digitalWrite(13, LOW);
          digitalWrite(11, HIGH);
          Serial.println(alarmOnOff);
        }
      }
    }
  } else {
    if (digitalRead(10) == 1) {
      digitalWrite(2, HIGH);
      delay(15000); // Wait for 15000 millisecond(s)
      digitalWrite(2, LOW);
    }
  }
}