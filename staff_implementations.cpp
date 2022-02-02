	#include<bits/stdc++.h>
#include"staff.h"
using namespace std;
int valid_str(char toCheck[])
{
    int count=0;
    int len=strlen(toCheck);
    for (int i=0;i<len;i++)
    {
        if ((toCheck[i]>=65&&toCheck[i]<=90)||(toCheck[i]>=97&&toCheck[i]<=122))
        {
           count++;
           continue;
        }
        else
        {
            return 0;
            break;
        }
    }
    if(count==len)
        return 1;
    return 0;
}
void staff::create_login()
{
    cout<<"Enter Employee Number of Teacher: ";
    cin>>employee_no;
    fflush(stdin);
    do
    {
        cout<<"Enter Name of Teacher: ";
        gets(name);
        fflush(stdin);
        if(valid_str(name)==0)
            cout<<"Enter a valid name\n";
    }while(valid_str(name)==0);
    do
    {
        cout<<"Enter Department of Teacher: ";
        gets(department);
        fflush(stdin);
        if(valid_str(department)==0)
            cout<<"Enter a valid Department Name\n";
    }while(valid_str(department)==0);
    cout<<"Enter Password for Teacher: ";
    gets(pword);
    fflush(stdin);
}
int staff::check_login(char p[])
{
    if(strcmp(p,pword)==0)
        return 1;
    else
        return 0;
}
void staff::student_operations()
{
    int rno,i,k,p1=0,p2=0;
    if(students.size()==0)
    {
        cout<<"No Students have been Linked\n";
        return;
    }
    cout<<"Enter Student Roll No: ";
    cin>>rno;
    fflush(stdin);
    for(i=0;i<int(students.size());i++)
    {
        if(students[i]->get_rollno()==rno)
        {
            p1=1;
            vector<Attendances *> &v=students[i]->attendance;
            for(k=0;k<int(v.size());k++)
            {
                if(strcmp(v[k]->name_teacher(),name)==0)
                {
                    v[k]->set_attendance();
                    p2=1;
                }
            }
            if(p2==0)
            {
                Attendances *att=new Attendances();
                att->set_name(name);
                att->set_attendance();
                v.push_back(att);
            }
        }
    }
    if(p1==0)
    {
        cout<<"Invalid Roll Number. Please try again!";
    }
}
int staff::get_emp_no()
{
    return employee_no;
}
void staff::add_student(Student *stu)
{
    students.push_back(stu);
}
staff::staff()
{
    strcpy(this->department,"\0");
    strcpy(this->name,"\0");
    strcpy(this->pword,"\0");
    employee_no=0;
}
