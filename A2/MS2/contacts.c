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

#include "contactHelpers.h"

char reply;
int Return;

// getName:
void getName(struct Name * name)
{
	clearKeyboard();
	printf("Please enter the contact's first name: ");
	scanf("%30[^\n]", name->firstName);
	clearKeyboard();
	printf("Do you want to enter a middle initial(s)? (y or n): ");
	Return = yes();

	if (Return == 1)
	{
		printf("Please enter the contact's middle initial(s): ");
		scanf("%[^\n]", name->middleInitial);
	}
	printf("Please enter the contact's last name: ");
	clearKeyboard();
	scanf("%35[^\n]", name->lastName);
}

// getAddress:
void getAddress(struct Address * address)
{
	printf("Please enter the contact's street number: ");
	address->streetNumber = getInt();
	printf("Please enter the contact's street name: ");
	scanf("%40[^\n]", address->street);
	printf("Do you want to enter an apartment number? (y or n): ");
	clearKeyboard();
	Return = yes();
	if (Return == 1)
	{
		printf("Please enter the contact's apartment number: ");
		address->apartmentNumber = getInt();
	}
	printf("Please enter the contact's postal code: ");
	scanf("%7[^\n]", address->postalCode);
	printf("Please enter the contact's city: ");
	clearKeyboard();
	scanf("%40[^\n]", address->city);
}

// getNumbers:
void getNumbers(struct Numbers * numbers)
{
		printf("Please enter the contact's cell phone number: ");
		scanf("%10s", numbers->cell);
	printf("Do you want to enter a home phone number? (y or n): ");
	clearKeyboard();
	Return = yes();
	if (Return == 1)
	{
		printf("Please enter the contact's home phone number: ");
		scanf("%10s", numbers->home);
	}
	printf("Do you want to enter a business phone number? (y or n): ");
	clearKeyboard();
	Return = yes();
	if (Return == 1)
	{
		printf("Please enter the contact's business phone number: ");
		scanf("%10s", numbers->business);
	}
}

// +-------------------------------------------+
// | ====== Assignment 2 | Milestone 1 ======= |
// +-------------------------------------------+

// getContact:
// Define Empty function definition below:
void getContact(struct Contact * contact)
{
	getName(&(*contact).name);
	getAddress(&contact->address);
	getNumbers(&contact->numbers);
}
