/*
 * linked_list.c for Linked List Student DB
 * Eng. Ahmed Essam
 */

#include "linked_list.h"

#define DPRINTF(...) 	{fflush(stdout); \
						fflush(stdin); \
						printf(__VA_ARGS__); \
						fflush(stdout); \
						fflush(stdin);}

void AddStudent(){

	struct sStudent* pNewStudent;
	struct sStudent* pLastStudent;

	//Assign location for new student
	pNewStudent = (struct sStudent*) malloc(sizeof(struct sStudent));

	//Check if list is empty
	if(gpFirstStudent == NULL){
		//Assign address of new student to gpFirstStudent
		gpFirstStudent = pNewStudent;
	}
	else{
		//Iterate for last student
		pLastStudent = gpFirstStudent;
		while(pLastStudent->pNext){
			pLastStudent = pLastStudent->pNext;
		}
		pLastStudent->pNext = pNewStudent;
	}

	//Fill out Student's data
	fillData(pNewStudent);

	//Assign pNext of pNewStudent to NULL
	pNewStudent->pNext = NULL;
	DPRINTF("\nSuccessfully added to list");
}

void DeleteStudent(){

	int selectedID = selectID();

	//Check list is not empty
	if(gpFirstStudent){

		struct sStudent* pPrevStudent = NULL;
		struct sStudent* pSelectedStudent = gpFirstStudent;

		//Iterate for selectedID
		while(pSelectedStudent){
			//Compare each node with selectedID
			if(pSelectedStudent->data.id == selectedID){
				if(pPrevStudent){
					//First node != selectedID
					pPrevStudent->pNext = pSelectedStudent->pNext;
				}
				else{
					//First node == selectedID
					gpFirstStudent = pSelectedStudent->pNext;
				}
				free(pSelectedStudent);
				DPRINTF("\nSuccessfully deleted ID %d", selectedID);
				return;
			}
			pPrevStudent = pSelectedStudent;
			pSelectedStudent = pSelectedStudent->pNext;
		}
		DPRINTF("\nID not found");
		return;
	}
	DPRINTF("\nList is empty");
	return;
}

void ViewAll(){

	//Check list is not empty
	if(gpFirstStudent){

		struct sStudent* pCurrentStudent = gpFirstStudent;
		int count = 1;

		while(pCurrentStudent){

			DPRINTF("\n Record Number %d", count);
			DPRINTF("\n \t ID: %d", pCurrentStudent->data.id);
			DPRINTF("\n \t Name: %s", pCurrentStudent->data.name);
			DPRINTF("\n \t Height: %f", pCurrentStudent->data.height);
			DPRINTF("\n----------------------");
			pCurrentStudent = pCurrentStudent->pNext;
			count++;
		}
	}
	else{
		DPRINTF("\nList is empty");
		return;
	}
}

void DeleteAllList(){

	//Check list is not empty
	if(gpFirstStudent){

		struct sStudent* pCurrentStudent = gpFirstStudent;

		while(pCurrentStudent){

			struct sStudent* pTempStudent = pCurrentStudent;
			pCurrentStudent = pCurrentStudent->pNext;
			free(pTempStudent);
		}
		gpFirstStudent = NULL;
		DPRINTF("\nSuccessfully deleted all list");
	}
	else{
		DPRINTF("\nList is empty");
		return;
	}
}

void NthNode(){

	int selectedNode = selectNode();

	//Check list is not empty
	if(gpFirstStudent){

		struct sStudent* pCurrentStudent = gpFirstStudent;
		int count = 0;

		while(pCurrentStudent){

			if(selectedNode == count){
				DPRINTF("\n Node at index %d", selectedNode);
				DPRINTF("\n \t ID: %d", pCurrentStudent->data.id);
				DPRINTF("\n \t Name: %s", pCurrentStudent->data.name);
				DPRINTF("\n \t Height: %f", pCurrentStudent->data.height);
				DPRINTF("\n----------------------");
				return;
			}

			pCurrentStudent = pCurrentStudent->pNext;
			count++;
		}
	}
	else{
		DPRINTF("\nList is empty");
		return;
	}
	DPRINTF("\nSelected Index is out of list boundaries");
}

void NthNodeFromEnd(){

	int selectedNode = selectNode();

	//Check list is not empty
	if(gpFirstStudent){

		struct sStudent* pMainStudent = gpFirstStudent;
		struct sStudent* pRefStudent = gpFirstStudent;

		//Move pRefStudent with distance = selectedNode
		for(int i = 0; i <= selectedNode; i++){
			pRefStudent = pRefStudent->pNext;
			if(pRefStudent == NULL){
				DPRINTF("\nSelected Index is out of list boundaries");
				return;
			}
		}

		//Move both pointers together till pRefStudent == NULL
		while(pRefStudent){
			pRefStudent = pRefStudent->pNext;
			pMainStudent = pMainStudent->pNext;
		}

		DPRINTF("\n Node at index %d from end", selectedNode);
		DPRINTF("\n \t ID: %d", pMainStudent->data.id);
		DPRINTF("\n \t Name: %s", pMainStudent->data.name);
		DPRINTF("\n \t Height: %f", pMainStudent->data.height);
		DPRINTF("\n----------------------");
		return;
	}
	else{
		DPRINTF("\nList is empty");
		return;
	}
}

void LenghtList(){

	int count = 0;

	//Check list is not empty
	if(gpFirstStudent){

		struct sStudent* pCurrentStudent = gpFirstStudent;

		while(pCurrentStudent){
			pCurrentStudent = pCurrentStudent->pNext;
			count++;
		}
	}

	DPRINTF("\nLength of List = %d", count);
}

void MiddleList(){

	//Check list is not empty
	if(gpFirstStudent){

		struct sStudent* slowPtr = gpFirstStudent;
		struct sStudent* fastPtr = gpFirstStudent;
		int index = 0;

		while(fastPtr && fastPtr->pNext){
			slowPtr = slowPtr->pNext;
			fastPtr = fastPtr->pNext;
			fastPtr = fastPtr->pNext;
			index++;
		}

		DPRINTF("\n Middle of List at index %d", index);
		DPRINTF("\n \t ID: %d", slowPtr->data.id);
		DPRINTF("\n \t Name: %s", slowPtr->data.name);
		DPRINTF("\n \t Height: %f", slowPtr->data.height);
		DPRINTF("\n----------------------");
		return;
	}
	else{
		DPRINTF("\nList is empty");
		return;
	}
}

void ReverseList(){

	//Check list is not empty
	if(gpFirstStudent){

		struct sStudent* pPrevStudent = gpFirstStudent;
		struct sStudent* pCurrentStudent = gpFirstStudent;
		struct sStudent* pNextStudent = NULL;
		
		pCurrentStudent = pCurrentStudent->pNext;
		pPrevStudent->pNext = NULL;

		while(pCurrentStudent){
			pNextStudent = pCurrentStudent->pNext;
			pCurrentStudent->pNext = pPrevStudent;
			pPrevStudent = pCurrentStudent;
			pCurrentStudent = pNextStudent;
		}

		gpFirstStudent = pPrevStudent;
		DPRINTF("\nList is Reversed Successfully");
		return;
	}
	else{
		DPRINTF("\nList is empty");
		return;
	}
}


void fillData(struct sStudent* pNewStudent){

	char tempText[40];

	DPRINTF("\nEnter Student's ID: ");
	gets(tempText);
	pNewStudent->data.id = atoi(tempText);

	DPRINTF("Enter Student's Name: ");
	gets(pNewStudent->data.name);

	DPRINTF("Enter Student's Height: ");
	gets(tempText);
	pNewStudent->data.height = atof(tempText);
}

int selectID(){

	char id[10];
	DPRINTF("\nEnter ID to be deleted: ");
	gets(id);
	return atoi(id);
}

int selectNode(){

	char node[10];
	DPRINTF("\nEnter index of Node: ");
	gets(node);
	return atoi(node);
}

