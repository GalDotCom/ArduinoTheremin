const int trigPin = 9;
const int echoPin = 10;
const int buzzerPin = 11;

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Clear the trigPin by setting it LOW:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(1);
  
  // Trigger the sensor by setting the trigPin HIGH for 10 microseconds:
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);

  // Read the echoPin and calculate the distance:
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  // Convert distance to frequen  cy (the closer the object, the higher the frequency):
  int frequency = map(distance, 0, 25, 4000, 100);

  // Ensure frequency is within a valid range:
  frequency = constrain(frequency, 100, 4000);

  // Generate sound on the buzzer:
  if (distance <= 25) {
    tone(buzzerPin, frequency);
  } else {
    noTone(buzzerPin);
  }

  // Print the distance for debugging:
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(100);
}
