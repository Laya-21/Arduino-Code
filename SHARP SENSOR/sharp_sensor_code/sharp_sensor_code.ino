#include <SharpIR.h>
#define ir1 A0
#define ir2 A1
#define ir3 A2
#define ir4 A3
#define ir5 A4
#define ir6 A5


#define model1 430
#define model2 430
#define model3 430
#define model4 430
#define model5 430
#define model6 430

SharpIR SharpIR1(ir1, model1);
SharpIR SharpIR2(ir2, model2);
SharpIR SharpIR3(ir3, model3);
SharpIR SharpIR4(ir4, model4);
SharpIR SharpIR5(ir5, model5);
SharpIR SharpIR6(ir6, model6);

void setup() {
  // put your setup code here, to run once:
    Serial.begin(115200);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    int dis1 = SharpIR1.distance();
    Serial.print("Mean Distance 1:- ");
    Serial.println(dis1);  

    int dis2 = SharpIR2.distance();
    Serial.print("Mean Distance 2:- ");
    Serial.println(dis2);  

    int dis3 = SharpIR3.distance();
    Serial.print("Mean Distance 3:- ");
    Serial.println(dis3);  

    int dis4 = SharpIR4.distance();
    Serial.print("Mean Distance 4:- ");
    Serial.println(dis4);  

    int dis5 = SharpIR5.distance();
    Serial.print("Mean Distance 5:- ");
    Serial.println(dis5);  

    int dis6 = SharpIR6.distance();
    Serial.print("Mean Distance 6:- ");
    Serial.println(dis6);  

    // user code begin
    // int threshold1 = 25;
    //   if(dis1 > threshold1)
    //   {
    //       digitalWrite(5, HIGH);
    //   }
    //   else
    //   {
    //       digitalWrite(5, LOW);
    //   }  
    //user code ends
    delay(300);
  }