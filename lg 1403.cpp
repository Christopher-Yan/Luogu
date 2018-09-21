#include<bits/stdc++.h>
using namespace std;
int n,ans;
int main()
{
	scanf("%d",&n);
	for(register int i=1;i<=n;i++) ans+=n/i;
	printf("%lld",ans);
	return 0;
} 
