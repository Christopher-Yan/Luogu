#include<bits/stdc++.h>
using namespace std;
int n,fl;
long long fr;
struct hand{
	long long l;
	long long r;
	long long z;
}h[1010];
bool cmp(hand a,hand b) {return a.z<b.z;}
int main()
{
	scanf("%d",&n);
	scanf("%d%d",&fl,&fr);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&h[i].l,&h[i].r);
		h[i].z=h[i].l*h[i].r;
	}
	sort(h+1,h+1+n,cmp);
	long long ans=fl;
	for(int i=1;i<n;i++)
		ans*=h[i].l;
	printf("%lld",ans/h[n].r);
	return 0;
}


/*
l1 r1    l2 r2
l2 r2	 l1 r1
   两种情况 

l1/r2 与 l2/r1 比较
去分母后：r1*l1 与 r2*l2 比较
So r*l的值越小，排位越靠前，sort一遍,搞定 

*/ 

