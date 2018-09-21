#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[210][210],f[210][210],maxn=-999999;
int main()
{
	scanf("%d%d",&n,&m);
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	int mid=m/2+1,k=1;
	for(int i=n;i>=1;i--)
	{
		if(m==1) k=0;
		for(int j=mid-k;j<=mid+k;j++)
			f[i][j]=max(max(f[i+1][j-1],f[i+1][j]),f[i+1][j+1])+a[i][j];
		if(k<<1+1<m) k++;  
	}
	for(int i=mid-k;i<=mid+k;i++)
		if(f[1][i]>maxn) maxn=f[1][i];
	printf("%d",maxn);
	return 0;
} 
