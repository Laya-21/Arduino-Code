#include <SharpIR.h>
#define ir1 A7
// #define ir2 A1
// #define ir3 A3
#define model1 430
// #define model2 430
// #define model3 430

SharpIR SharpIR1(ir1, model1);
// SharpIR SharpIR2(ir2, model2);
// SharpIR SharpIR3(ir3, model3);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(5, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("DISTANCE:- ");
  Serial.println(SharpIR1.distance());

  if(SharpIR1.distance() > 27 )
  {
      digitalWrite(5, LOW);
      Serial.println("LOW ");
  }

  else{
    digitalWrite(5, HIGH);
    Serial.println("HIGH ");
  }


  // Serial.println(SharpIR2.distance());
  // Serial.println(SharpIR3.distance());
  delay(500);
}
