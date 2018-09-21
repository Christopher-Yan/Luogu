#include<bits/stdc++.h>
using namespace std;
int n,t;
int sum=0;
int a[12992];
int ans=999999;
struct node{
	int x;
	int y;
}b[210000];
int top=0;
bool cmp(node q1,node q2)
{
	if(q1.x==q2.x) return q1.y<q2.y;
	return q1.x<q2.x;
}
void dfs(int now,int rw)
{
	if(now>t) return;
	bool flag=false;
//	cout<<now<<" "<<sum<<endl;
	for(int i=rw+1;i<=n;i++)
	{
		if(b[i].x>=now&&b[i].x+b[i].y-1<=t)
		{
			flag=true;
			sum+=b[i].y;
			a[++top]=i;
			if(sum>ans) return;
			dfs(b[i].x+b[i].y,i);
			--top;
			sum-=b[i].y;
		}
	}
	if(!flag) 
	{
		for(int i=1;i<=top;i++)
			cout<<a[i]<<" ";
		cout<<top<<endl;
		ans=min(ans,sum);
	}
}
int main()
{
	scanf("%d%d",&t,&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&b[i].x,&b[i].y);
	sort(b+1,b+n+1,cmp);
	cout<<endl<<endl;
	for(int i=1;i<=n;i++) cout<<b[i].x<<" "<<b[i].y<<endl;
	cout<<endl;
	dfs(1,0);
	cout<<ans;
} 
