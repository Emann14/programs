//============================================================================
// Name        : Program3.cpp
// Author      : Evan M
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<conio.h>
#include<string.h>

//Standard namespace declaration
using namespace std;

//Main Function
int main()
{

	string first;
	string second;
	string third;
	int i;

	for(i = 0; i <=2; i++)
	{
	cout<<"Please input a string."<<endl;

		getline(cin, first);

	cout<<"Please input a string."<<endl;

		getline(cin, second);

	 third = first + " " + second;

     cout << third << endl;
	}


     return 0;
}
