#include "Doctors.h"
string Doctors::get_department()
{
	return this->department;
}
int Doctors::get_length()
{
	return this->length;
}
void Doctors::set_department(string department)
{
	this->department = department;
}
void Doctors::set_length(int length)
{
	this->length = length;
}
void Doctors::show()
{
	Med_Personal::show();
	cout << setw(20) << this->department << setw(20) << this->length << endl;
}
void Doctors::shapka()
{
	Med_Personal::shapka();
	cout << setw(20) << "���������" << setw(20) << "���� ������" << endl;
	cout << "--------------------------------------------------------------------------------------------------------------------\t";
}
istream& operator>>(istream&in, Doctors&ob)
{
	string fam, name, otch, time, department;
	int length;
	_flushall();
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)((0 << 4 | 13)));
	cout << "\n������� : "; fam = ob.People::Check_string();
	ob.People::set_fam(fam);
	cout << "\n��� : "; name = ob.People::Check_string();
	ob.People::set_name(name);
	cout << "\n�������� : "; otch = ob.People::Check_string();
	ob.People::set_otch(otch); _flushall();
	cout << "\n����� ������ : " << endl;
	cout << " 1 - 6:30-15:30          7 - 14:00-22:00" << endl;
	cout << " 2 - 7:00-16:00          8 - 14:30-22:30" << endl;
	cout << " 3 - 7:30-16:30          9 - 15:00-23:00" << endl;
	cout << " 4 - 8:00-17:00          10 - 15:30-23:30" << endl;
	cout << " 5 - 8:30-17:30          11 - 16:00-00:00" << endl;
	cout << " 6 - 9:00-18:00          12 - 16:30-00:30" << endl;
	cout << "        0 - ������ ��� ����� ������" << endl;
	cout << " �� ���������: 8:00-17:00" << endl;
	cout << " ��� �����: ";
	int z; z = ob.People::Check_int();
	switch (z)
	{
	case 1:  ob.Med_Personal::set_time("6:30-15:30 "); break;
	case 2:  ob.Med_Personal::set_time("7:00-16:00"); break;
	case 3:  ob.Med_Personal::set_time("7:30-16:30"); break;
	case 4:  ob.Med_Personal::set_time("8:00-17:00"); break;
	case 5:  ob.Med_Personal::set_time("8:30-17:30"); break;
	case 6:  ob.Med_Personal::set_time("9:00-18:00"); break;
	case 7:  ob.Med_Personal::set_time("14:00-22:00"); break;
	case 8:  ob.Med_Personal::set_time("14:30-22:30"); break;
	case 9:  ob.Med_Personal::set_time("15:00-23:00"); break;
	case 10:  ob.Med_Personal::set_time("15:30-23:30"); break;
	case 11:  ob.Med_Personal::set_time("16:00-00:00"); break;
	case 12:  ob.Med_Personal::set_time("16:30-00:30"); break;
	case 0: getline(in, time);
		ob.Med_Personal::set_time(time); break;
	default:  ob.Med_Personal::set_time("8:00-17:00"); break;
	}
	_flushall();
	cout << "\n��������� : " << endl;
	cout << " 1 - �������������" << endl;
	cout << " 2 - ���������" << endl;
	cout << " 3 - �����������������" << endl;
	cout << " 4 - ������" << endl;
	cout << " 5 - ����������" << endl;
	cout << " 6 - ��������������" << endl;
	cout << " 7 - �������" << endl;
	cout << " 8 - ����������������" << endl;
	cout << " 9 - ���������������" << endl;
	cout << " �� ��������� - ���������������" << endl;
	cout << " ��� �����: ";
	char x; cin >> x;
	switch (x)
	{
	case '1':  ob.Doctors::set_department("�������������"); break;
	case '2':  ob.Doctors::set_department("���������"); break;
	case '3':  ob.Doctors::set_department("�����������������"); break;
	case '4':  ob.Doctors::set_department("������"); break;
	case '5':  ob.Doctors::set_department("����������"); break;
	case '6':  ob.Doctors::set_department("��������������"); break;
	case '7':  ob.Doctors::set_department("�������"); break;
	case '8':  ob.Doctors::set_department("����������������"); break;
	case '9':  ob.Doctors::set_department("���������������"); break;
	default:   ob.Doctors::set_department("���������������"); break;
	} 
	cout << endl; _flushall();
	cout << "���� ������(������ ���) : "; length = ob.People::Check_int();
	ob.Doctors::set_length(length);
	return in;
}
ostream& operator<<(ostream&out, Doctors&ob)
{
	ob.show();
	return out;
}
ifstream& operator>>(ifstream&fin, Doctors&ob)
{
	fin >> ob.fam >> ob.name >> ob.otch >> ob.time >> ob.department >> ob.length;
	return fin;
}
ofstream& operator<<(ofstream&fout, Doctors&ob)
{
	fout << ob.fam << " " << ob.name << " " << ob.otch << " " << ob.time << " " << ob.department << " " << ob.length << endl;
	return fout;
}
bool Doctors::operator>(Doctors&ob)
{
	return (this->length > ob.length);
}
void Doctors::edit_pole(Doctors&ob)
{
	char vv;
	do{
		cout << " ����� ���� ������ ���������������: " << endl;
		cout << " 1 - �������" << endl;
		cout << " 2 - ���" << endl;
		cout << " 3 - ��������" << endl;
		cout << " 4 - ����� ������" << endl;
		cout << " 5 - ���������" << endl;
		cout << " 6 - ���� ������ (������ ���)" << endl;
		cout << " 0 - ��������� � ����" << endl;
		cout << "��� �����: ";
		cin >> vv;
		switch (vv)
		{
		case '1': 
			cout << " ����� �������: ";
			fam = ob.People::Check_string();
			ob.People::set_fam(fam);
			cout << endl;
			break;
		case '2': 
			cout << " ����� ���: ";
			name = ob.People::Check_string();
			ob.People::set_name(name);
			cout << endl; 
			break;
		case '3': 
			cout << " ����� ��������: ";
			otch = ob.People::Check_string();
			ob.People::set_otch(otch);
			cout << endl;
			break;
		case '4': 
			cout << " ����� ����� ������: ";
			time = ob.Med_Personal::Check_string();
			ob.Med_Personal::set_time(time);
			cout << endl; break;
		case '5': 
			cout << " ����� ���������: ";
			department = ob.Doctors::Check_string();
			ob.Doctors::set_department(department);
			cout << endl;
			break;
		case '6':
			cout << " ���� ������(������ ���): ";
			length = ob.Doctors::Check_int();
			ob.Doctors::set_length(length);
			cout << endl;
			break;
		}
	} while (vv != '0');
}