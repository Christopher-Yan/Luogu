#include<bits/stdc++.h>
using namespace std;
int n,m,fx,fy,ans;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int v[1050][1050];
int gg[105010][2];
char mp[1050][1050];
int f[1050][1050]; 
void dfs(int x,int y)
{
	ans++;
	gg[ans][0]=x;
	gg[ans][1]=y;
	v[x][y]=1;
	for(int i=0;i<4;i++)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(v[nx][ny]==1||mp[nx][ny]==mp[x][y]||nx>n||nx<1||ny>n||ny<1) continue;
		
		dfs(nx,ny);
	}
	return;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>mp[i][j];
	while(m--)
	{
		scanf("%d%d",&fx,&fy);
		if(v[fx][fy])
		{
			printf("%d\n",f[fx][fy]);
			continue;
		}
		ans=0;
		dfs(fx,fy);
		for(int i=1;i<=ans;i++)
		f[gg[i][0]][gg[i][1]]=ans;
		printf("%d\n",ans);
	}
	return 0;
}
