#include "Stack.h"
#include <string>
#include <fstream>
using namespace std;
template <class T>
Stack <T>::Stack()
{
	head == NULL;
}
template <class T>
Stack <T>::~Stack()
{
	if (head == NULL) return;
	delete head;
}
template <class T>
void Stack <T>::push(T value)
{
	if (head == NULL)
	{
		head = new item <T>;
		head->i = value;
		head->next = NULL;
	}
	else{
		item<T> *newItem = new item < T >;
		newItem->i = value;
		newItem->next = head;
		head = newItem;
	}
}
template <class T>
void Stack <T>::pop()
{
	item <T> *p = head;
	head = head->next;
	delete p;
}
template <class T>
T Stack <T>::pop1()
{
	item <T> *p = head;
	head = head->next;
	T it = p->i;
	delete p;
	return it;
}
template <class T>
void Stack <T>::show()
{
	item <T> *p = head;
	T t;
	int i = 0;
	t.shapka();
	while (p != NULL)
	{
		cout << i + 1 << ")" << p->i;
		p = p->next;
		i++;
	}
}
template <class T>
bool Stack <T>::empty()
{
	if (head == NULL) return false;
	else return true;
}
template <class T>
int Stack <T>::len()
{
	item<T>* tmp = head;
	int count = 0;
	if (!empty()) return count;
	while (tmp)
	{
		tmp = tmp->next;
		count++;
	}
	return count;
}
template <class T>
void Stack<T>::sort()
{
	item<T> *t = head, *tmp = NULL, *prev = NULL;
	bool flag = true;
	do{
		flag = false;
		t = head;
		while (t->next)
		{
			if (t->i > t->next->i)
			{
				if (t == head)
				{
					tmp = t;
					t = tmp->next;
					tmp->next = t->next;
					t->next = tmp;
					head = t;
					flag = true;
				}
				else{
					tmp = t;
					t = tmp->next;
					tmp->next = t->next;
					t->next = tmp;
					prev->next = t;
					flag = true;
				}
			}
			prev = t;
			t = t->next;
		}
	} while (flag);
}
template <class T>
void Stack <T>::SearchByFam(string search_name, string search_fam)
{
	int z = 0;
	item<T>* tmp = head;
	int k = 0;
	T t;
	while (tmp != NULL)
	{
		if ((tmp->i.People::get_name()) == search_name && (tmp->i.People::get_fam()) == search_fam)
		{
			z++;
			if (z == 1){
				cout << endl << "\t\tНайденные записи:" << endl << endl;
				cout << "--------------------------------------------------------------------------------------------------------------------\n";
				t.shapka();
				cout << endl;
			}
			cout << k + 1 << ")" << tmp->i << endl;
			k++;
		}
		tmp = tmp->next;
	}
	if (k == 0) cout << "Нет подходящих записей!" << endl;
	else cout << "--------------------------------------------------------------------------------------------------------------------\n\t";
	system("pause");
}
template <class T>
void Stack <T>::edit(int index)
{
	T obj;
	item<T> *tmp = this->head;
	if (index > this->len() || index < 1)
	{
		cout << "Нет такой записи!" << endl;
		system("pause");
	}
	else{
		cout << "\tИзменение данных" << endl;
		cin >> obj;
		cout << endl << "Готово!" << endl;
		for (int k = 1; k < index; k++)
			tmp = tmp->next;
		tmp->i = obj;
	}
}
template <class T>
void Stack <T>::ReadFile(string namefile)
{
	T tmp;
	ifstream fin(namefile, ios::in);
	while (fin>>tmp)
	{
		this->push(tmp);
	}
	fin.close();
}
template <class T>
void Stack <T>::WriteFile(string namefile)
{
	item<T>* tmp = head;
	ofstream fout(namefile, ios::app);
	while (tmp != NULL)
	{
		fout << tmp->i;
		tmp = tmp -> next;
	}
	fout.close();
}

template <class T>
item<T>* Stack<T>::get()
{
	return this->head;
}
template <class T>
void Stack<T>::pop_index(int k)
{
	item<T> *t = head, *prev = NULL, *del;
	if (k == 1)
	{
		del = t;
		t = t->next;
		head = t;
		delete del;
	}
	else
	{
		if (k == this->len())
		{
			for (int i = 1; i < k; i++)
			{
				prev = t;
				t = t->next;
			}
			del = t;
			prev->next = NULL;
			delete del;
			return;
		}
		else
		{
			for (int i = 1; i < k; i++)
			{
				prev = t;
				t = t->next;
			}
			del = t;
			prev->next = t->next;
			delete del;
			return;
		}
	}
}

