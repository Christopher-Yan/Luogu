#include<bits/stdc++.h>
using namespace std;
const int MAXN=10020;

queue<int> q;

struct edge{
	int u;
	int v;
	double w;
	int next;
}e[MAXN];

int n,m,top=0,s,t;
int x[MAXN],y[MAXN],f[MAXN];

double dis[MAXN];

bool v[MAXN]; 

double suan(int t1,int t2)
{
	return sqrt((x[t1]-x[t2])*(x[t1]-x[t2])+(y[t1]-y[t2])*(y[t1]-y[t2]));
}

int read()
{
	int x=0;
	int k=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') k=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0')
	{
		x=x*10+c-'0';
		c=getchar();
	} 
	return k*x;
}

int main()
{
	n=read();
	for(int i=1;i<=n;i++) f[i]=-1;
	for(int i=1;i<=n;i++) dis[i]=9999999.0;
	for(int i=1;i<=n;i++) v[i]=false;
	for(int i=1;i<=n;i++) x[i]=read(),y[i]=read();
	m=read();
	for(int i=1;i<=m;i++)
	{
		int 
		t1=read(),
		t2=read();
		++top;
		e[top].u=t1;
		e[top].v=t2;
		e[top].w=suan(t1,t2);
		e[top].next=f[t1];
		f[t1]=top;
		++top;
		e[top].u=t2;
		e[top].v=t1;
		e[top].w=suan(t1,t2);
		e[top].next=f[e[top].u];
		f[e[top].u]=top;
	}
	s=read(),t=read();
	dis[s]=0;
	v[s]=true;
	q.push(s);
	while(!q.empty())
	{
		int cur=q.front();
		v[cur]=false;
		q.pop();
		for(int i=f[cur];i!=-1;i=e[i].next)
		{
			if(dis[e[i].v]>dis[e[i].u]+e[i].w)
			{
				dis[e[i].v]=dis[e[i].u]+e[i].w;
				if(!v[e[i].v])
				{
					q.push(e[i].v);
					v[e[i].v]=true;
				} 
			}
		}
	}
	printf("%.2lf",dis[t]);
}
