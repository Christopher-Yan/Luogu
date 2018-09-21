#include<bits/stdc++.h>
using namespace std;
int n,a[121];
int l[121],r[121];
int ans=-12;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	l[1]=1;
	r[n]=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
			if(a[i]>a[j]) l[i]=max(l[j],l[i]);
		l[i]++;	
	}
	for(int i=n-1;i>=1;i--)
	{
		for(int j=i;j<=n;j++)
			if(a[i]>a[j]) r[i]=max(r[j],r[i]);
		r[i]++;
	}
	for(int i=1;i<=n;i++)
		ans=max(ans,l[i]+r[i]);
	cout<<n-ans+1;
}
