#include<bits/stdc++.h>
using namespace std;
int n,m,x,y;
int a[2000100];
int f[2000100][50];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		f[i][0]=a[i]; 
	}
	for(int j=1;(1<<j)<=n;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
			f[i][j]=min(f[i][j-1],f[i+(1<<j-1)][j-1]);
	printf("0\n");
	for(int i=2;i<=n;i++)
	{
		x=i-m;
		y=i-1;
		if(x<1) x=1;
		int k=log2(y-x+1);
		printf("%d\n",min(f[x][k],f[y-(1<<k)+1][k]));
	}
	return 0;
}
