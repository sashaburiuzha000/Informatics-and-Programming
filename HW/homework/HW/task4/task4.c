#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#ifndef __cplusplus
#define bool int
#define true 1
#define false 0
#endif
#define SIZE 10
#define BN 5
#define PN 20
#define MCT 100
#define SCT 1 
#define ST 2
#define ATK 3 
#define CK 4 
#define CCT -1 
#define EP 5 
#define SAP 0
#define SM 6

char producti[SIZE][PN];
char cod[SIZE][BN];
float cena[SIZE];
float skidka[SIZE];
int lp = -1,cc=0;
int pch[MCT][2];
float cost;

int user_choice() {
	int s = 0;
	while (true) {
		printf("vvedi nomer ");
		scanf_s("%d", &s);
		if ((s >= SAP) && (s <= SM))
			break;
	}
	return s;
}

void define_product() {

	strcpy_s(producti[0], 20, "cigaretes");
	strcpy_s(producti[1], 20, "coal");
	strcpy_s(producti[2], 20, "rope");
	strcpy_s(producti[3], 20, "meat");
	strcpy_s(producti[4], 20, "gps");
	strcpy_s(producti[5], 20, "oil");
	strcpy_s(producti[6], 20, "phone");
	strcpy_s(producti[7], 20, "coca-cola");
	strcpy_s(producti[8], 20, "coockie");

	strcpy_s(cod[0], 5, "0001");
	strcpy_s(cod[1], 5, "0002");
	strcpy_s(cod[2], 5, "0003");
	strcpy_s(cod[3], 5, "0004");
	strcpy_s(cod[4], 5, "0005");
	strcpy_s(cod[5], 5, "0006");
	strcpy_s(cod[6], 5, "0007");
	strcpy_s(cod[7], 5, "0008");
	strcpy_s(cod[8], 5, "0009");

	cena[0] = 100.0;
	cena[1] = 150.0;
	cena[2] = 109.0;
	cena[3] = 200.0;
	cena[4] = 179.0;
	cena[5] = 1800.0;
	cena[6] = 500.0;
	cena[7] = 350.0;
	cena[8] = 300.0;

	skidka[0] = 0;
	skidka[1] = 0;
	skidka[2] = 0;
	skidka[3] = 10.0;
	skidka[4] = 5.0;
	skidka[5] = 25.0;
	skidka[6] = 10.0;
	skidka[7] = 40.0;
	skidka[8] = 0.0;

}

show_product() {
	printf("-------------------------------------------------------------------\n");
	printf("Product \t cena \t skidka\t code\n");
	for (int i = 0; i < SIZE; i++) {
		printf("%-20s \t %.1f \t\t %.1f \t\t %s\n", producti[i], cena[i], skidka[i], cod[i]);
	}
	printf("-------------------------------------------------------------------\n");
}

bool find_product(char* code, int* pi) {
	for (int i = 0; i < SIZE; i++) {
		if (strcmp(code, cod[i]) == 0) {
			*pi = i;
			return true;
		}
	}
	return false;
}

int scan_product() {
	printf("vvedite cod producta\n");
	char bcode[BN];
	int i;

	scanf_s("%s", &bcode, BN);

	if (find_product(bcode, &i))
		lp= i;
	else
		printf("ne nashel cod");

}

int show_producti() {
	if (lp > -1) {
		printf("Product \t cena \t skidka\t cod\n");
		printf("%-20s \t %.1f \t\t %.1f \t\t %s\n", producti[lp], cena[lp], skidka[lp], cod[lp]);
	}
}

int add_to_check() {
	if ((cc >= MCT) || (lp < 0))
		return;

	if ((cc > 0) && (pch[cc - 1][0] == lp)) {
		pch[cc - 1][1]++;
		printf("obnovit chek %d\n", pch[cc - 1][1]);
	}
	else
	{
		cc++;
		pch[cc - 1][1] = 1;
		pch[cc - 1][0] = lp;
		printf("dobavit chek %d, check kolvo: %d\n", pch[cc - 1][1], cc);
	}
}

int create_check() {
	float sum = 0;
	printf("Product \t cena \t skidka\t cod\n");
	for (int i = 0; i < cc; i++) {
		printf("x* %d %-20s \t %.1f \t\t %.1f \t\t %s\n", pch[i][1], producti[pch[i][0]], cena[pch[i][0]], skidka[pch[i][0]], cod[pch[i][0]]);
	}
	sum = calculate_cost();
	printf("vsya cena is: %.1f\n", sum);
}

int calculate_cost() {
	if (cc == 0)
		return "net producta v cheke";
	for (int i = 0; i < cc; i++) {
		if (skidka[pch[i][0]] > 0) {
			cost = pch[i][1] * (cena[pch[i][0]] / 100 * (100 - skidka[pch[i][0]])) + cost;
		}
		else
			cost = pch[i][1] * cena[pch[i][0]] + cost;
	}
	return cost;
}

int exit_programm() {
	printf("vihod iz programmi\n");
}
show_menu() {
	printf("\ \n 0 - pokazat producti\n 1 - scan product\n 2 - pokazatproduct\n 3 - dobavit product v chek\n 4 - sdelat chek\n 5 - vihod iz programmi\n 6 - pokazat menu\n");
}

int main() {
	define_product();
	printf("\n 0 - show all producti\n 1 - scan current product\n 2 - show current product\n 3 - add product to check\n 4 - create check\n 5 - Exit programm\n 6 - Show menu\n");
	while (true) {
		switch (user_choice())
		{
		case SCT:
			scan_product();
			break;
		case ST:
			show_product();
			break;
		case ATK:
			add_to_check();
			break;
		case CK:
			create_check();
			break;
		case CCT:
			calculate_cost();
			break;
		case EP:
			exit_programm();
			break;
		case SAP:
			show_product();
			break;
		case SM:
			show_menu();
			break;
		}
	}
}