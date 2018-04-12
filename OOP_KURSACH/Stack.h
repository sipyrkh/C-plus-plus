#pragma once
#include <string>
using namespace std;
template <class T>
struct item
{
	T i;
	item <T> *next;
};
template <class T>
class Stack
{
	item <T> *head;
public:
	Stack();
	~Stack();
	void push(T ob);
	item<T>* get();
	void pop();
	void pop_index(int);
	T pop1();
	void show();
	int len();
	void sort();
	void ReadFile(string);
	void WriteFile(string);
	void edit(int);
	void SearchByFam(string, string);
	bool empty();
};
