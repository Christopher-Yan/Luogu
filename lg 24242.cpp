#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[50];
bool v[50],f;
void dfs(long long sum,long long las)
{
	if(sum+a[las]>m) return;
	if(sum>m) return; 
	if(las==n&&sum!=m) return;
	if(sum==m) 
	{
		if(f==1) return;
		printf("YES\n");
		f=1;
		return;
	} 
	for(int i=1;i<=n;i++) 
	{
		if(v[i]==0&&sum+a[i]<=m)
		{
			v[i]=1;
			dfs(sum+a[i],i);
			v[i]=0;
		}
	}
}
int main()
{
	while(cin>>n>>m)
	{
		memset(v,0,sizeof(v));
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		f=0;
		for(int i=1;i<=n;i++) 
		{
			v[i]=1;
			dfs(a[i],i);
			v[i]=0;
		}
		if(!f) printf("NO\n");
	}
}
