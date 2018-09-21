#include <iostream>
#include <cstdio>
#define it long long

using namespace std;

it n, m;
it c[30];
it dp[10010];

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> c[i]; 
	
	dp[0] = 1;
	for (int i = 1; i <= n; ++i)
		 for (int j = 1; j <= m; ++j)
		 	if (j - c[i] >= 0)
		 		dp[j] += dp[j - c[i]];
	
	cout << dp[m];
	
	return (int)0;
}
