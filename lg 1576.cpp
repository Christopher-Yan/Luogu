#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000100;
queue<int> q;

struct edge{
	int u;
	int v;
	double w;
	int next;
}e[MAXN]; 

int n,m,top=0;
int f[MAXN];

double dis[MAXN];

bool v[MAXN];

int read()
{
	int x=0;
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
	for(int i=1;i<=n;i++) dis[i]=-1,f[i]=-1;
	for(int i=1;i<=m;i++)
	{
		int 
		x=read(),
		y=read();
		double z=1.0*(100.0-read())/100.0;
		++top;
		e[top].u=x;
		e[top].v=y;
		e[top].w=z;
		e[top].next=f[x];
		f[x]=top;
		++top;
		e[top].u=y;
		e[top].v=x;
		e[top].w=z;
		e[top].next=f[y];
		f[y]=top;
	}
	int 
	s=read(),
	t=read();
	dis[s]=1.0;
	v[s]=true;
	q.push(s);
	while(!q.empty())
	{
		int cur=q.front();
		q.pop();
		v[cur]=false;
		for(int i=f[cur];i!=-1;i=e[i].next)
		{
			if(dis[e[i].v]<dis[e[i].u]*e[i].w*1.0)
			{
				dis[e[i].v]=dis[e[i].u]*e[i].w*1.0;
				if(!v[e[i].v])
				{
					q.push(e[i].v);
					v[e[i].v]=true;
				}
			}
		}
	}
	printf("%.8lf",100.0/dis[t]);
}
