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

#include "contactHelpers.h"

//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// clearKeyboard:
void clearKeyboard(void)
{
	while (getchar() != '\n'); // empty execution code block on purpose
}

// pause:
void pause(void)
{
	printf("(Press Enter to continue)");
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
			clearKeyboard();
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
	int Menu = 0, Return = 0;
	do
	{
		Menu = menu();

		switch (Menu) {
		case 1:
			printf("\n<<< Feature 1 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;
		case 2:
			printf("\n<<< Feature 2 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;
		case 3:
			printf("\n<<< Feature 3 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;
		case 4:
			printf("\n<<< Feature 4 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;
		case 5:
			printf("\n<<< Feature 5 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;
		case 6:
			printf("\n<<< Feature 6 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;
		default:
			printf("Exit the program? (Y)es/(N)o: ");
			Return = yes();
			if (Return == 1)
				printf("Contact Management System: terminated\n");
		}
	} while (Return != 1);
}
