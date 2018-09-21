#include<bits/stdc++.h>
using namespace std;
int n,m,a[100100];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int ans1=1;
	int ans2=1;
	int cur1=0;
	int cur2=0;
	for(int i=1;i<=n;i++)
	{
		cur1+=a[i];
		cur2+=a[n-i+1];
		if(i==n&&cur1==6)	ans1--;
		if(i==1&&cur2==6)	ans2--;
		if(cur1>6) ans1++,cur1=a[i];
		if(cur2>6) ans2++,cur2=a[n-i+1];
	}
	ans1=min(ans1,ans2);
	printf("%d",ans1);
	return 0;
}
