#include<iostream>
using namespace std;
struct node
{
    int freq;
    node *left;
    node *right;
    char character;
};
class Huffman
{
    int k,n;
    struct node *hc[21];
    public:
    Huffman()
    {
        k=0;
    }
    void create()
    {
        cout<<"enter number of characters"<<endl;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            node *c=new node;
            cout<<"Enter character and it's frequency"<<i+1<<endl;
            cin>>c->character;
            cin>>c->freq;
            c->left=c->right=NULL;
            hc[k]=c;
            k++;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if((hc[i]->freq)<(hc[j]->freq))
                {
                    node *t;
                    t=hc[i];
                    hc[i]=hc[j];
                    hc[j]=t;
                }
            }
        }
    }
    void buildTree()
    {
        int arr[50];
        for(int i=0;i<50;i++)
        {
            arr[i]=-1;
        }
        int l=0,i;
        for(i=0;i<n-1;i++)
        {
            node *p=new node;
            p->freq=hc[l]->freq+hc[l+1]->freq;
            cout<<endl;
            p->left=hc[l];
            p->right=hc[l+1];
            hc[l+1]=p;
            for(int k=l+1;k<n;k++)
            {
                for(int m=l+1;m<k;m++)
                {
                    if((hc[m]->freq)>(hc[k]->freq))
                    {
                        node *temp;
                        temp=hc[m];
                        hc[m]=hc[k];
                        hc[k]=temp;
                    }
                }
            }
            l=l+1;
        }
        hcode(hc[l],arr,0);
    }
    void hcode(node *root,int arr[],int top)
    {
        if(root->left)
        {
            arr[top]=0;
            hcode(root->left,arr,top+1);
        }
        if(root->right)
        {
            arr[top]=1;
            hcode(root->right,arr,top+1);
        }
        if(root->left==NULL&&root->right==NULL)
        {
            cout<<root->character<<" :   ";
            for(int i=0;i<top;i++)
            {
                cout<<arr[i];
               // cout<<endl;
            }cout<<endl;
        }
    }
};
int main()
{
    Huffman h1;
    h1.create();
    h1.buildTree();
}
//C++ GDB link :- https://www.onlinegdb.com/HyIDOzvkL
/* use this as input
6
a 5
b 9
c 12
d 13
e 16
f 45

expected output

f :   0
c :   100
d :   101
a :   1100
b :   1101
e :   111

*/

