#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int n,a[30],k,ans=0;
void dg(int,int,int);
bool pd(int x)
{
	for(int i=2;i<=sqrt(x);i++) if(x%i==0) return false;
	return true;
}
void dg(int num,int cnt,int sum)
{
	if(cnt==k&&pd(sum)==true) 
	{
		ans++;
		return;
	}
	for(int i=num+1;i<=n;i++)
		dg(i,cnt+1,sum+a[i]);
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		dg(i,1,a[i]);
	printf("%d",ans);
	return 0;
}
