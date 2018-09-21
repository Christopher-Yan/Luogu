#include<bits/stdc++.h>
#define lowbit(x) (x&-x)
#define MAXN 505000
using namespace std;
int n,m,x,y,q;
int a,tree[MAXN];
void change(int x,int k)
{
	for(int i=x;i<=n;i+=lowbit(i))
		tree[i]+=k;
}
int ask(int x)
{
	int sum=0;
	for(int i=x;i;i-=lowbit(i))
		sum+=tree[i];
	return sum;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&a);
		change(i,a);
	}
	for(register int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&q,&x,&y);
		if(q==1) change(x,y);
		if(q==2) printf("%d\n",ask(y)-ask(x-1)); 
	}
	return 0;
}
