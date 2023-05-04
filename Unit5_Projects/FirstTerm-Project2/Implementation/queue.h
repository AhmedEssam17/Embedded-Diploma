/*
 * queue.h for Student Info Management System
 * Eng. Ahmed Essam
*/

#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define DPRINTF(...)    {fflush(stdout); \
                        fflush(stdin); \
                        printf(__VA_ARGS__); \
                        fflush(stdout); \
                        fflush(stdin);}

#define size 50

//Senstive Data
typedef struct{
    char fName[50];
    char lName[50];
    int roll;
    float gpa;
    int courseId[10];
} sData;

extern sData buffer[size];

//Queue Initialization
typedef struct{
    unsigned int length;
    unsigned int count;
    sData* base;
    sData* head;
    sData* tail;
} queueBuffer_t;

//Queue Status
typedef enum{
    queueNoError,
    queueFull,
    queueEmpty,
    queueNull
} queueStatus;

//Main APIS to be called by user
void addStudentManually();
void addStudentFromFile();
void findByRoll();
void findByFirstName();
void findByCourseId();
void totalStudentCount();
void deleteStudent();
void updateStudent();
void showAll();

//Internal APIs
queueStatus queue_init();
queueStatus queue_isValid();
queueStatus queue_isEmpty();
queueStatus queue_isFull();
int roll_isUnique(int rollCheck);
void printInfo(sData* student);
void updateInfo(sData* student);

#endif /* QUEUE_H_ */
