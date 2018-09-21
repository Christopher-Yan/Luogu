#include<iostream>
#include<cstdio>

int n,q,x,ans;
int s[50050];

void erfen(int l,int r)
{
	int mid=(l+r)/2;
	if(l==r) 
	{
		ans=mid;
		return;
	}
	if(x<=s[mid]) erfen(l,mid);
	if(x>s[mid]) erfen(mid+1,r);
	
}

int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&x);
		s[i]=s[i-1]+x;
	}
	for(int i=1;i<=n;++i)
		--s[i];
	for(int i=1;i<=q;++i) 
	{
		scanf("%d",&x);
		erfen(1,n);
		printf("%d\n",ans);
	}
} 
