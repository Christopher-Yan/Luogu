#include<bits/stdc++.h>
using namespace std;
int n,p,c,top=0;
int mc[600],fir[10010],dis[5000],minn,k,ans,out=99999999;
bool f[5000];
struct edge{
	int u;
	int v;
	int w;
	int next;
}e[3000];
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
	n=read();p=read();c=read();
	for(int i=1;i<=n;i++)
		mc[i]=read();
	for(int i=1;i<=c;i++)
	{
		e[++top].u=read();
		e[top].v=read();
		e[top].w=read();
		e[top].next=fir[e[top].u];
		fir[e[top].u]=top;
		e[++top].u=e[top-1].v;
		e[top].v=e[top-1].u;
		e[top].w=e[top-1].w;
		e[top].next=fir[e[top].u];
		fir[e[top].u]=top;
	}
	for(int i=1;i<=p;i++)
	{
		for(int j=1;j<=p;j++) dis[j]=99999999,f[j]=0;
		dis[i]=0;
		for(int j=1;j<p;j++)
		{
			minn=99999999;
			for(int l=1;l<=p;l++) if(dis[l]<minn&&!f[l]) minn=dis[l],k=l;
			f[k]=1;
			for(int l=fir[k];l!=0;l=e[l].next)
				if(dis[e[l].v]>dis[e[l].u]+e[l].w) dis[e[l].v]=dis[e[l].u]+e[l].w;
		}
		ans=0;
		for(int l=1;l<=n;l++) ans+=dis[mc[l]];
		out=min(out,ans);
	}
	printf("%d",out);
	return 0;
}
