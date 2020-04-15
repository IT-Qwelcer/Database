#include "Worker.h"
#include <iostream>
#include <list>
#include <conio.h>
#include <ctype.h>
#include <fstream>

using namespace std;

list<worker>listworker;
const string filename = "Worker.txt";

void init()
{
	ifstream fin;
	fin.open(filename);

	bool isopen = fin.is_open();

	if (isopen == false) {

		//cout << "Error" << endl;
	}
	else {
		worker tempworker;
		int current = 0;
		string temp;

		while (!fin.eof()) {
			current++;
			getline(fin, temp);

			if (current == 1) {

				tempworker.name = temp;
			}
			else if (current == 2) {

				tempworker.sekondname = temp;

			}
			else if (current == 3) {

				tempworker.age = temp;
			}
			else if (current == 4) {

				tempworker.id = temp;
				listworker.push_back(tempworker);
				current = 0;
				tempworker = worker();
			}
		}
	}
}
int addinfo()
{
	worker newworker;

	cout << "\n\t Enter name -> ";
	cin >> newworker.name;

	cout << "\n\t\t Enter sekond name -> ";
	cin >> newworker.sekondname;

	cout << "\n\t Enter ege -> ";
	cin >> newworker.age;

	cout << "\n\t\t Enter id -> ";
	cin >> newworker.id;

	listworker.push_back(newworker);

	system("cls");
	return 0;
}

int redakt()
{
	string newName;
	string newSekondname;
	string newAge;
	string newID;
	string iD;
	cout << "\n\t Enter id worker for editing -> ";
	cin >> iD;
	system("cls");

	int a;

	for (worker& item : listworker) {

		if (iD == item.id) {

			cout << "\n\t Name -> " << item.name << endl;
			cout << "\t Sekond name -> " << item.sekondname << endl;
			cout << "\t Age -> " << item.age << endl;
			cout << "\t ID -> " << item.id << endl;
			cout << endl;

			do {
				cout << "\n\t 1.Name " << endl;
				cout << "\t 2.Sekond name " << endl;
				cout << "\t 3.Age " << endl;
				cout << "\t 4.ID " << endl;
				cout << "\t 5.Exit " << endl;
				cout << "\n\t Selekt punkt for editing -> ";
				cin >> a;
				system("cls");

				switch (a)
				{
				case 1:
					cout << "\n\t Enter new name -> ";
					cin >> newName;
					item.name = newName;
					system("cls");
					break;
				case 2:
					cout << "\n\t\t Enter new sekond name -> ";
					cin >> newSekondname;
					item.sekondname = newSekondname;
					system("cls");
					break;
				case 3:
					cout << "\n\t Enter new age -> ";
					cin >> newAge;
					item.age = newAge;
					system("cls");
					break;
				case 4:
					cout << "\n\t\t Enter new ID -> ";
					cin >> newID;
					item.id = newID;
					system("cls");
					break;
				case 5:
					break;
				}

			} while (a != 5);
		}
	}

	return 0;
}

int dleteWorkers()
{
	string name;
	cout << "\n\t Enter sekond name for dell worker -> ";
	cin >> name;

	for (auto i = listworker.begin(); i != listworker.end(); i++) {

		if (i->sekondname == name) {

			listworker.erase(i);
			break;
		}
	}

	return 0;
}

int shorchbyAge()
{
	string age;
	cout << "\n\t Enter age for search -> ";
	cin >> age;

	for (worker item : listworker) {

		if (item.age == age) {

			cout << "\n\t Name -> " << item.name << endl;
			cout << "\t Sekond name -> " << item.sekondname << endl;
			cout << "\t Age -> " << item.age << endl;
			cout << "\t ID -> " << item.id << endl;
			cout << endl;
		}
	}

	return 0;
}

void shourchbySekondname()
{
	string sekondname;
	cout << "\n\t Enter sekond name worker for shourch -> ";
	cin >> sekondname;

	for (worker item : listworker) {

		if (item.sekondname == sekondname) {

			cout << "\n\t Name -> " << item.name << endl;
			cout << "\t Sekond name -> " << item.sekondname << endl;
			cout << "\t Age -> " << item.age << endl;
			cout << "\t ID -> " << item.id << endl;
			cout << endl;
		}
	}
}

int writeinfile()
{
	for (worker item : listworker) {

		ofstream fout;
		fout.open(filename, fstream::app);

		bool isopen = fout.is_open();

		if (isopen == true) {

			cout << "\n\t File was write seksesful! \n";
			fout << item.name << endl;
			fout << item.sekondname << endl;
			fout << item.age << endl;
			fout << item.id << endl;
		}
		else {
			cout << "\n\t Error file not opend! \n";
		}
	}

	return 0;
}