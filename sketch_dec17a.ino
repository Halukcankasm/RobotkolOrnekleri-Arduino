#include <Stepper.h>
#include<SoftwareSerial.h>
#include <Servo.h> //servo motor kütüphanesini dahil ettik

Servo servo1;          //1.servo motor oluşturduk
Servo servo2;          //2.servo motor oluşturduk
Servo servo3;          //3.servo motor oluşturduk

int servo1_derece;     //1.servo motor derece değişkeni
int servo2_derece;     //2.servo motor derece değişkeni
int servo3_derece;     //3.servo motor derece değişkeni


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


int step1Poskayit[] = {1,1,1,1,1,1,1,1,1,1};     //1.step motorun kayıt başlangışları
int step2Poskayit[] = {1,1,1,1,1,1,1,1,1,1};     //2.step motorun kayıt başlangışları
int step3Poskayit[] = {1,1,1,1,1,1,1,1,1,1};     //3.step motorun kayıt başlangışları

int servo1Poskayit[] = {1,1,1,1,1,1,1,1,1,1};    //1.servo motorun kayıt başlangışları
int servo2Poskayit[] = {1,1,1,1,1,1,1,1,1,1};    //2.servo motorun kayıt başlangışları
int servo3Poskayit[] = {1,1,1,1,1,1,1,1,1,1};    //3.servo motorun kayıt başlangışları
 
int i ;
int button_kayit_deger;



Stepper stepmotor1(step1adim,step1pulse,step1yon,10,11);    //1.stepmotor

Stepper stepmotor2(step2adim,step2pulse,step2yon,10,11);    //2.stepmotor

Stepper stepmotor3(step3adim,step3pulse,step3yon,10,11);    //3.stepmotor

                                                            


//stepmotor nesnesi üretildi
//ve Step motorun bir tam turu 32 parçaya(step) bölündü
//dolayısıyla her bir stepte motor 360/11,25=32derece dönecek



void setup() {



stepmotor1.setSpeed(10000); //1,motorun rpm hızı=50
stepmotor2.setSpeed(10000); //2,motorun rpm hızı=50
stepmotor3.setSpeed(10000); //3,motorun rpm hızı=50

servo1.attach(8);  //servo1 motorunun 9.pine bağlı
servo2.attach(13); //servo1 motorunun 10.pine bağlı
servo3.attach(12); //servo1 motorunun 11.pine bağlı

Serial.begin(9600);
}

void loop() {

  if(Serial.available()){

      char bluetooth =Serial.read();
      Serial.println(bluetooth);

if(bluetooth == 'h' && servo1_derece < 180 )            //
     {                                                  //
      servo1_derece= servo1_derece+1;                   //
      servo1.write(  servo1_derece);                    //  1.SERVO MOTORUN BLUETOOTH                   
      delay(100);                                       //
      }                                                 //       KONTROLU
                                                        //
      if(bluetooth == 'f' && servo1_derece  > 0   )     //
      {                                                 //
      servo1_derece = servo1_derece -1;                 //
      servo1.write( servo1_derece );                    //                
      delay(100);                                       //
      }                                                 //


     if(bluetooth == 'i' && servo2_derece < 180 )       //
     {                                                  //
     servo2_derece=servo2_derece+1;                     //
      servo2.write(  servo2_derece);                    //  2.SERVO MOTORUN BLUETOOTH                  
      delay(100);                                       //
      }                                                 //       KONTROLU
                                                        //
      if(bluetooth == 'm' && servo2_derece > 0 )        //
      {                                                 //
      servo2_derece= servo2_derece-1;                   //
      servo2.write(servo2_derece);                      //
      delay(100);                                       //
      }                                                 //



     if(bluetooth == 'n' && servo3_derece < 180 )       //
     {                                                  //
      servo3_derece= servo3_derece+1;                   //
      servo3.write( servo3_derece);                     //  3.SERVO MOTORUN BLUETOOTH
      delay(100);                                       //
      }                                                 //       KONTROLU
                                                        //
      if(bluetooth == 'k' && servo3_derece > 0 )        //
      {                                                 //
      servo3_derece= servo3_derece-1;                   //
      servo3.write(servo3_derece);                      //
      delay(100);                                       //
      }        


if(bluetooth== 'd'){             //
  digitalWrite(step1yon,0);      //Saat yönünün tersi                             
  stepmotor1.step(step1adim);    //
  step1sayici--;                 //Adım azaltarak devam edecek
  delay(20);                     //       
  bluetooth = 0;              }  //        
                                 // 1.STEP KONTROLÜ
if(bluetooth == 'b'){            //
  digitalWrite(step1yon,1);      //Saat yönünde dönecek
  step1sayici++;                 //Adım adım artarak devam edecek
  stepmotor1.step(step1adim);    //
  delay(20);                     //
  bluetooth=0;             }     //
                                 




if(bluetooth== 'a'){             //
  digitalWrite(step2yon,0);      //Saat yönünün tersi                             
  stepmotor2.step(step2adim);    //
  step1sayici--;                 //Adım azaltarak devam edecek
                                 //       
  bluetooth = 0;              }  //        
                                 // 2.STEP KONTROLÜ
if(bluetooth == 'c'){            //
  digitalWrite(step2yon,1);      //Saat yönünde dönecek
  step2sayici++;                 //Adım adım artarak devam edecek
  stepmotor2.step(step2adim);    //
                                 //
  bluetooth=0;             }     //
                                 


if(bluetooth== 'e'){             //
  digitalWrite(step3yon,0);      //Saat yönünün tersi                             
  stepmotor3.step(step3adim);    //
  step1sayici--;                 //Adım azaltarak devam edecek
                                 //       
  bluetooth = 0;              }  //        
                                 // 3.STEP KONTROLÜ
if(bluetooth == 'g'){            //
  digitalWrite(step3yon,1);      //Saat yönünde dönecek
  step3sayici++;                 //Adım adım artarak devam edecek
  stepmotor3.step(step3adim);    //
                                 //
  bluetooth=0;             }     //
                                 

                                 
                                 

                                       
 
  if(bluetooth == 'r'){                //KAYITLI HAREKET KOMUTU 
    button_kayit_deger ++;             //
         delay(100);                   //
     }                                 //
     
  switch(button_kayit_deger){
      case 1:
        step1Poskayit[0] = step1adim;
        step2Poskayit[0] = step2adim;
        step3Poskayit[0] = step3adim;
       
        servo1Poskayit[0] = servo1_derece;
        servo2Poskayit[0] = servo2_derece;
        servo3Poskayit[0] = servo3_derece;
       

        break;
        
      case 2:
        step1Poskayit[1] = step1adim;
        step2Poskayit[1] = step2adim;
        step3Poskayit[1] = step3adim;
        
        servo1Poskayit[1] = servo1_derece;
        servo2Poskayit[1] = servo2_derece;
        servo3Poskayit[1] = servo3_derece;

         break;
         
      case 3:
        step1Poskayit[2] = step1adim;
        step2Poskayit[2] = step2adim;
        step3Poskayit[2] = step3adim;
        
        servo1Poskayit[2] = servo1_derece;
        servo2Poskayit[2] = servo2_derece;
        servo3Poskayit[2] = servo3_derece;         

         break;

      case 4:
        step1Poskayit[3] = step1adim;
        step2Poskayit[3] = step2adim;
        step3Poskayit[3] = step3adim;
        
        servo1Poskayit[3] = servo1_derece;
        servo2Poskayit[3] = servo2_derece;
        servo3Poskayit[3] = servo3_derece;        

         break;

      case 5:
        step1Poskayit[4] = step1adim;
        step2Poskayit[4] = step2adim;
        step3Poskayit[4] = step3adim;
        
        servo1Poskayit[4] = servo1_derece;
        servo2Poskayit[4] = servo2_derece;
        servo3Poskayit[4] = servo3_derece;      


        case 6:
        step1Poskayit[5] = step1adim;
        step2Poskayit[5] = step2adim;
        step3Poskayit[5] = step3adim;
        
        servo1Poskayit[5] = servo1_derece;
        servo2Poskayit[5] = servo2_derece;
        servo3Poskayit[5] = servo3_derece;  

        case 7:
        step1Poskayit[6] = step1adim;
        step2Poskayit[6] = step2adim;
        step3Poskayit[6] = step3adim;
        
        servo1Poskayit[6] = servo1_derece;
        servo2Poskayit[6] = servo2_derece;
        servo3Poskayit[6] = servo3_derece;  


        case 8:
        step1Poskayit[7] = step1adim;
        step2Poskayit[7] = step2adim;
        step3Poskayit[7] = step3adim;
        
        servo1Poskayit[7] = servo1_derece;
        servo2Poskayit[7] = servo2_derece;
        servo3Poskayit[7] = servo3_derece;  

        case 9:
        step1Poskayit[8] = step1adim;
        step2Poskayit[8] = step2adim;
        step3Poskayit[8] = step3adim;
        
        servo1Poskayit[8] = servo1_derece;
        servo2Poskayit[8] = servo2_derece;
        servo3Poskayit[8] = servo3_derece;  


        case 10:
        step1Poskayit[9] = step1adim;
        step2Poskayit[9] = step2adim;
        step3Poskayit[9] = step3adim;
        
        servo1Poskayit[9] = servo1_derece;
        servo2Poskayit[9] = servo2_derece;
        servo3Poskayit[9] = servo3_derece;          

         break;
          }

    if(bluetooth='G' )             
  {

while(1){
 
if(servo1Poskayit[0]>0 && servo2Poskayit[0]>0 && servo3Poskayit[0]>0){  
        while(
        stepmotor1.step(step1Poskayit[0]);                                
        stepmotor2.step(step2Poskayit[0]);                                
        stepmotor3.step(step3Poskayit[0]);   
        servo1.write(servo1Poskayit[0]);
        servo2.write(servo2Poskayit[0]);
        servo3.write(servo3Poskayit[0]); 
        delay(300);}                               
if(bluetooth='Q') break; 

if(servo1Poskayit[1]>0 && servo2Poskayit[1]>0 && servo3Poskayit[1]>0){
        stepmotor1.step(step1Poskayit[1]);  
        stepmotor2.step(step2Poskayit[1]);   
        stepmotor3.step(step3Poskayit[1]);                                                          
        servo1.write(servo1Poskayit[1]);
        servo2.write(servo2Poskayit[1]);
        servo3.write(servo3Poskayit[1]);
        delay(300); }
        
if(bluetooth='Q') break; 

if(servo1Poskayit[2]>0 && servo2Poskayit[2]>0 && servo3Poskayit[2]>0){
        stepmotor1.step(step1Poskayit[2]);  
        stepmotor2.step(step2Poskayit[2]);   
        stepmotor3.step(step3Poskayit[2]);   
if(bluetooth='Q') break; 
        servo1.write(servo1Poskayit[2]);
        servo2.write(servo2Poskayit[2]);
        servo3.write(servo3Poskayit[2]); 
        delay(300);}
if(bluetooth='Q') break; 

if(servo1Poskayit[3]>0 && servo2Poskayit[3]>0 && servo3Poskayit[3]>0){
        stepmotor1.step(step1Poskayit[3]);  
        stepmotor2.step(step2Poskayit[3]);   
        stepmotor3.step(step3Poskayit[3]);    
if(bluetooth='Q') break; 
        servo1.write(servo1Poskayit[3]);
        servo2.write(servo2Poskayit[3]);
        servo3.write(servo3Poskayit[3]); 
        delay(300);}
if(bluetooth='Q') break; 

if(servo1Poskayit[4]>0 && servo2Poskayit[4]>0 && servo3Poskayit[4]>0){
        stepmotor1.step(step1Poskayit[4]);  
        stepmotor2.step(step2Poskayit[4]);   
        stepmotor3.step(step3Poskayit[4]);   
        servo1.write(servo1Poskayit[4]);
        servo2.write(servo2Poskayit[4]);
        servo3.write(servo3Poskayit[4]);
        delay(300);}
if(bluetooth='Q') break; 

if(servo1Poskayit[5]>0 && servo2Poskayit[5]>0 && servo3Poskayit[5]>0){
        stepmotor1.step(step1Poskayit[5]);  
        stepmotor2.step(step2Poskayit[5]);   
        stepmotor3.step(step3Poskayit[5]);   
        servo1.write(servo1Poskayit[5]);
        servo2.write(servo2Poskayit[5]);
        servo3.write(servo3Poskayit[5]);
        delay(300);}
if(bluetooth='Q') break; 

if(servo1Poskayit[6]>0 && servo2Poskayit[6]>0 && servo3Poskayit[6]>0){
        stepmotor1.step(step1Poskayit[6]);  
        stepmotor2.step(step2Poskayit[6]);   
        stepmotor3.step(step3Poskayit[6]);   
        servo1.write(servo1Poskayit[6]);
        servo2.write(servo2Poskayit[6]);
        servo3.write(servo3Poskayit[6]); 
        delay(300);}
if(bluetooth='Q') break; 

if(servo1Poskayit[7]>0 && servo2Poskayit[7]>0 && servo3Poskayit[7]>0){
        stepmotor1.step(step1Poskayit[7]);  
        stepmotor2.step(step2Poskayit[7]);   
        stepmotor3.step(step3Poskayit[7]);   
        servo1.write(servo1Poskayit[7]);
        servo2.write(servo2Poskayit[7]);
        servo3.write(servo3Poskayit[7]); 
        delay(300);}
if(bluetooth='Q') break; 

if(servo1Poskayit[8]>0 && servo2Poskayit[8]>0 && servo3Poskayit[8]>0){
        stepmotor1.step(step1Poskayit[8]);  
        stepmotor2.step(step2Poskayit[8]);   
        stepmotor3.step(step3Poskayit[8]);   
        servo1.write(servo1Poskayit[8]);
        servo2.write(servo2Poskayit[8]);
        servo3.write(servo3Poskayit[8]);
        delay(300);}
if(bluetooth='Q') break; 

if(servo1Poskayit[9]>0 && servo2Poskayit[9]>0 && servo3Poskayit[9]>0){
        stepmotor1.step(step1Poskayit[9]);  
        stepmotor2.step(step2Poskayit[9]);   
        stepmotor3.step(step3Poskayit[9]);   
        servo1.write(servo1Poskayit[9]);
        servo2.write(servo2Poskayit[9]);
        servo3.write(servo3Poskayit[9]); 
        delay(300);}
if(bluetooth='Q') break; 


}
button_kayit_deger = 0;
step1Poskayit[9]=0; step2Poskayit[9]=0; step3Poskayit[9]=0; servo1Poskayit[9]=0; servo2Poskayit[9]=0; servo3Poskayit[9]= 0;
step1Poskayit[8]=0; step2Poskayit[8]=0; step3Poskayit[8]=0; servo1Poskayit[8]=0; servo2Poskayit[8]=0; servo3Poskayit[8]= 0;
step1Poskayit[7]=0; step2Poskayit[7]=0; step3Poskayit[7]=0; servo1Poskayit[7]=0; servo2Poskayit[7]=0; servo3Poskayit[7]= 0;
step1Poskayit[6]=0; step2Poskayit[6]=0; step3Poskayit[6]=0; servo1Poskayit[6]=0; servo2Poskayit[6]=0; servo3Poskayit[6]= 0;
step1Poskayit[5]=0; step2Poskayit[5]=0; step3Poskayit[5]=0; servo1Poskayit[5]=0; servo2Poskayit[5]=0; servo3Poskayit[5]= 0;
step1Poskayit[4]=0; step2Poskayit[4]=0; step3Poskayit[4]=0; servo1Poskayit[4]=0; servo2Poskayit[4]=0; servo3Poskayit[4]= 0;
step1Poskayit[3]=0; step2Poskayit[3]=0; step3Poskayit[3]=0; servo1Poskayit[3]=0; servo2Poskayit[3]=0; servo3Poskayit[3]= 0;
step1Poskayit[2]=0; step2Poskayit[2]=0; step3Poskayit[2]=0; servo1Poskayit[2]=0; servo2Poskayit[2]=0; servo3Poskayit[2]= 0;
step1Poskayit[1]=0; step2Poskayit[1]=0; step3Poskayit[1]=0; servo1Poskayit[1]=0; servo2Poskayit[1]=0; servo3Poskayit[1]= 0;
}

if(bluetooth ==  'H'){                       //
                                             //
        stepmotor1.step(step1Poskayit[i]);   //
        stepmotor2.step(step2Poskayit[i]);   //
        stepmotor3.step(step3Poskayit[i]);   //  KAPATMA İSKELESİ
                                             //
        servo1.write(servo1Poskayit[i]);     //
        servo2.write(servo2Poskayit[i]);     //
        servo3.write(servo3Poskayit[i]);     //
                                             //
  }                                          //

}
}
