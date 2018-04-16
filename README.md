# rcsesimontypes
RCSE Embedded Systems Lab 2018

# Functional Requirements

1 Show the message "Press Enter to Start" until the user presses the "Enter Key"
2 Show the message "Select Level 1 to 5" until the user gives a number between 1 to 5
3 Set score = 0
4 Show a random sequence with (level + 5) number of characters for 2 seconds
5 Hide the sequence and prompt the user to enter the sequence 
6 If the user enters the correct sequence increment the score by 1 (ie score++) else if the answer is wrong go to step 10
7 If the score is a multiple of 5 (ie score % 5 == 0) increment level by 1 (ie level++)
8 Go to Step 4	
9 If the user presses "Space Key" to restart the game go to Step 2
10 Show the message "Game Over" along with score

# Required Components

	1 Arduino Uno
	1 A PS2 keyboard
	2 A LCD Display (16x2)
	3 Jumper Wires
	

