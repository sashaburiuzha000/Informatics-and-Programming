#include<stdio.h>
#include<locale.h>
#include<math.h>


int main()
{
	setlocale(LC_ALL, "russian");

	printf("������� ���������� ������ ���������� � � ������:\n");
	int x, y, r;
	scanf_s("%d %d %d", &x, &y, &r);

	printf("������� ���������� ������ ���������� � � ������:\n");
	int x1, y1, r1;
	scanf_s("%d %d %d", &x1, &y1, &r1);

	int d, diff,d2=2;
	diff = pow((x1-x), 2) + pow((y1-y), 2);
	d = sqrt(diff);

	if ((r + r1 > d) && (r + d > r1) && (r1 + d > r))
		printf("���������� ������������");
	else
		if ((r + r1 == d) || (abs(r - r1) == d))
			printf("���������� ��������");
		else
			if (((r1 - r) * d2 > (x1 - x) * d2 + (y1 - y) * d2))
				printf("���� ���������� ��������� � ������");
			else
				if ((d = r - r1) && ((r1 - r) * d2 > (x1 - x) * d2 + (y1 - y) * d2))
					printf("���� ���������� ��������� � ������ � ���������� ��������");
			else
			printf("���������� �� �������");

			return 0;




}