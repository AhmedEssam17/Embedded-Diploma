/*
 * linked_list.h for Linked List Student DB
 * Eng. Ahmed Essam
*/

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

// Sensitive Data
struct sData{
	int id;
	char name[40];
	float height;
};

// Linked List Node
struct sStudent{
	struct sData data;
	struct sStudent* pNext;
};

extern struct sStudent* gpFirstStudent;

//Main APIs
void AddStudent();
void DeleteStudent();
void ViewAll();
void DeleteAllList();
void NthNode();
void NthNodeFromEnd();
void LenghtList();
void MiddleList();
void ReverseList();

//Nested APIs
void fillData(struct sStudent* pNewStudent);
int selectID();
int selectNode();

#endif /* LINKED_LIST_H_ */
