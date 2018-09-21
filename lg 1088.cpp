#include<bits/stdc++.h>
using namespace std;
int n,a[10100],m;
int main()
{
	scanf("%d%d",&n,&m);
	for(register int i=1;i<=n;i++) scanf("%d",&a[i]);
	while(m--) next_permutation(a+1,a+1+n);
	for(register int i=1;i<=n;i++) printf("%d ",a[i]);
}
