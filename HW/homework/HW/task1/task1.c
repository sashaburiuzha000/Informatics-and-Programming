#include <stdio.h>

int main()
{
    int i, n, * mas;
    int k = 0;
    setlocale(0, "rus");
    printf("¬ведите размер массива: ");
    scanf_s("%d", &n);
    srand(time(0));
    mas = malloc(n * sizeof(int));
    printf("—генерированный массив:\n");
    for (i = 0; i < n; i++) {
        mas[i] = rand() % 100; // диапазон случайных чисед от 0 до 100
        printf("%d ", mas[i]);
    }
    for (i = 1; i < n; i++) {
        if (mas[i] > mas[i - 1] && )
            k++;
    }
    printf("%d ", &k);
    putchar('\n');
    free(mas);
    system("pause");
    return 0;
}