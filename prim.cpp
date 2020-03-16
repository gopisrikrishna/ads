#include<iostream>
using namespace std;
int n,cost[10][10];
void prims()
{
	int i,j,k,l,x,near_value[10],temp=999,mincost=0,tree[10][3];
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(temp>cost[i][j])
			{
				temp=cost[i][j];
				k=i;
				l=j;
			}
	tree[1][1]=k;   
	tree[1][2]=l;
	tree[1][3]=temp;
	mincost=temp;
	for(i=1;i<=n;i++)
	{
		if(cost[i][k]<cost[i][l])
			near_value[i]=k;
		else
			near_value[i]=l;
	}
	near_value[k]=near_value[l]=100;
	temp=999;
	for(i=2;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			if(near_value[j]!=100 && cost[j][near_value[j]]<temp)
			{
				temp=cost[j][near_value[j]];
				x=j;
			}
		tree[i][1]=x;
		tree[i][2]=near_value[x];
		tree[i][3]=cost[x][near_value[x]];
		mincost+=cost[x][near_value[x]];
		near_value[x]=100;
		for(j=1;j<=n;j++)
			if(near_value[j]!=100 && cost[j][near_value[j]]>cost[j][x])
				near_value[j]=x;
		temp=999;
	}
	cout<<"\nThe M.S.T is ____\n\n";
	for(i=1;i<n;i++)
	{
		for(j=1;j<3;j++)
			cout<<tree[i][j]<<" ";
		cout<<endl;
	}
	cout<<"\nMinimum COst: "<<mincost;
}
int main()
{
	int i,j,k,m,c;
	cout <<"enter no of vertices";
	cin >> n;
	cout <<"ente no of edges";
	cin >> m;
	cout <<"enter edges and cost";
	for(k=1;k<=m;k++)
	{
		cin >>i>>j>>c;
		cost[i][j]=c;
		cost[j][i]=c;
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(cost[i][j]==0)
				cost[i][j]=999;
	prims();
}

/*
6
10

1 2 6                                                                                                                                        
1 3 1                                                                                                                                        
1 4 5                                                                                                                                        
2 3 5                                                                                                                                        
3 4 5                                                                                                                                        
2 5 3                                                                                                                                        
5 6 6                                                                                                                                        
5 3 6                                                                                                                                        
3 6 4                                                                                                                                        
6 4 2 

*/