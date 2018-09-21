#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,m,p[26],w[26],f[30100],x;
int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d",&w[i],&x);
		p[i] = x * w[i];
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = n; j >= 1; j--)
		{
			if(w[i] <= j) f[j] = max(f[j],f[j - w[i]] + p[i]);
			else f[j] = f[j];
		}
	}
	cout<<f[n];
} 
