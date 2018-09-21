#include<bits/stdc++.h>
using namespace std;
int n,s[101000],x,t=0;
int a[101000],b[101000],top=0;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		while(a[s[t]]<a[i]&&t>0) 
		{
			b[s[t]]=i;
			--t;
		}
		s[++t]=i;
	}
	for(int i=1;i<=n;i++) cout<<b[i]<<endl;
}
