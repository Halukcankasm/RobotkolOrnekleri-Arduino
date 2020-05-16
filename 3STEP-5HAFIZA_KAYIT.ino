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


int step1Poskayit[] = {1,1,1,1,1}; 
int step2Poskayit[] = {1,1,1,1,1};
int step3Poskayit[] = {1,1,1,1,1};


int button_kayit_deger = 0; 
boolean button_baslat_deger = false;

int i ;
const int button_kayit = 14; 
const int button_baslat = 15;



int adim0=0;
int adim1=0;
int adim2=0;

int deger0=0;
int deger1=0;
int deger2=0;

int step1 = 0;
int step2 = 0;
int step3 = 0;

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

  pinMode(button_kayit, INPUT);
  pinMode(button_baslat, INPUT);

  Serial.begin(9600);
}

void loop() {

  if(Serial.available()){

      int steppos =Serial.read();
      Serial.println(steppos);



if(steppos == '0'){              //
  step1=step1 + 3;               //
  stepmotor1.step(step1);        //
  delay(50);                     //      1.STEP MOTOR 
                  }              //        KONTROLÜ
                                 //
if(steppos == '1'){              //
  step1=step1 - 3;               //
  stepmotor1.step(step1);        //
  delay(50);                     //
                  }              //
                                 




if(steppos == '2'){              //
  step2=step2 + 3;               //
  stepmotor2.step(step2);        //
  delay(50);                     //      2.STEP MOTOR 
                  }              //        KONTROLÜ
                                 //
if(steppos == '3'){              //
  step2=step2 - 3;               //
  stepmotor2.step(step2);        //
  delay(50);                     //
                  }              //


if(steppos == '4'){              //
  step3=step3 + 3;               //
  stepmotor3.step(step3);        //
  delay(50);                     //      3.STEP MOTOR 
                  }              //        KONTROLÜ
                                 //
if(steppos == '5'){              //
  step3=step3 - 3;               //
  stepmotor3.step(step3);        //
  delay(50);                     //
                  }              //

                  


                                 
                                 

                                       //STEP KAYITLI HAREKET
 
  if(steppos == '6'){                  //1.KAYITLI HAREKET KOMUTU 
    button_kayit_deger = 1;            //
     }                                 //

  if(steppos == '7'){                  //2.KAYITLI HAREKET KOMUTU   
    button_kayit_deger = 2;            //
     }                                 //

  if(steppos == '8'){                  //3.KAYITLI HAREKET KOMUTU 
    button_kayit_deger = 3;            //
     }                                 //

  if(steppos == '9'){                  //4.KAYITLI HAREKET KOMUTU 
    button_kayit_deger = 4;            //
     }                                 //

  if(steppos == 'A'){                  //5.KAYITLI HAREKET KOMUTU 
    button_kayit_deger = 5;            //
     }                                 //

     
  
  switch(button_kayit_deger){
      case 1:
        step1Poskayit[0] = step1;
        step2Poskayit[0] = step2;
        step3Poskayit[0] = step3;
       

        break;
        
      case 2:
        step1Poskayit[1] = step1;
        step2Poskayit[1] = step2;
        step3Poskayit[1] = step3;
        

         break;
         
      case 3:
        step1Poskayit[2] = step1;
        step2Poskayit[2] = step2;
        step3Poskayit[2] = step3;
         

         break;

      case 4:
        step1Poskayit[3] = step1;
        step2Poskayit[3] = step2;
        step3Poskayit[3] = step3;
        

         break;

      case 5:
        step1Poskayit[4] = step1;
        step2Poskayit[4] = step2;
        step3Poskayit[4] = step3;
        

         break;
          }

    if(steppos='B' )             
  {
   stepmotor1.step(step1Poskayit[0]);  
      stepmotor2.step(step2Poskayit[0]);   
         stepmotor3.step(step3Poskayit[0]);      
  }

      if(steppos='C' )             
  {
   stepmotor1.step(step1Poskayit[1]);  
      stepmotor2.step(step2Poskayit[1]);   
         stepmotor3.step(step3Poskayit[1]);      
  }

      if(steppos='D' )             
  {
   stepmotor1.step(step1Poskayit[2]);  
      stepmotor2.step(step2Poskayit[2]);   
         stepmotor3.step(step3Poskayit[2]);      
  }

      if(steppos='E' )             
  {
   stepmotor1.step(step1Poskayit[3]);  
      stepmotor2.step(step2Poskayit[3]);   
         stepmotor3.step(step3Poskayit[3]);      
  }

      if(steppos='F' )             
  {
   stepmotor1.step(step1Poskayit[4]);  
      stepmotor2.step(step2Poskayit[4]);   
         stepmotor3.step(step3Poskayit[4]);      
  }
     
}
}
