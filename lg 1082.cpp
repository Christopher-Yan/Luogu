#include<iostream>
#include<cstdio>

using namespace std;

typedef long long ll;

ll a,b;

void ex_gcd(ll a,ll b,ll &x,ll &y)
{
	if (b==0)
	{
		x = 1;
		y = 0;
		return;
	}
	ex_gcd(b,a%b,x,y);
	ll tmp = y;
	y = x-y*(a/b);
	x = tmp;
}

int main()
{
	ll x,y;
	cin >> a >> b;
	ex_gcd(a,b,x,y);
	while (x<=0) x+=b;
	cout << x;
}
