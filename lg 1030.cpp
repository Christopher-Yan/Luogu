#include<bits/stdc++.h>
using namespace std;
int k=0,n;
bool v[10];
char sz[10],sh[10];
void dfs(int l,int r)
{
	char c=sh[k+r-l];
	printf("%c",c);v[k+r-l]=1;
	for(int j=l;j<=r;j++)
	{
		if(sz[j]==c)
		{
			for(int i=0;i<=k;i++) 
				if(v[i]==0) goto as;
			k+=r-l+1;
			as:;
			if(l>j-1) goto cf; 
			dfs(l,j-1);
			cf:;
			if(j+1>r) continue;
			dfs(j+1,r);
			
		}
	}
}
int main()
{
	gets(sz);
	gets(sh);
	n=strlen(sh);
	dfs(0,n-1);
} 
