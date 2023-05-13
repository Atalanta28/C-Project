#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100
#define MAX_NAME_LENGTH 50
#define MAX_ID_LENGTH 10
#define MAX_TITLE_LENGTH 50

struct Employee {
    char name[MAX_NAME_LENGTH];
    char employeeID[MAX_ID_LENGTH];
    double salary;
    char jobTitle[MAX_TITLE_LENGTH];
};

// Function prototypes
void addEmployee(struct Employee employees[], int *numEmployees);
void viewEmployees(struct Employee employees[], int numEmployees);
void searchEmployee(struct Employee employees[], int numEmployees, char searchID[MAX_ID_LENGTH]);

int main() {
    struct Employee employees[MAX_EMPLOYEES];
    int numEmployees = 0;
    char searchID[MAX_ID_LENGTH];

    int choice;
    do {
        printf("Employee Management System\n");
        printf("1. Add Employee\n");
        printf("2. View Employees\n");
        printf("3. Search Employee\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee(employees, &numEmployees);
                break;
            case 2:
                viewEmployees(employees, numEmployees);
                break;
            case 3:
                printf("Enter employee ID to search: ");
                scanf("%s", searchID);
                searchEmployee(employees, numEmployees, searchID);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

void addEmployee(struct Employee employees[], int *numEmployees) {
    if (*numEmployees >= MAX_EMPLOYEES) {
        printf("Maximum number of employees reached.\n");
        return;
    }

    struct Employee newEmployee;
    printf("Enter employee name: ");
    scanf(" %[^\n]s", newEmployee.name);
    printf("Enter employee ID: ");
    scanf("%s", newEmployee.employeeID);
    printf("Enter employee salary: ");
    scanf("%lf", &newEmployee.salary);
    printf("Enter employee job title: ");
    scanf(" %[^\n]s", newEmployee.jobTitle);

    employees[*numEmployees] = newEmployee;
    (*numEmployees)++;
    printf("Employee added successfully.\n");
}

void viewEmployees(struct Employee employees[], int numEmployees) {
    if (numEmployees == 0) {
        printf("No employees found.\n");
        return;
    }

    printf("Employee List:\n");
    printf("ID\tName\tSalary\tJob Title\n");
    for (int i = 0; i < numEmployees; i++) {
        printf("%s\t%s\t%.2lf\t%s\n", employees[i].employeeID, employees[i].name, employees[i].salary, employees[i].jobTitle);
    }
}

void searchEmployee(struct Employee employees[], int numEmployees, char searchID[MAX_ID_LENGTH]) {
    if (numEmployees == 0) {
        printf("No employees found.\n");
        return;
    }

    for (int i = 0; i < numEmployees; i++) {
        if (strcmp(employees[i].employeeID, searchID) == 0) {
            printf("Employee found:\n");
            printf("ID\tName\tSalary\tJob Title\n");
            printf("%s\t%s\t%.2lf\t%s\n", employees[i].employeeID, employees[i].name, employees[i].salary, employees[i].jobTitle);
            return;
        }
    }
    printf("No employee found with ID: %s\n", searchID);
}