#include<bits/stdc++.h>
#define lowbit(x) (x&-x)
#define MAXN 505000
using namespace std;
int n,m,x,y,q,k;
int a[MAXN],tree[MAXN];
void change(int x,int k)
{
	for(register int i=x;i<=n;i+=lowbit(i))
		tree[i]+=k;
}
int ask(int x)
{
	int sum=0;
	for(register int i=x;i;i-=lowbit(i))
		sum+=tree[i];
	return sum;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(register int i=1;i<=n;i++) 
		scanf("%d",&a[i]);
	for(register int i=1;i<=m;i++)
	{
		scanf("%d",&q);
		if(q==1) 
		{
			scanf("%d%d%d",&x,&y,&k);
			change(x,k);
			change(y+1,-k);
		}
		if(q==2) 
		{
			scanf("%d",&x);
			printf("%d\n",ask(x)+a[x]);
		} 
	}
	return 0;
}
