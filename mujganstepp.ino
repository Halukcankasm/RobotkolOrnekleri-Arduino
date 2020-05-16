#include <Stepper.h>

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

Stepper stepmotor0(200,stepPin0,stepPin1,stepPin2,stepPin3);    //1,motor

Stepper stepmotor1(200,stepPin10,stepPin11,stepPin12,stepPin13);//2,motor

Stepper stepmotor2(200,stepPin20,stepPin21,stepPin22,stepPin23);//3,motor

//stepmotor nesnesi üretildi
//ve Step motorun bir tam turu 200 parçaya(step) bölündü
//dolayısıyla her bir stepte motor 360/200=1,8 derece dönecek

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

analogRead(A0);  
analogRead(A1);
analogRead(A2);


deger0=analogRead(A0);
adim0=map(deger0,0,1023,0,100);
deger1=analogRead(A1);
adim1=map(deger1,0,1023,0,100);
deger2=analogRead(A2);
adim2=map(deger2,0,1023,0,100);
   

stepmotor0.setSpeed(50); //1,motorun rpm hızı=50
stepmotor1.setSpeed(50); //2,motorun rpm hızı=50
stepmotor2.setSpeed(50); //3,motorun rpm hızı=50
}

void loop() {
 stepmotor0.step(adim0); //1,8*adim0 max değer 100=100*1,8=180 }

 stepmotor1.step(adim1);

 stepmotor2.step(adim2);
 delay(1000);

}
