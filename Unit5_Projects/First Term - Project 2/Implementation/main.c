/*
 * main.c for Student Info Management System
 * Eng. Ahmed Essam
*/

#include "queue.h"

int main(){

    char tempText[40];

    if(queue_init() == queueNoError){
        DPRINTF("\n*****Student Management System*****");
    }
    else{
        DPRINTF("\nFAILED to initialize Queue");
        return 0;
    }

    while(1){
        
        DPRINTF("\n======================");
        DPRINTF("\nList of Available Options:\n");
        DPRINTF("\n 1: Add New Student Manually");
        DPRINTF("\n 2: Add New Student/s From Text File");
        DPRINTF("\n 3: Find Student by Roll Number");
        DPRINTF("\n 4: Find Student/s by First Name");
        DPRINTF("\n 5: Find Student/s by Course ID");
        DPRINTF("\n 6: Total Number of Students");
        DPRINTF("\n 7: Delete Student by Roll Number");
        DPRINTF("\n 8: Update Student by Roll Number");
        DPRINTF("\n 9: View All Students Info");
        DPRINTF("\n 10: Exit");

        DPRINTF("\n\n Enter an Option: ");
        gets(tempText);
        DPRINTF("\n======================");

        switch(atoi(tempText)){

        case 1:
            addStudentManually();
            break;
        case 2:
            addStudentFromFile();
            break;
        case 3:
            findByRoll();
            break;
        case 4:
            findByFirstName();
            break;
        case 5:
            findByCourseId();
            break;
        case 6:
            totalStudentCount();
            break;
        case 7:
            deleteStudent();
            break;
        case 8:
            updateStudent();
            break;
        case 9:
            showAll();
            break;
        case 10:
            return 0;
        }
    }
    return 0;
}
