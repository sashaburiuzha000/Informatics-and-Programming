#include<iostream>
#include<math.h>
//#include<stdio>
//#include<conio>
//#include <string>

using namespace std;

class Money
{
private:
	int rub, coin;

public:
	Money() { rub == coin == 0; }

	Money(const char* str)
	{
		string a;
		int n = 0, ob[2];
		for (int i = 0; i < (strlen(str) + 1); i++)
			if (str[i] != '.' && i != strlen(str))
				a += str[i];
			else
			{
				ob[n] = atoi(a.c_str());

				n++;
				a = "";
			}
		rub = ob[0];
		coin = ob[1];
	}

	void ShowMoney()
	{
		cout  <<rub<< "."<< coin<< endl;
	}

	void EditMoney()
	{
		this->rub = (this->rub + this->coin / 100);
		this->coin %= 100;
	}

	void PlusMoney(const Money& money)
	{
		rub += money.rub;
		coin += money.coin;
	}

	void MinusMoney(const Money& money)
	{
		if ((rub - money.rub) <= 0)
			rub = 0;
		else
			rub = rub - money.rub;

		if ((coin - money.coin) < 0 || (rub - money.rub) <= 0)
			coin = 0;
		else
			coin = coin - money.coin;
	}
};
int main()
{
	char str[80];
	int a;

	cout << "Enter Money if format: (Rub.Coin)";
	cin >> str;

	while (true)
	{
		cout << "Enter operation: "<< endl << "1) 1 - minus" << endl << "2) 2 - plus" << endl << "3) 3 - exit" << endl;
		cin >> a;
		if (a == 3)
			break;
		if (a == 2)
		{
			Money ob(str);
			cout << "Enter Money in format: (Rub.Coin)";
			cin >> str;
			Money ob2(str);
			ob.PlusMoney(ob2);
			ob.EditMoney();
			ob.ShowMoney();
		}
		if (a == 1)
		{
			Money ob(str);
			cout << "Enter Time in format: (Rub.Coin)";
			cin >> str;
			Money ob3(str);
			ob.MinusMoney(ob3);
			ob.EditMoney();
			ob.ShowMoney();
		}
	}

	system("Pause");
}