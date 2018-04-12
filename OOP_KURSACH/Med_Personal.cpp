#include "Med_Personal.h"

string Med_Personal::get_time()
{
	return this->time;
}
void Med_Personal::set_time(string time)
{
	this->time = time;
}
void Med_Personal::show()
{
	People::show();
	cout << setw(20) << this->time;
}
void Med_Personal::shapka()
{
	People::shapka();
	cout << setw(20) << "Время приёма";
}