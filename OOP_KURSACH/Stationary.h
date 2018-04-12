#ifndef STATIONARY_H
#define STATIONARY_H

#include <iostream>
#include <iomanip>
#include <conio.h>
#include <fstream>
#include "Patients.h"
using namespace std;

class Stationary :public Patients
{
protected:
	int procedures;
public:
	Stationary(string fam_in = " ", string name_in = " ", string otch_in = " ", string diagnose_in = " ", int procedures_in = 0):Patients(fam_in, name_in, otch_in)
	{
		procedures = procedures_in;
		//cout << "Конструктор Stationary" << endl;
	}
	~Stationary()
	{
		//cout << "Деструктор Stationary" << endl;
	}
	int get_procedures();
	bool operator>(Stationary&);
	void set_procedures(int);
	virtual void show();
	virtual void shapka();
	void edit_pole(Stationary&ob);
	friend istream& operator>>(istream&in, Stationary&ob);
	friend ostream& operator<<(ostream&out, Stationary&ob);
	friend ifstream& operator>>(ifstream&fin, Stationary&ob);
	friend ofstream& operator<<(ofstream&fout, Stationary&ob);
};

#endif STATIONARY_H