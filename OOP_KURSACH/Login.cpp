#include "Login.h"
#include <fstream>
#include "windows.h"
#include <conio.h>

void Login::set_username(string username)
{
	this->username = username;
}
void Login::set_password(string password)
{
	this->password = password;
}
istream& operator>>(istream&in, Login&ob)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)((0 << 4 | 7)));
	string username, password;
	char vvod; _flushall();
	cout << "\t��� ������������: "; cin >> username;
	ob.set_username(username); _flushall();
	cout << "\t������: "; 
	while (true){
		vvod = _getch();
		if (vvod == '\r')
			break;
		if (vvod == '\b'){
			cout << "\b \b";
			password.pop_back(); 
			continue;
		}
		password.push_back(vvod);
		cout << "*";
	}
	cout << endl;
	ob.set_password(password);
	return in;
}
ostream& operator<<(ostream&out, Login&ob)
{
	cout << ob.username << " " << ob.password << endl;
	return out;
}
ifstream& operator>>(ifstream&fin, Login&ob)
{
	fin >> ob.username >> ob.password;
	return fin;
}
ofstream& operator<<(ofstream&fout, Login&ob)
{
	fout << ob.username << " " << ob.password << endl;
	return fout;
}
bool Login::login_menu()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	Login ob;
	char choise;
	SetConsoleTextAttribute(hConsole, (WORD)((0 << 4 | 11)));
	cout << "\t����� ����������!" << endl;
	cout << " ������� � ������� ��� �����������������!" << endl;
	SetConsoleTextAttribute(hConsole, (WORD)((0 << 4 | 9)));
	cout << "  1 - ����� " << endl;
	cout << "  2 - ������������������ " << endl;
	cout << "  0 - �����" << endl;
	cout << "  ��� �����: "; cin >> choise;
	switch (choise)
	{
	case '1':
	{
		system("cls");
		cout << "\t-------�����������-------" << endl;
		cout << endl;
		cin >> ob;
		if (ob.enter()){
			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4 | 10)));
			cout << "\t�� ������� ����������������!" << endl;
			return true;
		}
		else{
			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4 | 12)));
			cout << "\t�������� ������ ��� �����!" << endl;
			Sleep(3000);
			ob.login_menu();
		}
	}
	break;
	case '2': system("cls");
		    cout << "\t���������� ��� ������������ � ������!" << endl << endl;
		    ob.registration();
			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4 | 10)));
		    cout << "\t�� ������� ������������������!" << endl;
			Sleep(3000);
		    ob.login_menu(); break;
	case '0': exit(1);
	default: SetConsoleTextAttribute(hConsole, (WORD)((0 << 4 | 12)));
		cout << "\t�������� �����!" << endl;
		ob.login_menu();
	}
}
bool Login::enter()
{
	Login ob;
	ifstream fin("Login.txt", ios::in);
	while (fin >> ob)
	{
		if ((this->username.compare(ob.username) == 0) && (this->password.compare(ob.password) == 0))
		{
			return true;
		}		
	}
	fin.close();
	return false;
}
void Login::registration()
{
	Login ob;
	Login ob1;
	cin >> ob1;
	ofstream fout("Login.txt", ios::app);
	fout << ob1;
	fout.close();
}