/* Samantha Miller
   CPSC-340-01
   Project 1: Guessing Game: Computer generates a random number for the user to guess.*/

#include <iostream>
#include <string>
#include <ctime>
#include <climits>
#include <cstdlib>

using namespace std;

//Description: Uses srand function to generate a random number between 1-1000
//Inputs:  None.
//Outputs: Returns a randomly generated number between 1 and 1000.
int generateNumber();

//Description:  Asks user for a guess, verifying input is a number and within range.
//Inputs: None. Function handles input through cin/cout.
//Outputs: Returns the user's guess to the main program. 
int getGuess();

//The compares the guess to the computer's number and provides feedback if incorrect.
//Input: The generated integer and the guessed integer.
//Output:  Returns a boolean, true if the guess is correct, false if guess is incorrect.
bool compare(int generated, int guess);

//The program that runs the user interface, functions, and generates a number to guess.
//No inputs. Output returns 0 if no errors.
int main() {

	int genNum = 0;
	int userNum = 0;
	bool rightAnswer = false;
	char yn = 'y';

	//Seed the number generator
	srand(time(0)%INT_MAX);
	cout<<"The Guessing Game: Developed by Samantha Miller."<<endl;
	cout<<"Cranky prompts inspired by GLaDOS (owned by Valve Corporation)."<<endl;
	cout<<"There will be cake after the tests are complete."<<endl;
	
	//Loop to quit the program
	do {
		cout<<endl;
		genNum = generateNumber();
		//cout<<"Number generated: "<<genNum<<endl;
		cout<<"I have generated a random number for you to guess."<<endl;
		
		//Loop for to continue guessing
		//I've never done this many do/whiles in my life.
		do {
			userNum = getGuess();
			cout<<"You guessed "<<userNum<<"."<<endl;
			rightAnswer = compare(genNum, userNum);
			cout<<endl;
		} while (!rightAnswer);

		cout<<endl;
		cout<<"You have won. For now."<<endl;
		cout<<"Would you like another test? Game. I meant game. Type y or n: ";
		cin.get(yn);
		cin.ignore(80, '\n');
		if (yn != 'y' && yn != 'n') {
			cout<<"You do not follow directions well and neither typed y nor n. We shall continue."<<endl;
		}
	} while (yn != 'n');

	cout<<"This concludes this portion of the test. I lied about the cake."<<endl;
	return 0;
}

int generateNumber() {
	int number = 0;
	number = rand()%1000 + 1;
}

int getGuess() {
	int guess = 0;
	//While it does not meet the number criteria, guess again.
	bool goodNum = false;
	do {
		cout<<"Type a number between 1 and 1000: ";
		while (cin.peek() >= '0' && cin.peek() <= '9') {
			cin>>guess;
		}
		if (guess > 0 && guess <= 1000) {
			goodNum = true;
		} else {
			cout<<"Your entry did not meet the parameters."<<endl;
			goodNum = false;
			cin.ignore(80, '\n');
		}
	} while (goodNum == false);
	cin.ignore(80, '\n');
	return guess;
}

bool compare(int generated, int guess) {
	if (generated < guess) {
		cout<<"Typical human. Guess lower."<<endl;
		return false;
	} else if (generated > guess) {
		cout<<"I thought you were smarter than you looked. Guess higher."<<endl;
		return false;
	} else {
		return true;
	}
}
