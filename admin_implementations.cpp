#include<bits/stdc++.h>
#include"admin.h"
#include"staff.h"
using namespace std;
void Admin::create_login()
{
    cout<<"Enter Employee Number of Admin: ";
    cin>>employee_number;
    fflush(stdin);
    cout<<"Enter Password of Admin: ";
    gets(pword);
    fflush(stdin);
}
int Admin::check_login(char pstring[])
{
    if(strcmp(pstring,pword)==0)
        return 1;
    else
        return 0;
}
void Admin::staff_login_operations(int op=1)
{
    if(op==1)
    {
        staff *teacher=new staff();
        teacher->create_login();
        teachers.push_back(teacher);
        cout<<"Teacher Account Created\n";
    }
    else
    {
        int id,i,p1=0;
        char pword[30],ch;
        if(int(teachers.size())==0)
        {
            cout<<"No Teacher Accounts available\n";
            return;
        }
        else
        {
            system("cls");
            cout<<"Teacher Login\n";
        }
        do
        {
            cout<<"Enter Teacher's Employee ID: ";
            cin>>id;
            fflush(stdin);
            for(i=0;i<int(teachers.size());i++)
            {
                if(id==teachers[i]->get_emp_no())
                {
                    p1=1;
                    do
                    {
                        cout<<"Enter Teacher's Password: ";
                        gets(pword);
                        fflush(stdin);
                        if(teachers[i]->check_login(pword)==0)
                            cout<<"Wrong Password. Try Again\n";
                    }while(teachers[i]->check_login(pword)==0);
                    break;
                }
            }
            if(p1==0)
                cout<<"Enter valid ID\n";
        }while(p1==0);
        do
        {
            system("cls");
            cout<<"Teacher Menu\n1.Enter Attendance\n2.Exit\n";
            cout<<"Enter option: ";
            cin>>p1;
            if(p1==1)
                teachers[i]->student_operations();
            if(p1==2)
                return;
            cout<<"Do you want to continue in Teacher Menu?(y/n) ";
            cin>>ch;
        }while(ch=='y'||ch=='Y');
    }
}
void Admin::student_login_operations(int op=1)
{
    if(op==1)
    {
        Student *student=new Student();
        student->create_login();
        students.push_back(student);
        cout<<"Student Account Created\n";
    }
    else
    {
        int rno,i,p1=0;
        char pword[30],ch;
        if(students.size()==0)
        {
            cout<<"No Student Accounts Available\n";
            return;
        }
        else
        {
            system("cls");
            cout<<"Student Login\n";
        }
        do
        {
            cout<<"Enter Roll Number: ";
            cin>>rno;
            fflush(stdin);
            for(i=0;i<int(students.size());i++)
            {
                if(rno==students[i]->get_rollno())
                {
                    p1=1;
                    cout<<"Enter Student's Password: ";
                    gets(pword);
                    fflush(stdin);
                    if(students[i]->check_login(pword)==0)
                        cout<<"Wrong Password. Try Again\n";
                    break;
                }
            }
            if(p1==0)
                cout<<"Enter valid Roll Number\n";
        }while((students[i]->check_login(pword)==0)||(p1==0));
        do
        {
            system("cls");
            cout<<"Student Menu\n1.View Attendance\n2.Exit\n";
            cout<<"Enter option: ";
            cin>>p1;
            if(p1==1)
                students[i]->view_attendence();
            if(p1==2)
                return;
            cout<<"Do you want to continue in Student Menu?(y/n) ";
            cin>>ch;
        }while(ch=='y'||ch=='Y');
    }
}
void Admin::staff_student_operations()
{
    int eno,rno,i,j,c1,c2;
    cout<<"Enter Employee Number of Teacher: ";
    cin>>eno;
    for(i=0;i<int(teachers.size());i++)
    {
        if(teachers[i]->get_emp_no()==eno)
        {
            cout<<"Enter Roll Number of Student: ";
            cin>>rno;
            c1=1;
            for(j=0;j<int(students.size());j++)
            {
                if(students[j]->get_rollno()==rno)
                {
                    cout<<"Linked Teacher and Student\n";
                    teachers[i]->add_student(students[j]);
                    c2=1;
                }
            }
            if(c2==0)
                cout<<"Invalid Roll Number. Try Again.\n";
        }
    }
    if(c1==0)
        cout<<"Invalid Employee Number.Try Again.\n";
}
