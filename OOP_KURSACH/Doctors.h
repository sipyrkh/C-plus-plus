#ifndef DOCTORS_H
#define DOCTORS_H

#include <iostream>
#include <iomanip>
#include <conio.h>
#include <fstream>
#include "Med_Personal.h"
using namespace std;

class Doctors :public Med_Personal
{
protected:
	string department;
	int length;
public:
	Doctors(string fam_in = " ", string name_in = " ", string otch_in = " ", string time_in = " ", string department_in = " ", int length_in = 0) :Med_Personal(fam_in, name_in, otch_in, time_in)
	{
		department = department_in;
		length = length_in;
		//cout << "Конструктор Doctors" << endl;
	}
	~Doctors()
	{
		//cout << "Деструктор Doctors" << endl;
	}
	string get_department();
	int get_length();
	bool operator>(Doctors&);
	void set_department(string);
	void set_length(int);
	virtual void show();
	virtual void shapka();
	void edit_pole(Doctors&ob);
	friend istream& operator>>(istream&in, Doctors&ob);
	friend ostream& operator<<(ostream&out, Doctors&ob);
	friend ifstream& operator>>(ifstream&fin, Doctors&ob);
	friend ofstream& operator<<(ofstream&fout, Doctors&ob);
};

#endif DOCTORS_H