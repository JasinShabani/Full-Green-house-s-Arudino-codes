/*int ThermistorPin = 0;
int Vo;
float R1 = 10000;
float logR2, R2, T, Tc, Tf;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;

void setup() {
Serial.begin(9600);
}

void loop() {

  Vo = analogRead(ThermistorPin);
  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  Tc = T - 273.15;
  Tf = (Tc * 9.0)/ 5.0 + 32.0; 

  Serial.print("Temperature: "); 
  Serial.print(Tf);
  Serial.print(" F; ");
  Serial.print(Tc);
  Serial.println(" C");   

  delay(500);
}*/
#include <LiquidCrystal.h>// include the library code
int ThermistorPin = 0;
int Vo;
float R1 = 10000;
float logR2, R2, T, Tc, Tf;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;
const int pResistor = 1; // Photoresistor at Arduino analog pin A0
const int ledPin=9;       // Led pin at Arduino pin 9
int lightCal;
int lightVal;
//Variables
int value;
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(4, 6, 10, 11, 12, 13);
/*********************************************************/
void setup() {
  // set up the LCD's number of columns and rows:
  pinMode(2, OUTPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(ledPin, OUTPUT);  // Set lepPin - 9 pin as an output
  pinMode(pResistor, INPUT);// Set pResistor - A0 pin as an input (optional)
  lightCal = analogRead(pResistor);
  // Print a message to the LCD.
}

void loop() {
  value = analogRead(pResistor);
  Vo = analogRead(ThermistorPin);
  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  Tc = T - 273.15;
  Tf = (Tc * 9.0)/ 5.0 + 32.0; 
  lcd.print("Temperature");
  lcd.print(Tc); 
  lightVal = analogRead(pResistor);
  //You can change value "25"
  if (lightVal < lightCal - 50)
  {
    digitalWrite(9, HIGH);
  }

  //else, it is bright, turn pin 9 LOW
  else
  {
    digitalWrite(9, LOW);
  }
  if(Tc >= 32){
    digitalWrite(2, HIGH);
  }
  else{
     digitalWrite(2, LOW);
  }
  delay(500);
  lcd.clear();
  
  

}

