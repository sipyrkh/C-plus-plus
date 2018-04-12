#include "Stationary.h"

int Stationary::get_procedures()
{
	return this->procedures;
}
void Stationary::set_procedures(int procedures)
{
	this->procedures = procedures;
}
void Stationary::show()
{
	Patients::show();
	cout << setw(20) << this->procedures << endl;
}
void Stationary::shapka()
{
	Patients::shapka();
	cout << setw(20) << "Кол-во процедур" << endl;
	cout << "--------------------------------------------------------------------------------------------------------------------\t";
}
istream& operator>>(istream&in, Stationary&ob)
{
	string fam, name, otch, diagnose;
	int procedures;
	_flushall();
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)((0 << 4 | 13)));
	cout << "\nФамилия : "; fam = ob.People::Check_string();
	ob.People::set_fam(fam);
	cout << "\nИмя : "; name = ob.People::Check_string();
	ob.People::set_name(name);
	cout << "\nОтчество : "; otch = ob.People::Check_string();
	ob.People::set_otch(otch); _flushall();
	cout << "\nДиагноз : "; diagnose = ob.People::Check_string();
	ob.Patients::set_diagnose(diagnose); _flushall();
	cout << "\nКоличество процедур в день : "; procedures = ob.People::Check_int();
	ob.Stationary::set_procedures(procedures);
	return in;
}
ostream& operator<<(ostream&out, Stationary&ob)
{
	ob.show();
	return out;
}
ifstream& operator>>(ifstream&fin, Stationary&ob)
{
	fin >> ob.fam >> ob.name >> ob.otch >> ob.diagnose >> ob.procedures;
	return fin;
}
ofstream& operator<<(ofstream&fout, Stationary&ob)
{
	fout << ob.fam << " " << ob.name << " " << ob.otch << " " << ob.diagnose << " " << ob.procedures << endl;
	return fout;
}
bool Stationary::operator>(Stationary&ob)
{
	return (this->procedures) > ob.procedures;
}
void Stationary::edit_pole(Stationary&ob)
{
	char vv;
	do{
		cout << " Какое поле хотите отредактировать: " << endl;
		cout << " 1 - Фамилию" << endl;
		cout << " 2 - Имя" << endl;
		cout << " 3 - Отчество" << endl;
		cout << " 4 - Диагноз" << endl;
		cout << " 5 - Количество процедур в день" << endl;
		cout << " 0 - Вернуться в меню" << endl;
		cout << "Ваш выбор: ";
		cin >> vv;
		switch (vv)
		{
		case '1':
			cout << " Новая фамилия: ";
			fam = ob.People::Check_string();
			ob.People::set_fam(fam);
			cout << endl;
			break;
		case '2':
			cout << " Новое имя: ";
			name = ob.People::Check_string();
			ob.People::set_name(name);
			cout << endl;
			break;
		case '3':
			cout << " Новое отчество: ";
			otch = ob.People::Check_string();
			ob.People::set_otch(otch);
			cout << endl;
			break;
		case '4':
			cout << " Новый диагноз: ";
			diagnose = ob.Patients::Check_string();
			ob.Patients::set_diagnose(diagnose);
			cout << endl; 
			break;
		case '5':
			cout << " Количество процедур в день: ";
			procedures = ob.Check_int();
			ob.set_procedures(procedures);
			cout << endl;
			break;
		}
	} while (vv != '0');
}