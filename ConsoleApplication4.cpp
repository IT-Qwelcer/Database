#include <iostream>
#include "Worker.h"

using namespace std;

int main()
{
	init();
	int a;
	int count = 0;

	do {
		cout << "\n\t 1.Add new worker \n";
		cout << "\t 2.Redakr \n";
		cout << "\t 3.Search by age \n";
		cout << "\t 4.Search by sekond name \n";
		cout << "\t 5.Dellet \n";
		cout << "\t 6.Write in file \n";
		cout << "\t 7.Exit \n";
		cout << "\n\t Select an action: ";
		cin >> a;
		system("cls");

		switch (a)
		{
		case 1:
			addinfo();
			break;
		case 2:
			redakt();
			break;
		case 3:
			shorchbyAge();
			break;
		case 4:
			shourchbySekondname();
			break;
		case 5:
			dleteWorkers();
			break;
		case 6:
			writeinfile();
			count++;
			break;
		case 7:
			writeinfile();
			break;
		}

	} while (a != 7);
}