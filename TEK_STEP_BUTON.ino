#include <Stepper.h>
#include<SoftwareSerial.h>






int step1 = 0;   //1.step motor derece değişkeni

const int button1=A0;
const int button2=A1;
const int button3=A2;
const int button4=A3;
const int button5=A4;


int stepPin0=9;   //
int stepPin1=10;  //1.step motorun pin bağlantısı
int stepPin2=11;  //
int stepPin3=12;  //

int step1Poskayit[] = {1,1,1,1,1,1,1,1,1,1};     //1.step motorun kayıt başlangışları



int i ;
int button_kayit_deger;



Stepper stepmotor1(32,stepPin0,stepPin1,stepPin2,stepPin3);    //1.stepmotor


//stepmotor nesnesi üretildi
//ve Step motorun bir tam turu 32 parçaya(step) bölündü
//dolayısıyla her bir stepte motor 360/11,25=32derece dönecek



void setup() {
pinMode(stepPin0,OUTPUT);
pinMode(stepPin1,OUTPUT);
pinMode(stepPin2,OUTPUT);
pinMode(stepPin3,OUTPUT);



pinMode(button1,INPUT);
pinMode(button2,INPUT);
pinMode(button3,INPUT);
pinMode(button4,INPUT);
pinMode(button5,INPUT);



stepmotor1.setSpeed(200); //1,motorun rpm hızı=50


Serial.begin(9600);
}

void loop() {


if(button1==HIGH){             //
  step1=step1 + 3;               //
  stepmotor1.step(step1);        //
  delay(50);                     //      1.STEP MOTOR 
                  }              //        KONTROLÜ
                                 //
if(button2==HIGH){            //
  step1=step1 - 3;               //
  stepmotor1.step(step1);        //
  delay(50);                     //
                  }              //
                                 


                                       
 
  if(button3==HIGH){                   //KAYITLI HAREKET KOMUTU 
    button_kayit_deger++;
    delay(500);                        //
     }                                 //


  switch(button_kayit_deger){
      case 1:
        step1Poskayit[0] = step1;
       break;
        
      case 2:
        step1Poskayit[1] = step1;
      break;
         
      case 3:
        step1Poskayit[2] = step1;
     break;

      case 4:
        step1Poskayit[3] = step1;
       break;

      case 5:
        step1Poskayit[4] = step1;
      break;

        case 6:
        step1Poskayit[4] = step1;
        break;
       
          }

    if(button4==HIGH)             
  {

while(1){
 
        stepmotor1.step(step1Poskayit[0]);                                                
if(button5==HIGH) break; 
        stepmotor1.step(step1Poskayit[1]);  
if(button5==HIGH) break; 
        stepmotor1.step(step1Poskayit[2]);  
if(button5==HIGH) break; 
        stepmotor1.step(step1Poskayit[3]);  
if(button5==HIGH) break; 
        stepmotor1.step(step1Poskayit[4]);  
if(button5==HIGH) break; 
        stepmotor1.step(step1Poskayit[5]);  
if(button5==HIGH) break; 
        stepmotor1.step(step1Poskayit[6]);  
if(button5==HIGH) break; 
}


step1Poskayit[6]=0;
step1Poskayit[5]=0; 
step1Poskayit[4]=0;
step1Poskayit[3]=0; 
step1Poskayit[2]=0; 
step1Poskayit[1]=0; 
}



}
