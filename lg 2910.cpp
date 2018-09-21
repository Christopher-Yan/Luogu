#include<bits/stdc++.h>
using namespace std;
int n,m,a[110][110],b[11000],f[110][110],ans;
int main()
{
	scanf("%d%d",&n,&m);
	for(register int i=1;i<=m;i++) scanf("%d",&b[i]);
	for(register int i=1;i<=n;i++)
		for(register int j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
			f[i][j]=a[i][j];
		}
			
	for(register int k=1;k<=n;k++)
		for(register int i=1;i<=n;i++)
			for(register int j=1;j<=n;j++)
				if(f[i][k]+f[k][j]<f[i][j])
				f[i][j]=f[i][k]+f[k][j];
	for(register int i=2;i<=m;i++)
		ans+=f[b[i-1]][b[i]];
	printf("%d",ans);
	return 0;
}
