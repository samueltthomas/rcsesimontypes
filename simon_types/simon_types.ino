#include <MI0283QT2.h>
#include <DisplaySPI.h>
#include <PS2Keyboard.h>

const int DataPin = 5;
const int IRQpin =  3;

PS2Keyboard keyboard;
MI0283QT2 lcd;

String input_str;
String random_str;
String score_string;
char input_char = '\0';

int level = 0;
int score = -1;

int state = 0;

String generate_random_string(int length)
{
  int randomNumber;
  String str = "";
  const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  while (str.length() < length) {
    randomNumber = random(26);
    str += charset[randomNumber];
  }
  return str;
}

void setup() {
  lcd.begin();
  keyboard.begin(DataPin, IRQpin);
  Serial.begin(9600);

  lcd.fillScreen(RGB(255,  255,  0));

  while (input_char != PS2_ENTER) {
    if (keyboard.available()) {
      input_char = keyboard.read();
    }
    lcd.drawText( 70, 110, "PRESS ENTER TO START", 1,  RGB(255,  255,  0),  RGB(0,  0,  0));
  }

  state = 1;

  lcd.fillScreen(RGB(51,  255,  153));
  randomSeed(analogRead(0));

}

void loop() {

  while (!(level >= 1 && level <= 5)) {
    lcd.drawText( 70, 110, "SELECT LEVEL 1 to 5", 1,  RGB(51,  255,  153),  RGB(0,  0,  0));
    if (keyboard.available()) {
      level = keyboard.read() - '0';
    }
  }

  if (state < 2) {
    state = 2;
    lcd.fillScreen(RGB(255,  255,  255));
  }


   state = 3;
   
  do {
    
     score++;
    
    if (score > 0) {
      lcd.fillScreen(RGB(0,  255,  0));
      lcd.drawText(100, 110, "CORRECT", 1,  RGB(0,  255,  0),  RGB(0,  0,  0));
      lcd.fillScreen(RGB(255,  255,  255));
    }

    random_str = generate_random_string(level + 4);
    lcd.drawText(100, 80, "PLEASE REMEMBER", 1,  RGB(255,  255,  255),  RGB(0,  0,  0));
    lcd.drawText(100, 110, random_str, 1,  RGB(255,  255,  255),  RGB(0,  0,  0));
    delay(2000);
    lcd.fillScreen(RGB(255,  255,  255));
    lcd.drawText(100, 80, "PLEASE TYPE", 1,  RGB(255,  255,  255),  RGB(0,  0,  0));
    
    
    if(score>0) {
        score_string = "Score : " + String(score);
        lcd.drawText(200, 20, score_string, 1,  RGB(255,  255,  255),  RGB(0,  0,  0));
    }
  
    input_str = "";
    input_char = '\0';

    while ((input_str.length() < random_str.length())) {
      if (keyboard.available()) {
        input_char = keyboard.read();

        if(input_char>96&&input_char<123){
          input_char = input_char - 32;
        }
        
        if(input_char=='Z'){
          input_char='Y';
        }
        else if(input_char=='Y'){
          input_char='Z';
        }

        
         input_str += input_char;
        
      
        lcd.drawText(100, 110, input_str, 1,  RGB(255,  255,  255),  RGB(0,  0,  0));
      }
    }

   

    if (score != 0 && (score +1) % 5 == 0) {
      level++;
    }


  } while (random_str.equalsIgnoreCase(input_str));

  lcd.fillScreen(RGB(255,  0,  0));

  score_string = "GAME OVER : SCORE : " + String(score);
  lcd.drawText(70, 110, score_string, 1,  RGB(255,  0,  0),  RGB(0,  0,  0));

  state = 1;
  level = 0;
  score = -1;
  delay(3000);
   lcd.fillScreen(RGB(51,  255,  153));


}
