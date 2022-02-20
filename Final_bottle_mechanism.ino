#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int current_state=0;
int prev_state=0;
int count=0;

void setup()
{
  Serial.begin(9600);
  
  //tilt switch
  pinMode(8, INPUT);
  digitalWrite(8, HIGH);

  //LCD screen
  analogWrite(6, 100);
  lcd.begin(16, 2);
  
}

void loop()
{
  current_state=digitalRead(8); //HIGH when not pressed, LOW when pressed

  if(current_state != prev_state){    //prevents count growing continuosly
    if(current_state==HIGH){      //switch NOT pressed
      //tilt switch
      Serial.print(count);
      Serial.print(", NOT Drink");
      
      //LCD print
      lcd.setCursor(0, 0);
      lcd.print("Not Drinking!!!");
      lcd.setCursor(0, 10);
      lcd.print(" Stay Hydrated");
      } 
    else{     //sqitch pressed
      count++;
      Serial.print(count);
      Serial.print(", Drink");
      
      //LCD print
      lcd.setCursor(0, 0);
      lcd.print("Drinking!!!    ");
      lcd.setCursor(0, 10);
      lcd.print("                         ");
      }
    Serial.print("\n");
    }
    prev_state=current_state;
    
}
