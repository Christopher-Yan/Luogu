#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int n,x[5005],y[5005];
double minn[5001],total=0,INF=99999999,mi;
bool u[5001];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
	for(int i=1;i<=n;i++)
    {
        u[i]=1;
        minn[i]=sqrt((x[1]-x[i])*(x[1]-x[i])+(y[1]-y[i])*(y[1]-y[i]));
    }
	v[1]=0;
	for(int i=1;i<n;i++)
	{
		int k=0;
		mi=INF;
        for(int j=1;j<=n;j++)
            if(u[j]&&minn[j]<mi)
            {
            	k=j;
            	mi=minn[j];
			}
	 	if(k!=0)
        {
            u[k]=0;
            total+=minn[k];
            for(int j=1;j<=n;j++)
            {
               double d=sqrt((x[k]-x[j])*(x[k]-x[j])+(y[k]-y[j])*(y[k]-y[j]));
               if(u[j]&&d<minn[j])
                  minn[j]=d;
            }
        }
			 
	}
	printf("%.2lf",total);
}
/* 
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;
int n,m,u,v;
double l[5001],na[5001],INF=99999999,mi,sum=0;
long long x[5001],y[5001];
void prim(int v0)
{
    sum=0;
    for(int i=1;i<=n;i++)
    {
        na[i]=v0;
        l[i]=sqrt((x[v0]-x[i])*(x[v0]-x[i])+(y[v0]-y[i])*(y[v0]-y[i]));
    }
    na[v0]=0;
    for(int i=1;i<n;i++)
    {
        v=0;
        mi=INF;
        for(int j=1;j<=n;j++)
            if(na[j]!=0&&mi>l[j])
            {
                mi=l[j];
                v=j;
            }
        if(v!=0)
        {
            na[v]=0;
            sum+=l[v];
            for(int j=1;j<=n;j++)
            {
               double kk=sqrt((x[v]-x[j])*(x[v]-x[j])+(y[v]-y[j])*(y[v]-y[j]));
              if(na[j]!=0&&kk<l[j])
                  l[j]=kk;
            
        }
    }
    printf("%.2f\n",sum);
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
       cin>>x[i]>>y[i];
    prim(1);
    return 0;
} */
