/* Samantha Miller
   CPSC-340-01
   Project 1: Guessing Game*/

#include <iostream>
#include <string>
#include <ctime>
#include <climits>
#include <cstdlib>

using namespace std;

//Description: Uses srand function to generate a random number between 1-1000
int generateNumber();
int getGuess();
bool compare(int generated, int guess);


int main()
{
	int genNum = 0;
	int userNum = 0;
	//Seed the number generator
	srand(time(0)%INT_MAX);
	cout<<"Welcome to the Guessing Game! Developed by Samantha Miller."<<endl;
	genNum = generateNumber();
	cout<<genNum<<endl;
	cout<<"I have generated a random number for you to guess."<<endl;
	numUser = getGuess();

	return 0;
}

int generateNumber()
{
	int number = 0;
	number = rand()%1000 + 1;
}

int getGuess()
{
	int guess = 0;
	cout<<"Type a number between 1 and 1000: ";
	//While it does not meet the number criteria, guess again.
	while (!(cin.peek() >= '0' && <= '9'))
	{
		cout<<"You typed an invalid character! Type a number betweeen 1 and 1000: ";
	}
}
/*
bool compare(int generated, int guess)
{
}*/
