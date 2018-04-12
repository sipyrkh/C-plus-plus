#ifndef AMBULATORY_H
#define AMBULATORY_H

#include <iostream>
#include <iomanip>
#include <conio.h>
#include <fstream>
#include "Patients.h"
using namespace std;

class Ambulatory :public Patients
{
protected:
	int press;
	string medication;
public:
	Ambulatory(string fam_in = " ", string name_in = " ", string otch_in = " ", string diagnose_in = " ", string medication_in = " ", int press_in = 0) :Patients(fam_in, name_in, otch_in, diagnose_in)
	{
		press = press_in;
		medication = medication_in;
		//cout << "Конструктор Ambulatory" << endl;
	}
	~Ambulatory()
	{
		//cout << "Деструктор Ambulatory" << endl;
	}
	string get_medication();
	int get_press();
	bool operator>(Ambulatory&);
	void set_press(int);
	void set_medication(string);
	virtual void show();
	virtual void shapka();
	void edit_pole(Ambulatory&ob);
	friend istream& operator>>(istream&in, Ambulatory&ob);
	friend ostream& operator<<(ostream&out, Ambulatory&ob);
	friend ifstream& operator>>(ifstream&fin, Ambulatory&ob);
	friend ofstream& operator<<(ofstream&fout, Ambulatory&ob);
};

#endif AMBULATORY_H