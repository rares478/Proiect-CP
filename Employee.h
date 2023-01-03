#ifndef EMPLOYEE_H
#define EMPLOYEE_H

typedef struct {
	int day;
	int month;
	int year;
	int hour;
} Date;

typedef struct {
	int id;
	char* name;
	char* position;
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
} Employee;


#endif