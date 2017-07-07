
/**
* HC-SR04
* Ultrasonic sensor
* Speed of sound:
* v = 340m/s
* v = 0,034cm/us
*
* Time = distance / speed:
* t = s/v=10/0,034 = 294us
*
* Distance in cm:
* s = t * 0,034 / 2
* We need to divide it by 2, because the sound has to path this distance two times.
* (there and than back)
*/

const int trigPin = 9;
const int echoPin = 10;

long duration;
int distance;

void setup() {
	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);
	Serial.begin(9600);

}

void loop() {
	digitalWrite(trigPin, LOW);
	delayMicroseconds(2);

	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);

	duration = pulseIn(echoPin, HIGH);
	distance = duration * 0.034 / 2;

	Serial.print("Distance: ");
	Serial.print(distance);
	Serial.println(" cm");

	delayMicroseconds(100);
}