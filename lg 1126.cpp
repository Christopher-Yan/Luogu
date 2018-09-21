#include<bits/stdc++.h>
#define INF 99999999
using namespace std;
int fx,fy,ex,ey,n,m,i,j,l=0,ans1=INF,k;
bool a[55][55],v[52][52][52][52];
int ddx[4][12]={-3,-2,-1,0,0,0,0,0,0,3,2,1, 0,0,0,3,2,1,-3,-2,-1,0,0,0, 3,2,1,0,0,0,0,0,0,-3,-2,-1, 0,0,0,-3,-2,-1,3,2,1,0,0,0};
int ddy[4][12]={0,0,0,3,2,1,-3,-2,-1,0,0,0, 3,2,1,0,0,0,0,0,0,-3,-2,-1, 0,0,0,-3,-2,-1,3,2,1,0,0,0, -3,-2,-1,0,0,0,0,0,0,3,2,1};
char direct;
int dx[12],dy[12];
int direc;
int direc3;
struct node{
	int x;
	int y;
	int d;
	int ans;
	bool operator < (const node & a) const
    {
        return ans > a.ans;
    }
}cur,now,fir,las;
priority_queue <node> q;
void bfs()
{
	q.push(fir);
	while(!q.empty())
	{
		now=q.top();q.pop();
		//if (now.x==fir.x||now.y==fir.y||now.x==5||now.y==44) cout<<now.x<<" "<<now.y<<endl; 
		if(now.d==1)  k=0;
		if(now.d==2)  k=1;
		if(now.d==3)  k=2;
		if(now.d==4)  k=3;
		for(j=0;j<12;j++)
			dx[j]=ddx[k][j],dy[j]=ddy[k][j];
 		for(i=0;i<12;i++)
		{
			if(i<=2) direc3=now.d;
			else if(i<=5) direc3=now.d+1;
			else if(i<=8) direc3=now.d-1;
			else if(i<=11) direc3=(now.d+2)%4;
			cur.x=now.x+dx[i];
			cur.y=now.y+dy[i];
			if(direc3==5) direc3=1;
			if(direc3==0) direc3=4;
			if(cur.x==fir.x && cur.y==fir.y) continue;
			bool f=true;
			if(cur.x==now.x) 
				for(j=min(now.y,cur.y);j<=max(now.y,cur.y);j++)
					if(a[now.x][j]==1) f=false;
			if(cur.y==now.y) 
				for(j=min(now.x,cur.x);j<=max(now.x,cur.x);j++)
					if(a[j][now.y]==1) f=false;
			if(!f) continue;
			if(a[cur.x][cur.y]==1||cur.x>=n||cur.x<1||cur.y>=m||cur.y<1) continue;
			if(v[cur.x][cur.y][now.x][now.y]==1) continue;
			int ml=abs(now.d-direc3);
			if(ml==3) ml=1;
			cur.ans=now.ans+ml+1;
		   // if(cur.x==fir.x||cur.y==fir.y||now.x==5||now.y==44)	cout<<cur.x<<" "<<cur.y<<" "<<cur.ans<<endl;
			if(cur.x==las.x && cur.y==las.y) 
				ans1=min(ans1,cur.ans);
			cur.d=direc3;
			q.push(cur);
			v[cur.x][cur.y][now.x][now.y]=1;
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j]==1) a[i-1][j-1]=1,a[i-1][j]=1,a[i][j-1]=1;
			if(i==0||j==0||i==n||j==m) a[i][j]=1;
		}			
	scanf("%d%d%d%d",&fir.x,&fir.y,&las.x,&las.y);
	cin>>direct;
	if(fir.x==las.x && las.y==fir.y) 
	{
		cout<<0<<endl;
		return 0;
	}
	if(direct=='N') direc=1;
	if(direct=='E') direc=2;
	if(direct=='S') direc=3;
	if(direct=='W') direc=4;
	fir.d=direc;
	fir.ans=0;
	bfs();
	if(ans1!=INF) 
	{
		cout<<ans1;
		return 0;
	}
	printf("-1");
	return 0;
}
