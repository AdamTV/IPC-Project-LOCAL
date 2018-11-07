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
void getName(struct Contact *name) {
	printf("Please enter the contact's first name: ");
	scanf(" %31[^\n]", name->name.firstName);
	printf("Do you want to enter a middle initial(s)? (y or n): ");
	scanf(" %c", &yn);
	if (yn == 'y' || yn == 'Y') {
		printf("Please enter the contact's middle initial(s): ");
		scanf(" %7[^\n]", name->name.middleInitial);
	}
	printf("Please enter the contact's last name: ");
	scanf(" %36[^\n]", name->name.lastName);
}

// Get and store from standard input the values for Address
// Put your code here that defines the Contact getAddress function:
void getAddress(struct Contact *address) {
	printf("Please enter the contact's street number: ");
	scanf("%d", &address->address.streetNum);
	printf("Please enter the contact's street name: ");
	scanf(" %41[^\n]", address->address.street);
	printf("Do you want to enter an apartment number? (y or n): ");
	scanf(" %c", &yn);
	if (yn == 'y' || yn == 'Y') {
		printf("Please enter the contact's apartment number: ");
		scanf("%d", &address->address.aptNum);
	}
	printf("Please enter the contact's postal code: ");
	scanf(" %8[^\n]", address->address.postalCode);
	printf("Please enter the contact's city: ");
	scanf(" %41[^\n]", address->address.city);
}

// Get and store from standard input the values for Numbers
// Put your code here that defines the Contact getNumbers function:
void getNumbers(struct Contact * numbers) {
	printf("Do you want to enter a cell phone number? (y or n): ");
	scanf(" %c", &yn);
	if (yn == 'y' || yn == 'Y') {
		printf("Please enter the contact's cell phone number: ");
		scanf("%10s", numbers->numbers.cell);
	}
	printf("Do you want to enter a home phone number? (y or n): ");
	scanf(" %c", &yn);
	if (yn == 'y' || yn == 'Y') {
		printf("Please enter the contact's home phone number: ");
		scanf("%10s", numbers->numbers.home);
	}
	printf("Do you want to enter a business phone number? (y or n): ");
	scanf(" %c", &yn);
	if (yn == 'y' || yn == 'Y') {
		printf("Please enter the contact's business phone number: ");
		scanf("%10s", numbers->numbers.business);
	}
}
