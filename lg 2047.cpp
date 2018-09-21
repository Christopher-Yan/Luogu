#include <iostream>
#include <cstdio>

using namespace std;

typedef long long LL;
typedef double DD;

const int INF = 1e9;

int n, m, x, y, z;
int dis[105][105];

LL c[105][105];

DD ans[105];

int read()
{
	int x = 0;
	int k = 1;
	char c = getchar();
	
	while (c > '9' || c < '0') 
		if (c == '-') k = -1, c = getchar();
		else c = getchar();
	while (c <= '9' && c >= '0')
		x = x * 10 + c -'0',
		c = getchar();
	
	return k * x;
}

int main()
{
	n = read();
	m = read();
	
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			dis[i][j] = INF,
			c[i][j] = 0;
	
	for (int i = 1; i <= n; ++i)
		dis[i][i] = 0;
	
	for (int i = 1; i <= m; ++i)
		x = read(),
		y = read(),
		z = read(),
		dis[x][y] = dis[y][x] = z,
		c[x][y] = c[y][x] = 1;
	
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
			if (dis[i][j] > dis[i][k] + dis[k][j])
				dis[i][j] = dis[i][k] + dis[k][j],
				c[i][j] = c[i][k] * c[k][j];
			else if (dis[i][j] == dis[i][k] + dis[k][j])
				c[i][j] += c[i][k] * c[k][j];
	
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				if (i != k && j != k && dis[i][k] + dis[k][j] == dis[i][j])
					ans[k] += (DD)c[i][k] * c[k][j] / (DD)c[i][j];  
	
	for (int i = 1; i <= n; ++i)
		printf("%.3lf\n", ans[i]);
	
	return 0; 
} 
