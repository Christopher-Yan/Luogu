#include<bits/stdc++.h>
using namespace std;
int n,m,a[10101],v[10101],ans=0;
void dfs(int b,int sum)
{
	if(sum>m) return;
	if(sum==m) 
	{
		ans++;
		return;
	}
	for(int i=b+1;i<=n;i++)
	{
		if(!v[i]&&a[i]+sum<=m)
		{
			v[i]=1;
			dfs(i,sum+a[i]);
			v[i]=0;
		}
	} 
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	dfs(0,0);
	cout<<ans;
}




/*
4 4
1 1 2 2

*/ 
