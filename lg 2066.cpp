#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,a[101][100],w[1001],f[101][101],t=0,c[101];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{	
			int maxn=-1;
			for(int k=0;k<=j;k++) 
				if(f[i-1][k]+a[i][j-k]>maxn) 
					maxn=f[i-1][k]+a[i][j-k];
			f[i][j]=maxn;
		}
	cout<<f[n][m]<<endl;
} 
