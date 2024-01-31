#include "SDB.h"
#include <stdio.h>
#define MAX_STUDENTS 10

void SDB_action(uint8 choice);

void SDB_APP()
{
    uint8 choice;
    do
    {
       printf("\n######## System of class of School Include 10 Students and their information ######### \n\n");
        printf("\n  Choose an option:\n");
        printf("\n================================================\n\n");
        printf("[1] Add entry\n");
        printf("[2] Get used size in database\n");
        printf("[3] Read student data\n");
        printf("[4] Get the list of all student IDs\n");
        printf("[5] Check if ID exists\n");
        printf("[6] Delete student data\n");
        printf("[7] Check if database is full\n");
        printf("[0] Exit\n");
        printf("\n================================================\n");
        printf("Enterchoice: ");
        scanf("%hhu", &choice);
        SDB_action(choice);
    }
    while (choice != 0);
}

void SDB_action(uint8 choice)
{
    switch (choice)
    {
    case 1:
    {  // Implementation for adding an entry
        if (SDB_AddEntry())
        {
            printf("Data added successfully.\n");
        }
        else
        {
            printf("Data not added. Database may be full.\n");
        }
        break;
    }
    case 2:
    {     // Implementation for getting used size in database
        uint8 usedSize = SDB_GetUsedSize();
        printf("Used size in database: %hhu\n", usedSize);
        break;
    }
    case 3:
    {     // Implementation for reading student data
        uint32 id;
        printf("Enter student ID: ");
        scanf("%u", &id);
        if (SDB_ReadEntry(id))
        {
            printf("Data found.\n");
        }
        else
        {
            printf("Data not found.\n");
        }
        break;
    }
    case 4:       // Implementation for getting the list of all student IDs
    {
        uint8 count;
        uint32 list[MAX_STUDENTS];
        SDB_GetList(&count, list);
        printf("List of student IDs:\n");
        for (uint8 i = 0; i < count; i++)
        {
            printf("%u\n", list[i]);
        }
        break;
    }
    case 5:    // Implementation for checking if ID exists
    {
        uint32 id;
        printf("Enter student ID: ");
        scanf("%u", &id);
        if (SDB_IsIdExist(id))
        {
            printf("ID exists.\n");
        }
        else
        {
            printf("ID not found.\n");
        }
        break;
    }
    case 6:  // Implementation for deleting student data
    {
        uint32 id;
        printf("Enter student ID to delete: ");
        scanf("%u", &id);
        SDB_DeleteEntry(id);
        printf("Data deleted.\n");
        break;
    }
    case 7:   // Implementation for checking if database is full
    {
        if (SDB_IsFull())
        {
            printf("Database is full.\n");
        }
        else
        {
            printf("Database is not full.\n");
        }
        break;
    }
    case 0:     // for exit of project
    {
        printf("Exiting...\n");
        break;
    }
    default:    // for any choice other above
    {
        printf("Invalid choice.\n");
        break;
    }
    }
}

int main()
{
    SDB_APP();
    return 0;
}
