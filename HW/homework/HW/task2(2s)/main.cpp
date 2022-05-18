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

	std::cout << "¬ведите начало вектора: ";
	std::cin >> begin;

	std::cout << "¬ведите конец вектора: ";
	std::cin >> end;

	Vector vector_1(begin, end);

	vector_1.ShowVector();

	while (true) {

		std::cout << std::endl << "¬ведите число: " << std::endl << "1 - —умма векторов" << std::endl << "2 - —кал€рное произведение векторов" << std::endl << "3 - ”множение скал€ра на вектор" << std::endl << "4 - ¬ычислить длину вектора" << std::endl << "5 - «акончить программу" << std::endl;
		std::cout << "„исло = ";

		std::cin >> num;

		if (num == 5)
			break;

		switch (num)
		{
		case 1:
		{
			std::cout << "¬ведите начало вектора: ";
			std::cin >> begin;

			std::cout << "¬ведите конец вектора: ";
			std::cin >> end;

			Vector vector_2(begin, end);

			vector_2.ShowVector();

			vector_1 = vector_1 + vector_2;

			vector_1.ShowVector();
			break;
		}
		case 2:
		{
			std::cout << "¬ведите начало вектора: ";
			std::cin >> begin;

			std::cout << "¬ведите конец вектора: ";
			std::cin >> end;

			Vector vector_2(begin, end);

			vector_1 = vector_1 * vector_2;

			vector_1.ShowVector();
			break;
		}
		case 3:
		{

			std::cout << "¬ведите скал€р: ";
			std::cin >> scal;

			vector_1 = vector_1 * scal;

			vector_1.ShowVector();
			break;
		}
		case 4:
		{


			std::cout << "ƒлина вектора = ";
			vector_1.ShowSize();
			break;
		}

		}
	}


	return 0;
}