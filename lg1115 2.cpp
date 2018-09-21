#include<iostream>
#include<cstdio>
using namespace std;
int n,x,sum=0,minn=1,maxn=-1000,ans=-100000000;
int main()
{
	cin>>n>>x;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		sum+=x;
		if(sum>ans) ans=sum;
		if(sum<0) sum=0;
	}
	cout<<ans;
 } 
