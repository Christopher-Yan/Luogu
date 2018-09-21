#include<bits/stdc++.h>
using namespace std;
const int MAXN=100001;
typedef long long LL;
int q,x,y,k;
LL ans;
struct segtree{
	int l;
	int r;
	long long w;
	int f;
}tree[MAXN<<2];
int read()
{
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') 
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
void down(int u)
{
	tree[u<<1].f+=tree[u].f;
	tree[(u<<1)+1].f+=tree[u].f;
	tree[u<<1].w+=(tree[u<<1].r-tree[u<<1].l+1)*tree[u].f;
	tree[(u<<1)+1].w+=(tree[(u<<1)+1].r-tree[(u<<1)+1].l+1)*tree[u].f;
	tree[u].f=0;
}
void add(int u)
{
	if(tree[u].l>=x&&tree[u].r<=y)
	{
		tree[u].w+=k*(tree[u].r-tree[u].l+1);
		tree[u].f+=k;
		return;
	}
    if(tree[u].f) down(u);
	int m=(tree[u].l+tree[u].r)>>1;
	if(x<=m) add(u<<1);
	if(y>m) add((u<<1)+1);
	tree[u].w=tree[u<<1].w+tree[(u<<1)+1].w;
}
void build(int l,int r,int u)
{
	tree[u].l=l;
	tree[u].r=r;
	tree[u].f=0;
	if(l==r) 
	{
		scanf("%lld",&tree[u].w);
		return;
	}
	int m=(l+r)>>1;
	build(l,m,u<<1);
	build(m+1,r,(u<<1)+1);
	tree[u].w=tree[u<<1].w+tree[(u<<1)+1].w;
}
void search(int u)
{
	if(tree[u].l>=x&&tree[u].r<=y) 
	{
		ans+=tree[u].w;
		return;
	}
	if(tree[u].f) down(u);
	int m=(tree[u].r+tree[u].l)>>1;
	if(x<=m) search(u<<1);
	if(y>m) search((u<<1)+1);
}
int main()
{
	int n,m;
	n=read();m=read();
	build(1,n,1);
	while(m--)
	{
		q=read();
		if(q==1)
		{
			x=read();
			y=read();
			k=read();
			add(1);
		}
		if(q==2) 
		{
			x=read();
			y=read();
			ans=0;
			search(1);
			printf("%d\n",ans);
		} 
	}
} 
