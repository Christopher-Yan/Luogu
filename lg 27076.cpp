#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
typedef long long ll;
int T;
ll n,m,p,q;
ll a[101001],b[101001];


int read()
{
	int x=0;
	int k=1;
	char c=getchar();
	while(c>'9'||c<'0')
	    if(c=='-') k=-1,c=getchar();
	    else c=getchar();
	while(c>='0'&&c<='9')
		x=x*10+c-'0',
		c=getchar();
	return x*k;
}

bool zz(ll x)
{
	for(register int i=2;i*i<=x;++i)
	{
		if(x%i==0) return 0;
	}
	return 1;
}

int main()
{
	T=read();
	while(T--)
	{
		q=1;
		p=1;
		n=read();
		m=read(); 
		for(register int i=1;i<=n;++i)
		{
			a[i]=read();
			
		}
			
		for(register int i=1;i<=m;++i)
		{
			b[i]=read();
			
		}
		std::sort(b+1,b+1+m);
		std::sort(a+1,a+n+1);
		int c=1;
		for(register int i=n;i>=1;--i)
		{
			q*=a[i];
			if(q%b[c]==0) q/=b[c],++c;
		}	
		for(register int i=c;i<=m;++i)
		{
			p*=b[i];
			
		}
		if(q%p==0&&zz(q/p)) printf("YES\n");
		else printf("NO\n");
		
	}
}
