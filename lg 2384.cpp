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

int n,m;
int f[maxn];
long long dis[maxn];

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
	for(int i=1;i<=n;i++) dis[i]=0x7777777,f[i]=-1;
	for(int i=1;i<=m;i++)
	{
		e[i].u=read();
		e[i].v=read();
		e[i].w=read();
		e[i].next=f[e[i].u];
		f[e[i].u]=i;
	}
	dis[1]=1;
	v[1]=true;
	q.push(1);
	while(!q.empty())
	{
		int cur=q.front();
		q.pop();
		v[cur]=false;
		for(int i=f[cur];i!=-1;i=e[i].next)
			if(dis[e[i].v]>dis[e[i].u]*e[i].w)
			{
				dis[e[i].v]=dis[e[i].u]*e[i].w;
				if(!v[e[i].v])
				{
					v[e[i].v]=true;
					q.push(e[i].v);
				}
			}
	}
	while(dis[n]>=mod) dis[n]-=mod;
	printf("%lld",dis[n]);
}
