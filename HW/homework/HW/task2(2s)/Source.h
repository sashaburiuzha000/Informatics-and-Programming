#include<vector>

class Vector
{
private:
	std::vector <int> main_vector;
	bool isEnd;
	int x, y;
	int size;

public:
	Vector() {
		main_vector.reserve(0);
		isEnd = true;
		x = 0;
		y = 0;
		size = 0;
	};

	Vector(std::vector <int> _main_vector, bool _isEnd, int _x, int _y, int _size) {
		isEnd = _isEnd;
		x = _x;
		y = _y;
		main_vector = _main_vector;
		size = _size;
	};

	Vector(const Vector& vect) {
		isEnd = vect.isEnd;
		x = vect.x;
		y = vect.y;
		main_vector = vect.main_vector;
		size = vect.size;
	};
public:
	Vector(int _begin, int _end) {

		int size;

		x = _begin;
		y = _end;

		size = abs(x - y);

		this->main_vector.resize(size);

		if (x > y) {

			for (int i = 0; i < main_vector.size(); i++) {
				this->main_vector[i] = y + i;
			}
		}
		if (y > x) {
			for (int i = 0; i < main_vector.size(); i++) {
				this->main_vector[i] = x + i;
			}
		}
	};

public:
	void ShowVector() {

		std::cout << "Твой вектор: ";

		for (int i = 0; i < main_vector.size(); i++) {
			std::cout << main_vector[i] << " ";
		}

		std::cout << std::endl;

	};

	void ShowSize() {
		size = main_vector.size();
		std::cout << size;
	}

	Vector operator=(const Vector& vect) {

		if (this == &vect)
			return *this;

		main_vector = vect.main_vector;
		return *this;
	};

	Vector operator+(const Vector& right) {

		if (main_vector.size() <= right.main_vector.size()) {

			for (int i = 0; i < main_vector.size(); i++) {
				main_vector[i] = main_vector[i] + right.main_vector[i];
			}

			return *this;
		}

		if (main_vector.size() >= right.main_vector.size()) {

			for (int i = 0; i < right.main_vector.size(); i++) {
				main_vector[i] = main_vector[i] + right.main_vector[i];
			}

			return *this;
		}

	}

	Vector operator*(const Vector& right) {

		if (main_vector.size() <= right.main_vector.size()) {

			for (int i = 0; i < main_vector.size(); i++) {
				main_vector[i] = main_vector[i] * right.main_vector[i];
			}
			return *this;
		}


		if (main_vector.size() >= right.main_vector.size()) {

			for (int i = 0; i < right.main_vector.size(); i++) {
				main_vector[i] = main_vector[i] * right.main_vector[i];
			}
			return *this;
		}

	}

	Vector operator*(const int val) {
		for (int i = 0; i < main_vector.size(); i++) {
			main_vector[i] = main_vector[i] * val;
		}

		return *this;
	}

};
