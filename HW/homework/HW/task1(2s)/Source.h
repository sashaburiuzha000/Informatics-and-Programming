using namespace std;

#include<iostream>
#include<math.h>

#define RUB 100

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
		cout << rub << "." << coin << endl;
	}

	void EditMoney()
	{
		this->rub = (this->rub + this->coin / RUB);
		this->coin %= RUB;
	}

	Money& operator += (const Money& money)
	{
		rub += money.rub;
		coin += money.coin;

		return *this;
	}

	void ConvMoney(const Money& money)
	{
		int randPr = 0, flag;
		randPr = 85;


		flag = rub;
		rub = this->rub / randPr;
		coin = (flag % randPr * RUB + money.coin) * RUB / (randPr * RUB);

	}

	Money& operator -= (const Money& money)
	{
		if ((rub - money.rub) < 0)
			rub = 0;
		else
			rub = rub - money.rub;
		if ((coin - money.coin) < 0)
		{
			rub = rub - (money.coin / RUB);
			coin = money.coin % RUB;
		}

		return *this;
	}

	void MoneyProcent(const Money& money)
	{
		float randPr = 0;
		randPr = rand() % 90 + 70;

		float AllCoin = 0;

		AllCoin = (money.rub * RUB + money.coin) * (randPr / RUB);

		this->rub = (int)AllCoin / RUB;
		this->coin = (int)AllCoin % RUB;
	}

};