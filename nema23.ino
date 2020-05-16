#include <Stepper.h>
#include<SoftwareSerial.h>

const int step1adim = 2;  //adım sayısını belirtiyoruz
const int step1yon = 3;   //5.pine bağlıyoruz - motorun yönünü kontrol eder
const int step1pulse = 2; //4.pine atanıyor

int step1sayici = 0;


int i = 0;
int ix = 0;
int iy = 0;
int iz = 0;

Stepper stepmotor1(step1adim,step1pulse,step1yon,10,11);    //2.stepmotor

                                                          
int Step1_Hafiza[10]={10000,10000,10000,10000,10000,10000,10000,10000,10000,10000};



void setup() {
stepmotor1.setSpeed(5000);


Serial.begin(9600);
}

void loop() {

  if(Serial.available()){

      char bluetooth =Serial.read();
      Serial.println(bluetooth);

      if(bluetooth== 'c')
      {                              //
      digitalWrite(step1yon,0);      //Saat yönünün tersi                             
      stepmotor1.step(step1adim);    //
      step1sayici=step1sayici-1;     //Adım azaltarak devam edecek
      Serial.println(step1sayici);   //       
      bluetooth = 0;
      }                              //        
                                     // 2.STEP KONTROLÜ
      if(bluetooth == 'a'){          //
      digitalWrite(step1yon,1);      //Saat yönünde dönecek
      step1sayici=step1sayici+1;     //Adım adım artarak devam edecek
      stepmotor1.step(step1adim);    //
      Serial.println(step1sayici);   //
      bluetooth=0;
      }                              //
          
                                 



if(bluetooth == 'r'&& ix<10 )
{             //kaydetme bölümü
Step1_Hafiza[ix]=step1sayici;
ix=ix+1;
}
  if(ix==10){ix=0;}


if(bluetooth== 'o'){
  bluetooth = 0;
  bluetooth =Serial.read(); //Oynatma komutu
  Serial.println(bluetooth);
  iy=0;
              while(1)
              {
               char bluetooth =Serial.read();
                  for(iy=0;iy<10;iy++)
                  {
                     if(bluetooth=='p'){ break;}   //Döngüden çıkma komutu.
                     Serial.println(bluetooth);
                     
                    if(Step1_Hafiza[iy]!= 10000)
                       {
                             while(step1sayici>Step1_Hafiza[iy])  //->2.Step motorun derecesi kayıt derecesinde büyük ise döngüye gir!
                             
                              {         
                              digitalWrite(step1yon,0);           //->Saat yönünün tersinde hareket et
                              stepmotor1.step(step1adim);         //->2 adım dön
                              step1sayici=step1sayici-1;
                              Serial.println(step1sayici);        //->Adım azaltarak devam et
                              if(step1sayici==Step1_Hafiza[iy])
                              {break;}
                              }
                              delay(500);
                              
                    }  
                                       
                     
                    if(bluetooth=='p'){ break;} 
                    Serial.println(bluetooth); 
 
                    if(Step1_Hafiza[iy]!= 10000)
                    {                                            
                              while(step1sayici<Step1_Hafiza[iy]) //->2.Step motorun derecesi kayıt derecesinde küçük ise döngüye gir!
                              { 
                                     
                              digitalWrite(step1yon,1);          //->Saat yönününde hareket et
                              stepmotor1.step(step1adim);        //->2 adım dön
                              step1sayici=step1sayici+1; 
                              Serial.println(step1sayici);        //->Adım arttırarak devam et
                              if(step1sayici==Step1_Hafiza[iy])
                              {break;}
                              }
                    if(bluetooth=='p'){ break;}
                    Serial.println(bluetooth);
                              delay(500);
                    if(bluetooth=='p'){ break;}
                    Serial.println(bluetooth);
                             
                    }

               }
    
           }
            for(iz=0;iz<10;iz++)
           {
            Step1_Hafiza[iz]=10000;
           }
           iz=0;
       }
     }
}
  
                                 
                
