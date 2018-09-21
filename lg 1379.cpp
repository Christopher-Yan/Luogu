#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll n;
short a[4][4],fx,fy,nx,ny;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
queue<ll> q;
map<ll,int> v;
map<ll,int> ans;
void solve()
{
	q.push(n);
	ans[n]=0;
	v[n]=1;
	while(!q.empty())
	{
		ll now,cur=q.front();
		q.pop();
		now=cur;
		for(int i=3;i>=1;i--)
			for(int j=3;j>=1;j--)
			{
				a[i][j]=now%10,now/=10;
				if(a[i][j]==0) fx=i,fy=j;
			}
//		for(int p=1;p<=3;p++)
//		{
//			for(int j=1;j<=3;j++)
//				cout<<a[p][j]<<" ";
//			cout<<endl;
//		}
		for(int i=0;i<4;i++)
		{
			nx=fx+dx[i];
			ny=fy+dy[i];
			if(nx<1 || nx>3 || ny<1 || ny>3) continue;
			swap(a[fx][fy],a[nx][ny]);
			now=0;
			for(int p=1;p<=3;p++)
				for(int j=1;j<=3;j++)
					now=now*10+a[p][j];
			if(v[now]==1) 
			{
				swap(a[fx][fy],a[nx][ny]);
				continue;
			}
			if(now==123804765)
			{
				printf("%d",ans[cur]+1);
				exit(0);
			}
			else
			{
				ans[now]=ans[cur]+1;
//				for(int p=1;p<=3;p++)
//		{
//			for(int j=1;j<=3;j++)
//				cout<<a[p][j]<<" ";
//			cout<<endl;
//		}
				v[now]=true;
				q.push(now);
			}
			swap(a[fx][fy],a[nx][ny]);
		}	
	}
}
int main()
{
	scanf("%lld",&n);
	if(n==123804765) 
	{
		printf("0");
		return 0;
	}
	solve();
}
