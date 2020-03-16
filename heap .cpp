#include<iostream>
#include<stdlib.h>
using namespace std;
class heap
{
private:
int i,H[50];
void reheapUP(int i);
void reheapDOWN(int i);
public:
int n;
heap()
{
for(i=0;i<50;i++)
{
H[i]=0;
}
}
void insert(int x);
void Delete();
void display();
void search(int val);
};
void heap::reheapUP(int i)
{
while(i>0 && H[i]>H[(i-1)/2])
{
swap(H[i],H[(i-1)/2]);
i=(i-1)/2;
}
}
void heap::reheapDOWN(int i)
{
int k;
while(2*i<n-1 && H[i]<max(H[2*i+1],H[2*i+2]))
{
if(H[2*i+1]>H[2*i+2])
k=2*i+1;
else
k=2*i+2;
swap(H[i],H[k]);
i=k;
}
}

void heap::insert(int x)
{
H[n]=x;
reheapUP(n);
n++;
}
void heap::search(int val)
{
int a=1;
for(int i=0;i<n;i++)
{
if(H[i]==val)
{
cout<<"Element found\n";
a=0;
}
}
if(a==1)
cout<<"Element not found\n";
}
void heap::Delete()
{
cout<<"deleted data is: "<<H[0]<<endl;
int x;
x=H[n-1];
H[0]=x;
reheapDOWN(0);
n--;
}
void heap::display()
{
for(i=0;i<n;i++)
{
cout<<H[i]<<" ";
}
cout<<endl;
}
int main()
{
int  ch,val;
heap h;
cout<<" 1.Insert \n 2.Delete \n 3.Display \n 4.search \n 5.Exit";
while(1)
{
cout<<"\n Enter Your Choice :";
cin>>ch;
switch(ch)
{
case 1:
cout<<"Enter val :";
cin>>val;
h.insert(val);
break;
case 2:
h.Delete();
break;
case 3:
h.display();
break;
case 4:
cout<<"Enter value to be searched :";
cin>>val;
h.search(val);
break;
case 5:
exit(0);
break;
default:
cout<<"Wrong choice\n";
}}}
