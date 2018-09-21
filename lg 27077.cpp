#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int a[100010],b[100101];
int n,s,m,cnt;

bool f[100100];

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

int main()
{
	m=read();
	n=read();
	s=read();
	a[0]=0;
	for(register int i=1;i<=n;++i)
	{
		a[i]=read();
		if(a[i]-a[i-1]>=s) b[++cnt]=i,f[i]=true;
	}
	if(m-a[n]>=s) b[++cnt]=n+1;
	a[n+1]=m;
	for(register int i=n;i>=1;--i)
	{
		if(!f[i]&&a[i+1]-a[i]>=s) b[++cnt]=i,f[i]=true;
	}
	if(cnt==n+1) printf("YES\n");
	else printf("NO");
	if(cnt==n+1)
		for(register int i=1;i<=cnt;++i) 
			printf("%d ",b[i]);
	printf("0"); 
	 
}
