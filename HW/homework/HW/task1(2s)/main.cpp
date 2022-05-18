#include<iostream>
#include<math.h>
#include <D:\ucheba\informatikaiprogramirovanie\info\Informatics-and-Programming\HW\homework\HW\task1(2s)\Source.h>
//#include<stdio>
//#include<conio>
//#include <string>

using namespace std;

int main()
{
	char str[80];
	int a;

	cout << "Enter Money if format: (Rub.Coin)";
	cin >> str;

	while (true)
	{
		cout << "Enter operation: " << endl << "1) 1 - minus" << endl << "2) 2 - plus" << endl << "3) 3 - multiplication by procent" << endl << "4) 4 - Convertation to $" << endl << "5) 5 - exit" << endl;
		cin >> a;
		if (a == 5)
			break;
		if (a == 2)
		{
			Money ob(str);
			cout << "Enter Money in format: (Rub.Coin)";
			cin >> str;
			Money ob2(str);
			ob += ob2;
			ob.EditMoney();
			ob.ShowMoney();
		}
		if (a == 1)
		{
			Money ob(str);
			cout << "Enter Money in format: (Rub.Coin)";
			cin >> str;
			Money ob1(str);
			ob -= ob1;
			ob.EditMoney();
			ob.ShowMoney();
		}
		if (a == 3)
		{
			cout << "Enter Money in format: (Rub.Coin)";
			cin >> str;
			Money ob3(str);
			ob3.EditMoney();
			ob3.MoneyProcent(ob3);
			ob3.ShowMoney();
		}
		if (a == 4)
		{
			Money ob(str);
			cout << "Enter Money in format: (Rub.Coin)";
			cin >> str;
			Money ob4(str);
			ob.EditMoney();
			ob.ConvMoney(ob4);
			ob.ShowMoney();
		}
	}

	system("Pause");
}