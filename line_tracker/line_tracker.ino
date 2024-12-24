#include <Pixy2.h>
#include <Wire.h>

Pixy2 pixy;

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

  pixy.init();

  // int initResult = pixy.init();
  // if (initResult != 0) {
  //     Serial.print("Pixy2 initialization failed with code: ");
  //     Serial.println(initResult);
  //     while (1); // Halt the program if initialization fails
  // }
  // Serial.println("Pixy2 initialized successfully");
  Serial.println(pixy.changeProg("line"));
  pixy.setLamp(1, 0);          // Turn on the white LED (1 = on, 0 = off)
  pixy.setLED(255, 255, 255); 

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(motorLeft, OUTPUT);
  pinMode(motorRight, OUTPUT);

   // RGB values for white
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
  // backward(180,180);
  forward(180,180);
  // int8_t i;
  // char buf[128];

  // pixy.line.getMainFeatures();
  // forward(100,100);
  // Serial.println("laya");


  // if (pixy.line.numVectors > 0) {
  //   int x0 = pixy.line.vectors[0].m_x0;
  //   int x1 = pixy.line.vectors[0].m_x1;

  //   int line_midpoint = (x0 + x1) / 2;

  //   int centre_x = 79 / 2;

  //   int error = line_midpoint - centre_x;

  //   int base_speed = 150;
  //   int kp = 5;
  //   int kd = 10;
  //   int pid = kp * error + kd * (error - last_error);

  //   int right_speed = base_speed + pid;
  //   int left_speed = base_speed - pid;

  //   forward(left_speed, right_speed);
  //   /*
  //   if(error<0)
  //   {
  //     backward(150,150);
  //   }
  //   else{
  //     forward(left_speed, right_speed);
  //   }
  //   */
  //   last_error = error;
  // }
}

// #include <Pixy2.h>

// Pixy2 pixy;

// // Motor pins for L298N motor driver
// const int motorLeftPWM = 3;   // ENA
// const int motorLeftIN1 = 5;   // IN1
// const int motorLeftIN2 = 6;   // IN2
// const int motorRightPWM = 10; // ENB
// const int motorRightIN3 = 9;  // IN3
// const int motorRightIN4 = 11; // IN4

// // Motor speed variables
// int baseSpeed = 150; // Base speed of motors (0-255)
// float Kp = 0.5;      // Proportional gain for line correction

// void setup() {
//   // Initialize Serial communication for debugging
//   Serial.begin(115200);
  
//   // Initialize the Pixy2 camera
//   pixy.init();
  
//   // Motor pin setup
//   pinMode(motorLeftPWM, OUTPUT);
//   pinMode(motorLeftIN1, OUTPUT);
//   pinMode(motorLeftIN2, OUTPUT);
//   pinMode(motorRightPWM, OUTPUT);
//   pinMode(motorRightIN3, OUTPUT);
//   pinMode(motorRightIN4, OUTPUT);

//   Serial.println("Pixy2 Line Following Started");
// }

// void loop() {
//     // Get line features from Pixy2
//     int result = pixy.line.getMainFeatures();

//     if (result < 0) {
//         // Error occurred while getting features
//         Serial.print("Error getting line features: ");
//         Serial.println(result);
//     } else if (pixy.line.numVectors > 0) {
//         // Get the first vector (line segment)
//         int32_t linePosition = pixy.line.vectors[0].m_x1;
//         int32_t error = linePosition - (pixy.frameWidth / 2);

//         // Calculate motor speeds based on the error
//         int leftSpeed = baseSpeed - (error * Kp);
//         int rightSpeed = baseSpeed + (error * Kp);

//         // Constrain motor speeds to 0-255
//         leftSpeed = constrain(leftSpeed, 0, 255);
//         rightSpeed = constrain(rightSpeed, 0, 255);

//         // Drive the motors
//         driveMotors(leftSpeed, rightSpeed);

//         // Debug information
//         Serial.print("Number of vectors: ");
//         Serial.println(pixy.line.numVectors);
//         Serial.print("Line Position: ");
//         Serial.print(linePosition);
//         Serial.print(" | Error: ");
//         Serial.print(error);
//         Serial.print(" | Left Speed: ");
//         Serial.print(leftSpeed);
//         Serial.print(" | Right Speed: ");
//         Serial.println(rightSpeed);
//     } else {
//         // No line detected
//         stopMotors();
//         Serial.println("No line detected");
//     }

//     // Small delay for stability
//     delay(50);
// }

// // Function to drive the motors
// void driveMotors(int leftSpeed, int rightSpeed) {
//   // Left motor control
//   if (leftSpeed > 0) {
//     digitalWrite(motorLeftIN1, HIGH);
//     digitalWrite(motorLeftIN2, LOW);
//     analogWrite(motorLeftPWM, leftSpeed);
//   } else {
//     digitalWrite(motorLeftIN1, LOW);
//     digitalWrite(motorLeftIN2, HIGH);
//     analogWrite(motorLeftPWM, -leftSpeed);
//   }

//   // Right motor control
//   if (rightSpeed > 0) {
//     digitalWrite(motorRightIN3, HIGH);
//     digitalWrite(motorRightIN4, LOW);
//     analogWrite(motorRightPWM, rightSpeed);
//   } else {
//     digitalWrite(motorRightIN3, LOW);
//     digitalWrite(motorRightIN4, HIGH);
//     analogWrite(motorRightPWM, -rightSpeed);
//   }
// }

// // Function to stop the motors
// void stopMotors() {
//   digitalWrite(motorLeftIN1, LOW);
//   digitalWrite(motorLeftIN2, LOW);
//   analogWrite(motorLeftPWM, 0);

//   digitalWrite(motorRightIN3, LOW);
//   digitalWrite(motorRightIN4, LOW);
//   analogWrite(motorRightPWM, 0);
// }
