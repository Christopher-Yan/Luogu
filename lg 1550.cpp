#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,minn[404],e[404][404],total=0;
bool u[404];
int main()
{
	scanf("%d",&n);
	memset(u,1,sizeof(u));
	memset(minn,0x7f,sizeof(minn));
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&e[n+1][i]);
		e[i][n+1]=e[n+1][i];
	}e[n+1][n+1]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) 
			scanf("%d",&e[i][j]);
	minn[1]=0;
	for(int i=1;i<=n+1;i++)
	{
		int k=0;
		for(int j=1;j<=n+1;j++)
			if(minn[j]<minn[k]&&u[j]) k=j;
		u[k]=false;
		for(int j=1;j<=n+1;j++)
			if(u[j]&&minn[j]>e[k][j]) minn[j]=e[k][j];
	}
	for(int i=1;i<=n+1;i++) total+=minn[i];
	printf("%d",total);
	return 0;
}
