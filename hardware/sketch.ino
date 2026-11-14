#define TRIG_PIN 5
#define ECHO_PIN 18
#define BUZZER_PIN 19

float distance;
long duration;

void setup() {
  Serial.begin(115200);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  Serial.println("FloodSense System Started");
}

void loop() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH, 30000);

  if (duration == 0) {
    Serial.println("Sensor reading error");
    delay(1000);
    return;
  }

  distance = duration * 0.0343 / 2;

  Serial.print("Water distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance < 10) {
    Serial.println("ALERT: HIGH WATER LEVEL!");
    digitalWrite(BUZZER_PIN, HIGH);
  }
  else {
    Serial.println("Water level NORMAL");
    digitalWrite(BUZZER_PIN, LOW);
  }

  delay(1000);
}
