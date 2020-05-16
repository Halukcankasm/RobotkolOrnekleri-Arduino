#include <Stepper.h>
#include<SoftwareSerial.h>

const int step2adim = 2;  //adım sayısını belirtiyoruz
const int step2yon = 5;   //5.pine bağlıyoruz - motorun yönünü kontrol eder
const int step2pulse = 4; //4.pine atanıyor

int step2sayici = 0;


int i = 0;
int ix = 0;
int iy = 0;
int iz = 0;

Stepper stepmotor2(step2adim,step2pulse,step2yon,10,11);    //2.stepmotor

                                                          
int Step2_Hafiza[10]={10000,10000,10000,10000,10000,10000,10000,10000,10000,10000};



void setup() {
stepmotor2.setSpeed(10000);


Serial.begin(9600);
}

void loop() {

  if(Serial.available()){

      char bluetooth =Serial.read();
      Serial.println(bluetooth);

      if(bluetooth== 'c')
      {                              //
      digitalWrite(step2yon,0);      //Saat yönünün tersi                             
      stepmotor2.step(step2adim);    //
      step2sayici=step2sayici-1;     //Adım azaltarak devam edecek
      Serial.println(step2sayici);   //       
      bluetooth = 0;
      }                              //        
                                     // 2.STEP KONTROLÜ
      if(bluetooth == 'a'){          //
      digitalWrite(step2yon,1);      //Saat yönünde dönecek
      step2sayici=step2sayici+1;     //Adım adım artarak devam edecek
      stepmotor2.step(step2adim);    //
      Serial.println(step2sayici);   //
      bluetooth=0;
      }                              //
          
                                 



if(bluetooth == 'r'&& ix<10 )
{             //kaydetme bölümü
Step2_Hafiza[ix]=step2sayici;
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
                     
                    if(Step2_Hafiza[iy]!= 10000)
                       {
                             while(step2sayici>Step2_Hafiza[iy])  //->2.Step motorun derecesi kayıt derecesinde büyük ise döngüye gir!
                             
                              {         
                              digitalWrite(step2yon,0);           //->Saat yönünün tersinde hareket et
                              stepmotor2.step(step2adim);         //->2 adım dön
                              step2sayici=step2sayici-1;
                              Serial.println(step2sayici);        //->Adım azaltarak devam et
                              if(step2sayici==Step2_Hafiza[iy])
                              {break;}
                              }
                              delay(500);
                              
                    }  
                                       
                     
                    if(bluetooth=='p'){ break;} 
                    Serial.println(bluetooth); 
 
                    if(Step2_Hafiza[iy]!= 10000)
                    {                                            
                              while(step2sayici<Step2_Hafiza[iy]) //->2.Step motorun derecesi kayıt derecesinde küçük ise döngüye gir!
                              { 
                                     
                              digitalWrite(step2yon,1);          //->Saat yönününde hareket et
                              stepmotor2.step(step2adim);        //->2 adım dön
                              step2sayici=step2sayici+1; 
                              Serial.println(step2sayici);        //->Adım arttırarak devam et
                              if(step2sayici==Step2_Hafiza[iy])
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
            Step2_Hafiza[iz]=10000;
           }
           iz=0;
       }
     }
}
  
                                 
                
