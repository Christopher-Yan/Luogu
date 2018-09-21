#include<bits/stdc++.h>
using namespace std;
int n,m,fx,fy,ans;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int v[1010][1010];
char mp[1010][1010];
int f[1010][1010]; 
queue <int> q;
void bfs()
{
	ans=1;
	q.push(fx);
	q.push(fy);
	v[fx][fy]=1;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		int y=q.front();q.pop();
		for(int i=0;i<=3;i++)
		{
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(v[nx][ny]==1||mp[nx][ny]==mp[x][y]||nx>n||nx<1||ny>n||ny<1) continue;
			v[nx][ny]=1;
			q.push(nx);
			q.push(ny);
			ans++;
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>mp[i][j];
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		for(int k=1;k<=n;k++) 
			v[j][k]=0;
		scanf("%d%d",&fx,&fy);
		bfs();
		printf("%d\n",ans);
	}
	return 0;
}
