#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef struct employee
{
    char empno[30];
    char name[30];
    char salary[40];
} emp;
void addRecord()
{
    FILE *myfile;
    emp e;
    myfile = fopen("employee.bin", "ab");
    printf("Enter empno, name and salary");
    scanf("%s%s%s", &e.empno, e.name, &e.salary);
    fwrite(&e, sizeof(emp), 1, myfile);
    fclose(myfile);
}
void displayRecord()
{
    FILE *myfile;
    emp e;
    myfile = fopen("employee.bin", "rb");
    printf("The records are:\n");
    while (fread(&e, sizeof(emp), 1, myfile) == 1)
    {
        printf("%s %s %s\n", e.empno, e.name, e.salary);
    }
}
// void updateRecord()
// {
//     FILE *myfile;
//     emp e;
//     float tempsal;
//     int tempno;
//     myfile = fopen("employee.bin", "r+b");
//     printf("Enter the empno whose salary is changed:");
//     scanf("%d", &tempno);
//     while (fread(&e, sizeof(emp), 1, myfile) == 1)
//     {
//         if (e.empno == tempno)
//         {
//             printf("Enter new salary");
//             scanf("%f", &tempsal);
//             e.salary = tempsal;
//             fseek(myfile, -sizeof(emp), SEEK_CUR);
//             fwrite(&e, sizeof(emp), 1, myfile);
//             printf("%s salary is changed\n", e.name);
//             break;
//         }
//     }
//     fclose(myfile);
// }
// void deleteRecord()
// {
//     FILE *myfile, *temp;
//     int tempempno;
//     emp e;
//     myfile = fopen("employee.bin", "rb");
//     temp = fopen("temp.bin", "wb");
//     printf("Enter the Employee Number Whose record is to be deleted");
//     scanf("%d", &tempempno);
//     while (fread(&e, sizeof(emp), 1, myfile) == 1)
//     {
//         if (e.empno != tempempno)
//         {
//             fwrite(&e, sizeof(emp), 1, temp);
//         }
//         else
//         {
//             printf("The %d Employee number record has been deleted", e.empno);
//         }
//     }
//     fclose(myfile);
//     fclose(temp);
//     myfile = fopen("employee.bin", "wb");
//     temp = fopen("temp.bin", "rb");
//     while (fread(&e, sizeof(emp), 1, temp) == 1)
//     {
//         fwrite(&e, sizeof(emp), 1, myfile);
//     }
//     fclose(myfile);
//     fclose(temp);
// }
int main()
{
    int choice;
    while (1)
    {
        system("cls");
        printf("Employee Management System\n");
        printf("1. Add Record\n");
        printf("2. Display Record\n");
        printf("3. Update Record\n");
        printf("4. Delete Record\n");
        printf("5. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            addRecord();
            break;
        case 2:
            displayRecord();
            break;
        // case 3:updateRecord();
        // break;
        // case 4:deleteRecord();
        // break;
        case 5:
            exit(0);
        }
        getch();
    }
    return 0;
}
