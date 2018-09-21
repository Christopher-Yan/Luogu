#include<bits/stdc++.h>
#define MAXN 400
using namespace std;
int a[MAXN],n,maxn=-1024,ans,y;
int search(int x)
{
	ans=0;
	for(int i=x;i>=1;i--)
		if(a[i]==a[x]||a[i]==1) ans++;
		else break;
	for(int i=x+1;i<=2*n;i++) 
		if(a[i]==a[x+1]||a[i]==1) ans++;
		else return ans;
}
int main()
{
	scanf("%d",&n);char c;
	for(register int i=1;i<=n;i++)
	{
		cin>>c;
		if(c=='w') a[i]=1;
		if(c=='b') a[i]=2;
		if(c=='r') a[i]=3;
		a[i+n]=a[i];
	}
	for(register int i=1;i<=2*n-2;i++)
		if(a[i]!=a[i+1]) y=search(i),maxn=max(maxn,y);
	printf("%d",maxn);
 } 
