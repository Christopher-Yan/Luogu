#include<bits/stdc++.h>
using namespace std;
struct edge{
	int u;
	int v;
	int w;
	int next;
}e[501000];
int fir[10100]; 
int dis[10100];
int n,m,s;
bool v[10100];
inline int read()
{
	int k=1;
	int x=0;
	char c=getchar();
	if(c=='-') k=-1;
	while(c>'9'||c<'0') c=getchar();
	while(c<='9'&&c>='0') 
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return k*x;
}
int main()
{
	n=read();m=read();s=read();
	memset(fir,0,sizeof fir);
	memset(v,0,sizeof v);
	for(int i=1;i<=n;i++) dis[i]=2147483647;
	for(int i=1;i<=m;i++)
	{
		e[i].u=read();
		e[i].v=read();
		e[i].w=read();
		e[i].next=fir[e[i].u];
		fir[e[i].u]=i;
	}
	dis[s]=0;
	for(int i=1;i<n;i++)
	{
		int minn=999999;
		int k=0;
		for(int j=1;j<=n;j++)
			if(!v[j]&&dis[j]<minn) minn=dis[j],k=j;
		v[k]=1;
		for(int i=fir[k];i!=0;i=e[i].next)
			if(dis[k]+e[i].w<=dis[e[i].v]) 
				dis[e[i].v]=dis[k]+e[i].w;
	}
	for(int i=1;i<=n;i++)
		printf("%d ",dis[i]);
	return 0;
} 
