#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include<locale.h>
#ifndef __cplusplus
#define bool int
#define true 1
#define false 0
#endif

int *user_n, *pc_n, num;

int num_generate(int n) {

  setlocale(LC_ALL, "russian");
  int num = 0, i = 0;
  int numbers[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	srand(time(0));

	while (n > 0) {

		i = rand() % 10 + 1;
		while ((numbers[i] < 0) && (i < 10)) 
			i++;
		while ((numbers[i] < 0) && (i > -1))
			i--;
		num = num * 10 + numbers[i];
		numbers[i] = -1;
		n--;
	}

	return num;
}

void c_and_b(int *pc_num, int *user_num, int n, int *c_count, int *b_count) {

	*c_count = *b_count = 0;

	for (int i = 0; i < n; i++) {

		if ((pc_n[i] == user_n[i]) && (user_n[i] > -1)) {
			*b_count += 1;
			user_n[i] = -1;
		}

	}

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {

			if ((pc_n[i] == user_n[j]) && (user_n[j] > -1)) {

				*c_count += 1;
				user_n[j] = -1;
			}
		}
	}
}



int main() {

	int n, user_num, c = 0, b = 0;

	while (true) {

		printf("введите ноемер (от 2 до 5): \n");
		scanf_s("%d", &n);

		if ((n >= 2) && (n <= 5))
			break;
		else
			printf("неправильный диапозон\n");
	}

	user_n = (int)malloc(n * sizeof(int));
	pc_n = (int)malloc(n * sizeof(int));
	num = num_generate(n);

	int i = 0;

	while (num != 0) {

		pc_n[i] = num % 10;
        num /= 10;
		i++;
	}


	while (true) {

		printf("введите число без повторений: ");
		scanf_s("%d", &user_num);

		i = 0;

		while (user_num != 0) {

			user_n[i] = user_num % 10;
			user_num /= 10;
			i++;
		}
        
		c_and_b(pc_n, user_n, n, &c, &b);

		if (b == n) {

			printf("вы угадали число!");
			break;
		}
		else
			printf("кол-во коров = %d\n кол-во быков = %d\n", c, b);
	}

	return 0;
}