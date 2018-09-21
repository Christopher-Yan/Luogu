#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int n,ch,ha,s,x,y,k=0,a[6000],ans=0;
	cin>>n>>s;
	cin>>ch>>ha;
	int l=ch+ha;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		if(x<=l) a[++k]=y;
	}
	sort(a+1,a+k+1);
	for(int i=1;i<=k;i++)
	{
		if(s-a[i]>=0) ans++,s-=a[i];
		else break;
	}
	cout<<ans;
}
