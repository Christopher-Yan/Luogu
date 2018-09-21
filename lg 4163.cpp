#include<bits/stdc++.h>
using namespace std;
int T,m;
int top;
int a[12],b[12];
bool v[12];
map<long long,bool> M;
string c;
int ans=0;
void solve(int n,int p)
{
	cout<<p<<" ";
	if(n==top+1)
		if(p==0) ans++;
	for(int i=1;i<=top;i++)
	{
		if(!v[i])
		{
			v[i]=1;
			while(p>=m) p-=m;
			solve(n-1,p*10+a[i]);
			v[i]=0;
		}
	}
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		top=0;
		M.clear();
		ans=0;
		cin>>c;
		int l=c.size();
		for(int i=0;i<l;i++) a[++top]=c[i]-'0';
		scanf("%d",&m);
		solve(1,0);
		printf("%d\n",ans);
	}
}
