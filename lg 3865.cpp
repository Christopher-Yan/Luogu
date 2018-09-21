#include<bits/stdc++.h>
using namespace std;
const int MAXN=100020;
int n,m,x,y,ans;
struct segtree{
	int l;
	int r;
	int w;
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
void build(int l,int r,int u)
{
	tree[u].l=l;tree[u].r=r;
	if(l==r)
	{
		tree[u].w=read();
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,u<<1);
	build(mid+1,r,(u<<1)+1);
	tree[u].w=max(tree[u<<1].w,tree[(u<<1)+1].w);	
}
void search(int u)
{
	if(tree[u].l==tree[u].r)
	{
		ans=max(ans,tree[u].w);
		return;
	}
	int mid=(tree[u].l+tree[u].r)>>1;
	if(x<=mid) search(u<<1);
	if(y>mid) search((u<<1)+1);
}
int main()
{
	n=read();m=read();
	build(1,n,1); 
	while(m--)
	{
		x=read();
		y=read();
		ans=-999999;
		search(1);
		printf("%d\n",ans);
	}
}
