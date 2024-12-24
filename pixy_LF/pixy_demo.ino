#define IN1 5
#define IN2 6
#define IN3 9
#define IN4 11
#define motorLeft 3
#define motorRight 10
int last_error = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.print("Staring...\n");

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(motorLeft, OUTPUT);
  pinMode(motorRight, OUTPUT);

}

void forward(int speed_l, int speed_r) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(motorLeft, speed_l);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(motorRight, speed_r);
}

void backward(int speed_l, int speed_r) {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(motorLeft, speed_l);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(motorRight, speed_r);
}

void loop() {
  // put your main code here, to run repeatedly:
  forward(180,180);

}
