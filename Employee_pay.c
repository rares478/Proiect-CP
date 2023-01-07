#include <stdio.h>
#include <time.h>
#include "Employee_pay.h"
#include "Employee_database.h"

float calculate_salary(Employee* e) {
    if (e == NULL) {
        return 0.0;
    }

    // calculate salary based on pay rate and hours worked
    e->salary = e->pay_rate * e->hours_worked;

    // calculate taxes based on salary
    e->taxes = e->salary * 0.25;

    // calculate total salary with taxes and bonus
    float total_salary = e->salary - e->taxes + e->bonus; 

    return total_salary;
}

float calculate_bonus(Employee* e) {
    if (e == NULL) {
        return 0.0;
    }

    time_t t = time(NULL);
    struct tm* tm = localtime(&t);

    int year = tm->tm_year + 1900;

    // calculate bonus based on salary and years of service
    int years_of_service = year - e->start_date.year;
    e->bonus = e->salary * (years_of_service * 0.05);

    return e->bonus;
}

float calculate_taxes(Employee* e)
{
    if (e == NULL) {
        return 0.0;
    }

    // calculate salary based on pay rate and hours worked
    e->salary = e->pay_rate * e->hours_worked;

    // calculate taxes based on salary
    e->taxes = e->salary * 0.25;

    float total_taxes = e->taxes;

    return total_taxes;
}

void pay_employee(Employee* e) {
    if (e == NULL) {
        return;
    }

    // open the input file
    FILE* fp = fopen("employees.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    // open the output file
    FILE* fp_out = fopen("employees_temp.txt", "w");
    if (fp_out == NULL) {
        perror("Error opening file");
        return;
    }

    // copy the data from the input file to the output file, updating the salary and bonus for the given employee
    int id;
    char ename[100];
    char position[100];
    float pay_rate;
    float hours_worked;
    float salary;
    float taxes;
    float bonus;
    int day1, month1, year1;
    int day2, month2, year2;
    int day3, month3, year3, hour3;
    int day4, month4, year4, hour4;
    int performance_rating;
    while (fscanf(fp, "%d,%99[^,],%99[^,],%f,%f,%f,%f,%f,%d-%d-%d,%d-%d-%d,%d-%d-%d-%d,%d-%d-%d-%d,%d\n",
        &id, ename, position, &pay_rate, &hours_worked, &salary,
        &taxes, &bonus, &day1, &month1, &year1, &day2, &month2, &year2,
        &day3, &month3, &year3, &hour3, &day4, &month4, &year4, &hour4, &performance_rating) == 23) {
        if (id == e->id) {
            // update the salary and bonus for the employee
            float new_salary = salary + calculate_salary(e) + calculate_bonus(e);
            salary = new_salary;
            bonus = 0.0;
            float new_taxes = taxes + calculate_taxes(e);
            taxes = new_taxes;
        }

        // write the data to the output file
        fprintf(fp_out, "%d,%s,%s,%f,%f,%f,%f,%f,%d-%d-%d,%d-%d-%d,%d-%d-%d-%d,%d-%d-%d-%d,%d\n",
            id, ename, position, pay_rate, hours_worked, salary, taxes, bonus,
            day1, month1, year1, day2, month2, year2,
            day3, month3, year3, hour3, day4, month4, year4, hour4,
            performance_rating);
    }

    // close the files
    fclose(fp);
    fclose(fp_out);

    // delete the original file and rename the temporary file
    remove("employees.txt");
    rename("employees_temp.txt", "employees.txt");
}

void print_pay() {
    // open the input file
    FILE* fp = fopen("employees.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    // read the data from the file and print the payroll report
    int id;
    char ename[100];
    char position[100];
    float pay_rate;
    float hours_worked;
    float salary;
    float taxes;
    float bonus;
    Date start_date;
    Date end_date;
    Date clock_in;
    Date clock_out;
    int performance_rating;
    printf("ID  Name            Position          Pay Rate   Hours Worked   Salary   Taxes   Bonus   \n");
    printf("=========================================================================================\n");
    while (fscanf(fp, "%d,%99[^,],%99[^,],%f,%f,%f,%f,%f,%d-%d-%d,%d-%d-%d,%d-%d-%d-%d,%d-%d-%d-%d,%d\n",
        &id, ename, position, &pay_rate, &hours_worked, &salary,
        &taxes, &bonus, &start_date.day, &start_date.month, &start_date.year,
        &end_date.day, &end_date.month, &end_date.year,
        &clock_in.day, &clock_in.month, &clock_in.year,&clock_in.hour,
        &clock_out.day, &clock_out.month, &clock_out.year,&clock_out.hour,
        &performance_rating) == 23) {
        printf("%-4d%-16s%-20s%-12.2f%-14.2f%-9.2f%-8.2f%-8.2f\n",
            id, ename, position, pay_rate, hours_worked, salary, taxes, bonus);
    }

    // close the file
    fclose(fp);

    printf("\n\n\n");
    printf("1. Go back to main menu\n");
    printf("2. Exit\n");
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        show_main();
        break;
    case 2:
        return 0;
        break;
    default:
        show_main();
        break;
    }
}