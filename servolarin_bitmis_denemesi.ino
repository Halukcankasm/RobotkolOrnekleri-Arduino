
#include <SoftwareSerial.h>
#include <Servo.h> //servo motor kütüphanesini dahil ettik


Servo servo1;          //1.servo motor oluşturduk
Servo servo2;          //2.servo motor oluşturduk
Servo servo3;          //3.servo motor oluşturduk

int servo1_derece;     //1.servo motor derece değişkeni
int servo2_derece;     //2.servo motor derece değişkeni
int servo3_derece;     //3.servo motor derece değişkeni
char bluetooth ;


SoftwareSerial bt_bluetooth(TxD, RxD);

int servo1Poskayit[] = {1,1,1,1,1,1,1,1,1,1};    //1.servo motorun kayıt başlangışları
int servo2Poskayit[] = {1,1,1,1,1,1,1,1,1,1};    //2.servo motorun kayıt başlangışları
int servo3Poskayit[] = {1,1,1,1,1,1,1,1,1,1};    //3.servo motorun kayıt başlangışları
 
int i ;
int button_kayit_deger;




void setup() {


servo1.attach(9);  //servo1 motorunun 9.pine bağlı
servo2.attach(10); //servo1 motorunun 10.pine bağlı
servo3.attach(11); //servo1 motorunun 11.pine bağlı

  Serial.begin(9600);       // start serial communication at 9600bps
   bt_bluetooth.begin(9600);

}

void loop() {


  if(bt_bluetooth.available()>0){

       bluetooth =Serial.read();
     

if(bluetooth == 'U' && servo1_derece < 180 )            //
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




                                       
 
  if(bluetooth == '6'){                //KAYITLI HAREKET KOMUTU 
    button_kayit_deger ++;             //
         delay(100);                   //
     }                                 //
     
  switch(button_kayit_deger){
      case 1:

       
        servo1Poskayit[0] = servo1_derece;
        servo2Poskayit[0] = servo2_derece;
        servo3Poskayit[0] = servo3_derece;
       

        break;
        
      case 2:
 
        
        servo1Poskayit[1] = servo1_derece;
        servo2Poskayit[1] = servo2_derece;
        servo3Poskayit[1] = servo3_derece;

         break;
         
      case 3:

        
        servo1Poskayit[2] = servo1_derece;
        servo2Poskayit[2] = servo2_derece;
        servo3Poskayit[2] = servo3_derece;         

         break;

      case 4:

        
        servo1Poskayit[3] = servo1_derece;
        servo2Poskayit[3] = servo2_derece;
        servo3Poskayit[3] = servo3_derece;        

         break;

      case 5:

        
        servo1Poskayit[4] = servo1_derece;
        servo2Poskayit[4] = servo2_derece;
        servo3Poskayit[4] = servo3_derece;      


        case 6:

        
        servo1Poskayit[5] = servo1_derece;
        servo2Poskayit[5] = servo2_derece;
        servo3Poskayit[5] = servo3_derece;  

        case 7:

        
        servo1Poskayit[6] = servo1_derece;
        servo2Poskayit[6] = servo2_derece;
        servo3Poskayit[6] = servo3_derece;  


        case 8:

        
        servo1Poskayit[7] = servo1_derece;
        servo2Poskayit[7] = servo2_derece;
        servo3Poskayit[7] = servo3_derece;  

        case 9:

        
        servo1Poskayit[8] = servo1_derece;
        servo2Poskayit[8] = servo2_derece;
        servo3Poskayit[8] = servo3_derece;  


        case 10:
 
        
        servo1Poskayit[9] = servo1_derece;
        servo2Poskayit[9] = servo2_derece;
        servo3Poskayit[9] = servo3_derece;          

         break;
          }

    if(bluetooth='G' )             
  {

while(1){
 
if(servo1Poskayit[0]>0 && servo2Poskayit[0]>0 && servo3Poskayit[0]>0){  
   
        servo1.write(servo1Poskayit[0]);
        servo2.write(servo2Poskayit[0]);
        servo3.write(servo3Poskayit[0]); 
        delay(300);}                               
if(bluetooth='Q') break; 

if(servo1Poskayit[1]>0 && servo2Poskayit[1]>0 && servo3Poskayit[1]>0){
                                                         
        servo1.write(servo1Poskayit[1]);
        servo2.write(servo2Poskayit[1]);
        servo3.write(servo3Poskayit[1]);
        delay(300); }
        
if(bluetooth='Q') break; 

if(servo1Poskayit[2]>0 && servo2Poskayit[2]>0 && servo3Poskayit[2]>0){
 
if(bluetooth='Q') break; 
        servo1.write(servo1Poskayit[2]);
        servo2.write(servo2Poskayit[2]);
        servo3.write(servo3Poskayit[2]); 
        delay(300);}
if(bluetooth='Q') break; 

if(servo1Poskayit[3]>0 && servo2Poskayit[3]>0 && servo3Poskayit[3]>0){
  
if(bluetooth='Q') break; 
        servo1.write(servo1Poskayit[3]);
        servo2.write(servo2Poskayit[3]);
        servo3.write(servo3Poskayit[3]); 
        delay(300);}
if(bluetooth='Q') break; 

if(servo1Poskayit[4]>0 && servo2Poskayit[4]>0 && servo3Poskayit[4]>0){

        servo1.write(servo1Poskayit[4]);
        servo2.write(servo2Poskayit[4]);
        servo3.write(servo3Poskayit[4]);
        delay(300);}
if(bluetooth='Q') break; 

if(servo1Poskayit[5]>0 && servo2Poskayit[5]>0 && servo3Poskayit[5]>0){
  
        servo1.write(servo1Poskayit[5]);
        servo2.write(servo2Poskayit[5]);
        servo3.write(servo3Poskayit[5]);
        delay(300);}
if(bluetooth='Q') break; 

if(servo1Poskayit[6]>0 && servo2Poskayit[6]>0 && servo3Poskayit[6]>0){

        servo1.write(servo1Poskayit[6]);
        servo2.write(servo2Poskayit[6]);
        servo3.write(servo3Poskayit[6]); 
        delay(300);}
if(bluetooth='Q') break; 

if(servo1Poskayit[7]>0 && servo2Poskayit[7]>0 && servo3Poskayit[7]>0){

        servo1.write(servo1Poskayit[7]);
        servo2.write(servo2Poskayit[7]);
        servo3.write(servo3Poskayit[7]); 
        delay(300);}
if(bluetooth='Q') break; 

if(servo1Poskayit[8]>0 && servo2Poskayit[8]>0 && servo3Poskayit[8]>0){
  
        servo1.write(servo1Poskayit[8]);
        servo2.write(servo2Poskayit[8]);
        servo3.write(servo3Poskayit[8]);
        delay(300);}
if(bluetooth='Q') break; 

if(servo1Poskayit[9]>0 && servo2Poskayit[9]>0 && servo3Poskayit[9]>0){
 
        servo1.write(servo1Poskayit[9]);
        servo2.write(servo2Poskayit[9]);
        servo3.write(servo3Poskayit[9]); 
        delay(300);}
if(bluetooth='Q') break; 


}
button_kayit_deger = 0;
servo1Poskayit[9]=0; servo2Poskayit[9]=0; servo3Poskayit[9]= 0;
servo1Poskayit[8]=0; servo2Poskayit[8]=0; servo3Poskayit[8]= 0;
servo1Poskayit[7]=0; servo2Poskayit[7]=0; servo3Poskayit[7]= 0;
servo1Poskayit[6]=0; servo2Poskayit[6]=0; servo3Poskayit[6]= 0;
servo1Poskayit[5]=0; servo2Poskayit[5]=0; servo3Poskayit[5]= 0;
servo1Poskayit[4]=0; servo2Poskayit[4]=0; servo3Poskayit[4]= 0;
servo1Poskayit[3]=0; servo2Poskayit[3]=0; servo3Poskayit[3]= 0;
servo1Poskayit[2]=0; servo2Poskayit[2]=0; servo3Poskayit[2]= 0;
servo1Poskayit[1]=0; servo2Poskayit[1]=0; servo3Poskayit[1]= 0;
}

if(bluetooth ==  'H'){                       //
        delay(100);                          //  KAPATMA İSKELESİ
                                             //
        servo1.write(100);                   //
        servo2.write(100);                   //
        servo3.write(100);                   //
                                             //
  }                                          //

}
}
