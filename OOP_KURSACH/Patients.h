#define _CRT_SECURE_NO_WARNINGS
#ifndef PATIENTS_H
#define PATIENTS_H

#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>
#include "People.h"
using namespace std;

class Patients :public People
{
protected:
	string diagnose;
public:
	Patients(string fam_in = " ", string name_in = " ", string otch_in = " ", string diagnose_in = " ") :People(fam_in, name_in, otch_in)
	{
		diagnose = diagnose_in;
		//cout << "Конструктор Machines" << endl;
	}
	~Patients()
	{
		//cout << "Деструктор Machines" << endl;
	}
	string get_dignose();
	void set_diagnose(string);
	virtual void show();
	virtual void shapka();
};

#endif PATIENTS_H