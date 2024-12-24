#include "Arduino.h"
#include "Sensor_Array.h"


Sensor_Array::Sensor_Array(int IR_1, int IR_2, int IR_3, int IR_4, int IR_5, int IR_6, int IR_7)
    {
      ir1 = IR_1;
      ir2 = IR_2;
      ir3 = IR_3;
      ir4 = IR_4;
      ir5 = IR_5;
      ir6 = IR_6;
      ir7 = IR_7;

    }

    void Sensor_Array::pinSetup()
    {
      pinMode(ir1, INPUT);
      pinMode(ir2, INPUT);
      pinMode(ir3, INPUT);
      pinMode(ir4, INPUT);
      pinMode(ir5, INPUT);
      pinMode(ir6, INPUT);
      pinMode(ir7, INPUT);
    }

    void Sensor_Array::THRESHOLD(int value)
    {
      if(analogRead(ir1) > value){
        digital_IR1 = 1;
      }

      if(analogRead(ir2) > value){
        digital_IR2 = 1;
      }

      if(analogRead(ir3) > value){
        digital_IR3 = 1;
      }

      if(analogRead(ir4) > value){
        digital_IR4 = 1;
      }

      if(analogRead(ir5) > value){
        digital_IR5 = 1;
      }

      if(analogRead(ir6) > value){
        digital_IR6 = 1;
      }

      if(analogRead(ir7) > value){
        digital_IR7 = 1;
      }
    }

    float Sensor_Array::PID()
    {
      THRESHOLD(50);
      float kp = 0.71;
      float kd = 0.51;
      error = 30*digital_IR7 + 20*digital_IR6 + 10*digital_IR5 - 10*digital_IR3 - 20*digital_IR2 - 30*digital_IR1;
      int P = error;
      int D = error - last_error;
      last_error = error;

      float PID_speed = kp*P + kd*D;

      return PID_speed;
    }