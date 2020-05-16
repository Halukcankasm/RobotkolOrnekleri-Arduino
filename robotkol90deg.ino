#include <Servo.h> //servo motor kütüphanesini dahil ettik
Servo servo1; //servo motor oluşturduk
Servo servo2;
Servo servo3;

int deger0;
int deger1;
int deger2;
int deger3;

int derece0;
int derece1;
int derece2;
int derece3;
void setup() {
   servo1.attach(9); //servo1 motorunun 6.pine bağlı
   servo2.attach(10); //servo1 motorunun 7.pine bağlı
   servo3.attach(11); //servo1 motorunun 8.pine bağlı

}

void loop() {
analogRead(A0);
analogRead(A1);
analogRead(A2);
analogRead(A3);

deger0=analogRead(A0);
derece0=map(deger0,0,1023,0,180);

deger1=analogRead(A1);
derece1=map(deger1,0,1023,0,180);

deger2=analogRead(A2);
derece2=map(deger2,0,1023,0,180);

deger3=analogRead(A3);
derece3=map(deger3,0,1023,0,180);



servo1.write(derece0);
servo2.write(derece1);
servo3.write(derece3);
}
