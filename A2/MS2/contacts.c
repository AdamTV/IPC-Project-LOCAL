/* -------------------------------------------
Name:			 ADAM STINZIANI
Student number:  124521188
Email:			 astinziani@myseneca.ca
Section:		 IPC144SVV
Date:			 2018-11-14
----------------------------------------------
Assignment: 2
Milestone:  2
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "contacts.h"

char reply;

// getName:
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

// getAddress:
void getAddress(struct Address * address) {
	printf("Please enter the contact's street number: ");
	scanf("%u", &address->streetNumber);
	printf("Please enter the contact's street name: ");
	clear();
	scanf("%40[^\n]", address->street);
	printf("Do you want to enter an apartment number? (y or n): ");
	clear();
	scanf("%c", &reply);
	if (reply == 'y' || reply == 'Y') {
		printf("Please enter the contact's apartment number: ");
		scanf("%u", &address->apartmentNumber);
	}
	printf("Please enter the contact's postal code: ");
	clear();
	scanf("%7[^\n]", address->postalCode);
	printf("Please enter the contact's city: ");
	clear();
	scanf("%40[^\n]", address->city);
}

// getNumbers:
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

// +-------------------------------------------+
// | ====== Assignment 2 | Milestone 1 ======= |
// +-------------------------------------------+

// getContact:
// Define Empty function definition below:
void getContact(struct Contact * contact)
{

}
