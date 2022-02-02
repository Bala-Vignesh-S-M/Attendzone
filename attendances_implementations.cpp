#include<bits/stdc++.h>
#include"attendances.h"
using namespace std;
int valid_date(int day,int month,int year)
{
    int check=1;
    if(year <= 3000 && year >=1000)
    {
        if((month==1 || month==3 || month==5|| month==7|| month==8||month==10||month==12) && (day>0 && day<=31))
            check=1;
        else if((month==4 || month==6 || month==9|| month==11) && (day>0 && day<=30))
            check=1;
        else if(month==2)
        {
            if((year%400==0 || (year%100!=0 && year%4==0)) && (day>0 && day<=29))
                check=1;
            else if(day>0 && day<=28)
                check=1;
            else
                check=0;
        }
        else
            check=0;
    }
    else
        check=0;
    return check;
}
void Attendances::set_name(char name[])
{
    strcpy(name_of_teacher,name);
}
void Attendances::set_attendance()
{
    cout<<"Enter details for Attendance:\n";
    do
    {
        cout<<"Enter beginning day: ";
        cin>>beg_day;
        cout<<"Enter beginning month: ";
        cin>>beg_month;
        cout<<"Enter beginning year: ";
        cin>>beg_year;
        if(valid_date(beg_day,beg_month,beg_year)==0)
            cout<<"Invalid date. Enter again\n";
    }while(valid_date(beg_day,beg_month,beg_year)==0);
    do
    {
        cout<<"Enter ending day: ";
        cin>>end_day;
        cout<<"Enter ending month: ";
        cin>>end_month;
        cout<<"Enter ending year: ";
        cin>>end_year;
        if(valid_date(end_day,end_month,end_year)==0)
            cout<<"Invalid Date. Enter again\n";
    }while(valid_date(end_day,end_month,end_year)==0);
    do
    {
        cout<<"Enter total number of working hours: ";
        cin>>total_hours;
        cout<<"Enter number of hours present: ";
        cin>>present_hours;
        if(total_hours<present_hours)
            cout<<"Enter hours again.\n";
    }while(total_hours<present_hours);
}
void Attendances::view_attendance()
{
    cout<<"Name of Teacher: "<<name_of_teacher<<endl;
    cout<<"Beginning Day: "<<beg_day<<'/'<<beg_month<<'/'<<beg_year<<endl;
    cout<<"Ending Day: "<<end_day<<'/'<<end_month<<'/'<<end_year<<endl;
    cout<<"Hours Present:  "<<present_hours<<endl;
    cout<<"Total Number of Hours: "<<total_hours<<endl;
}
Attendances::Attendances(Attendances& a)
{
    this->beg_day=a.beg_day;
    this->beg_month=a.beg_month;
    this->beg_year=a.beg_year;
    this->end_day=a.end_day;
    this->end_month=a.end_month;
    this->end_year=a.end_year;
    strcpy(this->name_of_teacher,a.name_of_teacher);
    this->present_hours=a.present_hours;
    this->total_hours=a.total_hours;
}
char *Attendances::name_teacher()
{
    return name_of_teacher;
}
Attendances::Attendances()
{
    beg_day=beg_month=beg_year=end_day=end_month=end_year=present_hours=total_hours=0;
    strcpy(name_of_teacher,"\0");
}
