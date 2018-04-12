#include "People.h"

string People::get_fam()
{
	return this->fam;
}
string People::get_name()
{
	return this->name;
}
string People::get_otch()
{
	return this->otch;
}
void People::set_fam(string fam)
{
	this->fam = fam;
}
void People::set_name(string name)
{
	this->name = name;
}
void People::set_otch(string otch)
{
	this->otch = otch;
}
void People::show()
{
	cout << setw(15) << this->fam << setw(15) << this->name << setw(20) << this->otch;
}
void People::shapka()
{
	cout << setw(15) << "          Фамилия" << setw(15) << "Имя" << setw(20) << "Отчество";
}
int People::Check_int()
{
	int Fail_int;
	while (true){
		cin >> Fail_int;
		if (cin.good() == false){
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4 | 12)));
			cout << "Неверный ввод. Повторите попытку: " << endl;
			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4 | 13)));
			cin.clear();
			while (cin.get() != '\n');
		}
		else return Fail_int;
	}
}
string People::Check_string()
{
	string Fail_string;
	bool flag = true;
	do
	{
		flag = true;
		_flushall();
		cin >>Fail_string;
		int len = 0, f = 0;
		len = Fail_string.length();
		for (int i = 0; i < len; i++)
			if (Fail_string[i] < 'А' || Fail_string[i] > 'я' || (Fail_string[i] == 8 && i > 0))
				f++;
		if (f == 0)
			return Fail_string;
		else
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4 | 12)));
			cout << "Неверный ввод. Повторите попытку: " << endl;
			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4 | 13)));
			cin.clear();
			cin.sync();
			flag = false;
		}
	} while (!flag);
}