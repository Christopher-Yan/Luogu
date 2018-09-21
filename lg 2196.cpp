#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int w[30],k,n,pre[30],a[30][30],f[30],maxn=-10;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			cin>>a[i][j];
			a[j][i]=a[i][j];
		}
		f[1]=w[1];pre[n]=0;
	for(int i=2;i<=n;i++)
	{
		int k=0,m=0;
		for(int j=1;j<i;j++)
			if(f[j]>m&&a[i][j]==1) m=f[j],k=j;
		f[i]=m+w[i];
		pre[i]=k;
	}
	for(int i=1;i<=n;i++) 
	{
		int cur=maxn;
		maxn=max(maxn,f[i]);
		if(cur!=maxn) k=i;
	}cout<<k;
	while(pre[k])
	{
		cout<<" "<<pre[k];
		k=pre[k];
	}
	cout<<endl<<maxn;
}
