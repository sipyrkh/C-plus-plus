#pragma once
#include "Doctors.h"
#include "Med_Sisters.h"
#include "Stationary.h"
#include "Ambulatory.h"
#include "Stack.cpp"
#include <string>
template <class T>
class Interface
{
	T ob;
public:
	Interface(){}
	~Interface(){}
	void menu();
	void fun_do(string);
};