#include<bits/stdc++.h>
#define MAXN 41000
using namespace std;
int n,a[MAXN],b[MAXN],ans,p1,p2;
void merge_sort(int l,int r)
{
	if(l==r) return;
	int m=(l+r)>>1;
	merge_sort(l,m);
	merge_sort(m+1,r);
	p1=l,p2=m+1;
	for(int i=l;i<=r;i++)
		if(p1<=m && p2<=r)
			if(a[p1]<=a[p2]) b[i]=a[p1++];
			else b[i]=a[p2++],ans+=m-p1+1;
		else 
			if(p1<=m) b[i]=a[p1++];
			else b[i]=a[p2++];
	for(int i=l;i<=r;i++) a[i]=b[i];
}
int main()
{
	scanf("%d",&n);
	for(register int i=1;i<=n;i++) scanf("%d",&a[i]);
	merge_sort(1,n);
	printf("%d",ans);
	return 0;
} 
