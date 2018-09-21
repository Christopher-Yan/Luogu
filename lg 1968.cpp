#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 150;

int n;

double A[MAXN];
double dp[MAXN][3];

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> A[i];
	
	dp[1][1] = 100.0;
	dp[1][0] = A[1];
	
	for (int i = 2; i <= n; ++i)
	{
		dp[i][1] = max(dp[i - 1][0] / A[i] * 100.0, dp[i - 1][1]);
		dp[i][0] = max(dp[i - 1][1] / 100.0 * A[i], dp[i - 1][0]);
	}
	cout.setf(ios::fixed);
	cout.precision(2);
	cout << dp[n][1];
	
 	return 0;
}
