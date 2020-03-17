#include<iostream>
using namespace std;
void dij(int n,int v,int cost[10][10],int dist[])
{
int i,u,w,count,visited[10],min;
for(i=0;i<=n;i++)
{
visited[i]=0;
dist[i]=cost[v][i];
}
visited[v]=1;
count=2;
while(count<=n)
{
min=999;
for(w=1;w<=n;w++)
{
if(dist[w]<min&&(!visited[w]))
{
min=dist[w];
u=w;
visited[u]=1;
count++;
for(w=1;w<=n;w++)
{
if((dist[u]+cost[u][w]<dist[w])&&(!visited[w]))
dist[w]=dist[u]+cost[u][w];
}
}
}
}
}
int main()
{
int n,v,i,j,cost[10][10],dist[10];
cout<<"Enter number of nodes:";
cin>>n;
cout<<"\nEnter the cost matrix:";
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
cout<<"["<<i<<"]["<<j<<"]:";
cin>>cost[i][j];
if(cost[i][j]==0)
cost[i][j]=999;
}
cout<<"Line "<<i<<endl;
}
cout<<"\nEnter the source vertex:";
cin>>v;
dij(n,v,cost,dist);
cout<<"\nShortest path:\n";
for(i=1;i<=n;i++)
{
if(i!=v)
cout<<v<<"->"<<i<<"  cost=  "<<dist[i]<<endl;
}
}
