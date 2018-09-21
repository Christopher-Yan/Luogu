#include<bits/stdc++.h>
using namespace std;
int n,m,ans,fx,fy,ex,ey,nx,ny;
bool v[1010][100100];
bool a[1010][100100];
queue <int> q;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
char c;
void bfs()
{
	q.push(fx);
	q.push(fy);
	v[fx][fy]=1;
	while(!q.empty())
	{
		nx=q.front();
		ny=q.front();
		int xx=nx;
		int yy=ny;
		q.pop();q.pop();
		for(int i=0;i<4;i++)
		{
			nx+=dx[i];
			ny+=dy[i];
			if(!v[nx][ny] && nx>0 && nx<n && ny>0 && ny<m && a[nx][ny]!=a[xx][yy])
			{
				v[nx][ny]=1;
				q.push(nx);
				q.push(ny);
				ans++;
			}
		}
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			cin>>c;
			a[i][j]=c-48;
		}
	cin>>fx>>fy>>ex>>ey;
	bfs();
	cout<<ans;
 } 
