#define _CRT_SECURE_NO_WARNINGS
#ifndef MED_PERSONAL_H
#define MED_PERSONAL_H

#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>
#include "People.h"
using namespace std;

class Med_Personal:public People
{
protected:
	string time;
public:
	Med_Personal(string fam_in = " ", string name_in = " ", string otch_in = " ", string time_in = " ") :People(fam_in, name_in, otch_in)
	{
		time = time_in;
		//cout << "Конструктор Med_Personal" << endl;
	}
	~Med_Personal()
	{
		//cout << "Деструктор Med_Personal" << endl;
	}
	string get_time();
	void set_time(string);
	virtual void show();
	virtual void shapka();
};

#endif MED_PERSONAL_H