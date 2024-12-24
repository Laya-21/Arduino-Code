#include "Arduino.h"
#include "TB6612FNG.h"


TB1266FNG::TB1266FNG(int PWMA, int AIN_1, int AIN_2, int PWMB, int BIN_1, int BIN_2)
    {
      PWM_R = PWMA;
      R_IN1 = AIN_1;
      R_IN2 = AIN_2;

      PWM_L = PWMB;
      L_IN1 = BIN_1;
      L_IN2 = BIN_2;
    }

    void TB1266FNG::pinSetup()
    {
      //RIGHT MOTOR(A)
      pinMode(PWM_R, OUTPUT);
      pinMode(R_IN1, OUTPUT);
      pinMode(R_IN2, OUTPUT);

      //LEFT MOTOR(B)
      pinMode(PWM_L, OUTPUT);
      pinMode(L_IN1, OUTPUT);
      pinMode(L_IN2, OUTPUT);
    }

    void TB1266FNG::FORWARD(float speed_l, float speed_r)
    {
      digitalWrite(R_IN1, HIGH);
      digitalWrite(R_IN2, LOW);
      analogWrite(PWM_R, speed_r);

      digitalWrite(L_IN1, HIGH);
      digitalWrite(L_IN2, LOW);
      analogWrite(PWM_L, speed_l);
    }

    void TB1266FNG::BACKWARD(float speed_l, float speed_r)
    {
      digitalWrite(R_IN1, LOW);
      digitalWrite(R_IN2, HIGH);
      analogWrite(PWM_R, speed_r);

      digitalWrite(L_IN1, LOW);
      digitalWrite(L_IN2, HIGH);
      analogWrite(PWM_L, speed_l);
    }

    void TB1266FNG::EXT_RIGHT(float speed_l, float speed_r)
    {
      digitalWrite(R_IN1, LOW);
      digitalWrite(R_IN2, HIGH);
      analogWrite(PWM_R, speed_r);

      digitalWrite(L_IN1, HIGH);
      digitalWrite(L_IN2, LOW);
      analogWrite(PWM_L, speed_l);
    }

    void TB1266FNG::EXT_LEFT(float speed_l, float speed_r)
    {
      digitalWrite(R_IN1, HIGH);
      digitalWrite(R_IN2, LOW);
      analogWrite(PWM_R, speed_r);

      digitalWrite(L_IN1, LOW);
      digitalWrite(L_IN2, HIGH);
      analogWrite(PWM_L, speed_l);
    }

    void TB1266FNG::RIGHT(float speed_l, float speed_r)
    {
      digitalWrite(R_IN1, HIGH);
      digitalWrite(R_IN2, LOW);
      analogWrite(PWM_R, speed_r);

      digitalWrite(L_IN1, HIGH);
      digitalWrite(L_IN2, LOW);
      analogWrite(PWM_L, speed_l);
    }

    void TB1266FNG::LEFT(float speed_l, float speed_r)
    {
      digitalWrite(R_IN1, HIGH);
      digitalWrite(R_IN2, LOW);
      analogWrite(PWM_R, speed_r);

      digitalWrite(L_IN1, HIGH);
      digitalWrite(L_IN2, LOW);
      analogWrite(PWM_L, speed_l);
    }

    void TB1266FNG::STOP()
    {
      digitalWrite(R_IN1, LOW);
      digitalWrite(R_IN2, LOW);
      analogWrite(PWM_R, 0);

      digitalWrite(L_IN1, LOW);
      digitalWrite(L_IN2, LOW);
      analogWrite(PWM_L, 0);
    }