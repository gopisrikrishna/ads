#include<iostream>
using namespace std;
int adjmat[10][10],i,j,k,n,m,c,visit,visited[10],l,v,count,count1,vst,p;
int main()
{
	int dup1,dup2;
	cout<<"enter no of vertices";
	cin >> m;
	cout <<"enter no of edges";
	cin >>n;
	cout <<"enter edges and cost";
	for(k=1;k<=n;k++)
	{
		cin >>i >>j >>c;
		adjmat[i][j]=c;
		adjmat[j][i]=c;
	}
	for(i=1;i<=m;i++)
		for(j=1;j<=m;j++)
			if(adjmat[i][j]==0)
				adjmat[i][j]=137;
			visit=1;
	while(visit<=m)
	{
		v=137;
		for(i=1;i<=m;i++)
			for(j=1;j<=m;j++)
				if(adjmat[i][j]!=137 && adjmat[i][j]<v  && adjmat[i][j]!=-1 )
				{
					count =0;
					for(p=1;p<=m;p++)
					{
						if(visited[p]==i || visited[p]==j)
							count++;
					}
					if(count >= 2)
					{
						for(p=1;p<=m;p++)
							if(adjmat[i][p]!=137 && p!=j)
								dup1=p;
						for(p=1;p<=m;p++)
							if(adjmat[j][p]!=137 && p!=i)
								dup2=p;
						if(adjmat[dup1][dup2]==-1)
							continue;
					}
					l=i;
					k=j;
					v=adjmat[i][j];
				}
		cout <<"edge from " <<l <<"-->"<<k<<endl;
		adjmat[l][k]=-1;
		adjmat[k][l]=-1;
		visit++;
		count=0;
		count1=0;
		for(i=1;i<=m;i++)
		{
			if(visited[i]==l)
				count++;
			if(visited[i]==k)
				count1++;
		}
		if(count==0)
			visited[++vst]=l;
		if(count1==0)
			visited[++vst]=k;
}
