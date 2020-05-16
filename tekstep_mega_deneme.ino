#include <Stepper.h>


int stepPin0=9;   //
int stepPin1=10;  //1.step motorun pin bağlantısı
int stepPin2=11;  //
int stepPin3=12;  //




int steppos ;
int button_ileri =7;
int button_geri =6 ;
 

Stepper stepmotor1(32,stepPin0,stepPin1,stepPin2,stepPin3);    //1,motor


//stepmotor nesnesi üretildi
//ve Step motorun bir tam turu 32 parçaya(step) bölündü
//dolayısıyla her bir stepte motor 360/11,25=32derece dönecek

void setup() {

pinMode(stepPin0,OUTPUT);
pinMode(stepPin1,OUTPUT);
pinMode(stepPin2,OUTPUT);
pinMode(stepPin3,OUTPUT);




stepmotor1.setSpeed(200); //1,motorun rpm hızı=50


  Serial.begin(9600);
}

void loop() {

 if(digitalRead(button_ileri) == HIGH ) {           //
 steppos=steppos + 3 ;                              //
  stepmotor1.step(steppos);                              //
  delay(50);                                        //      1.STEP MOTOR 
                  }                                 //        KONTROLÜ
  if(digitalRead(button_geri) == HIGH ) {                                                    
  steppos=steppos - 3 ;                             //
  stepmotor1.step(steppos);                              //
  delay(50);                                        //
                  }                                 //
                                 

 delay(1000);

}
