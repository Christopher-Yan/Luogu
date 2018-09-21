#include<bits/stdc++.h>
using namespace std;
int n,f[200002],d[200002],minn,m;
int fa(int x)
{
	int l;
	if(f[x]!=x)
	{
		l=f[x];
		f[x]=fa(f[x]);
		d[x]+=d[l];
	}	
	return f[x];
}
void ufs(int x,int y)
{
	if(fa(x)!=fa(y)) {f[fa(x)]=fa(y);d[x]=d[y]+1;}
	else minn=min(minn,d[x]+d[y]+1);
	return;
}
int main() 
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) f[i]=i;
	minn=0x7777777;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&m);
		ufs(i,m);
	}
	printf("%d",minn);
}
