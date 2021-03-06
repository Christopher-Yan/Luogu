#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[52001],b[52001],c[52001];
int ans,p1,p2;
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
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) a[i]=i;
	for(int i=1;i<=52000;i++) 
	{
		ans=0;
		for(int j=1;j<=n;j++) c[j]=a[j];
		merge_sort(1,n);
		for(int j=1;j<=n;j++) a[j]=c[j];
		if(ans==m) 
		{
			for(int j=1;j<=n;j++) printf("%d ",a[j]);
			return 0;
		}
		next_permutation(a+1,a+n+1);
	}
	return 0;
} 
