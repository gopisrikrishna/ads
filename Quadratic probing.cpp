#include <iostream>
#include<stdlib.h>
using namespace std;
#define TABLE_SIZE 10
int h[TABLE_SIZE]={NULL};
void insert()
{
int key,index,i,flag=0,hkey;
cout<<"\nenter a value to insert into hash table\n";
cin>>key;
hkey=key%TABLE_SIZE;
for(i=0;i<TABLE_SIZE;i++)
{
index=(hkey+i*i)%TABLE_SIZE;
if(h[index] == NULL)
{
h[index]=key;
break;
}
}
if(i == TABLE_SIZE)
cout<<"\nelement cannot be inserted\n";
}
void search()
{
int key,index,i,flag=0,hkey;
cout<<"\nenter search element\n";
cin>>key;
hkey=key%TABLE_SIZE;
for(i=0;i<TABLE_SIZE; i++)
{
index=(hkey+i)%TABLE_SIZE;
if(h[index]==key)
{
cout<<"value is found at index "<<index;
break;
}
}
if(i == TABLE_SIZE)
cout<<"\n value is not found\n";
}
void display()
{
int i;
cout<<"\nelements in the hash table are \n";
for(i=0;i< TABLE_SIZE; i++)
cout<<"\nat index"<<i<<"\t value = "<<h[i];
}
main()
{
int opt,i;
while(1)
{
cout<<"\nPress 1. Insert\t 2. Display \t3. Search \t4.Exit \n";
cin>>opt;
switch(opt)
{
case 1:
insert();
break;
case 2:
display();
break;
case 3:
search();
break;
case 4:exit(0);
}
}
}

