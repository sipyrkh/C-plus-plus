#include "Interface.h"
#include "windows.h"
#include <iostream>
#include <string>
#include <fstream>
template <class T>
void Interface <T>::menu()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int ch;
	People t;
	do{
		system("cls");
		cout << "\t����� ���������� � �������������� ������� ���. ������!\n";
		SetConsoleTextAttribute(hConsole, (WORD)((0 << 4 | 12)));
		cout << "  � ��� �� ������ ��������?\n";
		cout << "  1 - ���������\n";
		cout << "  2 - ������������ �������\n";
		cout << "  3 - ���������� �� ������������ �������\n";
		cout << "  4 - ���������� �� ������������ �������\n";
		cout << "  5 - �����\n\n";
		cout << "  ��� �����: ";
		ch = t.Check_int();
		cout << endl;
		switch (ch)
		{
		case 1:
		{
			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4 | 10)));
			cout << endl << "  �� ������� ���� � ���������!" << endl << endl; 
			system("pause");
			Interface <Doctors> obj;
			obj.fun_do("Doctors.txt");
		}
		break;
		case 2:
		{
			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4 | 10)));
			cout << endl << "  �� ������� ���� � ���. �������!" << endl << endl; 
			system("pause");
			Interface <Med_Sisters> obj;
			obj.fun_do("Med_Sisters.txt");
		}
		break;
		case 3:
		{
			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4 | 10)));
			cout << endl << "  �� ������� ���� � ����������, ������������ �� ������������ �������!" << endl << endl; 
			system("pause");
			Interface <Stationary> obj;
			obj.fun_do("Stationary.txt");
		}
		break;
		case 4:
		{
			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4 | 10)));
			cout << endl <<"  �� ������� ���� � ����������, ������������ �� ������������ �������!" << endl << endl; system("pause");
			Interface <Ambulatory> obj;
			obj.fun_do("Ambulatory.txt");
		}
		break;
		case 5:
			exit(1);
			break;
		}
	} while (ch != 5);
}
template <class T>
void Interface <T>::fun_do(string namefile)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	Stack <T> st;
	item<T> *t;
	T value;
	st.ReadFile(namefile);
	int oz, ch;
	do{
		SetConsoleTextAttribute(hConsole, (WORD)((0 << 4 | 14)));
		system("cls");
		cout << "  *************\t���� *************" << endl;
		cout << "  1 - �������� ����������" << endl;
		cout << "  2 - ����������� ����������" << endl;
		cout << "  3 - ������� ���������� �� �������" << endl;
		cout << "  4 - ������� ���������� �� �������" << endl;
		cout << "  5 - ������� ��� ����������" << endl;
		cout << "  6 - ����� �� ����� � �������" << endl;
		cout << "  7 - �������������� ����������(���������)" << endl;
		cout << "  8 - �������������� �� �����" << endl;
		cout << "  9 - ���������� ����������" << endl;
		cout << "  0 - ��������� � ����\n";
		cout << "  *********************************" << endl;
		cout << "  ��������������: ���� �������������� ������ �������� �������!" << endl << endl;
		cout << "  ��� �����: ";
		t = st.get();
		ch = t->i.Check_int(); cout << endl;
		switch (ch)
		{
		case 1:
			cout << "\t���� ������:" << endl;
			cin >> value;
			st.push(value);
			break;
		case 2:
			if (st.empty()){
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4 | 5)));
				cout << "--------------------------------------------------------------------------------------------------------------------\n";
				st.show();
				cout << "--------------------------------------------------------------------------------------------------------------------\n\t";
			}
			else{
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4 | 12)));
				cout << "���� ����. �������� ����������!" << endl;
			}
			system("pause");
			break;
		case 3:
			if (st.empty()){
				st.pop();
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4 | 10)));
				cout << endl << "\t�������� ������ �������." << endl;
				system("pause");
			}
			else{
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4 | 12)));
				cout << "���� ����. �������� ����������!" << endl;
				system("pause");
			}
			break;
		case 4:
			if (st.empty()){
				cout << "--------------------------------------------------------------------------------------------------------------------\n";
				st.show();
				cout << "--------------------------------------------------------------------------------------------------------------------\n\t";
				int k;
				cout << "�� ������ ������� ������ ��� �������: "; cin >> k;
				if (k > st.len() || k < 1)
				{
					SetConsoleTextAttribute(hConsole, (WORD)((0 << 4 | 12)));
					cout << "\n\t������ � ����� ������� �� �������!\n\t";
					system("pause");
				}
				else{
					st.pop_index(k);
					SetConsoleTextAttribute(hConsole, (WORD)((0 << 4 | 10)));
					cout << endl << "\t�������� ������ �������." << endl;
					system("pause");
				}
			}
			else{
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4 | 12)));
				cout << "���� ����. �������� ����������!" << endl;
				system("pause");
			}
			break;
		case 5:
			if (st.empty()){
				while (st.empty())
				{
					st.pop();
				}
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4 | 10)));
				cout << endl << "\t�������� ������ �������." << endl;
				system("pause");
			}
			else{
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4 | 12)));
				cout << "���� ����. �������� ����������!" << endl;
				Sleep(3000);
			}
			break;
		case 6:
		{
			if (st.empty()){
				T ob;
				string search_name, search_fam;
				cout << endl << "----------�����----------" << endl << endl;
				cout << "������� �������: "; _flushall(); search_fam = ob.People::Check_string();
				cout << "������� ���: "; _flushall(); search_name = ob.People::Check_string();
				st.SearchByFam(search_name, search_fam);
			}
			else{
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4 | 12)));
				cout << "���� ����! ����� ����������!" << endl;
				Sleep(3000);
			}
		}
		break;
		case 7:
		{
			int key;
			if (st.empty()){
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4 | 5)));
				cout << "--------------------------------------------------------------------------------------------------------------------\n";
				st.show();
				cout << "--------------------------------------------------------------------------------------------------------------------\n\t";
				cout << "����� ������ ������ ���������������: "; cin >> key;
				st.edit(key);
			}
			else{
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4 | 12)));
				cout << "���� ����! �������������� ����������!" << endl;
				Sleep(3000);
			}
		}
		break;
		case 8:
			if (st.empty()){
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4 | 5)));
				cout << "--------------------------------------------------------------------------------------------------------------------\n";
				st.show();
				cout << "--------------------------------------------------------------------------------------------------------------------\n\t";
				cout << "������� ����� ������,������� ������ ���������������: "; oz = ob.People::Check_int();
				t = st.get();
				if (oz > 0 && oz <= st.len())
				{
					for (int i = 0; i < oz-1; i++)
						t = t->next;
					t->i.edit_pole(t->i);
				}
				else{
					cout << "��� ����� ������!" << endl;
					system("pause");
				}
			}
			else{
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4 | 12)));
				cout << "���� ����! ���������� ����������!" << endl;
				system("pause");
			}
			break;
		case 9:
		{
			if (st.empty()){
				st.sort();
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4 | 5)));
				cout << "--------------------------------------------------------------------------------------------------------------------\n";
				st.show();
				cout << "--------------------------------------------------------------------------------------------------------------------\n\t";
				system("pause");
			}
			else{
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4 | 12)));
				cout << "���� ����! ���������� ����������!" << endl;
				system("pause");
			}
		}
		}
	} while (ch != 0);
	ofstream fout(namefile, ios::out);
	fout.close();
	st.WriteFile(namefile);
}