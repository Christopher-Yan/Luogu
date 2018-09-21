#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,f[10001],maxn=-10;
struct node{
	int l,r;
}a[10001];
bool cmp(node a,node b)
{
	return a.l<b.l;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].l>>a[i].r;
	sort(a+1,a+1+n,cmp);
	f[1]=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			if(a[i].r>=a[j].r) f[i]=max(f[i],f[j]);
			f[i]++;
	}
	for(int i=1;i<=n;i++) maxn=max(maxn,f[i]);
	cout<<maxn;
}
