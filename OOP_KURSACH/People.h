#define _CRT_SECURE_NO_WARNINGS
#ifndef PEOPLE_H
#define PEOPLE_H
#include "Windows.h"
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>
using namespace std;

class People
{
protected:
	string fam, name, otch;
public:
	People(string fam_in= " ", string name_in = " ", string otch_in = " ")
	{
		fam = fam_in;
		name = name_in;
		otch = otch_in;
		//cout << "Конструктор People" << endl;
	}
	~People()
	{
		//cout << "Деструктор People" << endl;
	}
	string get_fam();
	string get_name();
	string get_otch();
	void set_fam(string);
	void set_name(string);
	void set_otch(string);
	virtual void show();
	virtual void shapka();
	int Check_int();
	string Check_string();
};

#endif PEOPLE_H