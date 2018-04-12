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
		cout << "\tДобро пожаловать в информационную систему мед. центра!\n";
		SetConsoleTextAttribute(hConsole, (WORD)((0 << 4 | 12)));
		cout << "  С кем вы хотите работать?\n";
		cout << "  1 - Докторами\n";
		cout << "  2 - Медицинскими сёстрами\n";
		cout << "  3 - Пациентами на стационарном лечении\n";
		cout << "  4 - Пациентами на амбулаторном лечении\n";
		cout << "  5 - Выход\n\n";
		cout << "  Ваш выбор: ";
		ch = t.Check_int();
		cout << endl;
		switch (ch)
		{
		case 1:
		{
			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4 | 10)));
			cout << endl << "  Вы выбрали меню с Докторами!" << endl << endl; 
			system("pause");
			Interface <Doctors> obj;
			obj.fun_do("Doctors.txt");
		}
		break;
		case 2:
		{
			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4 | 10)));
			cout << endl << "  Вы выбрали меню с Мед. сёстрами!" << endl << endl; 
			system("pause");
			Interface <Med_Sisters> obj;
			obj.fun_do("Med_Sisters.txt");
		}
		break;
		case 3:
		{
			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4 | 10)));
			cout << endl << "  Вы выбрали меню с пациентами, находящимися на стационарном лечении!" << endl << endl; 
			system("pause");
			Interface <Stationary> obj;
			obj.fun_do("Stationary.txt");
		}
		break;
		case 4:
		{
			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4 | 10)));
			cout << endl <<"  Вы выбрали меню с пациентами, находящимися на амбулаторном лечении!" << endl << endl; system("pause");
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
		cout << "  *************\tМЕНЮ *************" << endl;
		cout << "  1 - Добавить информацию" << endl;
		cout << "  2 - Просмотреть информацию" << endl;
		cout << "  3 - Удалить информацию из вершины" << endl;
		cout << "  4 - Удалить информацию по индексу" << endl;
		cout << "  5 - Удалить всю информацию" << endl;
		cout << "  6 - Поиск по имени и фамилии" << endl;
		cout << "  7 - Редактирование информации(полностью)" << endl;
		cout << "  8 - Редактирование по полям" << endl;
		cout << "  9 - Сортировка информации" << endl;
		cout << "  0 - Вернуться в меню\n";
		cout << "  *********************************" << endl;
		cout << "  ПРЕДУПРЕЖДЕНИЕ: ввод осуществляется только русскими буквами!" << endl << endl;
		cout << "  Ваш выбор: ";
		t = st.get();
		ch = t->i.Check_int(); cout << endl;
		switch (ch)
		{
		case 1:
			cout << "\tВвод данных:" << endl;
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
				cout << "Стек пуст. Просмотр невозможен!" << endl;
			}
			system("pause");
			break;
		case 3:
			if (st.empty()){
				st.pop();
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4 | 10)));
				cout << endl << "\tУдаление прошло успешно." << endl;
				system("pause");
			}
			else{
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4 | 12)));
				cout << "Стек пуст. Удаление невозможно!" << endl;
				system("pause");
			}
			break;
		case 4:
			if (st.empty()){
				cout << "--------------------------------------------------------------------------------------------------------------------\n";
				st.show();
				cout << "--------------------------------------------------------------------------------------------------------------------\n\t";
				int k;
				cout << "Вы хотите удалить запись под номером: "; cin >> k;
				if (k > st.len() || k < 1)
				{
					SetConsoleTextAttribute(hConsole, (WORD)((0 << 4 | 12)));
					cout << "\n\tЗапись с таким номером не найдена!\n\t";
					system("pause");
				}
				else{
					st.pop_index(k);
					SetConsoleTextAttribute(hConsole, (WORD)((0 << 4 | 10)));
					cout << endl << "\tУдаление прошло успешно." << endl;
					system("pause");
				}
			}
			else{
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4 | 12)));
				cout << "Стек пуст. Удаление невозможно!" << endl;
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
				cout << endl << "\tУдаление прошло успешно." << endl;
				system("pause");
			}
			else{
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4 | 12)));
				cout << "Стек пуст. Удаление невозможно!" << endl;
				Sleep(3000);
			}
			break;
		case 6:
		{
			if (st.empty()){
				T ob;
				string search_name, search_fam;
				cout << endl << "----------ПОИСК----------" << endl << endl;
				cout << "Введите фамилию: "; _flushall(); search_fam = ob.People::Check_string();
				cout << "Введите имя: "; _flushall(); search_name = ob.People::Check_string();
				st.SearchByFam(search_name, search_fam);
			}
			else{
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4 | 12)));
				cout << "Стек пуст! Поиск невозможен!" << endl;
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
				cout << "Какую запись хотите отредактировать: "; cin >> key;
				st.edit(key);
			}
			else{
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4 | 12)));
				cout << "Стек пуст! Редактирование невозможно!" << endl;
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
				cout << "Введите номер записи,которую хотите отредактировать: "; oz = ob.People::Check_int();
				t = st.get();
				if (oz > 0 && oz <= st.len())
				{
					for (int i = 0; i < oz-1; i++)
						t = t->next;
					t->i.edit_pole(t->i);
				}
				else{
					cout << "Нет такой записи!" << endl;
					system("pause");
				}
			}
			else{
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4 | 12)));
				cout << "Стек пуст! Сортировка невозможна!" << endl;
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
				cout << "Стек пуст! Сортировка невозможна!" << endl;
				system("pause");
			}
		}
		}
	} while (ch != 0);
	ofstream fout(namefile, ios::out);
	fout.close();
	st.WriteFile(namefile);
}