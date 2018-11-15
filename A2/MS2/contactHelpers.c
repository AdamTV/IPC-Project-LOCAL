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

// clearKeyboard:  Empty function definition 
void clearKeyboard(void)
{
	while (getchar() != '\n')	; // empty execution code block on purpose
}

// pause: Empty function definition goes here:
void pause(void)
{
	printf("(Press Enter to continue)");
	clearKeyboard();
}

// getInt: Empty function definition goes here:
int getInt(void)
{
	char NL = 'x';
	int Value;

	while (NL != '\n')
	{
		scanf("%d%c", &Value, &NL);
		if (NL != '\n')
		{
			clearKeyboard();
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		}
	}
	return Value;
}

// getIntInRange: Empty function definition goes here:
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

// yes: Empty function definition goes here:
int yes(void)
{
	char Value;
	char NL = 'x';

	while (NL != '\n' || Value != 'Y' || Value != 'y' || Value != 'N' || Value != 'n')
	{
		scanf("%c%c", &Value, &NL);
		if (NL != '\n')
		{
			clearKeyboard();
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		}
	}
	if (Value == 'Y' || Value == 'y')
		return 1;
	else
		return 0;
}

// menu: Empty function definition goes here:
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

// contactManagerSystem: Empty function definition goes here:
void contactManagerSystem(void)
{
	int Value, Return;
	do
	{
		Value = menu();

		switch (Value)
		{
		case 1:
			printf("<<< Feature 1 is unavailable >>>\n\n");
		case 2:
			printf("<<< Feature 2 is unavailable >>>\n\n");
		case 3:
			printf("<<< Feature 3 is unavailable >>>\n\n");
		case 4:
			printf("<<< Feature 4 is unavailable >>>\n\n");
		case 5:
			printf("<<< Feature 5 is unavailable >>>\n\n");
		case 6:
			printf("<<< Feature 6 is unavailable >>>\n\n");
		case 0:
			printf("Exit the program? (Y)es/(N)o: ");
			Return = yes();
			if (Return == 1)
				printf("Contact Management System: terminated\n");
		}
	} while (Return != 1);
}
