#include<bits/stdc++.h>
using namespace std;
long long g,l,J,y;
int ans=0;
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
int main()
{
	scanf("%lld%lld",&g,&l);
	J=g*l;
	for(int i=g;i*i<=J;i++)
	{
		if(J%i!=0) continue;
		if(g==gcd(i,J/i)) 
		{ans++;} 
	}
	cout<<(ans<<1);
	return 0;
}
