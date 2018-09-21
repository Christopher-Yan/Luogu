#include<bits/stdc++.h>
using namespace std;
const int MAXN=100100;
int n,m,x,y,ans; 

struct segtree{
	int l;
	int r;
	int w;
}tree[MAXN<<2];

void build(int l,int r,int u)
{
	tree[u].l=l;
	tree[u].r=r;
	if(l==r)
	{
		tree[u].w=0;
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,u<<1);
	build(mid+1,r,u<<1|1);
	tree[u].w=0;
}

void updata(int u)
{
	if(tree[u].l==tree[u].r&&tree[u].l==x)
	{
		tree[u].w+=y;
		return;
	}
	int mid=(tree[u].l+tree[u].r)>>1;
	if(x<=mid) updata(u<<1);
	if(x>mid) updata(u<<1|1);
	tree[u].w=tree[u<<1].w+tree[u<<1|1].w;
}

void ask(int u)
{
	if(tree[u].l>=x&&tree[u].r<=y) 
	{
		ans+=tree[u].w;
		return;
	}
	int mid=(tree[u].l+tree[u].r)>>1;
	if(x<=mid) ask(u<<1);
	if(y>mid) ask(u<<1|1);
}

int main()
{
	scanf("%d%d",&n,&m);
	build(1,n,1);
	while(m--)
	{
		char ch;
		cin>>ch;
		scanf("%d%d",&x,&y);
		switch(ch)
		{
			case 'x':updata(1);break;
			case 'y':ans=0;ask(1);printf("%d\n",ans);break;
			default:;
		}
	}
	return 0;
}
