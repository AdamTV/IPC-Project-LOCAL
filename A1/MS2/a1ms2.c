//ISBN to EAN (practice)
//Adam Stinziani
//2018-11-04

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char EAN[14];
char ISBN[11];

char convert(char ISBN);

int main(void) {

	printf("Enter ISBN: ");
	scanf(" %11s", ISBN);
	ISBN = convert(ISBN);
	printf("EAN = %s", EAN);

	return 0;
}

char convert(char ISBN); {
	EAN = { 9, 7, 8, 0 }
	int i;
	for (i = 4; i < 12; i++)
		EAN[i] = ISBN[i - 4];
	return EAN;
}
