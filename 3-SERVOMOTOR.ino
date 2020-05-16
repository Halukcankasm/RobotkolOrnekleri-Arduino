#include <Servo.h> //servo motor kütüphanesini dahil ettik
Servo servo1; //servo motor oluşturduk
Servo servo2;
Servo servo3;

int deger0;
int deger1;
int deger3;

int derece0;
int derece1;
int derece3;


int i ;
const int button_kayit = 12; 
const int button_baslat = 13;
const int button_kapatma = 8;
int button_kayit_deger = 0; 
boolean button_baslat_deger = false;

int servo1Poskayit[] = {1,1,1,1,1}; 
int servo2Poskayit[] = {1,1,1,1,1};
int servo3Poskayit[] = {1,1,1,1,1};


void setup() {
   servo1.attach(9); //servo1 motorunun 6.pine bağlı
   servo2.attach(10); //servo1 motorunun 7.pine bağlı
   servo3.attach(11); //servo1 motorunun 8.pine bağlı

  pinMode(button_kayit, INPUT);
  pinMode(button_baslat, INPUT);
  pinMode(button_kapatma, INPUT);
  Serial.begin(9600);

}

void loop() {
analogRead(A0);
analogRead(A1);
analogRead(A3);

deger0=analogRead(A0);
derece0=map(deger0,0,1023,0,180);

deger1=analogRead(A1);
derece1=map(deger1,0,1023,0,180);

deger3=analogRead(A3);
derece3=map(deger3,0,1023,0,180);



servo1.write(derece0);
servo2.write(derece1);
servo3.write(derece3);


if(digitalRead(button_kayit)==HIGH){ 
  
    button_kayit_deger ++ ;
delay(300);
    switch(button_kayit_deger){
      case 1:
        servo1Poskayit[0] = derece0;
        servo2Poskayit[0] = derece1;
        servo3Poskayit[0] = derece3;
       
        Serial.println("Pos 1 Kayit");
        break;
        
      case 2:
         servo1Poskayit[1] = derece0;
         servo2Poskayit[1] = derece1;
         servo3Poskayit[1] = derece3;
        
         Serial.println("Pos 2 Kayit");
         break;
         
      case 3:
         servo1Poskayit[2] = derece0;
         servo2Poskayit[2] = derece1;
         servo3Poskayit[2] = derece3;
         
         Serial.println("Pos 3 Kayit");
         break;
         
       case 4:
         servo1Poskayit[3] = derece0;
         servo2Poskayit[3] = derece1;
         servo3Poskayit[3] = derece3;
         
         Serial.println("Pos 4 Kayit");
         break;
         
       case 5:
         servo1Poskayit[4] = derece0;
         servo2Poskayit[4] = derece1;
         servo3Poskayit[4] = derece3;
         
         Serial.println("Pos 5 Kayit");
         break;
    }
  }

  if(digitalRead(button_baslat) == HIGH )
  {
 while(1){
  if(servo1Poskayit[0]>0 && servo2Poskayit[0]>0 && servo3Poskayit[0]>0){ 
        servo1.write(servo1Poskayit[0]);
        servo2.write(servo2Poskayit[0]);
        servo3.write(servo3Poskayit[0]); 
        delay(300);}
        if(digitalRead(button_kapatma) == HIGH ) break;

   if(servo1Poskayit[1]>0 && servo2Poskayit[1]>0 && servo3Poskayit[1]>0){ 
        servo1.write(servo1Poskayit[1]);
        servo2.write(servo2Poskayit[1]);
        servo3.write(servo3Poskayit[1]);
        delay(300);   }
   if(digitalRead(button_kapatma) == HIGH ) break;
    
   if(servo1Poskayit[2]>0 && servo2Poskayit[2]>0 && servo3Poskayit[2]>0){      
        servo1.write(servo1Poskayit[2]);
        servo2.write(servo2Poskayit[2]);
        servo3.write(servo3Poskayit[2]);
        delay(300);}
        if(digitalRead(button_kapatma) == HIGH ) break;
       
  if(servo1Poskayit[3]>0 && servo2Poskayit[3]>0 && servo3Poskayit[3]>0){       
        servo1.write(servo1Poskayit[3]);
        servo2.write(servo2Poskayit[3]);
        servo3.write(servo3Poskayit[3]);
         delay(300); }
        if(digitalRead(button_kapatma) == HIGH ) break;
      
  if(servo1Poskayit[4]>0 && servo2Poskayit[4]>0 && servo3Poskayit[4]>0){ 
        servo1.write(servo1Poskayit[4]);
        servo2.write(servo2Poskayit[4]);
        servo3.write(servo3Poskayit[4]);
         delay(300); }
   if(digitalRead(button_kapatma) == HIGH ) break;
 
}  
button_kayit_deger = 0;
 servo1Poskayit[4]=0; servo2Poskayit[4]=0; servo3Poskayit[4]= 0;
 servo1Poskayit[3]=0; servo2Poskayit[3]=0; servo3Poskayit[3]= 0;
 servo1Poskayit[2]=0; servo2Poskayit[2]=0; servo3Poskayit[2]= 0;
 servo1Poskayit[1]=0; servo2Poskayit[1]=0; servo3Poskayit[1]= 0;
 servo1Poskayit[0]=0; servo2Poskayit[0]=0; servo3Poskayit[0]= 0;
}
}
