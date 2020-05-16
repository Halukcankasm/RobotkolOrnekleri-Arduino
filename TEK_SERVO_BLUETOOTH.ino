#include <Servo.h> //servo motor kütüphanesini dahil ettik
Servo servo1; 
Servo servo2;          
Servo servo3;
int servo1_derece;     
int servo2_derece;     
int servo3_derece; 
char bluetooth ;
void setup() {
servo1.attach(9);  //servo1 motorunun 9.pine bağlı
servo2.attach(10); //servo1 motorunun 10.pine bağlı
servo3.attach(11);
Serial.begin(9600);       // start serial communication at 9600bps
}

void loop() {
if(Serial.available()>0){
bluetooth =Serial.read();
Serial.print(bluetooth);
if(bluetooth == 'U')                                    
     {                                                  
      servo1_derece= servo1_derece+5;                   
      servo1.write(servo1_derece);                                        
      Serial.print("servo-1 derece;");                  
      Serial.println(servo1_derece);                    
      delay(50);                                        
      }                                                       
                                                       
      if(bluetooth == 'W')                              
      {                                                 
      servo1_derece = servo1_derece -5;                 
      servo1.write( servo1_derece );                                    
      Serial.print("servo-1 derece;"); 
      Serial.print(servo1_derece);                 
      delay(50);                                        
      }  


     if(bluetooth == 'E')                                    
     {                                                  
      servo2_derece= servo2_derece+5;                   
      servo2.write(servo2_derece);                                        
      Serial.print("servo-2 derece;");                  
      Serial.println(servo2_derece);                    
      delay(50);                                        
      }                                                       
                                                       
      if(bluetooth == 'R')                              
      {                                                 
      servo2_derece = servo2_derece -5;                 
      servo2.write( servo2_derece );                                    
      Serial.print("servo-2 derece;"); 
      Serial.print(servo2_derece);                 
      delay(50);                                        
      }  

      if(bluetooth == 'T')                                    
     {                                                  
      servo3_derece= servo3_derece+5;                   
      servo3.write(servo3_derece);                                        
      Serial.print("servo-3 derece;");                  
      Serial.println(servo3_derece);                    
      delay(50);                                        
      }                                                       
                                                       
      if(bluetooth == 'Y')                              
      {                                                 
      servo3_derece = servo3_derece -5;                 
      servo3.write( servo3_derece );                                    
      Serial.print("servo-3 derece;"); 
      Serial.print(servo3_derece);                 
      delay(50);                                        
      }                                                                          
}
}
