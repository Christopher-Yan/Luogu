#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,ans[16],cnt;
bool f;
bool v1[160],v2[160],v3[16];
void dfs(int num)
{
	if(num==n+1) 
	{
		cnt++;
		if(cnt>3) return;
		for(int i=1;i<=n;i++) printf("%d ",ans[i]);
		printf("\n");
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(v3[i]==1||v1[num+i]==1||v2[num-i]==1) continue;
		ans[num]=i;
		v1[num+i]=1;v2[num-i]=1;v3[i]=1;
		dfs(num+1);
		ans[num]=0;
		v1[num+i]=0;v2[num-i]=0;v3[i]=0;
	}
}
int main()
{
	scanf("%d",&n);
	dfs(1);
	printf("%d",cnt);
} 
