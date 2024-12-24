 /*
 Example sketch for the PS4 Bluetooth library - developed by Kristian Lauszus
 For more information visit my blog: http://blog.tkjelectronics.dk/ or
 send me an e-mail:  kristianl@tkjelectronics.com
 */
///////aaaaa
#include <PS4BT.h>
#include <usbhub.h>

// Satisfy the IDE, which needs to see the include statment in the ino too.
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include <SPI.h>

USB Usb;
//USBHub Hub1(&Usb); // Some dongles have a hub inside
//BTD Btd(&Usb); // You have to create the Bluetooth Dongle instance like so

/* You can create the instance of the PS4BT class in two ways */
// This will start an inquiry and then pair with the PS4 controller - you only have to do this once
// You will need to hold down the PS and Share button at the same time, the PS4 controller will then start to blink rapidly indicating that it is in pairing mode
PS4BT PS4(&Btd, PAIR);

// After that you can simply create the instance like so and then press the PS button on the device
//PS4BT PS4(&Btd);

//-------Private Variables---------//
char upper_byte = 0x00, lower_byte = 0x00, i = 0,flag=0,count=0;
char JOYSTICK[4] = {0};
char ANALOG[2] = {0};
char in_byte = 0;
bool pair_flag = false;
bool prev_pair_flag = false;
int j;
#define LX 0
#define LY 1
#define RX 2
#define RY 3
//---------------------------------//

void setup() {
  Serial.begin(57600);
  
  if (Usb.Init() == -1) {
    delay(10);
    //Serial.print(F("\r\nOSC did not start"));
    while (1); // Halt
  }
///////////  Serial.print(F("\r\nPS4 Bluetooth Library Started"));
}


void loop() 
{
  count++;


  Usb.Task();
  if (PS4.connected()) 
  {
    pair_flag = true;
    Data_Update();

    if(count%250 == 0)
    {
        upper_byte = 0x00;
        lower_byte = 0x00;
    }
  }
  else
      pair_flag = false;


    Data_Update();      
    if(upper_byte!=0x00 || lower_byte!=0x00 || ANALOG[0]!=0 || ANALOG[1]!=0 || JOYSTICK[0]!=0 || JOYSTICK[1]!=0 || JOYSTICK[2]!=0 || JOYSTICK[3]!=0)
    {  
      in_byte=Serial.read(); 
      switch(in_byte)
      {
        case 97:    
          Data_Update();
          Send_Data();   //pairing lost 'u' sent by arduino pairing_flag = false in stm ucucucucucu sent by arduino when pair_flag becomes true after re-establishing 
        break;           //connection, prev pair flag -> false bt pair_flag == true, so send c....p 10 times so that stm sends 'a' to receive data from arduino i.e. pairing pcpcpc sent by arduino pairing_flag -> true in stm communication continued as usual.
  
        default:
        break;
      }
    } 
    if(count%250 == 0)
    {
        upper_byte = 0x00;
        lower_byte = 0x00;
    }

}

void Data_Update(void)
{
    JOYSTICK[LX] = PS4.getAnalogHat(LeftHatX);
    JOYSTICK[LY] = PS4.getAnalogHat(LeftHatY);
    JOYSTICK[RX] = PS4.getAnalogHat(RightHatX);
    JOYSTICK[RY] = PS4.getAnalogHat(RightHatY);

    ANALOG[0] = PS4.getAnalogButton(L2);
    ANALOG[1] = PS4.getAnalogButton(R2);
    
    if (PS4.getButtonPress(TRIANGLE)) 
    {
      //flag=1;
      lower_byte |= (1<<4);   //0001 0000
//      PS4.setLed(Green);
    }
      
    if (PS4.getButtonPress(CIRCLE)) 
    {
      //flag=1;
      lower_byte |= (1<<5);     //0010 0000
    }
    if (PS4.getButtonPress(CROSS)) 
    {
      //flag=1;
      lower_byte |= (1<<6);     //0100 0000
//      PS4.setLed(Blue);
    }
    if (PS4.getButtonPress(SQUARE)) 
    {
      //flag=1;
      lower_byte |= (1<<7);     //1000 0000
//      PS4.setLed(Yellow);
    }
    if (PS4.getButtonPress(UP)) 
    {
      //flag=1;
      upper_byte |= (1<<4);      //0001 0000
    } 
    if (PS4.getButtonPress(RIGHT)) 
    {
      //flag=1;
      upper_byte |= (1<<5);       //0010 0000
    }
    if (PS4.getButtonPress(DOWN)) 
    {
      //flag=1;
      upper_byte |= (1<<6);       //0100 0000
    } 
    if (PS4.getButtonPress(LEFT)) 
    {
      //flag=1;
      upper_byte |= (1<<7);       //1000 0000
    }
    if (PS4.getButtonPress(L1))
    {
      lower_byte |= (1<<2);       //0000 0100
    }
    if (PS4.getButtonPress(R1))
    {
      lower_byte |= (1<<3);       //0000 1000
    }
    if(PS4.getAnalogButton(L2))
    {
      lower_byte |= (1<<0);       //0000 0001
    }
    if(PS4.getAnalogButton(R2))
    {
      lower_byte |= (1<<1);       //0000 0010
    }
    if (PS4.getButtonPress(SHARE))
    {
      upper_byte |= (1<<0);       //0000 0001
    }
    if (PS4.getButtonPress(OPTIONS)) 
    {
      upper_byte |= (1<<3);       //0000 1000
    }
    if (PS4.getButtonPress(TOUCHPAD)) 
    {
      
      upper_byte |= (1<<1);       //0000 0010
    }
    if (PS4.getButtonPress(PS))
    {
      //upper_byte |= (1<<2);
      PS4.disconnect();
    }
}

void Send_Data(void)
{
  Serial.print('c');
  Serial.print(JOYSTICK[LX]);
  Serial.print(JOYSTICK[LY]);
  Serial.print(JOYSTICK[RX]);
  Serial.print(JOYSTICK[RY]);
      
  Serial.print(upper_byte);
  Serial.print(lower_byte);
  Serial.print(ANALOG[0]);
  Serial.print(ANALOG[1]);       

  if(pair_flag == false)
       Serial.print('u');
   else if(pair_flag == true)
       Serial.print('p');
}
