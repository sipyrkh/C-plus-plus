#include "Ambulatory.h"

string Ambulatory::get_medication()
{
	return this->medication;
}
int Ambulatory::get_press()
{
	return this->press;
}
void Ambulatory::set_press(int press)
{
	this->press = press;
}
void Ambulatory::set_medication(string medication)
{
	this->medication = medication;
}
void Ambulatory::show()
{
	Patients::show();
	cout << setw(20) << this->press << setw(20) << this->medication << endl;
}
void Ambulatory::shapka()
{
	Patients::shapka();
	cout << setw(20) << "Нижнее давление" << setw(20) << "Лекарство" << endl;
	cout << "--------------------------------------------------------------------------------------------------------------------\t";
}
istream& operator>>(istream&in, Ambulatory&ob)
{
	string fam, name, otch, diagnose, medication;
	int press;
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
	cout << "\nНазначенные лекарства : "; medication = ob.People::Check_string();
	ob.Ambulatory::set_medication(medication);
	cout << "\nНижнее артериальное давление : "; press = ob.People::Check_int();
	ob.Ambulatory::set_press(press);
	return in;
}
ostream& operator<<(ostream&out, Ambulatory&ob)
{
	ob.show();
	return out;
}
ifstream& operator>>(ifstream&fin, Ambulatory&ob)
{
	fin >> ob.fam >> ob.name >> ob.otch >> ob.diagnose >> ob.medication >> ob.press;
	return fin;
}
ofstream& operator<<(ofstream&fout, Ambulatory&ob)
{
	fout << ob.fam << " " << ob.name << " " << ob.otch << " " << ob.diagnose << " " << ob.medication << " " << ob.press << endl;
	return fout;
}
bool Ambulatory::operator>(Ambulatory&ob)
{
	return (this->press) > ob.press;
}
void Ambulatory::edit_pole(Ambulatory&ob)
{
	char vv;
	do{
		cout << " Какое поле хотите отредактировать: " << endl;
		cout << " 1 - Фамилию" << endl;
		cout << " 2 - Имя" << endl;
		cout << " 3 - Отчество" << endl;
		cout << " 4 - Диагноз" << endl;
		cout << " 5 - Назначенное лекарство" << endl;
		cout << " 6 - Нижнее артериальное давление" << endl;
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
			cout << " Назначенное лекарство: ";
			medication = ob.Ambulatory::Check_string();
			ob.Ambulatory::set_medication(medication);
			cout << endl;
			break;
		case '6':
			cout << " Нижнее артериальное давление: ";
			press = ob.Ambulatory::Check_int();
			ob.Ambulatory::set_press(press);
			cout << endl;
			break;
		}
	} while (vv != '0');
}