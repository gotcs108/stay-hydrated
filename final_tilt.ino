int current_state=0;
int prev_state=0;
int count=0;

void setup()
{
  Serial.begin(9600);
  
  pinMode(8, INPUT);
  digitalWrite(8, HIGH);
}

void loop()
{
  current_state=digitalRead(8); //HIGH when not pressed, LOW when pressed

  if(current_state != prev_state){    //prevents count growing continuosly
    if(current_state==HIGH){      //switch NOT pressed
      Serial.print(count);
      Serial.print(", NOT Drink");
      } 
    else{     //sqitch pressed
      count++;
      Serial.print(count);
      Serial.print(", Drink");
      }
    Serial.print("\n");
    }
    prev_state=current_state;
    
}
