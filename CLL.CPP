#include<stdio.h>
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
class sll
{
struct list
{
int data;
struct list *next;
}*head;
public:
typedef struct list node;
sll();
void create();
void insert();
void display();
int deletepos();
void insertatbeg();
void insertatmid();
void insertatend();
void search();
};
sll::sll()
{
head=NULL;
}

void main()
{
int ch;
clrscr();
sll obj;

do
{
cout<<"\n\tMAIN MENU\n";
cout<<"\t\t1.Create\n\t\t2.Display\n\t\t3.Insert\n\t\t4.Deletepos\n\t\t5.Search\n\t\t6.Exit\n";
cout<<"\n\tenter ur choice";
cin>>ch;
switch(ch)
{
case 1: obj.create();
	break;
case 2: obj.display();
	break;
case 3: obj.insert();
	break;
case 4: obj.deletepos();
	break;
case 5: obj.search();
	break;

case 6:
	exit(0);
}

}while(ch>0&&ch<8);
}
void sll::create(){
node *temp,*p;
temp=new node;
cout<<"enter the element";
cin>>temp->data;
if(head==NULL)
{
temp->next=temp;
head=temp;
}
else
{
p=head;
while(p->next!=head)
p=p->next;
temp->next=head;
p->next=temp;
}

}
void sll::display()
{
node *q;
if(head==NULL)
cout<<"\nList is Empty\n";
q=head;
if(q==head)
cout<<q->data<<"->";
q=q->next;
while(q!=head)
{
cout<<q->data<<"->";
q=q->next;
}}

void sll::search()
{
int found=0,key;
node *p;
p=head;
cout<<"Enter the element you want to found";
cin>>key;
if(p==NULL)
{
cout<<"the List is empty\n";
 }
while((p->next!=head) && (found==0))
{
if(p->data==key)
found=1;
else
p=p->next;
}
if(found==1)
{
cout<<"\n Search element is found";
}
else
{
cout<<"\n Search element is not found";
 }
}

void sll:: insert()
{
int ch;
do
{
cout<<"\n\t\t\t1.Inserat Front\n\t\t\t2.Insertat Middle\n\t\t\t3.Insert at End\n\t\t\t4.Display\n\t\t\t5.Exit\n";
cout<<"enter ur choice";
cin>>ch;
switch(ch)
{
case 1: insertatbeg();
	break;
case 2: insertatmid();
	break;
case 3: insertatend();
	break;
case 4: display();
	break;

}
}while(ch>0&&ch<5);
}

void sll:: insertatbeg()
{
node *temp,*p;
temp=new node;
cout<<"enter the inserted elemet";
cin>>temp->data;
temp->next=NULL;
p=head;
while(p->next!=head)
p=p->next;
p->next=temp;
temp->next=head;
head=temp;
}
void sll::insertatmid()
{
node *temp,*p;
int key;
temp=new node;
cout<<"enter the element";
cin>>temp->data;
if(head==NULL)
{
head=temp;
}
else
{

cout<<"enter the key element";
cin>>key;
p=head;

do
{
if(p->data==key)
{
temp->next=p->next;
p->next=temp;
cout<< "\n The Node is inserted";
return;
}
else
p=p->next;
}while(p!=head);
}}

void sll:: insertatend()
{
node *temp,*p;
temp=new node;
cout<<"\nenter element";
cin>>temp->data;
if(head==NULL)
{
temp->next=head;
head=temp;
}
else
{
p=head;
while(p->next!=head)
p=p->next;
temp->next=head;
p->next=temp;
}
}


int sll:: deletepos()
{
node *p,*p1;
int key;
cout<<"\nenter the element which is to be deleted:";
cin>>key;
p=head;

if(p->data==key)
{
p1=p->next;
	if(p1==p)
	{
	   p=NULL;
	   head=p;
	   cout<<"\nThe node is deleted";
	}
	else
	{
	while(p->next!=head)
	p=p->next;
	p->next=p1;
	head=p1;
	cout<<"\n The node is deleted";
	}
}
else
{
   while(p->next!=head)
   {
   if((p->next)->data==key)
   {
    p1=p->next;
    p->next=p1->next;
    p1->next=NULL;
    delete p1;
    cout<<"\nThe node is deleted";
    }
    else
    p=p->next;
    }
}    }

