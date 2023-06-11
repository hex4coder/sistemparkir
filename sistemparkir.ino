const unsigned int TRIG_PIN = 9;
const unsigned int ECHO_PIN = 10;
const unsigned int BUZZER_PIN = 13;
const unsigned int BAUD_RATE = 9600;

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(BAUD_RATE);
}

void beep(int distance) {
  digitalWrite(BUZZER_PIN, HIGH);
  delay(10 * distance);
  digitalWrite(BUZZER_PIN, LOW);
  delay(5 * distance);
}

void loop() {

  digitalWrite(BUZZER_PIN, LOW);

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);


  const unsigned long duration = pulseIn(ECHO_PIN, HIGH);
  int distance = duration / 29 / 2;
  if (duration == 0) {
    Serial.println("Warning: no pulse from sensor");
  } else {
    Serial.print("distance to nearest object:");
    Serial.println(distance);
    Serial.println(" cm");
  }
  

  if(distance <= 20) {
    beep(distance);
  } else {
    digitalWrite(BUZZER_PIN, LOW);
  }
}