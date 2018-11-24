/* -------------------------------------------
Name:			 ADAM STINZIANI
Student number:  124521188
Email:			 astinziani@myseneca.ca
Section:		 IPC144SVV
Date:			 2018-11-22
----------------------------------------------
Assignment: 2
Milestone:  4
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
	printf("Please enter the contact's first name: ");
	scanf("%30[^\n]", name->firstName);
	clearKeyboard();
	printf("Do you want to enter a middle initial(s)? (y or n): ");
	Return = yes();
	if (Return == 1)
	{
		printf("Please enter the contact's middle initial(s): ");
		scanf("%6[^\n]", name->middleInitial);
		clearKeyboard();
	}
	printf("Please enter the contact's last name: ");
	scanf("%35[^\n]", name->lastName);
	clearKeyboard();
}

// getAddress:
void getAddress(struct Address * address)
{
	printf("Please enter the contact's street number: ");
	while ((address->streetNumber = getInt()) < 0)
	{
		clearKeyboard();
		printf("Please enter the contact's street number: ");
	}
	printf("Please enter the contact's street name: ");
	scanf("%40[^\n]", address->street);
	clearKeyboard();
	printf("Do you want to enter an apartment number? (y or n): ");
	Return = yes();
	if (Return == 1)
	{
		printf("Please enter the contact's apartment number: ");
		while ((address->apartmentNumber = getInt()) < 0)
		{
			printf("Please enter the contact's apartment number: ");
		}
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
	getTenDigitPhone(numbers->cell);
	printf("Do you want to enter a home phone number? (y or n): ");
	Return = yes();
	if (Return == 1)
	{
		printf("Please enter the contact's home phone number: ");
		getTenDigitPhone(numbers->home);
	}
	printf("Do you want to enter a business phone number? (y or n): ");
	Return = yes();
	if (Return == 1)
	{
		printf("Please enter the contact's business phone number: ");
		getTenDigitPhone(numbers->business);
	}
}

// getContact:
void getContact(struct Contact * contact)
{
	getName(&(*contact).name);
	getAddress(&contact->address);
	getNumbers(&contact->numbers);
}