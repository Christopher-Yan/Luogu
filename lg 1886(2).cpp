#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
struct node{
	int w;
	int num;
}a,b,q1[1001000],q2[1001000];
int h1=1,h2=1,t1=0,t2=0;
int out[1001000];
int n,k;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a.w);
		a.num=i;
		while(q1[t1].w>a.w&&h1<=t1) --t1;
		q1[++t1]=a;
		while(q2[t2].w<a.w&&h2<=t2) --t2;
		q2[++t2]=a;
		while(q1[h1].num<=i-k) ++h1;
		while(q2[h2].num<=i-k) ++h2;
		if(i>=k)
		{
			printf("%d ",q1[h1].w);
			out[i]=q2[h2].w;
		}
	}cout<<endl;
	for(int i=k;i<=n;i++)
		printf("%d ",out[i]);
	return 0;	
}
