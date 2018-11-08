/* -------------------------------------------
Name:			ADAM STINZIZNI
Student number:	124521188
Email:			astinziani@myseneca.ca
Section:		IPC144SVV
Date:			2018-11-07
----------------------------------------------
Assignment: 1
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:
#include "contacts.h"

char yn;

// Get and store from standard input the values for Name
// Put your code here that defines the Contact getName function:
void getName(struct Name * name) {
	struct Name Name = { {0} };
	printf("Please enter the contact's first name: ");
	scanf("%30[^\n]", Name.firstName);
	printf("Do you want to enter a middle initial(s)? (y or n): ");
	clear();
	scanf("%c", &yn);
	if (yn == 'y' || yn == 'Y') {
		printf("Please enter the contact's middle initial(s): ");
		clear();
		scanf("%6[^\n]", Name.middleInitial);
	}
	printf("Please enter the contact's last name: ");
	clear();
	scanf("%35[^\n]", Name.lastName);
	*name = Name;
}

// Get and store from standard input the values for Address
// Put your code here that defines the Contact getAddress function:
void getAddress(struct Address * address) {
	struct Address Address = { 0, {0} };
	printf("Please enter the contact's street number: ");
	scanf("%d", &Address.streetNum);
	printf("Please enter the contact's street name: ");
	clear();
	scanf("%40[^\n]", Address.street);
	printf("Do you want to enter an apartment number? (y or n): ");
	clear();
	scanf("%c", &yn);
	if (yn == 'y' || yn == 'Y') {
		printf("Please enter the contact's apartment number: ");
		clear();
		scanf("%d", &Address.aptNum);
	}
	printf("Please enter the contact's postal code: ");
	clear();
	scanf("%7[^\n]", Address.postalCode);
	printf("Please enter the contact's city: ");
	clear();
	scanf("%40[^\n]", Address.city);
	*address = Address;
}

// Get and store from standard input the values for Numbers
// Put your code here that defines the Contact getNumbers function:
void getNumbers(struct Numbers * numbers) {
	struct Numbers Numbers = { {0} };
	printf("Do you want to enter a cell phone number? (y or n): ");
	clear();
	scanf("%c", &yn);
	if (yn == 'y' || yn == 'Y') {
		printf("Please enter the contact's cell phone number: ");
		clear();
		scanf("%10s", Numbers.cell);
	}
	printf("Do you want to enter a home phone number? (y or n): ");
	clear();
	scanf("%c", &yn);
	if (yn == 'y' || yn == 'Y') {
		printf("Please enter the contact's home phone number: ");
		clear();
		scanf("%10s", Numbers.home);
	}
	printf("Do you want to enter a business phone number? (y or n): ");
	clear();
	scanf("%c", &yn);
	if (yn == 'y' || yn == 'Y') {
		printf("Please enter the contact's business phone number: ");
		clear();
		scanf("%10s", Numbers.business);
	}
	*numbers = Numbers;
}

// empties the input buffer 
void clear(void)
{
	while (getchar() != '\n')
		;  // empty statement intentional 
}
