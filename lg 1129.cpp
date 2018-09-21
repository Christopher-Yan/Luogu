#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

int n, T;
int got[210];
int used[210];
int g[210][210];

bool DFS(int x) 
{
	for (int j = 1; j <= g[x][0]; j++)if (!used[g[x][j]]) 
	{
		used[g[x][j]] = 1;
		if (!got[g[x][j]] || DFS(got[g[x][j]])) { got[g[x][j]] = x; return 1; }
	}
	return 0;
}

int main()
{
	cin >> T;
	int a;
	while (T--)
	{
		int ans = 0, l;
		cin >> n;
		for (int i = 1; i <= n; ++i)
		{
			g[i][0] = 0;
			got[i] = 0;
			for (int j = 1; j <= n; ++j)
			{
				cin >> a;
				if (a == 1)
					g[i][++g[i][0]] = j;
			}
		}
				
		for (int i = 1; i <= n; ++i)
		{
			memset(used, false, sizeof(used));
			if (DFS(i)) ++ans;
		}
	
		if (ans == n) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}