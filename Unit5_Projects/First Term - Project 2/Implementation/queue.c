/*
 * queue.c for Student Info Management System
 * Eng. Ahmed Essam
 */

#include "queue.h"

sData buffer[size];
queueBuffer_t mainQueue;
queueBuffer_t* pQueue = &mainQueue;

queueStatus queue_init(){

    //Check Buffer availability
    if(buffer == NULL){
        return queueNull;
    }

    pQueue->base = buffer;
    pQueue->head = buffer;
    pQueue->tail = buffer;
    pQueue->length = size;
    pQueue->count = 0;

    return queueNoError;
}

queueStatus queue_isValid(){

    if(!pQueue->base || !pQueue->head || !pQueue->tail)
    {
        DPRINTF("\n[ERROR] Queue is not Valid");
        return queueNull;
    }
    else
        return queueNoError;
}

queueStatus queue_isEmpty(){

    if(pQueue->count == 0){
        DPRINTF("\n[ERROR] Queue is Empty");
        return queueEmpty;
    }
    else
        return queueNoError;
}

queueStatus queue_isFull(){

    if(pQueue->count == pQueue->length)
    {
        DPRINTF("\n[ERROR] Queue is Full");
        return queueFull;
    }
    else
        return queueNoError;
}

void addStudentManually(){

    if(queue_isValid() != queueNoError && queue_isFull() != queueNoError)
        return;

    DPRINTF("\n----------------------");
    DPRINTF("\nFill out Student Info");
    DPRINTF("\n----------------------");

    sData studentInfo;
    char tempText[40];

    DPRINTF("\nEnter Roll Number: ");
    gets(tempText);
    studentInfo.roll = atoi(tempText);
    if(roll_isUnique(studentInfo.roll) == 0)
        return;

    DPRINTF("Enter First Name: ");
    gets(studentInfo.fName);

    DPRINTF("Enter Last Name: ");
    gets(studentInfo.lName);

    DPRINTF("Enter GPA: ");
    gets(tempText);
    studentInfo.gpa = atof(tempText);

    DPRINTF("Enter each Course ID \n");
    for(int i = 0; i < 5; i++){
        DPRINTF(" Course %d ID: ", i+1);
        gets(tempText);
        studentInfo.courseId[i] = atoi(tempText);
    }

    *(pQueue->head) = studentInfo;
    pQueue->count++;

    if(pQueue->head == (pQueue->base + (pQueue->length * sizeof(queueBuffer_t))))
        pQueue->head = pQueue->base;
    else
        pQueue->head++;
    DPRINTF("\n[INFO] Student Info added successfully\n");
}

void addStudentFromFile(){

    if(queue_isValid() != queueNoError && queue_isFull() != queueNoError)
        return;

    FILE *fp;
    fp = fopen("addStudentFromFile.txt", "r");

    if(fp == NULL){
        DPRINTF("\n[ERROR] Failed to open file");
        return;
    }

    char line[100];
    char *token;

    while(fgets(line, sizeof(line), fp)){

        int counter = 1;
        int course = 0;
        sData newStudent;
        token = strtok(line, " ");

        while(token != NULL){
            switch(counter){
            case 1:
                newStudent.roll = atoi(token);
                if(roll_isUnique(newStudent.roll) == 0)
                    return;
                break;
            case 2:
                strcpy(newStudent.fName, token);
                break;
            case 3:
                strcpy(newStudent.lName, token);
                break;
            case 4:
                newStudent.gpa = atof(token);
                break;
            case 5:
                newStudent.courseId[course] = atoi(token);
                course++;
                counter--;
                break;
            }
            token = strtok(NULL, " ");
            counter++;
        }
        *(pQueue->head) = newStudent;
        pQueue->count++;

        if(pQueue->head == (pQueue->base + (pQueue->length * sizeof(queueBuffer_t))))
            pQueue->head = pQueue->base;
        else
            pQueue->head++;
    }
    fclose(fp);
    DPRINTF("\n[INFO] Student Info added successfully\n");
}

void findByRoll(){

    if(queue_isValid() != queueNoError && queue_isEmpty() != queueNoError)
        return;

    char tempText[40];
    int rollNum;

    DPRINTF("\nEnter Student's Roll Number: ");
    gets(tempText);
    rollNum = atoi(tempText);

    sData *student;
    student = pQueue->tail;
    for(int i = 0; i < pQueue->count; i++){
        if(student->roll == rollNum){
            printInfo(student);
            return;
        }
        student++;
    }
    DPRINTF("\n[ERROR] Roll Number not found");
}

void findByFirstName(){

    if(queue_isValid() != queueNoError && queue_isEmpty() != queueNoError)
        return;

    char firstName[40];
    int flag = 0;

    DPRINTF("\nEnter Student's First Name: ");
    gets(firstName);

    sData *student;
    student = pQueue->tail;
    for(int i = 0; i < pQueue->count; i++){
        if(strcmp(student->fName, firstName) == 0){
            printInfo(student);
            flag = 1;
        }
        student++;
    }
    if(flag == 0)
        DPRINTF("\n[ERROR] Student's First Name not found");

}

void findByCourseId(){

    if(queue_isValid() != queueNoError && queue_isEmpty() != queueNoError)
        return;

    char tempText[40];
    int course;

    DPRINTF("\nEnter Course ID: ");
    gets(tempText);
    course = atoi(tempText);

    sData *student;
    student = pQueue->tail;
    int flag = 0;
    for(int i = 0; i < pQueue->count; i++){
        for(int j = 0; j < 5; j++){
            if(student->courseId[j] == course){
                printInfo(student);
                flag = 1;
            }
        }
        student++;
    }
    if(flag == 0)
        DPRINTF("\n[ERROR] Course ID not found");
}

void totalStudentCount(){

    if(queue_isValid() != queueNoError)
        return;

    DPRINTF("\n[INFO] Total Number of Students = %d", pQueue->count);
    DPRINTF("\n[INFO] You can add up to 50 Students");
    DPRINTF("\n[INFO] %d more slots are available", 50 - pQueue->count);
}

void deleteStudent(){

    if(queue_isValid() != queueNoError)
        return;

    char tempText[40];
    int rollNum;

    DPRINTF("\nEnter Student's Roll Number: ");
    gets(tempText);
    rollNum = atoi(tempText);

    sData *student;
    sData *currStudent;
    sData *nextStudent;
    student = pQueue->tail;
    for(int i = 0; i < pQueue->count; i++){
        if(student->roll == rollNum){
            for(int j = i; j < pQueue->count; j++){
                currStudent = student;
                nextStudent = ++student;
                *currStudent = *nextStudent;
            }
            pQueue->count--;
            if(pQueue->head == pQueue->base)
                pQueue->head = (pQueue->base) + (pQueue->length * sizeof(queueBuffer_t));
            else
                pQueue->head--;
            DPRINTF("\n[INFO] Student Info successfully deleted");
            return;
        }
        student++;
    }
    DPRINTF("\n[ERROR] Roll Number not found");
}

void updateStudent(){

    if(queue_isValid() != queueNoError)
        return;

    char tempText[40];
    int rollNum;

    DPRINTF("\nEnter Student's Roll Number: ");
    gets(tempText);
    rollNum = atoi(tempText);

    sData *student;
    student = pQueue->tail;
    for(int i = 0; i < pQueue->count; i++){
        if(student->roll == rollNum){
            updateInfo(student);
            return;
        }
        student++;
    }
    DPRINTF("\n[ERROR] Roll Number not found");
}

void showAll(){

    if(queue_isValid() != queueNoError)
        return;

    sData *student;
    student = pQueue->tail;
    for(int i = 0; i < pQueue->count; i++){
        printInfo(student);
        student++;
    }
}

int roll_isUnique(int rollCheck){

    sData *student;
    student = pQueue->tail;
    for(int i = 0; i < pQueue->count; i++){
        if(student->roll == rollCheck){
            DPRINTF("\n[ERROR] Roll Number is already taken");
            return 0;
        }
        student++;
    }
    return 1;
}

void printInfo(sData* student){

    DPRINTF("\n\tRoll Number: %d", student->roll);
    DPRINTF("\n\tFirst Name: %s", student->fName);
    DPRINTF("\n\tLast Name: %s", student->lName);
    DPRINTF("\n\tGPA: %.2f", student->gpa);
    DPRINTF("\n\tCourses ID: ");
    for(int i = 0; i < 5; i++){
        DPRINTF("%d ", student->courseId[i]);
    }
    DPRINTF("\n----------------------");
}

void updateInfo(sData* student){

    char tempText[40];
    DPRINTF("\nChoose data to be updated: ");
    DPRINTF("\n 1: Roll Number");
    DPRINTF("\n 2: First Name");
    DPRINTF("\n 3: Last Name");
    DPRINTF("\n 4: GPA");
    DPRINTF("\n 5: Courses ID");
    DPRINTF("\n\nEnter an option: ");
    gets(tempText);

    switch(atoi(tempText)){
    case 1:
        DPRINTF("\nEnter Roll Number: ");
        gets(tempText);
        student->roll = atoi(tempText);
        if(!roll_isUnique(student->roll))
            return;
        else
            DPRINTF("\n\n[INFO] Data updated successfully");
        break;

    case 2:
        DPRINTF("\nEnter First Name: ");
        gets(student->fName);
        DPRINTF("\n\n[INFO] Data updated successfully");
        break;

    case 3:
        DPRINTF("\nEnter Last Name: ");
        gets(student->lName);
        DPRINTF("\n\n[INFO] Data updated successfully");
        break;

    case 4:
        DPRINTF("\nEnter GPA: ");
        gets(tempText);
        student->gpa = atof(tempText);
        DPRINTF("\n\n[INFO] Data updated successfully");
        break;

    case 5:
        DPRINTF("\nEnter each Course ID \n");
        for(int i = 0; i < 5; i++){
            DPRINTF(" Course %d ID: ", i+1);
            gets(tempText);
            student->courseId[i] = atoi(tempText);
        }
        DPRINTF("\n\n[INFO] Data updated successfully");
        break;
    }
}
