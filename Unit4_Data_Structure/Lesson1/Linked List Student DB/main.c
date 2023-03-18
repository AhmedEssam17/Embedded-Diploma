/*
 * main.c for Linked List Student DB
 * Eng. Ahmed Essam
*/

#include "linked_list.h"

#define DPRINTF(...) 	{fflush(stdout); \
						fflush(stdin); \
						printf(__VA_ARGS__); \
						fflush(stdout); \
						fflush(stdin);}

struct sStudent* gpFirstStudent = NULL;

void main(){

	char tempText[40];

	while(1){

		DPRINTF("\n======================");
		DPRINTF("\n \t List of Available Options:\n");
		DPRINTF("\n 1: Add New Student");
		DPRINTF("\n 2: Delete Student by ID");
		DPRINTF("\n 3: View All Students");
		DPRINTF("\n 4: Delete All Students");
		DPRINTF("\n 5: nth Node");
		DPRINTF("\n 6: nth Node from End");
		DPRINTF("\n 7: Length of List");
		DPRINTF("\n 8: Middle of List");
		DPRINTF("\n 9: Reverse List");

		DPRINTF("\n\n Enter an Option: ");
		gets(tempText);
		DPRINTF("\n======================");

		switch(atoi(tempText)){

		case 1:
			AddStudent();
			break;
		case 2:
			DeleteStudent();
			break;
		case 3:
			ViewAll();
			break;
		case 4:
			DeleteAllList();
			break;
		case 5:
			NthNode();
			break;
		case 6:
			NthNodeFromEnd();
			break;
		case 7:
			LenghtList();
			break;
		case 8:
			MiddleList();
			break;
		case 9:
			ReverseList();
			break;
		}
	}
}
