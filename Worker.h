#include<string>
#pragma once

using namespace std;

struct worker {

	string name;
	string sekondname;
	string age;
	string id;
};

void init();
int addinfo();
int redakt();
int dleteWorkers();
int shorchbyAge();
void shourchbySekondname();
int writeinfile();