#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 10

int main() {
	int array[SIZE];
	int count = 0;
	int newArray[SIZE];

	for (int i = 0; i < SIZE; i++) {
		array[i] = -5 + rand() % (15 + 1);
	}

	for (int i = 0; i < SIZE; i++) {
		printf("nachal_massiv[%d] = %d\n", i, array[i]);
	}

	for (int i = 1; i < SIZE - 1; i++) {
		if ((array[i] > array[i - 1]) && (array[i] > array[i + 1])) {
			newArray[count] = array[i];
			count++;
		}
	}

	printf("Local Mamximum = \n");
	for (int i = 0; i < count; i++) {
		printf("massiv_max[%d] = %d\n", i + 1, newArray[i]);
	}
	return 0;
}




