/***************************
File: sort_emp.c
Name: Hrishikesh Adigal
email: hadigal@sdsu.edu
****************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFF 60;

typedef unsigned int ui;

typedef struct
{
  int day;
  int mon;
  int yr;
}date;

typedef struct
{
  char name[40];
  int age;
  date doj;
  date dob;
  int id;
}emp_data;

void sort_name(emp_data *ep, int num)
{
  int flag;
  for(int i = 0; i < num; i++)
  {
    flag = 0;
    for(int j = 0;j < num - 1 - i; j++)
    {
      if(strcmp(ep[j+1].name,ep[j].name) < 1)
      {
        emp_data temp;
        temp = ep[j];
        ep[j] = ep[j+1];
        ep[j+1] = temp;
        flag++;
      }
    }
    if(flag ==0)
    {
      break;
    }
  }
}

void sort_empId(emp_data *ep, int num)
{
  //char *temp;
  emp_data temp;
  int min;
  for(int i = 0; i < num -1; i++)
  {
    min = i;
    for(int j = i + 1; j < num; j++)
    {
      if(ep[min].id > ep[j].id)
      {
        min = j;
      }
      if(i != min)
      {
        //emp_data temp;
        temp = ep[i];
        ep[i] = ep[min];
        ep[min] = temp;
      }
    }
  }
}

void swap(emp_data *ep, int i, int j)
{
  emp_data temp;
  temp = ep[i];
  ep[i] = ep[j+1];
  ep[j+1] = temp;
}

void sort_doj(emp_data *ep, int num)
{
  emp_data temp;
  int flag;
  for(int i = 0; i < num -1; i++)
  {
    flag  = 0;
    for(int j = i; j < num - 1 - i; j++)
    {
      if(ep[j].doj.yr == ep[j+1].doj.yr)
      {
        if(ep[j].doj.mon == ep[j+1].doj.mon)
        {
          if(ep[j].doj.day > ep[j+1].doj.day)
          {
            swap(ep,j,j+1);
            flag++;
          }
        }
        else if(ep[j].doj.mon > ep[j+1].doj.mon)
        {
          swap(ep,j,j+1);
          flag++;
        }
      }
      else if(ep[j].doj.yr > ep[j+1].doj.yr)
      {
        swap(ep,j,j+1);
        flag++;
      }
    }
    if(flag == 0)
    {
      break;
    }
  }
}

void sort_age(emp_data *ep, int num)
{
  int k,i,j;
  for(i = 1; i < num; i++)
  {
    k = ep[i].age;
    emp_data temp = ep[i];
    for(j = i - 1; j >=0 && k < ep[j].age; j--)
    {
      ep[j + 1] = ep[j];
    }
    ep[j + 1]  = temp;
  }
}

void print_data(emp_data *ep, int num)
{
  printf("\n##############################\n");
  for(int i = 0; i < num; i++)
  {
    printf("\n**** EMP[%d] ****\n",i);
    printf("Name:%s\n",ep[i].name);
    printf("Age:%d\n",ep[i].age);
    printf("ID:%d\n",ep[i].id);
    printf("DoJ:%d/%d/%d\n",ep[i].doj.mon,ep[i].doj.day,ep[i].doj.yr);
    printf("DoB:%d/%d/%d\n",ep[i].dob.mon,ep[i].dob.day,ep[i].dob.yr);
  }
  printf("\n##############################\n");
}

int main(void)
{
  ui num;
  size_t max = 40;
  printf("Enter number of emps.:\n");
  scanf("%u",&num);
  emp_data *emp;
  emp = (emp_data *)calloc(num,sizeof(emp_data));
  printf("\n--------- Enter emp. data ---------\n");
  for(int i = 0; i < num; i++)
  {
    printf("\n#### Emp #[%d] ####\n",i);
    printf("\nEnter Name:");
    scanf("%*1[\n]%[^\n]s",emp[i].name);

    printf("\nEnter Age:");
    scanf("%d",&emp[i].age);
    printf("\nEnter the doj:");
    scanf("%d%*1[/]%d%*1[/]%d",&emp[i].doj.mon,&emp[i].doj.day,&emp[i].doj.yr);
    printf("\nEnter the dob:");
    scanf("%d%*1[/]%d%*1[/]%d",&emp[i].dob.mon,&emp[i].dob.day,&emp[i].dob.yr);
    printf("\nEnter emp. ID:");
    scanf("%d",&emp[i].id);
  }

  label:
    printf("\n******** Enter one of the below sorting options ********\n");
    printf("1. Sort by Name\n");
    printf("2. Sort by Age\n");
    printf("3. Sort by ID\n");
    printf("4. Sort by DoJ\n");
    printf("5. EXIT\n***************************************************\n");

    int ip;
    scanf("%d",&ip);

    switch(ip)
    {
      case 1:
        sort_name(emp,num);
        print_data(emp,num);
        goto label;
      case 2:
        sort_age(emp,num);
        print_data(emp,num);
        goto label;
      case 3:
        sort_empId(emp,num);
        print_data(emp,num);
        goto label;
      case 4:
        sort_doj(emp,num);
        print_data(emp,num);
        goto label;
      case 5:
        printf("EXITING... Thank you\n");
        if(emp)
        {
          free(emp);
        }
        return EXIT_SUCCESS;
    }
}
