#include "Patients.h"

string Patients::get_dignose()
{
	return this->diagnose;
}
void Patients::set_diagnose(string diagnose)
{
	this->diagnose = diagnose;
}
void Patients::show()
{
	People::show();
	cout << setw(20) << this->diagnose;
}
void Patients::shapka()
{
	People::shapka();
	cout << setw(20) << "Дигноз";
}