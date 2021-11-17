#include <LiquidCrystal.h>// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);

int led=13; //initializing led pin in digital pin 13
int sensor1 = 2;
int sensor2 = 3;
int sensor3 = 4;

int Total = 3;
int Space;

void setup() {
// defines linght blocking sensor as input
pinMode(sensor1, INPUT);

// lcd display configurations
lcd.begin(16, 2);  
lcd.setCursor (0,0); // lcd.setCursor(col, row)
lcd.print("  Car  Parking  ");
lcd.setCursor (0,1);
lcd.print("     System     ");
delay (2000);
lcd.clear();  

Space = Total;
}

void loop(){ 
   if (digitalRead(sensor1)== LOW && digitalRead(sensor2)== LOW && digitalRead(sensor3)== LOW)// read the digital value sensor and if the sensor value is low to mean there is no light.
 {
  Space = Total;
  digitalWrite(led,LOW);//turn of the led
  Serial.println("space available");//print out "HIGH"
  lcd.setCursor (0,0);
  lcd.print("Total Spaces: ");
  lcd.print(Total);
  
  lcd.setCursor (0,1);
  lcd.print("Have  Space: ");
  lcd.print(Space);
 }
    if (digitalRead(sensor1)== HIGH || digitalRead(sensor2)== HIGH || digitalRead(sensor3)== LOW)// read the digital value sensor and if the sensor value is low to mean there is no light.
 {
  Space = Total-1;
  digitalWrite(led,LOW);//turn of the led
  Serial.println("space available");//print out "HIGH"
  lcd.setCursor (0,0);
  lcd.print("Total Spaces: ");
  lcd.print(Total);
  
  lcd.setCursor (0,1);
  lcd.print("Have  Space: ");
  lcd.print(Space);
 }
     if ((digitalRead(sensor1)== HIGH && digitalRead(sensor2)== HIGH)|| (digitalRead(sensor1)== HIGH && digitalRead(sensor3)== HIGH) || (digitalRead(sensor2)== HIGH && digitalRead(sensor3)== HIGH))// read the digital value sensor and if the sensor value is low to mean there is no light.
 {
  Space = Total-2;
  digitalWrite(led,LOW);//turn of the led
  Serial.println("space available");//print out "HIGH"
  lcd.setCursor (0,0);
  lcd.print("Total Spaces: ");
  lcd.print(Total);
  
  lcd.setCursor (0,1);
  lcd.print("Have  Space: ");
  lcd.print(Space);
 }
 
  if (digitalRead(sensor1)== HIGH && digitalRead(sensor2)== HIGH && digitalRead(sensor3)== HIGH) // read the digital value sensor and if the sensor value is high to mean there is light.
 {
  Space = Total-3;
  digitalWrite(led,HIGH); //turn on the led 
  Serial.println("no space");//print out "HIGH"
  
  lcd.setCursor (0,0);
  lcd.print(" Sorry no Space ");  
  lcd.setCursor (0,1);
  lcd.print("Have  Space: ");
  lcd.print(Space);
  delay (1000);
  lcd.clear();
 }
 
}
