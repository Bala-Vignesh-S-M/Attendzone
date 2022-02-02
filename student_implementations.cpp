#include<bits/stdc++.h>
#include"student.h"
using namespace std;
int valid_str(char toCheck[]);
void Student::create_login()
{
    cout<<"Enter Roll Number of Student: ";
    cin>>rollno;
    fflush(stdin);
    do
    {
        cout<<"Enter Name of Student: ";
        gets(name);
        fflush(stdin);
        if(valid_str(name)==0)
            cout<<"Enter valid name\n";
    }while(valid_str(name)==0);
    cout<<"Enter Password for Student: ";
    gets(pword);
    fflush(stdin);
}
int Student::check_login(char p[])
{
    if(strcmp(p,pword)==0)
        return 1;
    else
        return 0;
}
void Student::view_attendence()
{
    cout<<"Name: "<<name<<endl;
    cout<<"Roll Number: "<<rollno<<endl;
    cout<<"Attendances: "<<endl;
    if(attendance.size()>0)
    {
        for(int i=0;i<int(attendance.size());i++)
        {
            attendance[i]->view_attendance();
            cout<<endl;
        }
    }
    else
        cout<<"No Attendance Details available.\n";
}
int Student::get_rollno()
{
    return rollno;
}
Student::Student()
{
    strcpy(this->name,"\0");
    strcpy(this->pword,"\0");
    rollno=0;
}
