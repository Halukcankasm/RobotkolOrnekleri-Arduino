#include <Stepper.h>
#include <Servo.h>

Servo servo1; //servo motor oluşturduk
Servo servo2;
Servo servo3;

int deger0;
int deger1;
int deger2;

int derece0;
int derece1;
int derece2;

static const int PIN_MAVI      = 13;
static const int PIN_PEMBE     = 12;
static const int PIN_SARI      = 11;
static const int PIN_TURUNCU   = 10;

static const int PIN2_MAVI      = 9;
static const int PIN2_PEMBE     = 8;
static const int PIN2_SARI      = 7;
static const int PIN2_TURUNCU   = 4;

static const int PIN3_MAVI      = 0;
static const int PIN3_PEMBE     = 1;
static const int PIN3_SARI      = 2;
static const int PIN3_TURUNCU   = 32;

int adim=20;

int pot = 0;
int deger = 0;

int pot2 = 0;
int deger22 = 0; 

int pot3 = 0;
int deger3 = 0;

Stepper stepmotor(adim,PIN_MAVI, PIN_PEMBE, PIN_SARI, PIN_TURUNCU);
Stepper stepmotor2(adim,PIN2_MAVI, PIN2_PEMBE, PIN2_SARI, PIN2_TURUNCU);
Stepper stepmotor3(adim,PIN3_MAVI, PIN3_PEMBE, PIN3_SARI, PIN3_TURUNCU);

void setup() {
  
  stepmotor.setSpeed(5); //stepmotor hızı
  stepmotor2.setSpeed(5); //stepmotor hızı
  stepmotor3.setSpeed(5); //stepmotor hızı

   servo1.attach(3); //servo1 motorunun 6.pine bağlı
   servo2.attach(5); //servo1 motorunun 7.pine bağlı
   servo3.attach(11); //servo1 motorunun 8.pine bağlı
}

void loop() {
deger0=analogRead(A0);
derece0=map(deger0,0,1023,0,100);

deger1=analogRead(A1);
derece1=map(deger1,0,1023,0,100);

deger2=analogRead(A2);
derece2=map(deger2,0,1023,0,100);

servo1.write(derece0);
servo2.write(derece1);
servo3.write(derece2);




pot=map(analogRead(A3),0,1023,0,500);
pot2=map(analogRead(A4),0,1023,0,500);
pot3=map(analogRead(A5),0,1023,0,500);


if(pot !=deger){
  
   if(pot>deger){stepmotor.step(+1);}

   if(pot<deger){stepmotor.step(-1);}
 
 deger=pot;
               
}

if(pot2 !=deger22){
  
   if(pot2>deger22){stepmotor2.step(+1);}

   if(pot2<deger22){stepmotor2.step(-1);}
 
 
deger22=pot2;
               
}

if(pot3 !=deger3){
  
   if(pot3>deger3){stepmotor3.step(+1);}

   if(pot3<deger3){stepmotor3.step(-1);}
 
 
deger3=pot3;
               
}
}
