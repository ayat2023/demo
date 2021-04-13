#include<stdio.h>
#include<stdlib.h>
struct birth
{
    int year;
    int month;
    int day;
};

struct student
{
    char name[100];
    int id;
   struct birth date;
    int score;
};

struct node
{ struct student stu ;
struct node *next;
};

struct node *head=NULL,*tail=NULL,*temp=NULL;

void insert_beg(struct student st)
{temp=(struct node *)malloc(sizeof(struct node));
 temp->stu=st;
 if(head==NULL)
 {temp->next=NULL;
 head=tail=temp;
 }
 else
 {temp->next=head;
  head=temp;
 }
 }



void insert_end(struct student st)
{temp=(struct node *)malloc(sizeof(struct node));
 temp->stu=st;
 if(head==NULL)
 {temp->next=NULL;
 head=tail=temp;
 }
 else
 {temp->next=NULL;
 tail->next=temp;
 tail=temp;

 }
}


void insert_mid(int index,struct student st)
{temp=(struct node *)malloc(sizeof(struct node));
  temp->stu=st;
  if(index==0)
  insert_beg(st);
  else{ int i=0;
  struct node *temp2=head;
  for(i;i<index-1;i++)
      temp2=temp2->next;
  if(temp2==tail)
  insert_end(st);
  else{
  temp->next=temp2->next;
  temp2->next=temp;
}}}


void print() //print all the content of the linked list
{ struct node *temp2=head;
int i=0;
while(temp2!=NULL)
{printf("name of student is %s\n",temp2->stu.name);
 printf("id of student is %d\n",temp2->stu.id);
 printf("birth date of student is %d",temp2->stu.date.day);
 printf("/%d",temp2->stu.date.month);
 printf("/%d\n",temp2->stu.date.year);
 printf("score of student is %d\n\n",temp2->stu.score);

 temp2=temp2->next;
 }
}


int main ()
{
struct student st1={.name="aya tarek"};
st1.date.day=13;
st1.date.month=11;
st1.date.year=2000;
st1.id=55;
st1.score=3;

struct student st2={.name="ziad sayed"};
st2.date.day=19;
st2.date.month=11;
st2.date.year=1999;
st2.id=65;
st2.score=4;

struct student st3={.name="nancy khaled"};
st3.date.day=20;
st3.date.month=12;
st3.date.year=1999;
st3.id=99;
st3.score=5;

insert_beg(st1);
insert_end(st3);
insert_mid(0,st2);

print();
}
