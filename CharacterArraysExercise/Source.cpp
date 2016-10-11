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

void stringName5()
{
	int size = 255;
	char *name[5] = {
		name[0] = new char[256],
		name[1] = new char[256],
		name[2] = new char[256],
		name[3] = new char[256],
		name[4] = new char[256]
	};

	cout << "Type your full names here: " << endl;

	for (int i = 0; i < 5; i++)
	{
		cin >> name[i];
		stringRev(name[i]);
	}

	cout << "The names in reverse are: " << endl;
	
	for (int i = 0; i < 5; i++)
		cout << name[i] << endl;

	system("pause");
}

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
	bool length = false;
	int symbol = 0;
	int capital = 0;
	int number = 0;


	//Checks through character array for the end of the string
	for (int i = 0; i < strlen(password); i++)
	{
		if (i + 1 >= minimum)
			length = true;
		else if (i + 1 < minimum)
			length = false;
	}

	for (int i = 0; i < strlen(password); i++)
	{
		if (password[i] >= 65 && password[i] <= 90)		//Checks through the character array for a capital letter
			capital++;
		if (password[i] >= 48 && password[i] <= 57) 	//Checks through the character array for a number
			number++;
		if (password[i] >= 33 && password[i] <= 47)		//Checks through the character array for a symbol
			symbol++;
	}

	//Checks if all requirements are true
	if (length == true && symbol > 0 && capital > 0 && number > 0)
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
			break;
		}
		else
		{
			cout << "Invalid password!" << endl;
			system("pause");
		}
	}
}

/* Exercise 7 answers:
a. Trying to initialize the variable name[4] with "John". "John" is incompatible with type char[4]. To fix it, the type should be const char[5].
b. Trying to output a char array. The char array is uninitialized, and there is nothing to output. Initialize the array first, then output.
c. Trying to append name with surname. Both arrays are not compatible with the initilized values. They need to be const char.
d. Trying to initialized a character array, while adding an exclamation mark at the end with a separate initialization, then outputting. errorMsg is initialized uncorrectly. Both need to be const char.
*/

//Exercise 8

void piglatin()
{
	char *input = new char[256];
	int length = 0;

	cout << "Input a word and I'll give it to you in pig latin: ";
	cin >> input;

	while (input[length] != '\0') //Checks length
		length++;

	input[length] = input[0]; //Moves first letter to back and adds "ay"
	input[length + 1] = 'a';
	input[length + 2] = 'y';
	input[length + 3] = '\0';

	length = 0;
	while (input[length] != '\0') //Checks length again
		length++;

	for (int i = 0; i < length; i++) //Shifts the string back by 1
		input[i] = input[i + 1];

	cout << "Your word in pig latin is: " << input << endl;

	system("pause");
}

//Exercise 9
void lineCount()
{
	char *input = new char[256];
	int words = 0;
	int nums = 0;
	int sos = 0;
	int length = 0;
	
	cin.getline(input, 256);

	while (input[length] != '\0')
		length++;

	for (int i = 0; i < length+1; i++)
	{
		if (input[i - 1] <= 90 && input[i - 1] >= 65 && input[i] == 32 || input[i - 1] <= 122 && input[i - 1] >= 97 && input[i] == 32 || input[i - 1] <= 90 && input[i - 1] >= 65 && input[i] == '\0' || input[i - 1] <= 122 && input[i - 1] >= 97 && input[i] == '\0')
			words++;
		else if (input[i - 1] <= 57 && input[i - 1] >= 48 && input[i] == 32 || input[i - 1] <= 57 && input[i - 1] >= 48 && input[i] == '\0')
			nums++;
	}

	cout << "The amount of words in this line is: " << words << endl;
	cout << "The amount of numbers in this line is: " << nums << endl;

	system("pause");
}

//Exercise 10
bool palindrome()
{
	char input[256];
	int length = 0;
	char forward[256];
	char reverse[256];
	int match = 0;

	cin >> input;

	while (input[length] != '\0')
		length++;

	for (int i = 0; i < length + 1; i++)
		forward[i] = input[i];

	for (int i = 0; i < length + 1; i++)
		reverse[i] = input[length - i - 1];
	reverse[length] = '\0';

	for (int i = 0; i < length; i++)
	{
		if (reverse[i] == forward[i])
			match++;
	}

	if (match == length)
		return true;
	else
		return false;
}

void main()
{
	if (palindrome())
		cout << "Yep" << endl;
	else
		cout << "Nope" << endl;
	system("pause");
}