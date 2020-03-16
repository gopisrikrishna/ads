#include<iostream>
using namespace std;
struct node
{
    int key;
    node *next;
};
class chaining
{
    private:
        node *A[50];
        int i,j,n,m,h,e;
    public:
        chaining()
        {
            cout<<"enter the hash table size";
            cin>>m;
            for(i=0;i<=m;i++)
            {
                node *c= new node;
                c->key=-1;
                c->next=NULL;
                A[i]=c;
            }
        }
        void create()
        {
            cout<<"\n enter key value:";
            cin>>e;
            h=e%m;
            if(A[h]->key==-1)
            {
                A[h]->key=e;
            }
            else
            {
                node *start=new node;
                start =A[h];
                while(start->next !=NULL)
                {
                    start=start->next;
                }
                node *p=new node;
                p->key=e;
                p->next=NULL;
                start->next=p;
            }
        }

        int search(int a)
        {
            node *p=new node;
            h=a%m;
            p=A[h];
            while(p!=NULL)
            {
                if(p->key==a)
                      return 1;
                    p=p->next;
            }
            return 0;
        }
        int dele()
        {
            cout<<"enter element to be deleted"<<endl;
            cin>>e;
            h= search(e);
            if(h==1)
            {
                h=e%m;
                node *s=new node;
                node *r=new node;
                s=A[h];
                if(s->key==e)
                {
                    A[h]=s->next;
                    cout<<"element deleted"<<endl;
                    delete s;
                }
                else
                {
                    while(s->key !=e)
                    {
                        r=s;
                        s=s->next;
                    }
                    r->next=s->next;
                    delete s;
                    cout<<"element deleted \n";
                }
            }
            else
            {
                cout<<"element not found"<<endl;
            }
        }
        void display()
        {
            cout<<"\n elements are\n";
            for(i=0;i<m;i++)
            {
                node *t=new node;
                t=A[i];
                cout<<"at the index "<<i<<"\t :";
		 cout<<t->key;
		t=t->next;
		while(t !=NULL)
                {
                    cout<<"--->"<<t->key;
                    t=t->next;
                }
                cout<<"\n";
            }
        }
};
int main()
{
    chaining c;
    int ch;
        cout<<"\n1.insert\n2.search \n3.delete\n4.display\n5.exit\n";
    while(1)
    {
	cout<<"enter your choice :";
	cin>>ch;
        switch(ch)
        {
            case 1:
                c.create();
                break;
            case 2:
                    cout<<"enter a element to search"<<endl;
                    cin>>ch;
                    ch=c.search(ch);
            if(ch==1)
            {
                cout<<"element found"<<endl;
            }    
            else
            {
                cout<<"element not found"<<endl;
            }
            break;
        case 3:
            c.dele();
            break;
        case 4:
            c.display();
            break;
        case 5:
            return 0;
        
	default:
		cout<<"Wrong inpupt";
	}
    }
}



