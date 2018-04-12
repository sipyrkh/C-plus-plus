#include <iostream>
#include <string>
using namespace std;
class Login
{
protected:
	string username, password;
public:
	Login(string username_in = " ", string password_in = " ")
	{
		username = username_in;
		password = password_in;
		//cout << "Конструктор Login"<<endl;
	}
	~Login()
	{
		//cout << "Деструктор Login"<<endl;
	}
	void set_username(string);
	void set_password(string);
	bool login_menu();
	void registration();
	bool enter();
	friend istream& operator>>(istream&in, Login&ob);
	friend ostream& operator<<(ostream&out, Login&ob);
	friend ifstream& operator>>(ifstream&fin, Login&ob);
	friend ofstream& operator<<(ofstream&fout, Login&ob);
};