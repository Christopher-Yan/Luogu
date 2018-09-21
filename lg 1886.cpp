#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long LL;
const int MAXN=1001000;
LL n,m,x,y;
LL a[1001000],minm,maxm;
struct segtree{
	LL l;
	LL r;
	LL w1;
	LL w2;
}tree[MAXN<<2];
void build(int l,int r,int u)
{
	tree[u].l=l;
	tree[u].r=r;
	if(l==r) 
	{
		scanf("%lld",&tree[u].w1);
		tree[u].w2=tree[u].w1;
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,u<<1);
	build(mid+1,r,u<<1|1);
	tree[u].w1=max(tree[u<<1].w1,tree[u<<1|1].w1);
	tree[u].w2=min(tree[u<<1].w2,tree[u<<1|1].w2);
	return;
}
void ask(int u)
{
	if(tree[u].l>=x&&tree[u].r<=y)
	{
		maxm=max(maxm,tree[u].w1);
		minm=min(minm,tree[u].w2);
		return;
	}
	int mid=(tree[u].l+tree[u].r)>>1;
	if(x<=mid) ask(u<<1);
	if(y>mid) ask(u<<1|1);
	return;
}
int main()
{
	scanf("%d%d",&n,&m);
	build(1,n,1);
	for(int i=1;i<=n-m+1;i++)
	{
		x=i;y=i+m-1;
		minm=99999999999;
		maxm=-9999999999;
		ask(1);
		printf("%lld ",minm);
		a[i]=maxm;
	}cout<<endl;
	for(int i=1;i<=n-m+1;i++)
		printf("%lld ",a[i]);
}
