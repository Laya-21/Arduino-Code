#define throttle_pin A2 //CH3
#define direction_pin A1 //CH1

#define left_motor_lpwm 10
#define left_motor_rpwm 9
#define right_motor_lpwm 5
#define right_motor_rpwm 6


unsigned long throttle_pulse;
unsigned long direction_pulse;

void forward(int speed)
{
  analogWrite(left_motor_lpwm, speed);
  analogWrite(left_motor_rpwm, 0);
  analogWrite(right_motor_lpwm, speed);
  analogWrite(right_motor_rpwm, 0);
}

void backward(int speed)
{
  analogWrite(left_motor_lpwm, 0);
  analogWrite(left_motor_rpwm, speed);
  analogWrite(right_motor_lpwm, 0);
  analogWrite(right_motor_rpwm, speed);
}

void left(int speed)
{
  analogWrite(left_motor_lpwm, 0);
  analogWrite(left_motor_rpwm, speed);
  analogWrite(right_motor_lpwm, speed);
  analogWrite(right_motor_rpwm, 0);
}

void right(int speed)
{
  analogWrite(left_motor_lpwm, speed);
  analogWrite(left_motor_rpwm, 0);
  analogWrite(right_motor_lpwm, 0);
  analogWrite(right_motor_rpwm, speed);
}

void stop()
{
  analogWrite(left_motor_lpwm, 0);
  analogWrite(left_motor_rpwm, 0);
  analogWrite(right_motor_lpwm, 0);
  analogWrite(right_motor_rpwm, 0);
}

void setup()
{
  Serial.begin(115200);
  pinMode(throttle_pin, INPUT);
  pinMode(direction_pin, INPUT);
  
  pinMode(left_motor_lpwm, OUTPUT);
  pinMode(left_motor_rpwm, OUTPUT);
  pinMode(right_motor_lpwm, OUTPUT);
  pinMode(right_motor_rpwm, OUTPUT);
}

void loop()
{
  throttle_pulse = pulseIn(throttle_pin, HIGH);
  direction_pulse = pulseIn(direction_pin, HIGH);
  Serial.print(throttle_pulse);
  Serial.print(" ");
  Serial.print(direction_pulse);
  Serial.println(" ");

  if(throttle_pulse < 1550 && throttle_pulse > 1450 && direction_pulse < 1550 && direction_pulse > 1450)
  {
    stop();
  }
  else if(throttle_pulse >= 1550)
  {
    forward(map(throttle_pulse,1550,1990,0,255));
  }
  else if(throttle_pulse <= 1450)
  {
    backward(map(throttle_pulse,1450,990,0,255));
  }
  else if(direction_pulse >= 1550)
  {
    left(map(direction_pulse,1550,1990,0,255));
  }
  else if(direction_pulse <= 1450)
  {
    right(map(throttle_pulse,1450,990,0,255));
  }
}