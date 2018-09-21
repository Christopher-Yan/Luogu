#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int n,ch,ha,s,x,y,k=0,a[5010],ans=0,f[5010][1010];
	cin>>n>>s>>ch>>ha;
	int l=ch+ha;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		if(x<=l) a[++k]=y;
	}
	memset(f,0,sizeof(f)); 
	for(int i=1;i<=k;i++)
		for(int j=s;j>=a[i];j--)
			f[i][j]=max(f[i-1][j],f[i-1][j-a[i]]+1);
	cout<<f[n][s];
}
