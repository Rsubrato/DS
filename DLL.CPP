#include<stdio.h>
#include<iostream.h>
//S#include<conio.h>
#include<stdlib.h>
//using namespace std;
class sll
{
struct list
{
int data;
struct list *next;
struct list *prev;
}*head;
public:
typedef struct list node;
sll();
void create();
void insert();
void display();
int count();
void deletepos();
void insertatbeg();
void insertatmid();
void insertatend();
void search();
};
sll::sll()
{
head=NULL;
}

int main()
{
int ch,k,c;
//clrscr();
sll obj;
//while(1)
do
{
cout<<"\n\tMAIN MENU\n";
cout<<"\t\t1.create\n\t\t2.display\n\t\t3.insert\n\t\t4.deletepos\n\t\t5.count\n\t\t6.Search\n\t\t7.exit\n";
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
case 5: c=obj.count();
	cout<<"no of elements in the list are:"<<c;
	break;
case 6: obj.search();
	break;

case 7:
	exit(0);
}


//getch();
}while(ch>0&&ch<8);
}
void sll::create(){
node *temp,*p;
temp=new node;
cout<<"enter the element";
cin>>temp->data;
if(head==NULL)
{
temp->next=head;
temp->prev=head;
head=temp;
}
else
{
p=head;
while(p->next!=NULL)
p=p->next;
temp->next=NULL;
temp->prev=p;
p->next=temp;
}

}
void sll::display()
{
int d;
node *q;
q=head;
cout<<"\nelements in the list are\n";
while(q!=NULL)
{

cout<<"->"<< q->data;
q=q->next;
}
}
int sll:: count()
{
node *p;
int c=0;
p=head;
while(p!=NULL)
{
p=p->next;
c++;
}
return(c);
}
void sll::search()
{

int f=0,k,v,c;
node *p;
p=head;
c=0;
cout<<"Enter the element you want to found";
cin>>k;
while(p!=NULL)
{
c++;
if(p->data==k)
{
f=1;

cout<<"Element found at "<<c;

}

p=p->next;
}

if(f==0)
{
cout<<"Element not found";
}


}

void sll:: insert()
{
int ch;
do
{
cout<<"\n\t\t\t1.inseratbeg\n\t\t\t2.insertatmid\n\t\t\t3.insertatend\n\t\t\t4.display\n\t\t\t5.exit";
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
node *temp;
temp=new node;
cout<<"enter the inserted elemet";
cin>>temp->data;
temp->next=head;
temp->prev=NULL;
head->prev=head;
head=temp;
}
void sll::insertatmid()
{
node *temp,*p;
int key;
temp=new node;
cout<<"enter the element";
cin>>temp->data;
cout<<"enter the key element";
cin>>key;
p=head;
while(p!=NULL)
{
if(p->data==key)
{
p->next->prev=temp;
temp->next=p->next;
p->next=temp;
temp->prev=p;

}
p=p->next;
}
}
void sll:: insertatend()
{
node *temp,*p;
temp=new node;
cout<<"\nenter element";
cin>>temp->data;
if(head==NULL)
{
temp->next=head;
temp->prev=head;
head=temp;
}
else
{
p=head;
while(p->next!=NULL)
p=p->next;
temp->next=NULL;
temp->prev=p;
p->next=temp;
}
}
void sll:: deletepos()
{
node *p,*t,*q;
int pos,i,k;
cout<<"\nenter the element you want to delet";
cin>>pos;
if(head!=NULL)
{
	if(pos==1)
	{
		t=head;
		head=head->next;
		head->prev=NULL;
		cout<<t->data<<" Is deleted sucesfully\n";
		delete(t);
	}
	else
	{
		i=1;
		p=head;
		q=head;
		while(i<pos)
		{
			q=p;
			p=p->next;
			i++;
		}

		t=p;
		q->next=p->next;
		p->next->prev=q;
		cout<<t->data<<" Is deleted sucesfully\n";
		free(t);


	}
}
else
cout<<"\n\tLIST Is empty";
}

