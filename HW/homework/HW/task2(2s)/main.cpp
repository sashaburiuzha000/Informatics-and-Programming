#include<iostream>
#include<math.h>
#include<string>
#include<vector>

#include<D:\ucheba\informatikaiprogramirovanie\info\Informatics-and-Programming\HW\homework\HW\task2(2s)\Source.h>


int main() {

	setlocale(LC_ALL, "Russian");

	int begin, end;
	int num;
	int scal;

	std::cout << "������� ������ �������: ";
	std::cin >> begin;

	std::cout << "������� ����� �������: ";
	std::cin >> end;

	Vector vector_1(begin, end);

	vector_1.ShowVector();

	while (true) {

		std::cout << std::endl << "������� �����: " << std::endl << "1 - ����� ��������" << std::endl << "2 - ��������� ������������ ��������" << std::endl << "3 - ��������� ������� �� ������" << std::endl << "4 - ��������� ����� �������" << std::endl << "5 - ��������� ���������" << std::endl;
		std::cout << "����� = ";

		std::cin >> num;

		if (num == 5)
			break;

		switch (num)
		{
		case 1:
		{
			std::cout << "������� ������ �������: ";
			std::cin >> begin;

			std::cout << "������� ����� �������: ";
			std::cin >> end;

			Vector vector_2(begin, end);

			vector_2.ShowVector();

			vector_1 = vector_1 + vector_2;

			vector_1.ShowVector();
			break;
		}
		case 2:
		{
			std::cout << "������� ������ �������: ";
			std::cin >> begin;

			std::cout << "������� ����� �������: ";
			std::cin >> end;

			Vector vector_2(begin, end);

			vector_1 = vector_1 * vector_2;

			vector_1.ShowVector();
			break;
		}
		case 3:
		{

			std::cout << "������� ������: ";
			std::cin >> scal;

			vector_1 = vector_1 * scal;

			vector_1.ShowVector();
			break;
		}
		case 4:
		{


			std::cout << "����� ������� = ";
			vector_1.ShowSize();
			break;
		}

		}
	}


	return 0;
}