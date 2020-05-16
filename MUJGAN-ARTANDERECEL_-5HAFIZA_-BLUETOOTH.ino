#include <Stepper.h>
#include<SoftwareSerial.h>
#include <Servo.h> //servo motor kütüphanesini dahil ettik

Servo servo1;          //1.servo motor oluşturduk
Servo servo2;          //2.servo motor oluşturduk
Servo servo3;          //3.servo motor oluşturduk

int servo1_derece;     //1.servo motor derece değişkeni
int servo2_derece;     //2.servo motor derece değişkeni
int servo3_derece;     //3.servo motor derece değişkeni




int step1 = 0;   //1.step motor derece değişkeni
int step2 = 0;   //2.step motor derece değişkeni
int step3 = 0;   //3.step motor derece değişkeni

int stepPin0=9;   //
int stepPin1=10;  //1.step motorun pin bağlantısı
int stepPin2=11;  //
int stepPin3=12;  //


int stepPin10=1;  //
int stepPin11=2;  //2.step motorun pin bağlantısı
int stepPin12=3;  //
int stepPin13=4;  //



int stepPin20=5;  //
int stepPin21=6;  //3.step motorun pin bağlantısı
int stepPin22=7;  //
int stepPin23=8;  //


int step1Poskayit[] = {1,1,1,1,1};     //1.step motorun kayıt başlangışları
int step2Poskayit[] = {1,1,1,1,1};     //2.step motorun kayıt başlangışları
int step3Poskayit[] = {1,1,1,1,1};     //3.step motorun kayıt başlangışları
int servo1Poskayit[] = {1,1,1,1,1};    //1.servo motorun kayıt başlangışları
int servo2Poskayit[] = {1,1,1,1,1};    //2.servo motorun kayıt başlangışları
int servo3Poskayit[] = {1,1,1,1,1};    //3.servo motorun kayıt başlangışları
 
int i ;
int button_kayit_deger;

int 3.servoacı ;
int 2.servoacı ;
int 1.servoacı ;
int 3.stepacı ;
int 2.stepacı ;
int 1.stepacı ;
Stepper stepmotor1(32,stepPin0,stepPin1,stepPin2,stepPin3);    //1.stepmotor

Stepper stepmotor2(32,stepPin10,stepPin11,stepPin12,stepPin13);//2.stepmotor

Stepper stepmotor3(32,stepPin20,stepPin21,stepPin22,stepPin23);//3.stepmotor

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

servo1.attach(9);  //servo1 motorunun 9.pine bağlı
servo2.attach(10); //servo1 motorunun 10.pine bağlı
servo3.attach(11); //servo1 motorunun 11.pine bağlı

Serial.begin(9600);
}

void loop() {

  if(Serial.available()){

      int bluetooth =Serial.read();
      Serial.println(bluetooth);

if(bluetooth == 'A' && servo1_derece < 180 )            //
     {                                                  //
      servo1_derece= servo1_derece+1;                   //
      servo1.write(  servo1_derece);                    //  1.SERVO MOTORUN BLUETOOTH                   
      delay(100);                                       //
      }                                                 //       KONTROLU
                                                        //
      if(bluetooth == 'B' && servo1_derece  > 0   )     //
      {                                                 //
      servo1_derece = servo1_derece -1;                 //
      servo1.write( servo1_derece );                    //                
      delay(100);                                       //
      }                                                 //


     if(bluetooth == 'C' && servo2_derece < 180 )       //
     {                                                  //
     servo2_derece=servo2_derece+1;                     //
      servo2.write(  servo2_derece);                    //  2.SERVO MOTORUN BLUETOOTH                  
      delay(100);                                       //
      }                                                 //       KONTROLU
                                                        //
      if(bluetooth == 'D' && servo2_derece > 0 )        //
      {                                                 //
      servo2_derece= servo2_derece-1;                   //
      servo2.write(servo2_derece);                      //
      delay(100);                                       //
      }                                                 //



     if(bluetooth == 'E' && servo3_derece < 180 )       //
     {                                                  //
      servo3_derece= servo3_derece+1;                   //
      servo3.write( servo3_derece);                     //  3.SERVO MOTORUN BLUETOOTH
      delay(100);                                       //
      }                                                 //       KONTROLU
                                                        //
      if(bluetooth == 'F' && servo3_derece > 0 )        //
      {                                                 //
      servo3_derece= servo3_derece-1;                   //
      servo3.write(servo3_derece);                      //
      delay(100);                                       //
      }        



if(bluetooth== '0'){             //
  step1=step1 + 3;               //
  stepmotor1.step(step1);        //
  delay(50);                     //      1.STEP MOTOR 
                  }              //        KONTROLÜ
                                 //
if(bluetooth == '1'){            //
  step1=step1 - 3;               //
  stepmotor1.step(step1);        //
  delay(50);                     //
                  }              //
                                 




if(bluetooth == '2'){            //
  step2=step2 + 3;               //
  stepmotor2.step(step2);        //
  delay(50);                     //      2.STEP MOTOR 
                  }              //        KONTROLÜ
                                 //
if(bluetooth == '3'){            //
  step2=step2 - 3;               //
  stepmotor2.step(step2);        //
  delay(50);                     //
                  }              //


if(bluetooth == '4'){            //
  step3=step3 + 3;               //
  stepmotor3.step(step3);        //
  delay(50);                     //      3.STEP MOTOR 
                  }              //        KONTROLÜ
                                 //
if(bluetooth == '5'){            //
  step3=step3 - 3;               //
  stepmotor3.step(step3);        //
  delay(50);                     //
                  }              //

                  


                                 
                                 

                                       
 
  if(bluetooth == '6'){                //1.KAYITLI HAREKET KOMUTU 
    button_kayit_deger = 1;            //
     }                                 //

  if(bluetooth == '7'){                //2.KAYITLI HAREKET KOMUTU   
    button_kayit_deger = 2;            //
     }                                 //

  if(bluetooth == '8'){                //3.KAYITLI HAREKET KOMUTU 
    button_kayit_deger = 3;            //
     }                                 //

  if(bluetooth == '9'){                //4.KAYITLI HAREKET KOMUTU 
    button_kayit_deger = 4;            //
     }                                 //

  if(bluetooth == 'G'){                //5.KAYITLI HAREKET KOMUTU 
    button_kayit_deger = 5;            //
     }                                 //

     
  
  switch(button_kayit_deger){
      case 1:
        step1Poskayit[0] = step1;
        step2Poskayit[0] = step2;
        step3Poskayit[0] = step3;
       
        servo1Poskayit[0] = servo1_derece;
        servo2Poskayit[0] = servo2_derece;
        servo3Poskayit[0] = servo3_derece;
       

        break;
        
      case 2:
        step1Poskayit[1] = step1;
        step2Poskayit[1] = step2;
        step3Poskayit[1] = step3;
        
        servo1Poskayit[1] = servo1_derece;
        servo2Poskayit[1] = servo2_derece;
        servo3Poskayit[1] = servo3_derece;

         break;
         
      case 3:
        step1Poskayit[2] = step1;
        step2Poskayit[2] = step2;
        step3Poskayit[2] = step3;
        
        servo1Poskayit[2] = servo1_derece;
        servo2Poskayit[2] = servo2_derece;
        servo3Poskayit[2] = servo3_derece;         

         break;

      case 4:
        step1Poskayit[3] = step1;
        step2Poskayit[3] = step2;
        step3Poskayit[3] = step3;
        
        servo1Poskayit[3] = servo1_derece;
        servo2Poskayit[3] = servo2_derece;
        servo3Poskayit[3] = servo3_derece;        

         break;

      case 5:
        step1Poskayit[4] = step1;
        step2Poskayit[4] = step2;
        step3Poskayit[4] = step3;
        
        servo1Poskayit[4] = servo1_derece;
        servo2Poskayit[4] = servo2_derece;
        servo3Poskayit[4] = servo3_derece;       

         break;
          }

    if(bluetooth='G' )                             //            
{                                                  //
while(1){                                          //
        stepmotor1.step(1.stepacı);                //
        stepmotor2.step(2.stepacı);                //
        stepmotor3.step(3.stepacı);                //
                                                   //
 if(bluetooth='Q') break;                          //   1.KAYITLI HAREKETİ OYNAT
                                                   //
        servo1.write(1.servoacı);                  //
        servo2.write(2.servoacı);                  //
        servo3.write(3.servoacı);                  //
delay(100);                                        //
                                                   //
 if(bluetooth='Q') break;                          //
                                                   //
1.stepacı = 1.stepacı + 1;                         //
2.stepacı = 2.stepacı + 1;                         //
3.stepacı = 3.stepacı + 1;                         // 
                                                   //
1.servoacı = 1.servoacı + 1;                       //
2.servoacı = 2.servoacı + 1;                       //
3.servoacı = 3.servoacı + 1;                       //
                                                   //
if(1.stepacı == step1Poskayit[0]) 1.stepacı = 0;   //
if(2.stepacı == step2Poskayit[0]) 2.stepacı = 0;   //
if(3.stepacı == step3Poskayit[0]) 3.stepacı = 0;   //
if(1.servoacı == servo1Poskayit[0]) 1.servoacı = 0;// 
if(2.servoacı == servo2Poskayit[0]) 2.servoacı = 0;//
if(3.servoacı == servo3Poskayit[0]) 3.servoacı = 0;//
   
}
}


    if(bluetooth='H' )                             //            
{                                                  //
while(1){                                          //
        stepmotor1.step(1.stepacı);                //
        stepmotor2.step(2.stepacı);                //
        stepmotor3.step(3.stepacı);                //
                                                   //
 if(bluetooth='Q') break;                          //   2.KAYITLI HAREKETİ OYNAT
                                                   //
        servo1.write(1.servoacı);                  //
        servo2.write(2.servoacı);                  //
        servo3.write(3.servoacı);                  //
delay(100);                                        //
                                                   //
 if(bluetooth='Q') break;                          //
                                                   //
1.stepacı = 1.stepacı + 1;                         //
2.stepacı = 2.stepacı + 1;                         //
3.stepacı = 3.stepacı + 1;                         // 
                                                   //
1.servoacı = 1.servoacı + 1;                       //
2.servoacı = 2.servoacı + 1;                       //
3.servoacı = 3.servoacı + 1;                       //
                                                   //
if(1.stepacı == step1Poskayit[1]) 1.stepacı = 0;   //
if(2.stepacı == step2Poskayit[1]) 2.stepacı = 0;   //
if(3.stepacı == step3Poskayit[1]) 3.stepacı = 0;   //
if(1.servoacı == servo1Poskayit[1]) 1.servoacı = 0;// 
if(2.servoacı == servo2Poskayit[1]) 2.servoacı = 0;//
if(3.servoacı == servo3Poskayit[1]) 3.servoacı = 0;//
   
}
}


    if(bluetooth='J' )                             //            
{                                                  //
while(1){                                          //
        stepmotor1.step(1.stepacı);                //
        stepmotor2.step(2.stepacı);                //
        stepmotor3.step(3.stepacı);                //
                                                   //
 if(bluetooth='Q') break;                          //   3.KAYITLI HAREKETİ OYNAT
                                                   //
        servo1.write(1.servoacı);                  //
        servo2.write(2.servoacı);                  //
        servo3.write(3.servoacı);                  //
delay(100);                                        //
                                                   //
 if(bluetooth='Q') break;                          //
                                                   //
1.stepacı = 1.stepacı + 1;                         //
2.stepacı = 2.stepacı + 1;                         //
3.stepacı = 3.stepacı + 1;                         // 
                                                   //
1.servoacı = 1.servoacı + 1;                       //
2.servoacı = 2.servoacı + 1;                       //
3.servoacı = 3.servoacı + 1;                       //
                                                   //
if(1.stepacı == step1Poskayit[2]) 1.stepacı = 0;   //
if(2.stepacı == step2Poskayit[2]) 2.stepacı = 0;   //
if(3.stepacı == step3Poskayit[2]) 3.stepacı = 0;   //
if(1.servoacı == servo1Poskayit[2]) 1.servoacı = 0;// 
if(2.servoacı == servo2Poskayit[2]) 2.servoacı = 0;//
if(3.servoacı == servo3Poskayit[2]) 3.servoacı = 0;//
   
}
}


    if(bluetooth='K' )                             //            
{                                                  //
while(1){                                          //
        stepmotor1.step(1.stepacı);                //
        stepmotor2.step(2.stepacı);                //
        stepmotor3.step(3.stepacı);                //
                                                   //
 if(bluetooth='Q') break;                          //   4.KAYITLI HAREKETİ OYNAT
                                                   //
        servo1.write(1.servoacı);                  //
        servo2.write(2.servoacı);                  //
        servo3.write(3.servoacı);                  //
delay(100);                                        //
                                                   //
 if(bluetooth='Q') break;                          //
                                                   //
1.stepacı = 1.stepacı + 1;                         //
2.stepacı = 2.stepacı + 1;                         //
3.stepacı = 3.stepacı + 1;                         // 
                                                   //
1.servoacı = 1.servoacı + 1;                       //
2.servoacı = 2.servoacı + 1;                       //
3.servoacı = 3.servoacı + 1;                       //
                                                   //
if(1.stepacı == step1Poskayit[3]) 1.stepacı = 0;   //
if(2.stepacı == step2Poskayit[3]) 2.stepacı = 0;   //
if(3.stepacı == step3Poskayit[3]) 3.stepacı = 0;   //
if(1.servoacı == servo1Poskayit[3]) 1.servoacı = 0;// 
if(2.servoacı == servo2Poskayit[3]) 2.servoacı = 0;//
if(3.servoacı == servo3Poskayit[3]) 3.servoacı = 0;//
   
}
}

    if(bluetooth='L' )                             //            
{                                                  //
while(1){                                          //
        stepmotor1.step(1.stepacı);                //
        stepmotor2.step(2.stepacı);                //
        stepmotor3.step(3.stepacı);                //
                                                   //
 if(bluetooth='Q') break;                          //   5.KAYITLI HAREKETİ OYNAT
                                                   //
        servo1.write(1.servoacı);                  //
        servo2.write(2.servoacı);                  //
        servo3.write(3.servoacı);                  //
delay(100);                                        //
                                                   //
 if(bluetooth='Q') break;                          //
                                                   //
1.stepacı = 1.stepacı + 1;                         //
2.stepacı = 2.stepacı + 1;                         //
3.stepacı = 3.stepacı + 1;                         // 
                                                   //
1.servoacı = 1.servoacı + 1;                       //
2.servoacı = 2.servoacı + 1;                       //
3.servoacı = 3.servoacı + 1;                       //
                                                   //
if(1.stepacı == step1Poskayit[4]) {1.stepacı = 0;}    //
if(2.stepacı == step2Poskayit[4]) {2.stepacı = 0;}    //
if(3.stepacı == step3Poskayit[4]) {3.stepacı = 0;}    //
if(1.servoacı == servo1Poskayit[4]) {1.servoacı = 0;} // 
if(2.servoacı == servo2Poskayit[4]) {2.servoacı = 0;} //
if(3.servoacı == servo3Poskayit[4]) {3.servoacı = 0;} //
   
}
}
}
}
