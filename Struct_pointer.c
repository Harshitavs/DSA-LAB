#include <stdio.h>
#include <string.h>

struct Employee_details{
    int id;
    int age;
    char name[50];
    float salary;
} E;

int main() {
    struct Employee_details E;
    struct Employee_details *p = &E;

    printf("Enter Employee ID: ");
    scanf("%d", &p->id);

    printf("Enter Employee Age :");
    scanf(" %d" , &p->age);

    printf("Enter Employee Name: ");
    scanf(" %s", p->name);

    printf("Enter Employee Salary: ");
    scanf(" %f", &p->salary);

    printf("\nEmployee Details:\n");
    printf("ID: %d\n", p->id);
    printf("Age: %d\n", p->age);
    printf("Name: %s\n", p->name);
    printf("Salary: %.2f\n", p->salary);

    printf("\nAddresses of Employee Members:\n");
    printf("Address of ID: %p\n", &p->id);
    printf("Address of Age: %p\n", &p->age);
    printf("Address of Name: %p\n",&p->name);
    printf("Address of Salary: %p\n",&p->salary);

    return 0;
}