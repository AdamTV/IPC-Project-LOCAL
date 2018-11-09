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

char reply;

// Get and store from standard input the values for Name
// Put your code here that defines the Contact getName function:
void getName(struct Name * name) {
	printf("Please enter the contact's first name: ");
	scanf("%30[^\n]", name->firstName);
	printf("Do you want to enter a middle initial(s)? (y or n): ");
	clear();
	scanf("%c", &reply);
	if (reply == 'y' || reply == 'Y') {
		printf("Please enter the contact's middle initial(s): ");
		clear();
		scanf("%6[^\n]", name->middleInitial);
	}
	printf("Please enter the contact's last name: ");
	clear();
	scanf("%35[^\n]", name->lastName);
}

// Get and store from standard input the values for Address
// Put your code here that defines the Contact getAddress function:
void getAddress(struct Address * address) {
	printf("Please enter the contact's street number: ");
	scanf("%u", &address->streetNum);
	printf("Please enter the contact's street name: ");
	clear();
	scanf("%40[^\n]", address->street);
	printf("Do you want to enter an apartment number? (y or n): ");
	clear();
	scanf("%c", &reply);
	if (reply == 'y' || reply == 'Y') {
		printf("Please enter the contact's apartment number: ");
		scanf("%u", &address->aptNum);
	}
	printf("Please enter the contact's postal code: ");
	clear();
	scanf("%7[^\n]", address->postalCode);
	printf("Please enter the contact's city: ");
	clear();
	scanf("%40[^\n]", address->city);
}

// Get and store from standard input the values for Numbers
// Put your code here that defines the Contact getNumbers function:
void getNumbers(struct Numbers * numbers) {
	printf("Do you want to enter a cell phone number? (y or n): ");
	clear();
	scanf("%c", &reply);
	if (reply == 'y' || reply == 'Y') {
		printf("Please enter the contact's cell phone number: ");
		scanf("%10s", numbers->cell);
	}
	printf("Do you want to enter a home phone number? (y or n): ");
	clear();
	scanf("%c", &reply);
	if (reply == 'y' || reply == 'Y') {
		printf("Please enter the contact's home phone number: ");
		scanf("%10s", numbers->home);
	}
	printf("Do you want to enter a business phone number? (y or n): ");
	clear();
	scanf("%c", &reply);
	if (reply == 'y' || reply == 'Y') {
		printf("Please enter the contact's business phone number: ");
		scanf("%10s", numbers->business);
	}
}

// empties the input buffer 
void clear(void)
{
	while (getchar() != '\n')
		;  // empty statement intentional 
}
