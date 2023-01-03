#include <stdio.h>
#include "Employee_database.h"


void add_employee(Employee* e) {
    if (e == NULL) 
        return;

    // open the output file
    FILE* fp = fopen("employees.txt", "a");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    // write the employee data to the file
    fprintf(fp, "%d,%s,%s,%.2f,%.2f,%.2f,%.2f,%.2f,%d-%d-%d,%d-%d-%d,%d-%d-%d-%d,%d-%d-%d-%d,%d\n",
        e->id, e->name, e->position, e->pay_rate, e->hours_worked, e->salary,
        e->taxes, e->bonus,
        e->start_date.day, e->start_date.month, e->start_date.year,
        e->end_date.day, e->end_date.month, e->end_date.year,
        e->clock_in.day, e->clock_in.month, e->clock_in.year,e->clock_in.hour,
        e->clock_out.day, e->clock_out.month, e->clock_out.year,e->clock_out.hour,
        e->performance_rating);

    // close the file
    fclose(fp);
}

void modify_employee(Employee* e) {
    // open the input file
    FILE* fp_in = fopen("employees.txt", "r");
    if (fp_in == NULL) {
        perror("Error opening file");
        return;
    }

    // open a temporary file for output
    FILE* fp_out = fopen("employees.tmp", "w");
    if (fp_out == NULL) {
        perror("Error opening file");
        fclose(fp_in);
        return;
    }

    // read the records from the input file, modify the record for the
    // specified employee, and write the records to the temporary file
    int id;
    char name[100];
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

    while (fscanf(fp_in, "%d,%99[^,],%99[^,],%f,%f,%f,%f,%f,%d-%d-%d,%d-%d-%d,%d-%d-%d-%d,%d-%d-%d-%d,%d\n",
        &id, name, position, &pay_rate, &hours_worked, &salary,
        &taxes, &bonus, &day1, &month1, &year1, &day2, &month2, &year2,
        &day3, &month3, &year3, &hour3, &day4, &month4, &year4, &hour4,&performance_rating ) == 23) {
        if (id == e->id) {
            // update the fields that are not empty
            if (e->name[0] != '\0') {
                strcpy(name, e->name);
            }
            if (e->position[0] != '\0') {
                strcpy(position, e->position);
            }
            if (e->pay_rate > 0) {
                pay_rate = e->pay_rate;
            }
            if (e->hours_worked > 0) {
                hours_worked = e->hours_worked;
            }
            if (e->salary > 0) {
                salary = e->salary;
            }
            if (e->taxes > 0) {
                taxes = e->taxes;
            }
            if (e->bonus > 0) {
                bonus = e->bonus;
            }
            if (e->start_date.day > 0 && e->start_date.month > 0 && e->start_date.year > 0) {
                day1 = e->start_date.day;
                month1 = e->start_date.month;
                year1 = e->start_date.year;
            }
            if (e->end_date.day > 0 && e->end_date.month > 0 && e->end_date.year > 0) {
                day2 = e->end_date.day;
                month2 = e->end_date.month;
                year2 = e->end_date.year;
            }
            if (e->clock_in.day > 0 && e->clock_in.month > 0 && e->clock_in.year > 0 && e->clock_in.hour > 0) {
                day3 = e->clock_in.day;
                month3 = e->clock_in.month;
                year3 = e->clock_in.year;
                hour3 = e->clock_in.hour;
            }
            if (e->clock_out.day > 0 && e->clock_out.month > 0 && e->clock_out.year > 0 && e->clock_out.hour > 0) {
                day4 = e->clock_out.day;
                month4 = e->clock_out.month;
                year4 = e->clock_out.year;
                hour4 = e->clock_out.hour;
            }
            if (e->performance_rating > 0) {
                performance_rating = e->performance_rating; 
            }


            // write the modified record to the temporary file
            fprintf(fp_out, "%d,%s,%s,%.2f,%.2f,%.2f,%.2f,%.2f,%d-%d-%d,%d-%d-%d,%d-%d-%d-%d,%d-%d-%d-%d,%d\n",
                id, name, position, pay_rate, hours_worked, salary, taxes,
                bonus, day1, month1, year1, day2, month2, year2,
                day3, month3, year3, hour3, day4, month4, year4, hour4, performance_rating);
        }
        else {
            // copy the record as-is
            fprintf(fp_out, "%d,%s,%s,%.2f,%.2f,%.2f,%.2f,%.2f,%d-%d-%d,%d-%d-%d,%d-%d-%d-%d,%d-%d-%d-%d,%d\n",
                id, name, position, pay_rate, hours_worked, salary, taxes,
                bonus, day1, month1, year1, day2, month2, year2,
                day3, month3, year3, hour3, day4, month4, year4, hour4, performance_rating);
        }
    }

    fclose(fp_in);
    fclose(fp_out);

    remove("employees.txt");

    //rename the temporary file to the original file name
    rename("employees.tmp", "employees.txt");
}

void remove_employee(int id) {
    // open the input file
    FILE* fp_in = fopen("employees.txt", "r");
    if (fp_in == NULL) {
        perror("Error opening file");
        return;
    }

    // open a temporary file for output
    FILE* fp_out = fopen("employees.tmp", "w");
    if (fp_out == NULL) {
        perror("Error opening file");
        fclose(fp_in);
        return;
    }

    // read the records from the input file, skip the record for the
    // specified employee, and write the other records to the temporary file
    int eid;
    char name[100];
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
    while (fscanf(fp_in, "%d,%99[^,],%99[^,],%f,%f,%f,%f,%f,%d-%d-%d,%d-%d-%d,%d-%d-%d-%d,%d-%d-%d-%d,%d\n",
        &eid, name, position, &pay_rate, &hours_worked, &salary,
        &taxes, &bonus, &day1, &month1, &year1, &day2, &month2, &year2,
        &day3, &month3, &year3, &hour3, &day4, &month4, &year4, &hour4, &performance_rating) == 23) {
        if (eid != id) {
            // copy the record to the temporary file
            fprintf(fp_out, "%d,%s,%s,%.2f,%.2f,%.2f,%.2f,%.2f,%d-%d-%d,%d-%d-%d,%d-%d-%d-%d,%d-%d-%d-%d,%d\n",
                eid, name, position, pay_rate, hours_worked, salary, taxes,
                bonus, day1, month1, year1, day2, month2, year2,
                day3, month3, year3, hour3, day4, month4, year4, hour4, performance_rating);
        }
    }

    // close the files
    fclose(fp_in);
    fclose(fp_out);

    // delete the original file
    remove("employees.txt");

    // rename the temporary file to the original file name
    rename("employees.tmp", "employees.txt");
}

Employee* search_employee_by_name(char* name) {
    // open the input file
    FILE* fp = fopen("employees.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // search for the employee record
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
        if (strcmp(ename, name) == 0) {
            // allocate memory for the employee
            Employee* e = malloc(sizeof(Employee));
            if (e == NULL) {
                perror("Error allocating memory");
                fclose(fp);
                return NULL;
            }

            // copy the data into the employee struct
            e->id = id;
            e->name = malloc(strlen(name) + 1);
            strcpy(e->name, ename);
            e->position = malloc(strlen(position) + 1);
            strcpy(e->position, position);
            e->pay_rate = pay_rate;
            e->hours_worked = hours_worked;
            e->salary = salary;
            e->taxes = taxes;
            e->bonus = bonus;
            e->start_date.day = day1;
            e->start_date.month = month1;
            e->start_date.year = year1;
            e->end_date.day= day2;
            e->end_date.month = month2;
            e->end_date.year = year2;
            e->clock_in.day = day3;
            e->clock_in.month = month3;
            e->clock_in.year = year3;
            e->clock_in.hour = hour3;
            e->clock_out.day = day4;
            e->clock_out.month = month4;
            e->clock_out.year = year4;
            e->clock_out.hour = hour4;
            e->performance_rating = performance_rating;

            // close the file and return the employee
            fclose(fp);
            return e;
        }
    }

    // employee not found
    fclose(fp);
    return NULL;
}

Employee* search_employee_by_id(int id) {
    // open the input file
    FILE* fp = fopen("employees.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // search for the employee record
    int eid;
    char name[100];
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
        &eid, name, position, &pay_rate, &hours_worked, &salary,
        &taxes, &bonus, &day1, &month1, &year1, &day2, &month2, &year2,
        &day3, &month3, &year3, &hour3, &day4, &month4, &year4, &hour4, &performance_rating) == 23) {
        if (eid == id) {
            // allocate memory for the employee
            Employee* e = malloc(sizeof(Employee));

            if (e == NULL) {
                perror("Error allocating memory");
                fclose(fp);
                return NULL;
            }

            // copy the data into the employee struct
            e->id = id;
            e->name = malloc(strlen(name) + 1);
            strcpy(e->name, name);
            e->position = malloc(strlen(position) + 1);
            strcpy(e->position, position);
            e->pay_rate = pay_rate;
            e->hours_worked = hours_worked;
            e->salary = salary;
            e->taxes = taxes;
            e->bonus = bonus;
            e->start_date.day = day1;
            e->start_date.month = month1;
            e->start_date.year = year1;
            e->end_date.day = day2;
            e->end_date.month = month2;
            e->end_date.year = year2;
            e->clock_in.day = day3;
            e->clock_in.month = month3;
            e->clock_in.year = year3;
            e->clock_in.hour = hour3;
            e->clock_out.day = day4;
            e->clock_out.month = month4;
            e->clock_out.year = year4;
            e->clock_out.hour = hour4;
            e->performance_rating = performance_rating;

            // close the file and return the employee
            fclose(fp);
            return e;
        }
    }

    // employee not found
    fclose(fp);
    return NULL;
}
