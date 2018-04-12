#include "Med_Sisters.h"

string Med_Sisters::get_position()
{
	return this->position;
}
void Med_Sisters::set_position(string position)
{
	this->position = position;
}
void Med_Sisters::show()
{
	Med_Personal::show();
	cout << setw(20) << this->position << endl;
}
void Med_Sisters::shapka()
{
	Med_Personal::shapka();
	cout << setw(20) << "���������" << endl;
	cout << "--------------------------------------------------------------------------------------------------------------------\t";
}
istream& operator>>(istream&in, Med_Sisters&ob)
{
	string fam, name, otch, time;
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
	default:   ob.Med_Personal::set_time("8:00-17:00"); break;
	}
	_flushall();
	cout << "\n��������� ���������: " << endl;
	cout << " 1 - �������" << endl;
	cout << " 2 - �������" << endl;
	cout << " 3 - ��������" << endl;
	cout << " 4 - �����������" << endl;
	cout << " Default - �������" << endl;
	cout << " ��� �����: "; 
	char x; cin >> x;
	switch (x)
	{
	case '1':  ob.Med_Sisters::set_position("�������"); break;
	case '2':  ob.Med_Sisters::set_position("�������"); break;
	case '3':  ob.Med_Sisters::set_position("��������"); break;
	case '4':  ob.Med_Sisters::set_position("�����������"); break;
	default:   ob.Med_Sisters::set_position("�������"); break;
	}
	_flushall();
	return in;
}
ostream& operator<<(ostream&out, Med_Sisters&ob)
{
	ob.show();
	return out;
}
ifstream& operator>>(ifstream&fin, Med_Sisters&ob)
{
	fin >> ob.fam >> ob.name >> ob.otch >> ob.time >> ob.position;
	return fin;
}
ofstream& operator<<(ofstream&fout, Med_Sisters&ob)
{
	fout << ob.fam << " " << ob.name << " " << ob.otch << " " << ob.time << " " << ob.position << endl;
	return fout;
}
bool Med_Sisters::operator>(Med_Sisters&ob)
{
	return (this->position) > ob.position;
}
void Med_Sisters::edit_pole(Med_Sisters&ob)
{
	char vv;
	do{
		cout << " ����� ���� ������ ���������������: " << endl;
		cout << " 1 - �������" << endl;
		cout << " 2 - ���" << endl;
		cout << " 3 - ��������" << endl;
		cout << " 4 - ����� ������" << endl;
		cout << " 5 - ���������" << endl;
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
			position = ob.Med_Sisters::Check_string();
			ob.Med_Sisters::set_position(position);
			cout << endl;
			break;
		}
	} while (vv != '0');
}