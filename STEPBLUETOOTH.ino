#include <Stepper.h>
#include<SoftwareSerial.h>

int stepPin0=9;   //
int stepPin1=10;  //1.step motorun pin bağlantısı
int stepPin2=11;  //
int stepPin3=12;  //


int stepPin10=1;   //
int stepPin11=2;  //2.step motorun pin bağlantısı
int stepPin12=3;  //
int stepPin13=4;  //



int stepPin20=5;   //
int stepPin21=6;  //3.step motorun pin bağlantısı
int stepPin22=7;  //
int stepPin23=8;  //




int adim0=0;
int adim1=0;
int adim2=0;

int deger0=0;
int deger1=0;
int deger2=0;

Stepper stepmotor1(32,stepPin0,stepPin1,stepPin2,stepPin3);    //1,motor

Stepper stepmotor2(32,stepPin10,stepPin11,stepPin12,stepPin13);//2,motor

Stepper stepmotor3(32,stepPin20,stepPin21,stepPin22,stepPin23);//3,motor

//stepmotor nesnesi üretildi
//ve Step motorun bir tam turu 32 parçaya(step) bölündü
//dolayısıyla her bir stepte motor 360/11,25=32derece dönecek

void setup() {
pinMode(stepPin0,OUTPUT);
pinMode(stepPin1,OUTPUT);
pinMode(stepPin2,OUTPUT);
pinMode(stepPin3,OUTPUT);

pinMode(stepPin10,OUTPUT);
pinMode(stepPin11,OUTPUT);
pinMode(stepPin12,OUTPUT);
pinMode(stepPin13,OUTPUT);

pinMode(stepPin20,OUTPUT);
pinMode(stepPin21,OUTPUT);
pinMode(stepPin22,OUTPUT);
pinMode(stepPin23,OUTPUT);


stepmotor1.setSpeed(200); //1,motorun rpm hızı=50
stepmotor2.setSpeed(200); //2,motorun rpm hızı=50
stepmotor3.setSpeed(200); //3,motorun rpm hızı=50

  Serial.begin(9600);
}

void loop() {

  if(Serial.available()){

      int steppos =Serial.read();
      Serial.println(steppos);



if(steppos == '0'){              //
  stepmotor1.step(+3);           //
  delay(50);                     //      1.STEP MOTOR 
                  }              //        KONTROLÜ
                                 //
if(steppos == '1'){              //
  stepmotor1.step(-3);           //
  delay(50);                     //
                  }              //
                                 




if(steppos == '2'){              //
  stepmotor2.step(+3);           //
  delay(50);                     //      2.STEP MOTOR 
                  }              //        KONTROLÜ
                                 //
if(steppos == '3'){              //
  stepmotor2.step(-3);           //
  delay(50);                     //
                  }              //



if(steppos == '4'){              //
  stepmotor3.step(+3);           //
  delay(50);                     //      3.STEP MOTOR 
                  }              //        KONTROLÜ
                                 //
if(steppos == '5'){              //
  stepmotor3.step(-3);           //
  delay(50);                     //
                  }              //

                  
}
}
