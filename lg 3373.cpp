#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=100101;
struct segment{
	LL l;
	LL r;
	LL ad;
	LL mu;
	LL w;
}tree[MAXN<<2];
LL n,m,p,q,x,y;
LL ans,kk,k;
LL read()
{
	LL x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c<='9'&&c>='0') 
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
void build(int l,int r,int u)
{
	tree[u].ad=0;
	tree[u].mu=1;
	tree[u].l=l;
	tree[u].r=r;
	if(l==r) 
	{
		tree[u].w=read()%p;
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,u<<1);
	build(mid+1,r,u<<1|1);
	tree[u].w=(tree[u<<1].w+tree[u<<1|1].w)%p;
}
void down(int u)
{
	tree[u<<1].w=(tree[u<<1].w*tree[u].mu+tree[u].ad*(tree[u<<1].r-tree[u<<1].l+1))%p;
    tree[u<<1|1].w=(tree[u<<1|1].w*tree[u].mu+tree[u].ad*(tree[u<<1|1].r-tree[u<<1|1].l+1))%p;
	tree[u<<1].mu=(tree[u<<1].mu*tree[u].mu)%p;
    tree[u<<1|1].mu=(tree[u<<1|1].mu*tree[u].mu)%p;
    tree[u<<1].ad=(tree[u<<1].ad*tree[u].mu+tree[u].ad)%p;
    tree[u<<1|1].ad=(tree[u<<1|1].ad*tree[u].mu+tree[u].ad)%p;
	tree[u].ad=0;	
	tree[u].mu=1;
}
void add(int u)
{
	if(tree[u].l>=x&&tree[u].r<=y)
	{
		tree[u].w=(tree[u].w+(tree[u].r-tree[u].l+1)*kk)%p;
		tree[u].ad=(tree[u].ad+kk)%p; 
		return;
	}
	if(tree[u].ad!=0||tree[u].mu!=1) down(u);
	int mid=(tree[u].l+tree[u].r)>>1;
	if(x<=mid) add(u<<1);
	if(y>mid) add(u<<1|1);
	tree[u].w=(tree[u<<1].w+tree[u<<1|1].w)%p;
}
void mul(int u)
{
	if(tree[u].l>=x&&tree[u].r<=y)
	{
		tree[u].w=(tree[u].w*k)%p;
		tree[u].mu=(tree[u].mu*k)%p;
		tree[u].ad=(tree[u].ad*k)%p;
		return;
	}
	down(u);
	int mid=(tree[u].l+tree[u].r)>>1;
	if(x<=mid) mul(u<<1);
	if(y>mid) mul(u<<1|1);
	tree[u].w=(tree[u<<1].w+tree[u<<1|1].w)%p;
} 
void search(int u)
{
	if(tree[u].l>=x&&tree[u].r<=y)
	{
		ans=(ans+tree[u].w)%p;
		return;
	}
	down(u);
	int mid=(tree[u].l+tree[u].r)>>1;
	if(x<=mid) search(u<<1);
	if(y>mid) search(u<<1|1);
}
int main()
{
	n=read();
	m=read();
	p=read();
	build(1,n,1);
	while(m--)
	{
		q=read();
		if(q==1)
		{
			x=read();
			y=read();
			k=read();
			mul(1);
		}
		if(q==2)
		{
			x=read();
			y=read();
			kk=read();
			add(1);
		}
		if(q==3)
		{
			ans=0;
			x=read();
			y=read();
			search(1);
			printf("%lld\n",ans%p);
		}
	}
	return 0;
}
