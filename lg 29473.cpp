#include<iostream>
#include<cstdio>

const int MAXN=100100;

struct segtree{
	int l;
	int r;
	int w;
}tree[MAXN<<2];

int n,cnt,out,ans,x,y;

int a[MAXN];

int wei(int x)
{
	int p=a[x];
	int k=0;
	while(p>0)
	{
		++k;
		p/=10;
	}
	return k;
}

void build(int u,int l,int r)
{
	tree[u].l=l;
	tree[u].r=r;
	if(l==r) 
	{
		tree[u].w=a[++cnt];
		return;
	}
	int mid=(l+r)>>1;
	build(u<<1,l,mid);
	build(u<<1|1,mid+1,r);
	tree[u].w=std::max(tree[u<<1].w,tree[u<<1|1].w);
}

void ask(int u)
{
	if(tree[u].l>=x&&tree[u].r<=y)
	{
		ans=std::max(ans,tree[u].w);
		return;
	}
	int mid=(tree[u].l+tree[u].r)>>1;
	if(x<=mid) ask(u<<1);
	if(y>mid) ask(u<<1|1);
	return;
}

int read()
{
	int x=0;
	int k=1;
	char c=getchar();
	while(c>'9'||c<'0')
	    if(c=='-') k=-1,c=getchar();
	    else c=getchar();
	while(c>='0'&&c<='9')
		x=x*10+c-'0',
		c=getchar();
	return x*k;
}

int main()
{
	n=read();
	for(register int i=1;i<=n;++i)
		a[i]=read();
	build(1,1,n);
	for(register int i=1;i<=n;++i)
		for(register int j=i;j<=n;++j)
		{
			ans=-1;
			x=i;
			y=j;
			ask(1);
			if(wei(a[i])+wei(a[j])>9) continue;
			if(a[i]*a[j]<=ans) ++out;
		}
	printf("%d",out);
}
