#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int current_state=0;
int prev_state=0;
int count=0;

int timer=0;

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
      lcd.print("Not Drinking!!! ");
    }
    else{     //switch pressed
      count++;
      Serial.print(count);
      Serial.print(", Drink");
      
      //LCD print
      lcd.setCursor(0, 0);
      lcd.print("Drinking!!!      ");   //adding whitespace to remove the previous command
      lcd.setCursor(0, 10);
      lcd.print("                         ");   //adding whitespace to remove the previous command
      }
      Serial.print("\n");
    }

// adding timer to Not drinking
    if (current_state==HIGH){
      if (timer<5000){
        timer++;
        }
      else{
        Serial.print("Drink to stay hydrated");
        lcd.setCursor(0, 0);
        lcd.print("Drink to Hydrate!!");
        lcd.setCursor(0, 10);
        lcd.print("  Stay Healthy");
        Serial.print("\n");
        }
    }
    else {
      timer=0;
//      lcd.setCursor(0, 0);
//      lcd.print("Drink to Hydrate!!");
    }
    delay(1);
    prev_state=current_state;
}






///////
//      //starting timer
//      if (timer<5000){
//        timer++;
//        }
//      else{
//        Serial.print("Drink to stay hydrated");
//        lcd.setCursor(0, 0);
//        lcd.print("Drink to Hydrate!!");
//        }
//        Serial.print(timer);
//      } 
