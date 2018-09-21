#include<bits/stdc++.h>
using namespace std;
int n;
int a[16];
int s[16];
int xs[1600];
int sx[1600];
int sum=0;
void solve(int cur)
{
	if(cur==n+1)
	{
		++sum;
		if(sum>3) return;
		for(int i=1;i<=n;i++) printf("%d ",a[i]);
		printf("\n");
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(s[i]==1 || xs[cur+i]==1 || sx[cur-i+100]==1) continue;
		s[i]=1;
		a[cur]=i;
		xs[cur+i]=1;
		sx[cur-i+100]=1;
		solve(cur+1);
		s[i]=0;
		a[cur]=0;
		xs[cur+i]=0;
		sx[cur-i+100]=0;
	}
}
int main()
{
	scanf("%d",&n);
	solve(1);
	printf("%d",sum);
	return 0;
 } 
