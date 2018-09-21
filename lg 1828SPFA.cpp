#include<bits/stdc++.h>
using namespace std;
queue <int> q;
struct edge{
	int u;
	int v;
	int w;
	int next;
}e[2000];
int inf=99999,top=0;
int di[850],dis[850],fir[5000],ans;
bool v[850];
int n,m,k,ou=99999;
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
    k=read();n=read();m=read();
    for(int i=1;i<=k;i++) di[i]=read();
    for(int i=1;i<=m;i++)
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
    for(int i=1;i<=n;i++)
    {
        memset(dis,0x7f,sizeof dis);
        memset(v,0,sizeof v);
        dis[i]=0,v[i]=1,q.push(i);
        while(!q.empty())
        {
            int uu=q.front();
            for(int j=fir[uu];j!=0;j=e[j].next)
                if(dis[e[j].u]+e[j].w<dis[e[j].v]) 
                {
                    dis[e[j].v]=dis[e[j].u]+e[j].w;
                    if(!v[e[j].v]) 
                    {
                        q.push(e[j].v);
                        v[e[j].v]=true;
                    }
                }
            v[uu]=false;
            q.pop();
        }
        ans=0;
        for(int j=1;j<=k;j++)
            ans+=dis[di[j]];
        ou=min(ans,ou);
    }
    printf("%d",ou);
    return 0;
}
