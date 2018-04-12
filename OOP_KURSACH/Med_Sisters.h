#ifndef MED_SISTERS_H
#define MED_SISTERS_H

#include <iostream>
#include <iomanip>
#include <conio.h>
#include <fstream>
#include "Med_Personal.h"
using namespace std;

class Med_Sisters :public Med_Personal
{
protected:
	string position;
public:
	Med_Sisters(string fam_in = " ", string name_in = " ", string otch_in = " ", string time_in = " ", string position_in = " ") :Med_Personal(fam_in, name_in, otch_in, time_in)
	{
		position = position_in;
		//cout << "Конструктор Med_Sisters" << endl;
	}
	~Med_Sisters()
	{
		//cout << "Деструктор Med_Sisters" << endl;
	}
	string get_position();
	bool operator>(Med_Sisters&);
	void set_position(string);
	void edit_pole(Med_Sisters&ob);
	virtual void show();
	virtual void shapka();
	friend istream& operator>>(istream&in, Med_Sisters&ob);
	friend ostream& operator<<(ostream&out, Med_Sisters&ob);
	friend ifstream& operator>>(ifstream&fin, Med_Sisters&ob);
	friend ofstream& operator<<(ofstream&fout, Med_Sisters&ob);
};

#endif MED_SISTERS_H