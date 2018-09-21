#include<bits/stdc++.h>
using namespace std;
const int MAXN=20020;

queue<int> q;

struct edge{
	int u;
	int v;
	int w;
	int next;
}e[MAXN];
 
int n,m,s,t,top=0;
int dis[MAXN],f[MAXN];

bool v[MAXN];

int read()
{
	int x=0;
	char c=getchar();
	while(c>'9'||c<'0') c=getchar();
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
	s=read();
	t=read();
	
	int x,y,z;
	for(int i=1;i<=n;i++) dis[i]=99999999,f[i]=-1,v[i]=false;
	for(int i=1;i<=m;i++)
	{
		x=read();
		y=read();
		z=read();
		++top;
		e[top].u=x;
		e[top].v=y;
		e[top].w=z;
		e[top].next=f[x];
		f[x]=top;++top;
		e[top].u=y;
		e[top].v=x;
		e[top].w=z;
		e[top].next=f[y];
		f[y]=top;
	}
	v[s]=1;
	dis[s]=0;
	q.push(s);
	while(!q.empty())
	{
		int cur=q.front();
		v[cur]=false;
		q.pop();
		for(int i=f[cur];i!=-1;i=e[i].next)
		{
			if(dis[e[i].v]>)
		}
	}
} 
