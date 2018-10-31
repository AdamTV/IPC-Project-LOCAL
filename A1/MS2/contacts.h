/* -------------------------------------------
Name:		 ADAM STINZIANI
Student number:  124521188
Email:		 astinziani@myseneca.ca
Section:	 IPC144SVV
Date:		 2018-10-30
----------------------------------------------
Assignment: 1
Milestone:  1
---------------------------------------------- */

// Structure type Name declaration
struct Name {
    char firstName[31];
    char middleInitial[7];
    char lastName[36];
};

// Structure type Address declaration
// Place your code from Milestone #1 here...
struct Address {
    unsigned int streetNum;
    char street[41];
    unsigned int aptNum;
    char postalCode[8];
    char city[41];
};

// Structure type Numbers declaration
// Place your code from Milestone #1 here...
struct Numbers {
    char cell[11];
    char home[11];
    char business[11];
};
