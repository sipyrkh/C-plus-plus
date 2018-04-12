#pragma once
#include "Windows.h"
#include "Interface.cpp"
#include "Login.h"
#include <string>
#include <fstream>
#include <iostream>
#include <conio.h>

using namespace std;
void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "RUS");
	Login ob;
		if (ob.login_menu()){
			Interface <int> obj;
			Sleep(1000);
			obj.menu();
	}
}