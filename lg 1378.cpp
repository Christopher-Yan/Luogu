#include<bits/stdc++.h>
using namespace std;
const double pi=3.141592;
int n,x,y,x1,yx;
int a[7][3];
bool v[7];
double outt=-1;
double r[7];
double dis(int xx,int yy,int xx1,int yy1)
{
	return sqrt(pow((xx-xx1),2)+pow((yy-yy1),2));
}
double minn(int k)
{
	for(int i=1;i<=n;i++)
		if(i!=k&&v[i]==1)
			if(r[i]>dis(a[i][1],a[i][2],a[k][1],a[k][2])) return 0.0;
	double dist;
	double ans=min(min(abs(a[k][1]-x),abs(a[k][1]-x1)),min(abs(a[k][2]-y),abs(a[k][2]-yx)));
	for(int i=1;i<=n;i++)
		if(i!=k&&v[i]==1)
		{
			dist=dis(a[i][1],a[i][2],a[k][1],a[k][2])-r[i];
			ans=min(ans,dist);
		}
	return ans;
}
void dfs(int k,double res)
{
	double mm;
	if(k==n)
	{
		outt=max(outt,res);
		return;
	}
	for(int i=1;i<=n;i++)
		if(v[i]==0)
		{
			r[i]=minn(i);
			v[i]=1;
			dfs(k+1,res+pi*r[i]*r[i]);
			v[i]=0;
			r[i]=0;
		}
}
int main()
{
	scanf("%d",&n);
	scanf("%d%d%d%d",&x,&y,&x1,&yx);
	int s=abs(x-x1)*abs(y-yx);
	for(int i=1;i<=n;i++) scanf("%d%d",&a[i][1],&a[i][2]);
	dfs(0,0);
	cout<<int(s-outt+0.5);
}
