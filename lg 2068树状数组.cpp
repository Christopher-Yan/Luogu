#include<bits/stdc++.h>
using namespace std;
int c[501000],a,x,y,m,n;

char ch;

int lowbit(int x) {return x&-x;}

void change(int x,int k)
{
	for(int i=x;i<=n;i+=lowbit(i))
		c[i]+=k;
}

int ask(int x)
{
	int sum=0;
	for(int i=x;i;i-=lowbit(i))
		sum+=c[i];
	return sum;
}

int read()
{
	int x=0,k=1;
	char c=getchar();
	while(c>'9'||c<'0')
	{
		if(c=='-') k=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*k;
}

int main()
{
//	n=read();
//	m=read();
	cin>>n>>m; 
	for(int i=1;i<=m;i++) 
	{
//		char ch=getchar();
		cin>>ch>>x>>y;
//		x=read();
//		y=read();
		switch(ch)
		{
			case 'x':change(x,y);break;
			case 'y':printf("%d\n",ask(y)-ask(x-1));break;
			default:;
		}
	}
	return 0;
}
