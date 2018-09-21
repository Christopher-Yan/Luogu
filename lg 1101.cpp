#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int dx[9]={0,0,-1,-1,-1,0,1,1,1};
int dy[9]={0,-1,-1,0,1,1,1,0,-1};
char cc[8]={'a','y','i','z','h','o','n','g'};
char c[105][105];
bool v[1001][1001];
int n,i,j,xx,yy;
void dfs(int move,int x,int y)
{
	xx=x;yy=y;
	for(i=1;i<=7;i++)
	{
		if(c[xx][yy]!=cc[i]) break;
		xx+=dx[move];
		yy+=dy[move];	
	}
	if(i==8)
		for(i=1;i<=7;i++)
		{
			v[x][y]=true;
			x+=dx[move];
			y+=dy[move];	
		}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>c[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(c[i][j]=='y')
			{
				if(j>=7) 
					dfs(1,i,j);
				if(j<=n-6)
					dfs(5,i,j);
				if(i>=7)
					dfs(3,i,j);
				if(i<=n-6)
					dfs(7,i,j);
				if(j>=7&&i>=7)
					dfs(2,i,j);
				if(i>=7&&j<=n-6)
					dfs(8,i,j);
				if(j<=n-6&&i<=n-6)	
					dfs(6,i,j); 
				if(i<=n-6&&j>=7)
					dfs(4,i,j);
			}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			if(v[i][j]==false) printf("*");
			else printf("%c",c[i][j]);
		printf("\n");
	}
	
}
/*
8        
qyizhong 
gydthkjy
nwidghji
orbzsfgz
hhgrhwth
zzzzzozo 
iwdfrgng
yyyygggg
*/



