#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 5050;

int SW, LW; 
int n, m, x, T;
int c[MAXN];
int p[MAXN];
int w[MAXN];
int dp[MAXN];

int read()
{
	int x = 0;
	int k = 1;
	char c = getchar();
	
	while (c > '9' || c < '0')
		if (c == '-') k = -1, c = getchar();
		else c = getchar();
	while (c >= '0' && c <= '9')
		x = x * 10 + c - '0',
		c = getchar();

	return k * x;
} 

int main()
{
	SW = read();
	LW = read();
	T = LW / SW;
	m = read();
	n = read();
	for (int i = 1; i <= n; ++i) x = read(), c[i] = x * T;
	for (int i = 1; i <= m; ++i) p[i] = read(), w[i] = read();
	T = read();
	
	for (int i = 1; i <= m; ++i)
	{
		for (int j = T; j >= c[p[i]]; --j)
		{
			dp[j] = max(dp[j], dp[j - c[p[i]]] + w[i]);
		}
	} 
	
	
	cout << dp[T];
	return 0;
}
