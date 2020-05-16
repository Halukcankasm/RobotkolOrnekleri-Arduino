#include <Stepper.h>
#include<SoftwareSerial.h>
#include <Servo.h> //servo motor kütüphanesini dahil ettik

Servo servo1;          //1.servo motor oluşturduk
Servo servo2;          //2.servo motor oluşturduk
Servo servo3;          //3.servo motor oluşturduk

int servo1_derece;     //1.servo motor derece değişkeni
int servo2_derece;     //2.servo motor derece değişkeni
int servo3_derece;     //3.servo motor derece değişkeni


const int step1adim = 2;  //adım sayısını belirtiyoruz
const int step1yon = 3;   //3.pine bağlıyoruz - motorun yönünü kontrol eder
const int step1pulse = 2; //2.pine atanıyor

const int step2adim = 2;  //adım sayısını belirtiyoruz
const int step2yon = 5;   //5.pine bağlıyoruz - motorun yönünü kontrol eder
const int step2pulse = 4; //4.pine atanıyor

const int step3adim = 2;  //adım sayısını belirtiyoruz
const int step3yon = 7;   //3.pine bağlıyoruz - motorun yönünü kontrol eder
const int step3pulse = 6; //2.pine atanıyor

int step1sayici = 0;
int step2sayici = 0;
int step3sayici = 0;

int i = 0;
int ix = 0;
int iy = 0;

Stepper stepmotor1(step1adim,step1pulse,step1yon,10,11);    //1.stepmotor

Stepper stepmotor2(step2adim,step2pulse,step2yon,10,11);    //2.stepmotor

Stepper stepmotor3(step3adim,step3pulse,step3yon,10,11);    //3.stepmotor

                                                            
int Servo1_Hafiza[10]={10000,10000,10000,10000,10000,10000,10000,10000,10000,10000};
int Servo2_Hafiza[10]={10000,10000,10000,10000,10000,10000,10000,10000,10000,10000};
int Servo3_Hafiza[10]={10000,10000,10000,10000,10000,10000,10000,10000,10000,10000};

int Step1_Hafiza[10]={10000,10000,10000,10000,10000,10000,10000,10000,10000,10000};
int Step2_Hafiza[10]={10000,10000,10000,10000,10000,10000,10000,10000,10000,10000};
int Step3_Hafiza[10]={10000,10000,10000,10000,10000,10000,10000,10000,10000,10000};


void setup() {
stepmotor1.setSpeed(10000);
stepmotor2.setSpeed(10000);
stepmotor3.setSpeed(10000);

servo1.attach(8);  //servo1 motorunun 8.pine bağlı
servo2.attach(13);  //servo2 motorunun 9.pine bağlı
servo3.attach(12); //servo3 motorunun 12.pine bağlı

servo1.write(0);
servo2.write(0);
servo3.write(0);

Serial.begin(9600);
}

void loop() {

  if(Serial.available()){

      char bluetooth =Serial.read();
      Serial.println(bluetooth);

      if(bluetooth == 'i' && servo1_derece < 180 )      //
      {                                                 //
      servo1_derece= servo1_derece+1;                   //
      servo1.write(  servo1_derece);                    //  1.SERVO MOTORUN BLUETOOTH                   
      Serial.println(servo1_derece);
      bluetooth=0;
      }                                                 //       KONTROLU
                                                        //
      if(bluetooth == 'm' && servo1_derece  > 0   )     //
      {                                                 //
      servo1_derece = servo1_derece -1;                 //
      servo1.write( servo1_derece );                    //                
      Serial.println(servo1_derece);                    //
      bluetooth=0;                                      //
      }                                                 //


     if(bluetooth == 'h' && servo2_derece < 180 )       //
     {                                                  //
      servo2_derece=servo2_derece+1;                    //
      servo2.write(  servo2_derece);                    //  2.SERVO MOTORUN BLUETOOTH                                                         
      Serial.println(servo2_derece);                    //
      bluetooth=0;                                      //
      }                                                 //       KONTROLU
                                                        //
      if(bluetooth == 'f' && servo2_derece > 0 )        //
      {                                                 //
      servo2_derece= servo2_derece-1;                   //
      servo2.write(servo2_derece);                      //
      Serial.println(servo2_derece);                    //
      bluetooth=0;                                      //
      }                                                 //



     if(bluetooth == 'n')            //
     {                                                  //
      servo3_derece= servo3_derece+1;                   //
      servo3.write( servo3_derece);                     //  3.SERVO MOTORUN BLUETOOTH
      Serial.println(servo3_derece);
      bluetooth=0;
      }                                                 //       KONTROLU
                                                        //
      if(bluetooth == 'k')        //
      {                                                 //
      servo3_derece= servo3_derece-1;                   //
      servo3.write(servo3_derece);                      //
      Serial.println(servo3_derece);
      bluetooth=0;
      }        



      if(bluetooth== 'd')
      {                              //
      digitalWrite(step1yon,0);      //Saat yönünün tersi                             
      stepmotor1.step(step1adim);    //
      step1sayici=step1sayici-1;
      Serial.println(step1sayici); //Adım azaltarak devam edecek
      delay(20);                     //       
      bluetooth = 0;
      }                              //        
                                     // 1.STEP KONTROLÜ
      if(bluetooth == 'b')
      {                              //
      
      digitalWrite(step1yon,1);      //Saat yönünde dönecek
      step1sayici=step1sayici+1;     //Adım adım artarak devam edecek
      stepmotor1.step(step1adim);
      Serial.println(step1sayici);   //
      delay(20);                     //
      bluetooth=0;             
      }                              //
                                 



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
                                 


      if(bluetooth== 'e')
      {                              //
      digitalWrite(step3yon,0);      //Saat yönünün tersi                             
      stepmotor3.step(step3adim);    //
      step3sayici=step3sayici-1;     //Adım azaltarak devam edecek
      Serial.println(step3sayici);   //       
      bluetooth = 0;
      }                              //        
                                     // 3.STEP KONTROLÜ
      if(bluetooth == 'g')
      {                              //
      digitalWrite(step3yon,1);      //Saat yönünde dönecek
      stepmotor3.step(step3adim); 
      step3sayici=step3sayici+1;     //Adım adım artarak devam edecek
      Serial.println(step3sayici);   //
      bluetooth=0;
      }                              //
                                 


     if(bluetooth == 'r' && i<10 )   //
     {                               //kaydetme bölümü 
     Serial.println(bluetooth);  
     Servo1_Hafiza[i]=servo1_derece;
     Servo2_Hafiza[i]=servo2_derece;
     Servo3_Hafiza[i]=servo3_derece;

     Step1_Hafiza[i]=step1sayici;
     Step2_Hafiza[i]=step2sayici;
     Step3_Hafiza[i]=step3sayici;

     i=i+1;
     }
     
     if(i==10)
     {i=0;}

     if(bluetooth== 'o'){      //Oynatma komutu
     bluetooth = 0;            //Bluetooth sıfırla
     bluetooth =Serial.read(); //Okunan değerleri bluetooth'a at
     Serial.println(bluetooth);//Bluetooth'u port a yazdır 
   
     iy =0;                                     
               while(1)
               {
               char bluetooth =Serial.read();
                 for(iy=0;iy<10;iy++)
                 {
                     
                     if(Servo1_Hafiza[iy]!= 10000)
                     {
                     servo1.write(Servo1_Hafiza[iy]);
                     delay(750);
                     }
                     
                     if(Servo2_Hafiza[iy]!= 10000)
                     {
                     servo2.write(Servo2_Hafiza[iy]);
                     delay(750);
                     }
                     
                     if(Servo3_Hafiza[iy]!= 10000)
                     {
                     servo3.write(Servo3_Hafiza[iy]); 
                     delay(750);
                     }
                     
                     if(bluetooth=='p'){ break;}   //Döngüden  çıkma komutu
                     Serial.println(bluetooth); 

                     if(Step1_Hafiza[iy]!= 10000)   //->1.Step motorun derecesi kayıt derecesinde büyük ise döngüye gir!
                     {
                            while(step1sayici>Step1_Hafiza[iy])
                            {                                         
                            digitalWrite(step1yon,0);                 //->Saat yönünün tersinde hareket et
                            stepmotor1.step(step1adim);               //->2 adım dön
                            step1sayici=step1sayici-1;
                            Serial.println(step1sayici);              //->Adım azaltarak devam et
                            if(step1sayici==Step1_Hafiza[iy])
                            {break;}  
                            }
                            delay(500);
                          
                     }
                                                                      
                     if(bluetooth=='p'){ break;}   //Döngüden çıkma komutu.
                     Serial.println(bluetooth);       
 
                     if(Step1_Hafiza[iy]!= 10000)   //->1.Step motorun derecesi kayıt derecesinde küçük ise döngüye gir!
                     {  
                            while(step1sayici<Step1_Hafiza[iy])
                            {                                       
                            digitalWrite(step1yon,1);     //->Saat yönününde hareket et
                            stepmotor1.step(step1adim);   //->2 adım dön
                            step1sayici=step1sayici+1;    //->Adım arttırarak devam et
                            Serial.println(step1sayici);
                            if(step1sayici==Step1_Hafiza[iy])
                            {break;} 
                            }
                            delay(500);
                      
                    }
                    
                    if(bluetooth=='p'){ break;} //Döngüden çıkma komutu
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
                                                                   //  2.step kayıtlı hateket oynat
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
                              delay(500);
                    }
                    if(bluetooth=='p'){ break;}
                    Serial.println(bluetooth); 

                    if(Step3_Hafiza[iy]!= 10000)
                    {
                             while(step3sayici>Step3_Hafiza[iy])
                             {         //
                             digitalWrite(step3yon,0);                 //
                             stepmotor3.step(step3adim);               //
                             step3sayici=step3sayici-1;  
                             Serial.println(step3sayici);              //
                             if(step3sayici==Step3_Hafiza[iy]){break;}
                             }
                             delay(500); 
                    }    
    
                   if(Step3_Hafiza[iy]!= 10000)
                   {               //3.step kayıtlı hareket oynat
                   if(bluetooth=='p'){ break;}                         //
                             while(step3sayici<Step3_Hafiza[iy])
                             {                                         //
                             digitalWrite(step3yon,1);                 //
                             stepmotor3.step(step3adim);               //
                             step3sayici=step3sayici+1;
                             Serial.println(step3sayici);              //
                             if(step3sayici==Step3_Hafiza[iy]){break;}
                             }
                             delay(500);
                   }
                   if(bluetooth=='p'){ break;}
                   Serial.println(bluetooth); 
               }//For(iy=0;iy<10;iy++) döngüsünün sonu           
               iy=0;
               if(bluetooth=='p'){ break;}
           }//while döngüsünün sonu    
           
           for(ix=0;ix<10;ix++)
           {
           Servo1_Hafiza[ix]=10000;    Step1_Hafiza[ix]=10000;
           Servo2_Hafiza[ix]=10000;    Step2_Hafiza[ix]=10000;
           Servo3_Hafiza[ix]=10000;    Step3_Hafiza[ix]=10000;
           }
           ix=0;
      }//Oynatma döngüsünün sonu
    }//Bluetooth döngüsü
}
  
                                 
                
