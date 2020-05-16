#include <Stepper.h>                    //Step motor kütüphanesini dahil ettik
#include<SoftwareSerial.h>              //Bluetooth modülünü kütüphanesini dahil ettik
#include <Servo.h>                      //Servo motor kütüphanesini dahil ettik

Servo servo1;          //1.servo motor oluşturduk
Servo servo2;          //2.servo motor oluşturduk
Servo servo3;          //3.servo motor oluşturduk

int servo1_derece;     //1.servo motor derece değişkeni
int servo2_derece;     //2.servo motor derece değişkeni
int servo3_derece;     //3.servo motor derece değişkeni


const int step1adim = 2;  //Adım sayısını belirtiyoruz
const int step1yon = 3;   //3.pine bağlıyoruz - motorun yönünü kontrol eder
const int step1pulse = 2; //2.pine atanıyor

const int step2adim = 2;  //Adım sayısını belirtiyoruz
const int step2yon = 5;   //5.pine bağlıyoruz - motorun yönünü kontrol eder
const int step2pulse = 4; //4.pine atanıyor

const int step3adim = 2;  //Adım sayısını belirtiyoruz
const int step3yon = 7;   //3.pine bağlıyoruz - motorun yönünü kontrol eder
const int step3pulse = 6; //2.pine atanıyor

int step1sayici = 0;   //Step motor adımlarının kontrolü için bir değişken tanımladık
int step2sayici = 0;   //Step motor adımlarının kontrolü için bir değişken tanımladık
int step3sayici = 0;   //Step motor adımlarının kontrolü için bir değişken tanımladık

int i = 0;             // Hafızaların kayıt edildiği değişken
int ix = 0;            // Hafızanın sıfırlandığı değişken 
int iy = 0;            // Hafızanın kayıtlı olduğu konumları oynatan değişken

Stepper stepmotor1(step1adim,step1pulse,step1yon,10,11);    //1.stepmotor

Stepper stepmotor2(step2adim,step2pulse,step2yon,10,11);    //2.stepmotor

Stepper stepmotor3(step3adim,step3pulse,step3yon,10,11);    //3.stepmotor

                                                            
int Servo1_Hafiza[10]={10000,10000,10000,10000,10000,10000,10000,10000,10000,10000};  //Hafızaların tutulduğu dizi
int Servo2_Hafiza[10]={10000,10000,10000,10000,10000,10000,10000,10000,10000,10000};  //Hafızaların tutulduğu dizi
int Servo3_Hafiza[10]={10000,10000,10000,10000,10000,10000,10000,10000,10000,10000};  //Hafızaların tutulduğu dizi

int Step1_Hafiza[10]={10000,10000,10000,10000,10000,10000,10000,10000,10000,10000};  //Hafızaların tutulduğu dizi
int Step2_Hafiza[10]={10000,10000,10000,10000,10000,10000,10000,10000,10000,10000};  //Hafızaların tutulduğu dizi
int Step3_Hafiza[10]={10000,10000,10000,10000,10000,10000,10000,10000,10000,10000};  //Hafızaların tutulduğu dizi
                                                                       
                                                                       
void setup() {                                                         
stepmotor1.setSpeed(10000);                                            //Step motorların hızının ayarlamasını yaptık
stepmotor2.setSpeed(10000);                                            //Step motorların hızının ayarlamasını yaptık
stepmotor3.setSpeed(10000);                                            //Step motorların hızının ayarlamasını yaptık
                                                                       
servo1.attach(8);                                                      //Servo1 motorunun 8.pine bağlı
servo2.attach(13);                                                     //Servo2 motorunun 13.pine bağlı
servo3.attach(12);                                                     //Servo3 motorunun 12.pine bağlı
                                                                       
servo1.write(0);                                                       //Servo motorların başlangıç anında bulunacağı açı
servo2.write(60);                                                      //Servo motorların başlangıç anında bulunacağı açı
servo3.write(0);                                                       //Servo motorların başlangıç anında bulunacağı açı
                                                                       
Serial.begin(9600);                                                    //Bluetooth modülü başlangıç                     
}                                                                      
                                                                       
void loop() {                                                          
                                                                       
  if(Serial.available()){                                              //Bluetooth modülü bağlanma
                                                                       
      char bluetooth =Serial.read();                                   //Bluetoothtan gelen bilginin okunması  
      Serial.println(bluetooth);                                       //Seri port ekranından gelen bilginin görülmesini sağlıyor
      
                                                                       //1. SERVO MOTOR KONTROLÜ BAŞLANGIÇ
      if(bluetooth == 'i' && servo1_derece < 180 )                     //i harfi geldiğinde 1.servo motor saat yönünde dönecek
      {                                                                //Servo motora sınırlama getirildi
      servo1_derece= servo1_derece+1;                                  //Servo motorun derecesi 1 derece artıcak
      servo1.write(  servo1_derece);                                                     
      Serial.println(servo1_derece);                                   //Servo motorun konum bilgisi seri port ekranına geliyor
      bluetooth=0;                                                     //Bluetooth modülünden gelen bilgi sıfırlanıyor
      }                                                                      
      if(bluetooth == 'm' && servo1_derece  > 0   )                    //m harfi geldiğinde  1.servo motor saatin tersi yönünde dönecek
      {                                                                //Servo motora sınırlama getirildi
      servo1_derece = servo1_derece -1;                                //Servo motorun derecesi 1 derece azalıcak 
      servo1.write( servo1_derece );                                                 
      Serial.println(servo1_derece);                                   //Servo motorun konum bilgisi seri port ekranına geliyor 
      bluetooth=0;                                                     //Bluetooth modülünden gelen bilgi sıfırlanıyor
      }                                                                //1. SERVO MOTOR KONTROLÜ BİTİŞ
      
                                                                       //2. SERVO MOTOR KONTROLÜ BAŞLANGIÇ
     if(bluetooth == 'h' && servo2_derece < 180 )                      //h harfi geldiğinde 2. servo motor saat yönünde dönecek
     {                                                                 //Servo motora sınırlama getirildi
      servo2_derece=servo2_derece+1;                                   //Servo motorun derecesi 1 derece artıcak
      servo2.write(  servo2_derece);                                                                                             
      Serial.println(servo2_derece);                                   //Servo motorun konum bilgisi seri port ekranına geliyor
      bluetooth=0;                                                     //Bluetooth modülünden gelen bilgi sıfırlanıyor
      }                                                              
      if(bluetooth == 'f' && servo2_derece > 0 )                       //f harfi geldiğinde 2. servo motor saatin tersi yönünde dönecek
      {                                                                //Servo motora sınırlama getirildi
      servo2_derece= servo2_derece-1;                                  //Servo motorun derecesi 1 derece azalıcak       
      servo2.write(servo2_derece);                                     
      Serial.println(servo2_derece);                                   //Servo motorun konum bilgisi seri port ekranına geliyor
      bluetooth=0;                                                     //Bluetooth modülünden gelen bilgi sıfırlanıyor
      }                                                                //2. SERVO MOTOR KONTROLÜ BİTİŞ
                       
                                                                       //3. SERVO MOTOR KONTROLÜ BAŞLANGIÇ
     if(bluetooth == 'n' )                                             //n harfi geldiğinde 3. servo motor saat yönünde dönecek 
     {                                                                   
      servo3_derece= servo3_derece+1;                                  //Servo motorun derecesi 1 derece artıcak                         
      servo3.write( servo3_derece);                                    
      Serial.println(servo3_derece);                                   //Servo motorun konum bilgisi seri port ekranına geliyor       
      bluetooth=0;                                                     //Bluetooth modülünden gelen bilgi sıfırlanıyor
      }                                                   
                                                                      
      if(bluetooth == 'k')                                             //k harfi geldiğinde 3. servo motor saatin tersi yönünde dönecek
      {                                                               
      servo3_derece= servo3_derece-1;                                  //Servo motorun derecesi 1 derece azalıcak                       
      servo3.write(servo3_derece);                                     
      Serial.println(servo3_derece);                                   //Servo motorun konum bilgisi seri port ekranına geliyor 
      bluetooth=0;                                                     //Bluetooth modülünden gelen bilgi sıfırlanıyor 
      }                                                                //3. SERVO MOTOR KONTROLÜ BİTİŞ
      
                                                                       //1. STEP MOTOR KONTROLÜ BAŞLANGIÇ
      if(bluetooth== 'd')                                              //Bluetoothtan d harfi geldiğinde saat yönünün tersinde dönecek
      {                                                                
      digitalWrite(step1yon,0);                                        //Step motorun dönme yönünü belirler 0 saat yönünün tersi                             
      stepmotor1.step(step1adim);                                      //Step motorun adım atmasını sağlar
      step1sayici=step1sayici-2;                                       //Adım azaltarak devam edecek 
      delay(20);                                                              
      bluetooth = 0;                                                   //Bluetooth modülünden gelen bilgi sıfırlanıyor                                                    
      }                                                                        
      if(bluetooth == 'b')                                             //Bluetoothtan b harfi geldiğinde saat yönünde dönecek
      {                                                                
      digitalWrite(step1yon,1);                                        //Step motorun dönme yönünü belirler 1 saat yönünde 
      step1sayici=step1sayici+2;                                       //Adım adım artarak devam edecek
      stepmotor1.step(step1adim);                                      //Step motorun adım atmasını sağlar
      delay(20);                                                       
      bluetooth=0;                                                     //Bluetooth modülünden gelen bilgi sıfırlanıyor 
      }                                                                //1.STEP MOTOR KONTROLÜ BİTİŞ
      
                                                                       //2. STEP MOTOR KONTROLÜ BAŞLANGIÇ
      if(bluetooth== 'a')                                              //Bluetoothtan a harfi geldiğinde saat yönünün tersinde dönecek
      {                                                                
      digitalWrite(step2yon,0);                                        //Step motorun dönme yönünü belirler 0 saat yönünün tersi                               
      stepmotor2.step(step2adim);                                      //Step motorun adım atmasını sağlar
      step2sayici=step2sayici-2;                                       //Adım azaltarak devam edecek
      bluetooth = 0;                                                   //Bluetooth modülünden gelen bilgi sıfırlanıyor                      
      }                                                        
      if(bluetooth == 'c'){                                            //Bluetoothtan c harfi geldiğinde saat yönünde dönecek
      digitalWrite(step2yon,1);                                        //Step motorun dönme yönünü belirler 1 saat yönünde
      step2sayici=step2sayici+2;                                       //Adım adım artarak devam edecek
      stepmotor2.step(step2adim);                                      //Step motorun adım atmasını sağlar
      bluetooth=0;                                                     //Bluetooth modülünden gelen bilgi sıfırlanıyor
      }                                                                //2.STEP MOTOR KONTROLÜ BİTİŞ
      
                                                                       //3. STEP MOTOR KONTROLÜ BAŞLANGIÇ           
      if(bluetooth== 'e')                                              //Bluetoothtan e harfi geldiğinde saat yönünün tersinde dönecek
      {                                                                
      digitalWrite(step3yon,0);                                        //Step motorun dönme yönünü belirler 0 saat yönünün tersi                               
      stepmotor3.step(step3adim);                                      //Step motorun adım atmasını sağlar
      step3sayici=step3sayici-2;                                       //Adım azaltarak devam edecek
      bluetooth = 0;                                                   //Bluetooth modülünden gelen bilgi sıfırlanıyor
      }                                                                      
      if(bluetooth == 'g')                                             //Bluetoothtan g harfi geldiğinde saat yönünde dönecek
      {                                                                
      digitalWrite(step3yon,1);                                        //Step motorun dönme yönünü belirler 1 saat yönünde
      stepmotor3.step(step3adim);                                      //Step motorun adım atmasını sağlar
      step3sayici=step3sayici+2;                                       //Adım adım artarak devam edecek
      bluetooth=0;                                                     //Bluetooth modülünden gelen bilgi sıfırlanıyor
      }                                                                //3.STEP MOTOR KONTROLÜ BİTİŞ

                                                                       //KAYIT BAŞLANGIÇ
   if(bluetooth == 'r' && i<10 )                                       //r harfine basıldığında o konumda bulunan konumu kaydeder
     {                                                                 //kaydetme bölümü 
     Serial.println(bluetooth);                                        //
     Servo1_Hafiza[i]=servo1_derece;                                   //      Servo motorların
     Servo2_Hafiza[i]=servo2_derece;                                   //      kayıtlarının alındığı
     Servo3_Hafiza[i]=servo3_derece;                                   //      yer
                                                                       //
     Step1_Hafiza[i]=step1sayici;                                      //      Step motorların
     Step2_Hafiza[i]=step2sayici;                                      //      kayıtlarının alındığı 
     Step3_Hafiza[i]=step3sayici;                                      //      yer
                                                                       //
     i=i+1;                                                            //Bir sonra olacak kayıt için i harfini 1 arttırıyor
     }                                                                 //KAYIT BİTİŞ
                                                                       //
     if(i==10)                                                         //10 a eşit olduğunda 
     {i=0;}                                                            //i 0 olacak
     
                                                                       //OYNATMA BAŞLANGIÇ
     if(bluetooth== 'o'){                                              //Oynatma komutu
     bluetooth = 0;                                                    //Bluetooth sıfırla
     bluetooth =Serial.read();                                         //Okunan değerleri bluetooth'a at
     Serial.println(bluetooth);                                        //Bluetooth'u port a yazdır 
                                                                       //
     i =0;                                                             //       
               while(1)                                                //Motorların hafızaya kayıtlı olan konumların oynatılması
               {                                                       //
               char bluetooth =Serial.read();                          //Bluetoothtan gelen bilgiyi okuma
                 for(iy=0;iy<10;iy++)                                  //10 konuma kadar olan konumların oynatılması
                 {                                                     //SERVO MOTORLAR OYNATMA BAŞLANGIÇ
                                                                       //
                     if(Servo1_Hafiza[iy]!= 10000)                     //Konum kaydedilmişse          
                     {                                                 //
                     servo1.write(Servo1_Hafiza[iy]);                  //Servo motoru kaydedilen konumlara gönder
                     delay(750);                                       //
                     }                                                 //
                                                                       //
                     if(Servo2_Hafiza[iy]!= 10000)                     //Konum kaydedilmişse 
                     {                                                 //
                     servo2.write(Servo2_Hafiza[iy]);                  //Servo motoru kaydedilen konumlara gönder
                     delay(750);                                       //
                     }                                                 //
                                                                       //
                     if(Servo3_Hafiza[iy]!= 10000)                     //Konum kaydedilmişse
                     {                                                 //
                     servo3.write(Servo3_Hafiza[iy]);                  //Servo motoru kaydedilen konumlara gönder
                     delay(750);                                       //
                     }                                                 //SERVO MOTORLAR OYNATMA BİTİŞ
                                                                       //
                     if(bluetooth=='p'){ break;}                       //Döngüden  çıkma komutu
                     Serial.println(bluetooth);                        //
                                                                       //
                                                                       //STEP MOTORLAR OYNATMA BAŞLANGIÇ
                     if(Step1_Hafiza[iy]!= 10000)                      //Konum kaydedilmişse
                     {                                                 //
                            while(step1sayici>Step1_Hafiza[iy])        //1.Step motorun derecesi kayıt derecesinde büyük ise döngüye gir!
                            {                                          //       
                            digitalWrite(step1yon,0);                  //Saat yönünün tersinde hareket et
                            stepmotor1.step(step1adim);                //2 adım dön
                            step1sayici=step1sayici+2;                 //Adım azaltarak devam et
                            if(step1sayici==Step1_Hafiza[iy])          //
                            {break;}                                   //
                            }                                          //
                     }                                                 //
                                                                       //              
                     if(bluetooth=='p'){ break;}                       //Döngüden çıkma komutu.
                     Serial.println(bluetooth);                        //
                                                                       //
                     if(Step1_Hafiza[iy]!= 10000)                      // konum kaydedilmişse
                     {                                                 //
                            while(step1sayici<Step1_Hafiza[iy])        //1.Step motorun derecesi kayıt derecesinde küçük ise döngüye gir!
                            {                                          //    
                            digitalWrite(step1yon,1);                  //Saat yönününde hareket et
                            stepmotor1.step(step1adim);                //2 adım dön
                            step1sayici=step1sayici+2;                 //Adım arttırarak devam et
                                                                       //
                            if(step1sayici==Step1_Hafiza[iy])          //
                            {break;}                                   //
                                                                       //
                            }                                          //
                    }                                                  //
                                                                       //
                    if(bluetooth=='p'){ break;}                        //Döngüden çıkma komutu
                    Serial.println(bluetooth);                         //
                                                                       //
                    if(Step2_Hafiza[iy]!= 10000)                       // konum kaydedilmişse
                    {                                                  //
                              while(step2sayici>Step2_Hafiza[iy])      //2.Step motorun derecesi kayıt derecesinde büyük ise döngüye gir!
                              {                                        //
                              digitalWrite(step2yon,0);                //Saat yönünün tersinde hareket et
                              stepmotor2.step(step2adim);              //2 adım dön
                              step2sayici=step2sayici-2;               //Adım azaltarak devam et
                              if(step2sayici==Step2_Hafiza[iy])        //
                              {break;}                                 //
                              }                                        //
                    }                                                  //
                                                                       //     
                    if(bluetooth=='p'){ break;}                        //
                    Serial.println(bluetooth);                         //
                                                                       //
                    if(Step2_Hafiza[iy]!= 10000)                       // konum kaydedilmişse
                    {                                                  //
                              while(step2sayici<Step2_Hafiza[iy])      //->2.Step motorun derecesi kayıt derecesinde küçük ise döngüye gir!
                              {                                        //
                              digitalWrite(step2yon,1);                //->Saat yönününde hareket et
                              stepmotor2.step(step2adim);              //->2 adım dön
                              step2sayici=step2sayici+2;               //->Adım arttırarak devam et
                              if(step2sayici==Step2_Hafiza[iy])        //     
                              {break;}                                 //
                              }                                        //
                    }                                                  //
                    if(bluetooth=='p'){ break;}                        //
                    Serial.println(bluetooth);                         //
                                                                       //
                    if(Step3_Hafiza[iy]!= 10000)                       // konum kaydedilmişse
                    {                                                  //
                             while(step3sayici>Step3_Hafiza[iy])       //->3.Step motorun derecesi kayıt derecesinde büyük ise döngüye gir!
                             {                                         //
                             digitalWrite(step3yon,0);                 //
                             stepmotor3.step(step3adim);               //
                             step3sayici=step3sayici-2;                //
                             if(step3sayici==Step3_Hafiza[iy]){break;} //
                             }                                         //
                    }                                                  //
                                                                       //
                   if(Step3_Hafiza[iy]!= 10000)                        // konum kaydedilmişse
                   {                                                   //
                   if(bluetooth=='p'){ break;}                         //
                             while(step3sayici<Step3_Hafiza[iy])       //->3.Step motorun derecesi kayıt derecesinde küçük ise döngüye gir!
                             {                                         //
                             digitalWrite(step3yon,1);                 //
                             stepmotor3.step(step3adim);               //
                             step3sayici=step3sayici+2;                //
                             if(step3sayici==Step3_Hafiza[iy]){break;} //
                             }                                         //
                   }                                                   //
                   if(bluetooth=='p'){ break;}                         //
                   Serial.println(bluetooth);                          //
               }                                                       //For(iy=0;iy<10;iy++) döngüsünün sonu     
               iy=0;                                                   //
               if(bluetooth=='p'){ break;}                             //STEP MOTORLAR OYNATMA BİTİŞ
               
           }                                                           //OYNATMA WHILE DÖNGÜSÜ SONU
                                     
                                                                       //OYNATMA DURUNCA HAFIZAYI SİL
           for(ix=0;ix<10;ix++)                                        // p harfine basıldıktan sonra  
           {                                                           // kayıtlı hareketlerin
           Servo1_Hafiza[ix]=10000;    Step1_Hafiza[ix]=10000;         // oynatılması bittiğinde       
           Servo2_Hafiza[ix]=10000;    Step2_Hafiza[ix]=10000;         // kaydedilen bütün konumları 
           Servo3_Hafiza[ix]=10000;    Step3_Hafiza[ix]=10000;         // sıfırlama
           }                                                           // hafıza sıfırlamanın sonu
           ix=0;                                                       //
      }                                                                //Oynatma döngüsünün sonu
    }                                                                  //Bluetooth döngüsü
}
  
                                 
                
