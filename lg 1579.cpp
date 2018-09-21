#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define N 20000
using namespace std;
int prim[3000];
int k=0,n;
bool v[N];
bool pd(int);
void build()
{
	memset(v,0,sizeof(v));
	for(int i=2;i<=20000;i++)
	{
		if(v[i]==0)
		{	
			prim[++k]=i;
			for(int j=1;i*j<=N;j++) v[i*j]=1;
		} 
	}
}
bool pd(int x)
{
	if(x==0) return 0;
	for(int i=2;i<=sqrt(x);i++) if(x%i==0) return false;
	return true;
}
int main()
{
	build(); 
	cin>>n;
	for(int i=1;i<=k;i++)
	{
		if(prim[i]>=n) continue;
		for(int j=1;j<=k;j++)
		{
			if(prim[j]>=n) continue;
			if(pd(n-prim[i]-prim[j])==true) 
			{
				printf("%d %d %d",prim[i],prim[j],n-prim[i]-prim[j]); 
				return 0;
			}
		}
	}
		
}
