#include <stdio.h>
#include <math.h>
#include <locale.h>
#ifndef __cplusplus
#define bool int
#define true 1
#define false 0
#endif

void guess_number() {
	setlocale(LC_ALL, "russian");

  int nomer, kolvo = 0, random_nomer;
	srand(time(0));
  random_nomer = rand() % 1000 + 1;

	while (true) {

		printf(" ");
		scanf_s("%d", &nomer);

	    kolvo++;

    if (nomer < random_nomer)
	    printf("число больше\n");

	if (nomer > random_nomer)
		printf("число меньше\n");
	if (nomer == random_nomer) {
		printf("Vi ugadali chislo!\n");
		break;
	}
	}
	    printf("skritoe chislo: %d\n", nomer);
	    printf("kolvo popitok: %d\n", kolvo);
}
   void input_number() {

	 int nomer, kolvo = 0, x1 = 0, x2 = 1000, flag = 0, ug_n;
	 char vv;
	    printf("vvedite chislo: ");
	    scanf_s("%d", &nomer);
	 while ((x1 < x2) && (flag == 0)) {

		  ug_n = x1 + ((x2 - x1) / 2);

		  printf("skritoe chislo: %d?\n", ug_n);
		  scanf_s("%c", &vv, 1);

		  vv = getchar();
		  kolvo++;

		  switch (vv)
		  {
		  case '>': x1 = ug_n;
			  break;
		  case '<': x2 = ug_n;
			  break;
		  case '=': printf("PC prav!\n");
			  flag = 1;
			  break;
		  }
	  }
	  printf("skritoe chislo: %d\n", ug_n);
	  printf("kolvo popitok: %d", kolvo);
   }
   int main() {
	   int programa;
	   while (true) {

		   printf("viberi rejim(1 ili 2): ");
		   scanf_s("%d", &programa);

	   if ((programa == 1) || (programa == 2))
			   break;
	   }

	   if (programa == 1)
		   guess_number();
	   if (programa == 2)
		   input_number();

	   return 0;
   }