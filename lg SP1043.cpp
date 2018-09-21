#include<iostream>
#include<cstdio>
#include<cstring>

#define ls u<<1
#define rs u<<1|1

const int MAXN = 50010;

struct segtree{
	int l;
	int r;
	int sum;
	int pre;
	int suf;
}t[MAXN << 2];

int n,m;

int read()
{
	int x = 0;
	int k = 1;
	char c = getchar();
	
	while (c>'9' || c<'0') 
		if (c=='-') k = -1, c = getchar();
		else c = getchar();

	while (c>='0' && c<='9')
		x = x*10+c-'0',
		c = getchar();
	
	return k*x;
}

void update(int u)
{
	t[u].sum = t[ls].sum + t[rs].sum;
	t[u].pre = std::max(t[ls].pre,t[ls].sum+t[rs].pre);
	t[u].suf = std::max(t[rs].suf,t[rs].sum+t[ls].suf);
	t[u].ans = std::max(std::max(t[ls].pre,t[rs].suf),t[ls].suf+t[rs].pre);
}

void build(int u)
{
	t[u].l = l;
	t[u].r = r;
	if (l==r)
	{
		int x = read();
		t[u].sum = x;
		t[u].pre = x;
		t[u].suf = x;
		return;
	}
	
	int mid = (l+r) >> 1;
	build(l,mid,ls);
	build(mid+1,r,rs);
	update(u);
}

void modify


int main()
{
	n=read();
	build(1,n,1);
	 
	m=read();
	for (int i=1; i<=m; ++i)
	{
		x=read();
		y=read();
		
	} 
}
