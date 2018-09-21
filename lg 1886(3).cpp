#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int r[1000100][20];
int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&r[i][0]);
	for(int j=1;(1<<j)<=n;++j)
		for(int i=1;i+(1<<j)-1<=n;++i)
			r[i][j]=min(r[i][j-1],r[i+(1<<(j-1))][j-1]);
	int k=log2(m);
	for(int i=1;i<=n-m+1;++i) printf("%d ",min(r[i][k],r[i+m-(1<<k)][k]));printf("\n");
	for(int j=1;(1<<j)<=n;++j)
		for(int i=1;i+(1<<j)-1<=n;++i)
			r[i][j]=max(r[i][j-1],r[i+(1<<(j-1))][j-1]);
	for(int i=1;i<=n-m+1;i++) printf("%d ",max(r[i][k],r[i+m-(1<<k)][k]));
}
