#include <iostream>
#include <cstdio>

using namespace std;

int n, m, sum;
int c[30];
int dp[10010];

int main()
{
	cin >> n;
	m = n / 2;
	for (int i = 1; i <= n; ++i) 
	{
		cin >> c[i]; 
		sum += c[i];
	}
	sum /= 2;
	
	for (int i = 1; i <= n; ++i)
	{
		for (int j = m; j >= c[i]; --j)
		{
			cout << c[i] <<endl;
  		 	if (dp[j] + c[i] <= sum) 
		 		dp[j] = max(dp[j], dp[j - 1] + c[i]);
		}
	}
		 
	cout << dp[m];
	
	return 0;
}
