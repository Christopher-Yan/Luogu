#include<bits/stdc++.h>
using namespace std;
int T;
int A,B,G;
bool v[300][300];
struct dinner{
	int a;
	int b;
	int tot;
}fir,cur,now;
queue<dinner> q;
inline void fill(int k)
{
	if(k==1) cur.a=A; 
	else cur.b=B;
	return;
}
inline void empty(int k)
{
	if(k==1) cur.a=0;
	else cur.b=0;
	return;
}
inline void pour(int k)
{
	if(k==1)
	{
		cur.b+=cur.a;
		cur.a=0;
		if(cur.b>B) cur.a=cur.b-B,cur.b=B;
	}
	if(k==2)
	{
		cur.a+=cur.b;
		cur.b=0;
		if(cur.a>A) cur.b=cur.a-A,cur.a=A;
	}
	return;
}
void solve()
{
	fir.a=0;
	fir.b=0;
	v[0][0]=1;
	fir.tot=0;
	q.push(fir);
	while(!q.empty())
	{
		now=q.front();
		q.pop();
		cur=now; 
		if(cur.a==G||cur.b==G) {printf("%d",cur.tot);exit(0);}
		for(int i=1;i<=6;i++)
		{
			cur=now;
			bool f=false;
			if(i==1&&cur.a!=A) {fill(1);f=!f;}
			if(i==2&&cur.b!=B) {fill(2);f=!f;}
			if(i==3&&cur.a!=0) {empty(1);f=!f;}
			if(i==4&&cur.b!=0) {empty(2);f=!f;}
			if(i==5&&cur.b!=0&&cur.a!=A) {pour(2);f=!f;}
			if(i==6&&cur.a!=0&&cur.b!=B) {pour(1);f=!f;}
			if(f&&!v[cur.a][cur.b])
			{
				v[cur.a][cur.b]=1;
				cur.tot++;
				q.push(cur);
			}
		}
	}
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		memset(v,0,sizeof v);
		scanf("%d%d%d",&A,&B,&G);
		solve();
	}
} 
