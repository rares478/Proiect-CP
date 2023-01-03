#include <stdio.h>
#include <time.h>
#include "Employee_database.h"

void clock_in(Employee* e) {
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

    // get current time
    time_t t = time(NULL);
    struct tm* tm = localtime(&t);

    int year = tm->tm_year + 1900;
    int month = tm->tm_mon + 1;
    int day = tm->tm_mday;
    int hour = tm->tm_hour;

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
        &clock_out.day, &clock_out.month, &clock_out.year,&clock_out.hour,
        &performance_rating) == 23) {
        if (id == e->id) {
            clock_in.day = day;
            clock_in.month = month;
            clock_in.year = year;
            clock_in.hour = hour;
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

void clock_out(Employee* e)
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

    // get current time
    time_t t = time(NULL);
    struct tm* tm = localtime(&t);

    int year = tm->tm_year + 1900;
    int month = tm->tm_mon + 1;
    int day = tm->tm_mday;
    int hour = tm->tm_hour;

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
            clock_out.day = day;
            clock_out.month = month;
            clock_out.year = year;
            clock_out.hour = hour;
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

int calculate_hours_worked(Employee* e)
{
    int hour_in = e->clock_in.hour;
    int hour_out = e->clock_out.hour;

    int total_hours = hour_out - hour_in;

    return total_hours;
}

void request_leave(Employee* e, Date start, Date end)
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
            start_date.day = start.day;
            start_date.month = start.month;
            start_date.year = start.year;

            end_date.day = end.day;
            end_date.month = end.month;
            end_date.year = end.year;
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

void cancel_leave(Employee* e)
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

    //get current day
    time_t t = time(NULL);
    struct tm* tm = localtime(&t);

    int year = tm->tm_year + 1900;
    int month = tm->tm_mon + 1;
    int day = tm->tm_mday;

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

            end_date.day = day + 1;
            end_date.month = month;
            end_date.year = year;
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