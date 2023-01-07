#include "Employee_front.h"
#include "Employee_database.h"
#include "Employee_performance.h"
#include "Employee_attendance.h"
#include "Employee_pay.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

void add_employee_front()
{
    system("cls");
    printf("\n");
    printf("Insert Id:");
    int id;
    scanf("%d", &id);

    printf("Insert Name:");
    char name[30];
    scanf("%s", name);

    printf("Insert Position:");
    char position[30];
    scanf("%s", position);

    printf("Insert Pay Rate:");
    float pay_rate;
    scanf("%f", &pay_rate);

    Employee* e = malloc(sizeof(Employee));;

    Date tomorrow;
    Date end_date = (Date){ 0,0,0 };
    Date check_in = (Date){ 0,0,0,0 };
    Date check_out = (Date){ 0,0,0,0 };

    time_t t = time(NULL);
    struct tm* tm = localtime(&t);

    tomorrow.year = tm->tm_year + 1900;
    tomorrow.month = tm->tm_mon + 1;
    tomorrow.day = tm->tm_mday + 1;

    e->id = id;
    e->name = name;
    e->position = position;
    e->pay_rate = pay_rate;
    e->hours_worked = 0.00;
    e->salary = 0.00;
    e->taxes = 0.00;
    e->bonus = 0.00;
    e->start_date = tomorrow;
    e->end_date = end_date;
    e->clock_in = check_in;
    e->clock_out = check_out;
    e->performance_rating = 0;

    add_employee(e);

    show_main_admin();
}

void show_main_admin()
{
    int choice;
    system("cls");
    printf("Hello, what do you wish to do\n");
    printf("1. Add another employee\n");
    printf("2. Remove an employee\n");
    printf("3. Modify an existing employee\n");
    printf("4. Show all the employees\n");
    printf("5. Show all employees that are on vacation\n");
    printf("6. Search for an existing employee\n");
    printf("7. Exit\n");
    printf("Your choice is:");
    scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_employee_front();
            break;
        case 2:
            printf("Please enter an ID:");
            int id;
            scanf("%d", &id);
            remove_employee(id);
            break;
        case 3:
            system("cls");
            printf("Which employee do you wish to modify\n");
            printf("Your option:");
            char option[30];
            scanf("%s", option);

            Employee* e;
            if (isdigit(option[0]))
            {
                int id = atoi(option);
                e = search_employee_by_id(id);
            }
            else
            {
                e = search_employee_by_name(option);
            }
            modify_employee_front(e);
            break;
        case 4:
            print_pay();
            break;
        case 5:
            show_employees_on_vacation();
            break;
        case 6:
            printf("Insert name or ID:");
            char employee[30];
            scanf("%s", employee);
            Employee* es = {0};

            if (isdigit(employee[0]))
            {
                int id = atoi(employee);
                e = search_employee_by_id(id);
            }
            else
            {
                e = search_employee_by_name(employee);
            }

            print_info_front(es);
            break;
        default:
            show_main_admin();
            break;
        }
}

void show_main()
{
    system("cls");
    printf("Welcome to the Employee Management\n Are you an employee or an administrator\n");
    printf("1. Administrator\n");
    printf("2. Employee\n");
    printf("Your choice: ");

    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        system("cls");
        printf("Enter the password: ");
        char password[20];
        scanf("%s", password);
        if (strcmp(password, admin_password) == 0)
        {
            show_main_admin();
            break;
        }
        else
        {
            printf("Wrong password. Retry ?\n");
            printf("1. Yes\n");
            printf("2. No\n");
            printf("Your choice:");
            int yesno;
            scanf("%d", &yesno);

            switch (yesno)
            {
            case 1:
                system("cls");
                printf("Enter the password: ");
                char password1[20];
                scanf("%s", password);
                if (strcmp(password1, admin_password) == 0)
                {
                    show_main_admin();
                    break;
                }
                else
                {
                    printf("Wrong password. Going back to main menu");
                    show_main(); 
                    break;
                }
            case 2:
                show_main();
                break;
            }
        }
    case 2:
        check_employee();
        break;
    }
}

void check_employee()
{
    system("cls");
    printf("Welcome to work\n Please input your ID :");
    int id;
    scanf("%d", &id);
    Employee* e = search_employee_by_id(id);
    show_main_employee(e);
}

void show_main_employee(Employee* e)
{
    system("cls");
    printf("1. Check in\n");
    printf("2. Check out\n");
    printf("3. Check this month's salary\n");
    printf("4. Check if you have a bonus\n");
    printf("5. Check how much taxes you pay\n");
    printf("6. Request vacation\n");
    printf("7. Cancel your current vacation\n");
    printf("Your choice:");
    int choice;
    scanf("%d", &choice);
    
    switch (choice)
    {
    case 1:
        clock_in(e);
        break;
    case 2:
        clock_out(e);
        break;
    case 3:
        printf("This month's salary after taxes will be: ");
        int salary = (int)calculate_salary(e);
        printf("%d", salary);
        break;
    case 4:
        printf("This month's bonus based on your salary and years of service will be: ");
        int bonus = (int)calculate_bonus(e);
        printf("%d", bonus);
        break;
    case 5:
        printf("The taxes you'll have to pay amount to: ");
        int taxes = (int)calculate_taxes(e);
        printf("%d", taxes);
        break;
    case 6:
        printf("Enter the date you want to come back to\n");

        Date tomorrow;
        Date end_date;
        time_t t = time(NULL);
        struct tm* tm = localtime(&t);

        tomorrow.year = tm->tm_year + 1900;
        tomorrow.month = tm->tm_mon + 1;
        tomorrow.day = tm->tm_mday + 1;


        printf("Day:");
        scanf("%d", &end_date.day);
        printf("Month: ");
        scanf("%d", &end_date.month);
        printf("Year: ");
        scanf("%d", &end_date.year);
        request_leave(e, tomorrow, end_date);
        break;
    case 7:
        printf("Do you want to cancel your current vacation ?\n");
        printf("1. Yes\n");
        printf("2. No\n");
        printf("Your choice: ");
        int end_vacation;
        scanf("%d", &end_vacation);
        if (end_vacation)
            cancel_leave(e);
        break;
    }

    int continueda;
    printf("Do you wish to do something else ?\n");
    printf("1. Yes\n");
    printf("2. No\n");
    printf("Your choice: ");
    scanf("%d", &continueda);
    if (continueda == 1)
    {
        fflush(stdin);
        show_main_employee(e);
    }
    else 
        exit;
}

void show_employees_on_vacation()
{
    system("cls");
    FILE* fp = fopen("employees.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    Date today;

    time_t t = time(NULL);
    struct tm* tm = localtime(&t);
    today.year = tm->tm_year + 1900;
    today.month = tm->tm_mon + 1;
    today.day = tm->tm_mday;

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

    printf("ID  Name            Position            Date Left           Date Coming Back      \n");
    printf("==================================================================================\n");

    while (fscanf(fp, "%d,%99[^,],%99[^,],%f,%f,%f,%f,%f,%d-%d-%d,%d-%d-%d,%d-%d-%d-%d,%d-%d-%d-%d,%d\n",
        &id, ename, position, &pay_rate, &hours_worked, &salary,
        &taxes, &bonus, &start_date.day, &start_date.month, &start_date.year,
        &end_date.day, &end_date.month, &end_date.year,
        &clock_in.day, &clock_in.month, &clock_in.year, &clock_in.hour,
        &clock_out.day, &clock_out.month, &clock_out.year, &clock_out.hour,
        &performance_rating) == 23) {

        if (end_date.year == today.year && end_date.month >= today.month && end_date.day <= today.day)
        {
            printf("%-4d%-16s%-20s%", id, ename, position);
            printf("%d-%d-%d            %d-%d-%d\n", start_date.day, start_date.month, start_date.year, end_date.day, end_date.month, end_date.year);
        }
        else if(end_date.year > today.year )
        {
            printf("%-4d%-16s%-20s%", id, ename, position);
            printf("%d-%d-%d            %d-%d-%d\n", start_date.day, start_date.month, start_date.year, end_date.day, end_date.month, end_date.year);
        }

    }
    fclose(fp);

    printf("\n\n\n");
    printf("1. Go back to main menu\n");
    printf("2. Exit\n");
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        show_main_admin();
        break;
    case 2:
        break;
    default:
        show_main_admin();
        break;
    }
}

void modify_employee_front(Employee* e)
{
    system("cls");
    printf("ID  Name            Position          Pay Rate   Hours Worked   Salary Paid   Taxes Paid   Bonus   \n");
    printf("===================================================================================================\n");
    printf("%-4d%-16s%-20s%-12.2f%-17.2f%-10.2f%-11.2f%-8.2f\n\n\n",
        e->id, e->name, e->position, e->pay_rate, e->hours_worked, e->salary, e->taxes, e->bonus);
    printf("What do you wish to modify\n");
    printf("1. Name\n");
    printf("2. Position\n");
    printf("3. Pay Rate\n");
    printf("4. Bonus\n");
    printf("5. Return\n");
    printf("Your choice:");
    int choice;
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        printf("Insert new Name:");
        char new_name[30];
        scanf("%s", new_name);
        e->name = new_name;
        modify_employee(e);
        break;
    case 2:
        printf("Insert new Position:");
        char new_position[30];
        scanf("%s", new_position);
        strcpy(e->position, new_position);
        modify_employee(e);
        break;
    case 3:
        printf("Insert new Pay rate:");
        float new_pay;
        scanf("%f", &new_pay);
        e->pay_rate = new_pay;
        modify_employee(e);
        break;
    case 4:
        printf("Insert new Bonus:");
        float new_bonus;
        scanf("%f", &new_bonus);
        e->bonus = new_bonus;
        modify_employee(e);
        break;
    case 5:
        show_main_admin();
        break;
    }
    fflush(stdin);
    modify_employee_front(e);

}

void print_info_front(Employee* e)
{
    system("cls");
    printf("ID  Name            Position          Pay Rate   Hours Worked   Salary Paid   Taxes Paid   Bonus   \n");
    printf("===================================================================================================\n");
    printf("%-4d%-16s%-20s%-12.2f%-17.2f%-12.2f%-10.2f%-8.2f\n\n\n",
        e->id, e->name, e->position, e->pay_rate, e->hours_worked, e->salary, e->taxes, e->bonus);
    printf("More options \n");
    printf("1. Pay employee\n");
    printf("2. Give bonus\n");
    printf("3. Give raise\n");
    printf("4. Return to main menu\n");
    printf("Your option:");
    int option;
    scanf("%d", &option);

    switch (option) {
    case 1:
        pay_employee(e);
        break;
    case 2:
        printf("Enter the bonus amount: ");
        int bonus;
        scanf("%d", &bonus);
        give_bonus(e, bonus);
        e->bonus = e->bonus + bonus;
        break;
    case 3:
        printf("Enter the raise amount: ");
        int raise;
        scanf("%d", &raise);
        give_raise(e, raise);
        e->pay_rate = e->pay_rate + raise;
        break;
    case 4:
        show_main_admin();
        break;
    }
    fflush(stdin);
    print_info_front(e);
}