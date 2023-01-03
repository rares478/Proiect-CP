#include <stdio.h>
#include "Employee_database.h"
#include "Employee_performance.h"

void record_performance(Employee* e, int rating)
{
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

    // copy the data from the input file to the output file, updating the hours worked for the given employee
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
    while (fscanf(fp, "%d,%99[^,],%99[^,],%f,%f,%f,%f,%f,%d-%d-%d,%d-%d-%d,%d-%d-%d-%d,%d-%d-%d-%d,%d\n",
        &id, ename, position, &pay_rate, &hours_worked, &salary,
        &taxes, &bonus, &start_date.day, &start_date.month, &start_date.year,
        &end_date.day, &end_date.month, &end_date.year,
        &clock_in.day, &clock_in.month, &clock_in.year, &clock_in.hour,
        &clock_out.day, &clock_out.month, &clock_out.year, &clock_out.hour,
        &performance_rating) == 23) {
        if (id == e->id) {
            performance_rating = rating;

        }
        // write the data to the output file
        fprintf(fp_out, "%d,%s,%s,%.2f,%.2f,%.2f,%.2f,%.2f,%d-%d-%d,%d-%d-%d,%d-%d-%d-%d,%d-%d-%d-%d,%d\n",
            id, ename, position, pay_rate, hours_worked, salary, taxes, bonus,
            start_date.day, start_date.month, start_date.year,
            end_date.day, end_date.month, end_date.year,
            clock_in.day, clock_in.month, clock_in.year, clock_in.hour,
            clock_out.day, clock_out.month, clock_out.year, clock_out.hour, performance_rating);
    }

    // close the files
    fclose(fp);
    fclose(fp_out);

    // delete the original file and rename the temporary file
    remove("employees.txt");
    rename("employees_temp.txt", "employees.txt");
}

void give_raise(Employee* e, float amount) 
{
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

    // copy the data from the input file to the output file, updating the hours worked for the given employee
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
    while (fscanf(fp, "%d,%99[^,],%99[^,],%f,%f,%f,%f,%f,%d-%d-%d,%d-%d-%d,%d-%d-%d-%d,%d-%d-%d-%d,%d\n",
        &id, ename, position, &pay_rate, &hours_worked, &salary,
        &taxes, &bonus, &start_date.day, &start_date.month, &start_date.year,
        &end_date.day, &end_date.month, &end_date.year,
        &clock_in.day, &clock_in.month, &clock_in.year, &clock_in.hour,
        &clock_out.day, &clock_out.month, &clock_out.year, &clock_out.hour,
        &performance_rating) == 23) {
        if (id == e->id) {
            float current_salary = pay_rate;
            current_salary = current_salary + amount;
            pay_rate = current_salary;

        }
        // write the data to the output file
        fprintf(fp_out, "%d,%s,%s,%.2f,%.2f,%.2f,%.2f,%.2f,%d-%d-%d,%d-%d-%d,%d-%d-%d-%d,%d-%d-%d-%d,%d\n",
            id, ename, position, pay_rate, hours_worked, salary, taxes, bonus,
            start_date.day, start_date.month, start_date.year,
            end_date.day, end_date.month, end_date.year,
            clock_in.day, clock_in.month, clock_in.year, clock_in.hour,
            clock_out.day, clock_out.month, clock_out.year, clock_out.hour, performance_rating);
    }

    // close the files
    fclose(fp);
    fclose(fp_out);

    // delete the original file and rename the temporary file
    remove("employees.txt");
    rename("employees_temp.txt", "employees.txt");
}

extern void give_bonus(Employee* e, float amount)
{
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

    // copy the data from the input file to the output file, updating the hours worked for the given employee
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
    while (fscanf(fp, "%d,%99[^,],%99[^,],%f,%f,%f,%f,%f,%d-%d-%d,%d-%d-%d,%d-%d-%d-%d,%d-%d-%d-%d,%d\n",
        &id, ename, position, &pay_rate, &hours_worked, &salary,
        &taxes, &bonus, &start_date.day, &start_date.month, &start_date.year,
        &end_date.day, &end_date.month, &end_date.year,
        &clock_in.day, &clock_in.month, &clock_in.year, &clock_in.hour,
        &clock_out.day, &clock_out.month, &clock_out.year, &clock_out.hour,
        &performance_rating) == 23) {
        if (id == e->id) {
            float current_bonus = bonus;
            current_bonus = current_bonus + amount;
            bonus = current_bonus;

        }
        // write the data to the output file
        fprintf(fp_out, "%d,%s,%s,%.2f,%.2f,%.2f,%.2f,%.2f,%d-%d-%d,%d-%d-%d,%d-%d-%d-%d,%d-%d-%d-%d,%d\n",
            id, ename, position, pay_rate, hours_worked, salary, taxes, bonus,
            start_date.day, start_date.month, start_date.year,
            end_date.day, end_date.month, end_date.year,
            clock_in.day, clock_in.month, clock_in.year, clock_in.hour,
            clock_out.day, clock_out.month, clock_out.year, clock_out.hour, performance_rating);
    }

    // close the files
    fclose(fp);
    fclose(fp_out);

    // delete the original file and rename the temporary file
    remove("employees.txt");
    rename("employees_temp.txt", "employees.txt");
}
