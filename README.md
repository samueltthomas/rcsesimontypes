# Simon Types
RCSE Embedded Systems Lab 2018

# Breadboard

<img src="simon_types_breadboard.svg">

# Functional Requirements

1 Show the message "Press Enter to Start" until the user presses the "Enter Key"<br/>
2 Show the message "Select Level 1 to 5" until the user gives a number between 1 to 5<br/>
3 Set score = 0<br/>
4 Show a random sequence with (level + 5) number of characters for 2 seconds<br/>
5 Hide the sequence and prompt the user to enter the sequence <br/>
6 If the user enters the correct sequence increment the score by 1 (ie score++) else if the answer is wrong go to step 10 <br/>
7 If the score is a multiple of 5 (ie score % 5 == 0) increment level by 1 (ie level++) <br/>
8 Go to Step 4	<br/>
9 If the user presses "Space Key" to restart the game go to Step 2 <br/>
10 Show the message "Game Over" along with score <br/>

# Required Components

1 Arduino Uno Board 
2 LCD Screen (compatible with Hitachi HD44780 driver)
3 pin headers to solder to the LCD display pins
4 10k ohm potentiometer
5 220 ohm resistor * 3
6 hook-up wires
7 breadboard
8 PS2 Keyboard
9 PS2 Keyboard Connector
10 Red LED
11 Green LED


	

