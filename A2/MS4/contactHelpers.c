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

#include <string.h>

#include "contactHelpers.h"

#define MAXCONTACTS 5

// clearKeyboard:
void clearKeyboard(void)
{
	while (getchar() != '\n')	; // empty execution code block on purpose
}

// pause:
void pause(void)
{
	printf("(Press Enter to Continue)");
	clearKeyboard();
}

// getInt:
int getInt(void)
{
	char NL = 'x';
	int Value;

	while (NL != '\n')
	{
		scanf("%d%c", &Value, &NL);
		if (NL != '\n')
		{
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
			clearKeyboard();
		}
	}
	return Value;
}

// getIntInRange:
int getIntInRange(int min, int max)
{
	int Value;

	Value = getInt();

	while (Value < min || Value > max)
	{
		printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
		Value = getInt();
	}
	return Value;
}

// yes:
int yes(void)
{
	char Value = 0;
	char NL = 'x';

	do
	{
		scanf("%c%c", &Value, &NL);
		if ((Value != 'Y' && Value != 'y' && Value != 'N' && Value != 'n') || NL != 10)
		{
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		}
	} while ((Value != 'Y' && Value != 'y' && Value != 'N' && Value != 'n') || NL != 10);
	if (Value == 'Y' || Value == 'y')
		return 1;
	else
		return 0;
}

// menu:
int menu(void)
{
	int Value;

	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n\n");
	printf("Select an option:> ");

	Value = getIntInRange(0, 6);

	return Value;
}

// contactManagerSystem:
void contactManagerSystem(void)
{
	struct Contact contact[MAXCONTACTS] = 
	{ { { "Rick", {'\0'}, "Grimes" },
{ 11, "Trailer Park", 0, "A7A 2J2", "King City" },
{ "4161112222", "4162223333", "4163334444" } },
{
{ "Maggie", "R.", "Greene" },
{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
{ "9051112222", "9052223333", "9053334444" } },
{
{ "Morgan", "A.", "Jones" },
{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
{ "7051112222", "7052223333", "7053334444" } },
{
{ "Sasha", {'\0'}, "Williams" },
{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
{ "9052223333", "9052223333", "9054445555" } },
	};
	int Menu = 0, Return = 0;

	do
	{
		Menu = menu();

		switch (Menu) {
		case 1:
			printf("\n");
			displayContacts(contact, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 2:
			printf("\n");
			addContact(contact, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 3:
			printf("\n");
			updateContact(contact, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 4:
			printf("\n");
			deleteContact(contact, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 5:
			printf("\n");
			searchContacts(contact, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 6:
			printf("\n");
			sortContacts(contact, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		default:
			printf("\nExit the program? (Y)es/(N)o: ");
			Return = yes();
			printf("\n");
			if (Return == 1)
				printf("Contact Management System: terminated\n");
		}
	} while (Return != 1);
}

//A2MS3
// Generic function to get a ten-digit phone number (ensures 10-digit chars entered)
void getTenDigitPhone(char telNum[])
{
	int i, needInput = 1, count, length;

	while (needInput == 1)
	{
		scanf("%s", telNum);
		clearKeyboard();
		length = strlen(telNum);
		count = 0;
		for (i = 0; i < length && count == 0; i++)
		{
			if (telNum[i] < '0' || telNum[i] > '9')
				count++;
		}
		if (length == 10 && count == 0)
			needInput = 0;
		else
			printf("Enter a 10-digit phone number: ");
	}
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
	int i, Return;

	for (i = 0; i < size; i++)
	{
		Return = strcmp(contacts[i].numbers.cell, cellNum);
		if (Return == 0)
			return i;
	}
	return -1;
}

// displayContactHeader
void displayContactHeader(void)
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");
}

// displayContactFooter
void displayContactFooter(int contacts)
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d\n\n", contacts);
}

// displayContact:
void displayContact(const struct Contact* contact)
{
	printf("%s", contact->name.firstName);
	if (contact->name.middleInitial[0] != '\0')
		printf(" %s %s\n", contact->name.middleInitial, contact->name.lastName);
	else printf(" %s\n", contact->name.lastName);
	printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);
	printf("       %d %s, ", contact->address.streetNumber, contact->address.street);
	if (contact->address.apartmentNumber > 0)
		printf("Apt# %d, ", contact->address.apartmentNumber);
	printf("%s, %s\n" , contact->address.city, contact->address.postalCode);
}

// displayContacts:
void displayContacts(const struct Contact contact[], int size)
{
	int i, count = 0, valid;

	displayContactHeader();
	for (i = 0; i < size; i++)
	{
		if ((valid = strlen(contact[i].numbers.cell)) > 0)
		{
			displayContact(&contact[i]);
			count++;
		}
	}
	displayContactFooter(count);
}

// searchContacts:
void searchContacts(const struct Contact contact[], int size)
{
	int Return;
	char search[11];

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(search);
	Return = findContactIndex(contact, size, search);
	if (Return != -1)
	{
		displayContact(&contact[Return]);
		printf("\n");
	}
	else 
	{
		printf("*** Contact NOT FOUND ***\n\n");
	}
}

// addContact:
void addContact(struct Contact contact[], int size)
{
	int i, valid, done = 0;
	for (i = 0; i < size && done == 0; i++)
	{
		valid = strlen(contact[i].numbers.cell);
		if (valid == 0)
		{
			getContact(&contact[i]);
			done = 1;
			printf("--- New contact added! ---\n\n");
		}
	}
	if (done == 0)
	printf("*** ERROR: The contact list is full! ***\n\n");
}

// updateContact:
void updateContact(struct Contact contact[], int size)
{
	int Return, Yes;
	char num[11];

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(num);
	Return = findContactIndex(contact, size, num);
	if (Return == -1)
	{
		printf("*** Contact NOT FOUND ***\n\n");
	}
	else
	{
		printf("\nContact found:\n");
		displayContact(&contact[Return]);
		printf("\nDo you want to update the name? (y or n): ");
		Yes = yes();
		if (Yes == 1)
		{
			*contact[Return].name.firstName = '\0';
			*contact[Return].name.middleInitial = '\0';
			*contact[Return].name.lastName = '\0';
			getName(&contact[Return].name);
		}
		printf("Do you want to update the address? (y or n): ");
		Yes = yes();
		if (Yes == 1)
		{
			contact[Return].address.apartmentNumber = 0;
			*contact[Return].address.city = '\0';
			*contact[Return].address.postalCode = '\0';
			*contact[Return].address.street = '\0';
			contact[Return].address.streetNumber = 0;
			getAddress(&contact[Return].address);
		}
		printf("Do you want to update the numbers? (y or n): ");
		Yes = yes();
		if (Yes == 1)
		{
			*contact[Return].numbers.cell = '\0';
			*contact[Return].numbers.business = '\0';
			*contact[Return].numbers.home = '\0';
			getNumbers(&contact[Return].numbers);
		}
		printf("--- Contact Updated! ---\n\n");
	}
}

// deleteContact:
void deleteContact(struct Contact contact[], int size)
{
	int Return, Yes;
	char num[11];

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(num);
	Return = findContactIndex(contact, size, num);
	if (Return == -1)
	{
		printf("*** Contact NOT FOUND ***\n");
	}
	else
	{
		printf("\nContact found:\n");
		displayContact(&contact[Return]);
		printf("\n");
		printf("CONFIRM: Delete this contact? (y or n): ");
		Yes = yes();
		if (Yes == 1)
		{
			*contact[Return].name.firstName = '\0';
			*contact[Return].name.middleInitial = '\0';
			*contact[Return].name.lastName = '\0';
			contact[Return].address.streetNumber = '\0';
			*contact[Return].address.street = '\0';
			*contact[Return].address.postalCode = '\0';
			*contact[Return].address.city = '\0';	
			contact[Return].address.apartmentNumber = '\0';
			*contact[Return].numbers.business = '\0';
			*contact[Return].numbers.home = '\0';
			*contact[Return].numbers.cell = '\0';
			printf("--- Contact deleted! ---\n\n");
		} else
		{
			printf("\n");		
		}
	}
}

// sortContacts:
void sortContacts(struct Contact contact[], int size)
{
	int i, j, m;
	struct Contact temp;

	for (i = 0; i < size; i++)
	{
		m = i;
		for (j = i + 1; j < size; j++)
			if ((strcmp(contact[j].numbers.cell, contact[m].numbers.cell)) < 0)
			{
				m = j;
			}
		if (m != i)
		{
				temp = contact[i];
				contact[i] = contact[m];
				contact[m] = temp;
		}
	}
	printf("---Contacts sorted! ---\n\n");
}
