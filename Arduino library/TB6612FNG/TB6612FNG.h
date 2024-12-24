#ifndef TB6612FNG_h
#define TB6612FNG_h
#include "Arduino.h"


class TB1266FNG{

  private:

  //RIGHT MOTOR
  int PWM_R;
  int R_IN1;
  int R_IN2;

  // LEFT MOTOR
  int PWM_L;
  int L_IN1;
  int L_IN2;

  public:

    TB1266FNG(int PWMA, int AIN_1, int AIN_2, int PWMB, int BIN_1, int BIN_2);
    void pinSetup();
    void FORWARD(float speed_l, float speed_r);
    void BACKWARD(float speed_l, float speed_r);
    void RIGHT(float speed_l, float speed_r);
    void LEFT(float speed_l, float speed_r);
    void EXT_RIGHT(float speed_l, float speed_r);
    void EXT_LEFT(float speed_l, float speed_r);
    void STOP();
};

#endif