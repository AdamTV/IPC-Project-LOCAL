/* -------------------------------------------
Name:		 ADAM STINZIANI
Student number:	 124521188
Email:		 astinziani@myseneca.ca
Section:	 IPC144SVV
Date:	         2018-10-30
----------------------------------------------
Assignment: 1
Milestone:  2
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:
#include "contacts.h"

int main(void)
{
	// Declare variables here:
	struct Name fullName = { {0} };
	struct Address fullAddress = { 0,{0} };
	struct Numbers fullNumbers = { {0} };
	char yn;

	// Display the title
	printf("Contact Management System\n");
	printf("-------------------------\n");

	// Contact Name Input:
	printf("Please enter the contact's first name: ");
	scanf("%30s", fullName.firstName);
	printf("Do you want to enter a middle initial(s)? (y or n): ");
	scanf("%1s", &yn);
	if (yn == 'n') {
		yn = 'n';
	}
	else {
		printf("Please enter the contact's middle initial(s): ");
		scanf("%6s", fullName.middleInitial);
	}
	printf("Please enter the contact's last name: ");
	scanf("%35s", fullName.lastName);

	// Contact Address Input:
	printf("Please enter the contact's street number: ");
	scanf("%d", &fullAddress.streetNum);
	printf("Please enter the contact's street name: ");
	scanf("%40s", fullAddress.street);
	printf("Do you want to enter an apartment number? (y or n): ");
	scanf("%1s", &yn);

	if (yn == 'n') {
		yn = 'n';
	}
	else {
		printf("Please enter the contact's apartment number: ");
		scanf("%d", &fullAddress.aptNum);
	}

	printf("Please enter the contact's postal code: ");
	scanf("%7s", fullAddress.postalCode);
	printf("Please enter the contact's city: ");
	scanf("%40s", fullAddress.city);

	// Contact Numbers Input:
	printf("Do you want to enter a cell phone number? (y or n): ");
	scanf("%1s", &yn);
	if (yn == 'n') {
		yn = 'n';
	}
	else {
		printf("Please enter the contact's cell phone number: ");
		scanf("%10s", fullNumbers.cell);
	}
	printf("Do you want to enter a home phone number? (y or n): ");
	scanf("%1s", &yn);
	if (yn == 'n') {
		yn = 'n';
	}
	else {
		printf("Please enter the contact's home phone number: ");
		scanf("%10s", fullNumbers.home);
	}
	printf("Do you want to enter a business phone number? (y or n): ");
	scanf("%1s", &yn);
	if (yn == 'n') {
		yn = 'n';
	}
	else {
		printf("Please enter the contact's business phone number: ");
		scanf("%10s", fullNumbers.business);
	}

	// Display Contact Summary Details
	printf("\nContact Details\n---------------\nName Details");
	printf("\nFirst name: %s", fullName.firstName);
	printf("\nMiddle initial(s): %s", fullName.middleInitial);
	printf("\nLast name: %s\n\nAddress Details", fullName.lastName);
	printf("\nStreet number: %i", fullAddress.streetNum);
	printf("\nStreet name: %s", fullAddress.street);
	printf("\nApartment: %i", fullAddress.aptNum);
	printf("\nPostal code: %s", fullAddress.postalCode);
	printf("\nCity: %s\n\nPhone Numbers:", fullAddress.city);
	printf("\nCell phone number: %s", fullNumbers.cell);
	printf("\nHome phone number: %s", fullNumbers.home);
	printf("\nBusiness phone number: %s", fullNumbers.business);

	// Display Completion Message
	printf("\n\nStructure test for Name, Address, and Numbers Done!");

	return 0;
}

/*  SAMPLE OUTPUT:

	Contact Management System
	-------------------------
	Please enter the contact's first name: Tom
	Do you want to enter a middle initial(s)? (y or n): y
	Please enter the contact's middle initial(s): L. A.
	Please enter the contact's last name: Wong Song
	Please enter the contact's street number: 20
	Please enter the contact's street name: Keele Street
	Do you want to enter an apartment number? (y or n): y
	Please enter the contact's apartment number: 40
	Please enter the contact's postal code: A8A 4J4
	Please enter the contact's city: North York
	Do you want to enter a cell phone number? (y or n): Y
	Please enter the contact's cell phone number: 9051116666
	Do you want to enter a home phone number? (y or n): Y
	Please enter the contact's home phone number: 7052227777
	Do you want to enter a business phone number? (y or n): Y
	Please enter the contact's business phone number: 4163338888

	Contact Details
	---------------
	Name Details
	First name: Tom
	Middle initial(s): L. A.
	Last name: Wong Song

	Address Details
	Street number: 20
	Street name: Keele Street
	Apartment: 40
	Postal code: A8A 4J4
	City: North York

	Phone Numbers:
	Cell phone number: 9051116666
	Home phone number: 7052227777
	Business phone number: 4163338888

	Structure test for Name, Address, and Numbers Done!
*/
