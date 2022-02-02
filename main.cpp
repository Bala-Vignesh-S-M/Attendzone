#include<iostream>
#include<vector>
#include<process.h>
#include"admin.h"
#include<stdio.h>
using namespace std;
void admin_menu(Admin &admin1)
{
    int op,id;
    char ch;
    char pword[30];
    do
    {
        cout<<"Enter Admin ID: ";
        cin>>id;
        fflush(stdin);
        cout<<"Enter Admin Password: ";
        gets(pword);
        fflush(stdin);
        if(admin1.check_login(pword)==0)
            cout<<"Wrong Password. Try again";
    }while(admin1.check_login(pword)==0);
    do
    {
        system("cls");
        cout<<"Admin Menu\n1.Create Staff Account\n2.Create Student Account\n";
        cout<<"3.Create Student-Teacher Link\n4.Exit Admin Menu/Login\n";
        cout<<"Enter option: ";
        cin>>op;
        switch(op)
        {
            case 1 :admin1.staff_login_operations(1);
                    break;
            case 3 :admin1.staff_student_operations();
                    break;
            case 2 :admin1.student_login_operations(1);
                    break;
            case 4 :return;
                    break;
            default:cout<<"Enter valid option\n";
        }
        cout<<"Do you want to continue in Admin Menu?(y/n) ";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
}
int main()
{
    Admin admin1;
    cout<<"Creating Admin Login\n";
    admin1.create_login();
    int op1;
    char ch1;
    do
    {
        system("cls");
        cout<<"Welcome to Attendance Management System\n";
        cout<<"New Accounts for Teachers and Students need to be created by Admin\n";
        cout<<"Student-Teacher Links also have to be created by admin\n";
        cout<<"1.Admin Menu/Login\n2.Teacher Menu/Login\n";
        cout<<"3.Student Menu/Login\n4.Exit Program\n";
        cout<<"Enter option: ";
        cin>>op1;
        switch(op1)
        {
            case 1 :admin_menu(admin1);
                    break;
            case 2 :admin1.staff_login_operations(2);
                    break;
            case 3 :admin1.student_login_operations(2);
                    break;
            case 4 :exit(0);
                    break;
            default:cout<<"Enter valid option\n";
        }
        cout<<"Do you want to continue in Main Menu?(y/n) ";
        cin>>ch1;
    }while(ch1=='y'||ch1=='Y');
    return 0;
}
