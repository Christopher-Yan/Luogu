#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,s[200050],x,mins=99999999,maxs=-99999999,ds,ms,maxx=-99999999;
int main()
{
	s[0]=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)	
	{
		scanf("%d",&x);
		s[i]=s[i-1]+x;
		if(s[i]>=maxs) 	maxs=s[i],ds=i;
	}
	for(int i=1;i<=n;i++)
	{
		mins=99999999,maxs=-99999999;
		for(int j=1;j<i;j++) 
			if(s[j]>=maxs) 	maxs=s[j],ds=j;
		for(int j=1;j<i;j++) 
			if(s[j]<=mins) 	mins=s[j],ms=j;
		if(ds!=ms&&ds>ms&&mins<0) maxx=max(maxx,maxs-mins);
		
	}
	cout<<maxx;
} 
