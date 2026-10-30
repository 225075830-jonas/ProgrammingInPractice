#include <stdio.h>
#include <string.h>

#define NUM_SALARIES 50
#define NUM_BUDGETS 10
#define NUM_VEHICLES 20

int main()
{
    // ---------------- PART A: EMPLOYEE SALARIES ----------------
    float salaries[NUM_SALARIES];
    float totalSalary = 0;
    float averageSalary;
    float highestSalary = 0;
    float lowestSalary = 0;
    float searchSalary;
    int salaryFound = 0;

    printf("===== PART A: EMPLOYEE SALARIES =====\n\n");

    for (int i = 0; i < NUM_SALARIES; i++)
    {
        printf("Enter salary for employee %d: ", i + 1);
        scanf("%f", &salaries[i]);
    }

    printf("\nEmployee Salaries\n");
    for (int i = 0; i < NUM_SALARIES; i++)
    {
        printf("Employee %d: %.2f\n", i + 1, salaries[i]);
        totalSalary += salaries[i];

        if (i == 0)
        {
            highestSalary = salaries[i];
            lowestSalary = salaries[i];
        }
        if (salaries[i] > highestSalary)
        {
            highestSalary = salaries[i];
        }
        if (salaries[i] < lowestSalary)
        {
            lowestSalary = salaries[i];
        }
    }

    averageSalary = totalSalary / NUM_SALARIES;

    printf("\nAverage salary: %.2f\n", averageSalary);
    printf("Highest salary: %.2f\n", highestSalary);
    printf("Lowest salary: %.2f\n", lowestSalary);

    printf("\nEnter a salary to search for: ");
    scanf("%f", &searchSalary);

    salaryFound = 0;
    for (int i = 0; i < NUM_SALARIES; i++)
    {
        if (salaries[i] == searchSalary)
        {
            printf("Salary %.2f found at position %d (Employee %d)\n", searchSalary, i, i + 1);
            salaryFound = 1;
            break;
        }
    }
    if (!salaryFound)
    {
        printf("Salary %.2f not found.\n", searchSalary);
    }

    // ---------------- PART B: DEPARTMENT BUDGETS ----------------
    float budgets[NUM_BUDGETS];
    float totalBudget = 0;
    float averageBudget;
    float temp;

    printf("\n\n===== PART B: DEPARTMENT BUDGETS =====\n\n");

    for (int i = 0; i < NUM_BUDGETS; i++)
    {
        printf("Enter budget for department %d: ", i + 1);
        scanf("%f", &budgets[i]);
    }

    printf("\nDepartment Budgets\n");
    for (int i = 0; i < NUM_BUDGETS; i++)
    {
        printf("Department %d: %.2f\n", i + 1, budgets[i]);
        totalBudget += budgets[i];
    }

    averageBudget = totalBudget / NUM_BUDGETS;

    printf("\nTotal budget: %.2f\n", totalBudget);
    printf("Average budget: %.2f\n", averageBudget);

    // Bubble sort - ascending order
    for (int i = 0; i < NUM_BUDGETS - 1; i++)
    {
        for (int j = 0; j < NUM_BUDGETS - i - 1; j++)
        {
            if (budgets[j] > budgets[j + 1])
            {
                temp = budgets[j];
                budgets[j] = budgets[j + 1];
                budgets[j + 1] = temp;
            }
        }
    }

    printf("\nBudgets sorted from lowest to highest:\n");
    for (int i = 0; i < NUM_BUDGETS; i++)
    {
        printf("%.2f\n", budgets[i]);
    }

    // ---------------- PART C: VEHICLE REGISTRATION NUMBERS ----------------
    char registrations[NUM_VEHICLES][20];
    char searchReg[20];
    int regFound = 0;

    printf("\n\n===== PART C: VEHICLE REGISTRATION NUMBERS =====\n\n");

    for (int i = 0; i < NUM_VEHICLES; i++)
    {
        printf("Enter vehicle registration %d: ", i + 1);
        scanf("%19s", registrations[i]);
    }

    printf("\nVehicle Registrations\n");
    for (int i = 0; i < NUM_VEHICLES; i++)
    {
        printf("%d: %s\n", i + 1, registrations[i]);
    }

    printf("\nEnter a registration number to search for: ");
    scanf("%19s", searchReg);

    regFound = 0;
    for (int i = 0; i < NUM_VEHICLES; i++)
    {
        if (strcmp(registrations[i], searchReg) == 0)
        {
            printf("Registration %s found at position %d.\n", searchReg, i + 1);
            regFound = 1;
            break;
        }
    }
    if (!regFound)
    {
        printf("Registration %s not found.\n", searchReg);
    }

    return 0;
}
