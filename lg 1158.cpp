#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int a[101000],b[101000];
int now[3];
struct node{
	int a,b;
}e[104000];
bool cmp(node a,node b)
{
	return a.a>b.a;
}
int x[104000],y[102000];
int main()
{
	int x1,y1,x2,y2,n,k1,k2;
	cin>>x1>>y1>>x2>>y2;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i];
		e[i].a=pow(x[i]-x1,2)+pow(y[i]-y1,2);
		e[i].b=pow(x[i]-x2,2)+pow(y[i]-y2,2);
	}
	sort(e+1,e+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		if(e[i].b<=now[1]) continue;
		if(e[i].a<=now[2]) continue;
		if(e[i].a+now[2]<=e[i].b+now[1]) now[1]=e[i].a;
		else now[2]=e[i].b;
	}
	cout<<now[1]+now[2];
	return 0;
}

