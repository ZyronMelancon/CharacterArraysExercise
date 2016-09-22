#include <iostream>
#include <istream>
#include <string>
#include <cstdlib>

using namespace std;

//Exercise 1 + 2

void stringRev(char input[])
{
	char y = '0';
	int length = 0;

	for (int i = 0; i < 255; i++)
	{
		if (input[i] == 0)
			break;
		else
			length++;
	}

	for (int x = 0; x < length; x++)
	{
		for (int i = 0; i < length - x - 1; i++)
		{
			y = input[i + 1];
			input[i + 1] = input[i];
			input[i] = y;
		}
	}
}

void stringName()
{
	int size = 255;
	char *name = new char[256];
	cout << "Type your full name here: " << endl;

	cin >> name;

	stringRev(name);
	cout << "Your name in reverse is: " << name << endl;

	system("pause");
}

//Exercise 3


/* Exercise 4 answer: ASCII code 7 */

//Exercise 5

/* This function checks the input
password for multiple requirements,
those being: A minimum of 8 characters,
at least one symbol, at least one 
capital latter, and at least one 
number. */
bool passCheck(char password[])
{
	int minimum = 8;
	bool length = 0;
	int symbol = 0;
	int capital = 0;
	int number = 0;


	//Checks through character array for the end of the string
	for (int i = 0; i < strlen(password); i++)
	{
		if (password[i] == 0 && i - 1 >= minimum)
			length = true;
		else if (password[i] == 0 && i - 1 < minimum)
			length = false;
	}

	//Checks through the character array for a capital letter
	for (int i = 0; i < strlen(password); i++)
	{
		if (password[i] >= 65 && password[i] <= 90)
			capital++;
	}

	//Checks through the character array for a number
	for (int i = 0; i < strlen(password); i++)
	{
		if (password[i] >= 48 && password[i] <= 57)
			number++;
	}

	//Checks through the character array for a symbol
	for (int i = 0; i < strlen(password); i++)
	{
		if (password[i] >= 33 && password[i] <= 47)
			symbol++;
	}

	//Checks if all requirements are true
	if (length == true && symbol < 0 && capital < 0 && number < 0)
		return true;
	else
		return false;
}

void usrSystem()
{
	char *usrname = new char[256];
	char *passwrd = new char[256];

	cout << "Enter a username: ";
	cin >> usrname;

	while (true)
	{
		system("cls");
		cout << "Enter a password: ";
		cin >> passwrd;

		if (passCheck(passwrd) == true)
		{
			cout << "User created!" << endl;
			system("pause");
		}
		else
		{
			cout << "Invalid password!" << endl;
			system("pause");
		}
	}
}

void main()
{
	usrSystem();
}