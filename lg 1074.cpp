#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cstdlib>
using namespace std;
int a[15][15],maxn=-1,fx,fy,kk,ans;
int h[10][10];
int s[10][10];
int q[10][10];
int g[10][10]={0,0,0,0,0,0,0,0,0,0,0,1,1,1,2,2,2,3,3,3,0,1,1,1,2,2,2,3,3,3,0,1,1,1,2,2,2,3,3,3,0,4,4,4,5,5,5,6,6,6,0,4,4,4,5,5,5,6,6,6,0,4,4,4,5,5,5,6,6,6,0,7,7,7,8,8,8,9,9,9,0,7,7,7,8,8,8,9,9,9,0,7,7,7,8,8,8,9,9,9};
int fz[10][10]={0,0,0,0,0,0,0,0,0,0,0,6,6,6,6,6,6,6,6,6,0,6,7,7,7,7,7,7,7,6,0,6,7,8,8,8,8,8,7,6,0,6,7,8,9,9,9,8,7,6,0,6,7,8,9,10,9,8,7,6,0,6,7,8,9,9,9,8,7,6,0,6,7,8,8,8,8,8,7,6,0,6,7,7,7,7,7,7,7,6,0,6,6,6,6,6,6,6,6,6};
void dfs(int,int);
int sum() 
{
    int tmp=0;
    for(int i=1;i<=9;i++)
        for(int j=1;j<=9;j++)
        {
            tmp+=a[i][j]*fz[i][j];
        }
    return tmp;
}
void dfs(int x,int y)
{
	if(a[x][y])
	{
		if(x==9&&y==9)
		{
			maxn=max(maxn,sum());
			return;
		}
		else
		{
			if(y==9) dfs(x+1,1);
			else dfs(x,y+1);
		}
	}
	else
	{
		for(int i=1;i<=9;i++)
		{
			if(!h[x][i]&&!s[y][i]&&!q[g[x][y]][i])
			{
				a[x][y]=i;
				h[x][i]=1;
				s[y][i]=1;
				q[g[x][y]][i]=1;
				if(y+1>9)
				{
					if(x+1>9)
					{
						maxn=max(maxn,sum());
						return;
					}
					else dfs(x+1,1);
				}
				else dfs(x,y+1);
				a[x][y]=0;
				h[x][i]=0;
				s[y][i]=0;
				q[g[x][y]][i]=0;
			}
			
		}	
	}
	
}
int main()
{
	kk=clock();
	for(int i=1;i<=9;i++)
		for(int j=1;j<=9;j++)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j])
			{
				h[i][a[i][j]]=1;
				s[j][a[i][j]]=1;
				q[g[i][j]][a[i][j]]=1;
			}
		}
			
	dfs(1,1);
	printf("%d",maxn);
}
