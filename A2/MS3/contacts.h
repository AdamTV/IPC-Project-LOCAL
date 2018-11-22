// ----------------------------------------------------------------------------
// DO NOT remove the below 2 lines.
// The below two lines is needed to ensure only one copy
// of this header file is included when compiling the project.
// (it is referred to as "safeguarding")
// You will learn about this in C++ (OOP244/BTP200)
// For now, simply leave this code in!
#ifndef CONTACTS_H_
#define CONTACTS_H_
// ----------------------------------------------------------------------------

/* -------------------------------------------
Name:			 ADAM STINZIANI
Student number:  124521188
Email:			 astinziani@myseneca.ca
Section:		 IPC144SVV
Date:			 2018-11-21
----------------------------------------------
Assignment: 2
Milestone:  3
---------------------------------------------- */

//------------------------------------------------------
// Structure Types
//------------------------------------------------------

// Structure type Name declaration
struct Name
{
	char firstName[31];
	char middleInitial[15];
	char lastName[36];
};

// Structure type Address declaration
struct Address
{
	int streetNumber;
	char street[41];
	int apartmentNumber;
	char postalCode[8];
	char city[41];
};

// Structure type Numbers declaration
struct Numbers
{
	char cell[11];
	char home[11];
	char business[11];
};

// Structure type Contact declaration
struct Contact
{
	struct Name name;
	struct Address address;
	struct Numbers numbers;
};

//------------------------------------------------------
// Function Prototypes
//------------------------------------------------------

// Get and store from standard input the values for Name
void getName(struct Name *);

// Get and store from standard input the values for Address
void getAddress(struct Address *);

// Get and store from standard input the values for Numbers
void getNumbers(struct Numbers *);

// Get and store from standard input the values for a Contact (NOT: Contacts)
void getContact(struct Contact *);

// ----------------------------------------------------------------------------
// DO NOT remove the below line (closing of the "safeguard" condition)
#endif // !CONTACTS_H_
