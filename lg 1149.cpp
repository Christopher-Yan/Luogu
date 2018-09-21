#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int d[10]={6,2,5,5,4,5,6,3,7,6},ans=0,n;
int main()
{
	scanf("%d",&n);
	n=n-4;
	for(int i=0;i<=720;i++)
		for(int j=0;j<=720;j++)
		{
				int x=i;
				int y=j;
				int z=i+j;
				int k1=0,k2=0,k3=0;
				if(i==0) k1=6;
				if(j==0) k2=6;
				while(z>0)	k3+=d[z%10],z/=10;
				while(x>0)	k1+=d[x%10],x/=10;
				while(y>0)	k2+=d[y%10],y/=10;
				if(k1+k2+k3==n) 
					ans++;		
		}
	printf("%d",ans);
	return 0;
}
