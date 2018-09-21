#include<bits/stdc++.h>
using namespace std;
int n,a[105],i,j,sum=0;
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	int p=sum/n;
	a[0]=p;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i-1]<p)
		{
			a[i-1]=p;
			a[i]-=p-a[i-1];
			ans++; 
		}
		if(a[i]>p)
		{
			a[i]=p;
			a[i+1]+=a[i]-p;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
