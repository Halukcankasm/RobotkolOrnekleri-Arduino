#include <Stepper.h>
#include<SoftwareSerial.h>
#include <Servo.h> //servo motor kütüphanesini dahil ettik

Servo servo1;          //1.servo motor oluşturduk
Servo servo2;          //2.servo motor oluşturduk
Servo servo3;          //3.servo motor oluşturduk

int servo1_derece;     //1.servo motor derece değişkeni
int servo2_derece;     //2.servo motor derece değişkeni
int servo3_derece;     //3.servo motor derece değişkeni

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


const int step1adim = 2;  //adım sayısını belirtiyoruz
const int step1yon = 3;   //3.pine bağlıyoruz - motorun yönünü kontrol eder
const int step1pulse = 2; //2.pine atanıyor

const int step2adim = 2;  //adım sayısını belirtiyoruz
const int step2yon = 5;   //5.pine bağlıyoruz - motorun yönünü kontrol eder
const int step2pulse = 4; //4.pine atanıyor

const int step3adim = 2;  //adım sayısını belirtiyoruz
const int step3yon = 7;   //3.pine bağlıyoruz - motorun yönünü kontrol eder
const int step3pulse = 6; //2.pine atanıyor


Stepper stepmotor1(step1adim,step1pulse,step1yon,10,11);    //1.stepmotor

Stepper stepmotor2(step2adim,step2pulse,step2yon,10,11);    //2.stepmotor

Stepper stepmotor3(step3adim,step3pulse,step3yon,10,11);    //3.stepmotor

     

//stepmotor nesnesi üretildi
//ve Step motorun bir tam turu 32 parçaya(step) bölündü
//dolayısıyla her bir stepte motor 360/11,25=32derece dönecek



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

if(bluetooth == 'Q' && servo1_derece < 180 )            //
     {                                                  //
      servo1_derece= servo1_derece+1;                   //
      servo1.write(  servo1_derece);                    //  1.SERVO MOTORUN BLUETOOTH                   
      delay(100);                                       //
      }                                                 //       KONTROLU
                                                        //
      if(bluetooth == 'W' && servo1_derece  > 0   )     //
      {                                                 //
      servo1_derece = servo1_derece -1;                 //
      servo1.write( servo1_derece );                    //                
      delay(100);                                       //
      }                                                 //


     if(bluetooth == 'E' && servo2_derece < 180 )       //
     {                                                  //
     servo2_derece=servo2_derece+1;                     //
      servo2.write(  servo2_derece);                    //  2.SERVO MOTORUN BLUETOOTH                  
      delay(100);                                       //
      }                                                 //       KONTROLU
                                                        //
      if(bluetooth == 'R' && servo2_derece > 0 )        //
      {                                                 //
      servo2_derece= servo2_derece-1;                   //
      servo2.write(servo2_derece);                      //
      delay(100);                                       //
      }                                                 //



     if(bluetooth == 'T' && servo3_derece < 180 )       //
     {                                                  //
      servo3_derece= servo3_derece+1;                   //
      servo3.write( servo3_derece);                     //  3.SERVO MOTORUN BLUETOOTH
      delay(100);                                       //
      }                                                 //       KONTROLU
                                                        //
      if(bluetooth == 'Y' && servo3_derece > 0 )        //
      {                                                 //
      servo3_derece= servo3_derece-1;                   //
      servo3.write(servo3_derece);                      //
      delay(100);                                       //
      }        


if(bluetooth== 'g'){             //
  digitalWrite(step1yon,0);      //Saat yönünün tersi                             
  stepmotor1.step(step1adim);    //
  step1sayici--;                 //Adım azaltarak devam edecek
  delay(20);                     //       
  bluetooth = 0;              }  //        
                                 // 1.STEP KONTROLÜ
if(bluetooth == 'a'){            //
  digitalWrite(step1yon,1);      //Saat yönünde dönecek
  step1sayici++;                 //Adım adım artarak devam edecek
  stepmotor1.step(step1adim);    //
  delay(20);                     //
  bluetooth=0;             }     //
                                 




if(bluetooth== 'h'){             //
  digitalWrite(step2yon,0);      //Saat yönünün tersi                             
  stepmotor2.step(step2adim);    //
  step1sayici--;                 //Adım azaltarak devam edecek
                       //       
  bluetooth = 0;              }  //        
                                 // 2.STEP KONTROLÜ
if(bluetooth == 'b'){            //
  digitalWrite(step2yon,1);      //Saat yönünde dönecek
  step2sayici++;                 //Adım adım artarak devam edecek
  stepmotor2.step(step2adim);    //
                       //
  bluetooth=0;             }     //
                                 


if(bluetooth== 'j'){             //
  digitalWrite(step3yon,0);      //Saat yönünün tersi                             
  stepmotor3.step(step3adim);    //
  step1sayici--;                 //Adım azaltarak devam edecek
                     //       
  bluetooth = 0;              }  //        
                                 // 3.STEP KONTROLÜ
if(bluetooth == 'c'){            //
  digitalWrite(step3yon,1);      //Saat yönünde dönecek
  step3sayici++;                 //Adım adım artarak devam edecek
  stepmotor3.step(step3adim);    //
                      //
  bluetooth=0;             }     //
                                 

                                 
                                 

                                       
 
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

  if(bluetooth == 'A'){                //5.KAYITLI HAREKET KOMUTU 
    button_kayit_deger = 5;            //
     }                                 //


  if(bluetooth == 'B'){                //6.KAYITLI HAREKET KOMUTU 
    button_kayit_deger = 6;            //
     }                                 //

   if(bluetooth == 'C'){               //7.KAYITLI HAREKET KOMUTU 
    button_kayit_deger = 7;            //
     }                                 //

  if(bluetooth == 'D'){                //8.KAYITLI HAREKET KOMUTU 
    button_kayit_deger = 8;            //
     }                                 //         
     

    if(bluetooth == 'E'){              //9.KAYITLI HAREKET KOMUTU 
    button_kayit_deger = 9;            //
     }                                 //

  if(bluetooth == 'F'){                //10.KAYITLI HAREKET KOMUTU 
    button_kayit_deger = 10;           //
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


        case 6:
        step1Poskayit[4] = step1;
        step2Poskayit[4] = step2;
        step3Poskayit[4] = step3;
        
        servo1Poskayit[4] = servo1_derece;
        servo2Poskayit[4] = servo2_derece;
        servo3Poskayit[4] = servo3_derece;  

        case 7:
        step1Poskayit[4] = step1;
        step2Poskayit[4] = step2;
        step3Poskayit[4] = step3;
        
        servo1Poskayit[4] = servo1_derece;
        servo2Poskayit[4] = servo2_derece;
        servo3Poskayit[4] = servo3_derece;  


        case 8:
        step1Poskayit[4] = step1;
        step2Poskayit[4] = step2;
        step3Poskayit[4] = step3;
        
        servo1Poskayit[4] = servo1_derece;
        servo2Poskayit[4] = servo2_derece;
        servo3Poskayit[4] = servo3_derece;  

        case 9:
        step1Poskayit[4] = step1;
        step2Poskayit[4] = step2;
        step3Poskayit[4] = step3;
        
        servo1Poskayit[4] = servo1_derece;
        servo2Poskayit[4] = servo2_derece;
        servo3Poskayit[4] = servo3_derece;  


        case 10:
        step1Poskayit[4] = step1;
        step2Poskayit[4] = step2;
        step3Poskayit[4] = step3;
        
        servo1Poskayit[4] = servo1_derece;
        servo2Poskayit[4] = servo2_derece;
        servo3Poskayit[4] = servo3_derece;          

         break;
          }

    if(bluetooth='G' )             
  {

while(1){
 
if(servo1Poskayit[0]>0 && servo2Poskayit[0]>0 && servo3Poskayit[0]>0){  
        stepmotor1.step(step1Poskayit[0]);                                
        stepmotor2.step(step2Poskayit[0]);                                
        stepmotor3.step(step3Poskayit[0]);   
        servo1.write(servo1Poskayit[0]);
        servo2.write(servo2Poskayit[0]);
        servo3.write(servo3Poskayit[0]); }                               
if(bluetooth='Q') break; 

if(servo1Poskayit[1]>0 && servo2Poskayit[1]>0 && servo3Poskayit[1]>0){
        stepmotor1.step(step1Poskayit[1]);  
        stepmotor2.step(step2Poskayit[1]);   
        stepmotor3.step(step3Poskayit[1]);                                                          
        servo1.write(servo1Poskayit[1]);
        servo2.write(servo2Poskayit[1]);
        servo3.write(servo3Poskayit[1]); }
        
if(bluetooth='Q') break; 

if(servo1Poskayit[2]>0 && servo2Poskayit[2]>0 && servo3Poskayit[2]>0){
        stepmotor1.step(step1Poskayit[2]);  
        stepmotor2.step(step2Poskayit[2]);   
        stepmotor3.step(step3Poskayit[2]);   
if(bluetooth='Q') break; 
        servo1.write(servo1Poskayit[2]);
        servo2.write(servo2Poskayit[2]);
        servo3.write(servo3Poskayit[2]); }
if(bluetooth='Q') break; 

if(servo1Poskayit[3]>0 && servo2Poskayit[3]>0 && servo3Poskayit[3]>0){
        stepmotor1.step(step1Poskayit[3]);  
        stepmotor2.step(step2Poskayit[3]);   
        stepmotor3.step(step3Poskayit[3]);    
if(bluetooth='Q') break; 
        servo1.write(servo1Poskayit[3]);
        servo2.write(servo2Poskayit[3]);
        servo3.write(servo3Poskayit[3]); }
if(bluetooth='Q') break; 

if(servo1Poskayit[4]>0 && servo2Poskayit[4]>0 && servo3Poskayit[4]>0){
        stepmotor1.step(step1Poskayit[4]);  
        stepmotor2.step(step2Poskayit[4]);   
        stepmotor3.step(step3Poskayit[4]);   
        servo1.write(servo1Poskayit[4]);
        servo2.write(servo2Poskayit[4]);
        servo3.write(servo3Poskayit[4]); }
if(bluetooth='Q') break; 

if(servo1Poskayit[5]>0 && servo2Poskayit[5]>0 && servo3Poskayit[5]>0){
        stepmotor1.step(step1Poskayit[5]);  
        stepmotor2.step(step2Poskayit[5]);   
        stepmotor3.step(step3Poskayit[5]);   
        servo1.write(servo1Poskayit[5]);
        servo2.write(servo2Poskayit[5]);
        servo3.write(servo3Poskayit[5]);}
if(bluetooth='Q') break; 

if(servo1Poskayit[6]>0 && servo2Poskayit[6]>0 && servo3Poskayit[6]>0){
        stepmotor1.step(step1Poskayit[6]);  
        stepmotor2.step(step2Poskayit[6]);   
        stepmotor3.step(step3Poskayit[6]);   
        servo1.write(servo1Poskayit[6]);
        servo2.write(servo2Poskayit[6]);
        servo3.write(servo3Poskayit[6]); }
if(bluetooth='Q') break; 

if(servo1Poskayit[7]>0 && servo2Poskayit[7]>0 && servo3Poskayit[7]>0){
        stepmotor1.step(step1Poskayit[7]);  
        stepmotor2.step(step2Poskayit[7]);   
        stepmotor3.step(step3Poskayit[7]);   
        servo1.write(servo1Poskayit[7]);
        servo2.write(servo2Poskayit[7]);
        servo3.write(servo3Poskayit[7]); }
if(bluetooth='Q') break; 

if(servo1Poskayit[8]>0 && servo2Poskayit[8]>0 && servo3Poskayit[8]>0){
        stepmotor1.step(step1Poskayit[8]);  
        stepmotor2.step(step2Poskayit[8]);   
        stepmotor3.step(step3Poskayit[8]);   
        servo1.write(servo1Poskayit[8]);
        servo2.write(servo2Poskayit[8]);
        servo3.write(servo3Poskayit[8]); }
if(bluetooth='Q') break; 

if(servo1Poskayit[9]>0 && servo2Poskayit[9]>0 && servo3Poskayit[9]>0){
        stepmotor1.step(step1Poskayit[9]);  
        stepmotor2.step(step2Poskayit[9]);   
        stepmotor3.step(step3Poskayit[9]);   
        servo1.write(servo1Poskayit[9]);
        servo2.write(servo2Poskayit[9]);
        servo3.write(servo3Poskayit[9]); }
if(bluetooth='Q') break; 


}

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
