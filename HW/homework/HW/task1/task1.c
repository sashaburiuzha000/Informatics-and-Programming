#include <stdio.h>

int main()
{
    int i, n, * mas;
    int k = 0;
    setlocale(0, "rus");
    printf("������� ������ �������: ");
    scanf_s("%d", &n);
    srand(time(0));
    mas = malloc(n * sizeof(int));
    printf("��������������� ������:\n");
    for (i = 0; i < n; i++) {
        mas[i] = rand() % 100; // �������� ��������� ����� �� 0 �� 100
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