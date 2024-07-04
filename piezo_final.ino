#include <LiquidCrystal_I2C.h>
#include <Servo.h> 
int piezopin = A0; // Analog pin connected to the piezo sensor
int piezopin1 = A2; 
int piezopin2 = A1;
int piezopin3 = A3;
int ldr3 = A5 ; 
int led = 3;
int threshold = 800; // Threshold value for detecting a knock
int threshold1 = 800;
int ldr1  ;
int ldr2  ; 

//A3 =دخلة ++
//A2 = sortir --
//A1 = led route 
//

Servo myservo1; 
Servo myservo2;
int pos_b ;
int pos_a ;
int pos = 0; 

//const int lcd_address = 0x27; // Replace with your LCD I2C address if different

//LiquidCrystal_I2C lcd(lcd_address, 16, 2); // Set LCD dimensions (16 columns, 2 rows)

int counter = 0; // Initialize counter variable

void setup() {
  Serial.begin(9600); 

  //lcd.init();  // Initialize LCD communication
  //lcd.backlight(); // Turn on backlight (optional)
 
pinMode(9,OUTPUT);
pinMode(6,OUTPUT);
pinMode(A0,INPUT);
pinMode(A1,INPUT);
pinMode(A2,INPUT);
pinMode(A3,INPUT);

pinMode(A5,INPUT);
myservo1.attach(9); 
myservo2.attach(6); 
Serial.begin(9600);
}

void loop() {
 int piezovalue = analogRead(piezopin); // Read the analog value from the piezo sensor
 int piezovalue2 = analogRead(piezopin2);
 int piezovalue3 = analogRead(piezopin3);
 int piezovalue1 = analogRead(piezopin1);
   if ( piezovalue3 > 900 ) {
piezovalue3 = 0 ;


  }
  if ( piezovalue > 900 ) {
piezovalue = 0 ;


  }
  if ( piezovalue1 > 900 ) {
piezovalue1 = 0 ;


  }



 if (piezovalue1 > threshold1 ){

digitalWrite (led,HIGH);

}

else{
digitalWrite(led,LOW);
}

//Serial.println(piezovalue3);
  // Simulate a rising value (replace this with your actual value source)
  if ( piezovalue2 > threshold ) {
counter ++;
delay(1500);

  }
 else {counter = counter;}
  if ( piezovalue3 > threshold1 ) {
counter--;
delay(1500); 
  }
  else {counter = counter;}


//lcd.setCursor(0, 0);  // Set cursor position (0, 0) - top left
//lcd.print("places left");
//lcd.print(4 - counter);    // Display counter value

//Serial.println(piezovalue1);
//Serial.println(piezovalue2); 

  ldr1 = analogRead(A4);
  ldr2 = analogRead(A5);
  //ldr3 = analogRead(A5);
 // Serial.println(ldr1);
  Serial.println(ldr2);
  /*

  if (ldr1 > 100){
  myservo1.write(pos);
  myservo2.write(pos);
  pos_b = pos + 50;
  myservo1.write(pos_b);
  myservo2.write(pos_b);
   }

  if (ldr2 > 100){
  myservo2.write(pos);
  myservo1.write(pos);
  pos_a = pos - 50;
  myservo1.write(pos_a);
  myservo2.write(pos_a);
   }*/
  myservo1.write(pos);
  myservo2.write(pos);

  
        
}
