#include<bits/stdc++.h>
using namespace std;
struct edge{
	int u;
	int v;
	int next;
}e[101000];
bool vv[20000];
int n,m,l;
int sum;
int hx=1;
int ans;
int out=99999;
int fir[11000];
int v[11000];
inline int read()
{
	int k=1;
	int x=0;
    char c=getchar();
    if(c=='-') k=-k;
	while(c>'9'||c<'0') c=getchar();
	while(c<='9'&&c>='0')
	{
		x=x*10+c-'0';
		c=getchar();
	} 
	return k*x;
}
void solve(int x)
{
	if(hx>=ans) return;
	for(int i=fir[x];i!=0;i=e[i].next)
	{
		if(vv[i]) continue;
		++sum;
		v[e[i].v]++;
	}
	if(sum==m) 
	{
		ans=min(ans,hx);
		return;
	}
	for(int i=1;i<=n;i++)
	  if(!v[i])
		{
			++hx;
			v[i]=1; 
			solve(i);
			v[i]=0;
			--hx;
			for(int j=fir[i];j!=0;j=e[j].next)
			{
				if(vv[j]) vv[j]=0,--sum;
				v[e[j].v]--;
			}
		}
	return;
}
int main()
{
	n=read();
	m=read();
	memset(fir,0,sizeof fir);
	int top=0;
	for(int i=1;i<=m;i++)
	{
		int x=read();
		int y=read();
		++top;
		e[top].u=x;
		e[top].v=y;
		e[top].next=fir[x];
		fir[x]=top;
		++top;
		e[top].u=y;
		e[top].v=x;
		e[top].next=fir[y];
		fir[y]=top;
	}
	for(int i=1;i<=n;i++)
	{
		memset(v,0,sizeof v);
		v[i]=1;
		hx=1;
		sum=0;
		ans=99999;
		solve(i);
		out=min(out,ans);
		v[i]=0;
	}
	if(out==99999) printf("Impossible");
	else printf("%d",out);
	return 0;
} 
