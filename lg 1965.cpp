#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
ll n,m,k,x;
ll mul(ll a,ll b,ll p) {ll ans=1; while (b) {if (b&1) ans=ans*a%p; a=a*a%p; b>>=1;} return ans%p;}
int main()
{
	cin >> n >> m >> k >> x;
	cout << (m*mul(10,k,n)+x)%n;
	return 0; 
}
