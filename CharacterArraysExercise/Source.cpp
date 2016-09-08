#include <iostream>
#include <istream>
#include <string>
#include <cstdlib>

using namespace std;

char stringRev(char name[])
{
	int *revname = new int[255];
	int length = strlen(name);
	int i = 0;
	

	reverse(name, &name[strlen(name)]);

	return *name;
}

void stringName()
{
	int size = 255;
	char *name = new char[255];

	cout << "Type your full name here: " << endl;

	cin >> name;

	cout << "Your name in reverse is: " << stringRev(name) << endl;

	system("pause");
}

void main()
{
	stringName();
}