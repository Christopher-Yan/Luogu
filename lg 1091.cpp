#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,a[10001],f[10001],d[10001],maxn=-10;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	f[1]=1;
	for(int i=2;i<=n;i++) 
	{
		for(int j=1;j<=i;j++)
			if(a[j]<a[i]) f[i]=max(f[i],f[j]);
		f[i]++;
	}
	d[n]=1;
	for(int i=n-1;i>=1;i--)
	{
		for(int j=i;j<=n;j++)
			if(a[i]>a[j]) d[i]=max(d[i],d[j]);
		d[i]++;
	}
	for(int i=1;i<=n;i++) maxn=max(maxn,f[i]+d[i]);
	cout<<n-maxn+1;
}
