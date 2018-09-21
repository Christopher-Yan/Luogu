#include<bits/stdc++.h>
using namespace std;
const int MAXN=1001000;
const int maxn=10010;
const int mod=9987;

queue<int> q;

struct edge{
	int u;
	int v;
	long long w;
	int next;
}e[MAXN];

int n,m,k;
int f[maxn];
long long dis[maxn],minn;

bool v[maxn];

long long read()
{
	long long x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c<='9'&&c>='0') 
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}

int main()
{
	n=read();
	m=read();
	for(int i=1;i<=n;i++) dis[i]=99999999,f[i]=-1;
	for(int i=1;i<=m;i++)
	{
		e[i].u=read();
		e[i].v=read();
		e[i].w=read();
		e[i].next=f[e[i].u];
		f[e[i].u]=i;
	}
	dis[1]=1;
	for(int i=1;i<n;i++)
	{
		minn=99999999;
		for(int j=1;j<=n;j++)
			if(!v[j]&&dis[j]<minn) k=j,minn=dis[j];
		v[k]=1;
		for(int j=f[k];j!=-1;j=e[j].next)
			if(dis[e[j].v]>dis[e[j].u]*e[j].w)
				dis[e[j].v]=dis[e[j].u]*e[j].w;	
	}
	while(dis[n]>=mod) dis[n]-=mod;
	printf("%lld",dis[n]);
}
