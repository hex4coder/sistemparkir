const unsigned int TRIG_PIN = 9; // pin untuk trigger pada sensor ultrasonic
const unsigned int ECHO_PIN = 10;// pin untuk echo pada sensor ultrasonic
const unsigned int BUZZER_PIN = 13;// pin untuk buzzer pada pin digital nomor 13 (terhubung ke led)
const unsigned int BAUD_RATE = 9600;


// kode yang dipanggil ketika baru menyala
void setup() {
  // inisialisasi sensor ultrasonic
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  // inisialisasi buzzer
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(BAUD_RATE);
  digitalWrite(BUZZER_PIN, LOW);
 }

// bunyikan buzzer sesuai jarak (semakin dekat maka, semakin cepat bunyinya)
void beep(int distance) {
  digitalWrite(BUZZER_PIN, HIGH);
  delay(10 * distance);
  digitalWrite(BUZZER_PIN, LOW);
  delay(5 * distance);
}

void loop() {

  // kode untuk mendapatkan jarak
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  const unsigned long duration = pulseIn(ECHO_PIN, HIGH);
  int distance = duration / 29 / 2;
  
  // print jarak ke layar
  if (duration == 0) {
    Serial.println("Warning: no pulse from sensor");
  } else {
    Serial.print("distance to nearest object:");
    Serial.println(distance);
    Serial.println(" cm");
  }
  
  // jika jarak kurang dari atau samadengan 20cm maka bunyikan buzzer
  if(distance <= 20) {
    beep(distance);
  } else 
  // jika tidak matikan buzzer
  {
    digitalWrite(BUZZER_PIN, LOW);
  }
}
