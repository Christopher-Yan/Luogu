#include <iostream>
#include <cstdio> 
#include <cstring>
#include <cmath>

using namespace std;

const int MAXN = 2010;

short ma[MAXN][MAXN];

int n,m,lz,rz,ans,bns;
int up[MAXN][MAXN];
int left_[MAXN][MAXN];
int right_[MAXN][MAXN];

int read()
{
	int x = 0;
	char c = getchar();
	
	while(c>'9' || c<'0')  c = getchar();
	while(c>='0' && c<='9')
		x = x*10 + c - '0',
		c = getchar();
		
	return x;
}

void color_(int c)
{
	memset(up, 0, sizeof(up));
	memset(left_, 0, sizeof(left_));
	memset(right_, 0, sizeof(right_));
	
	for (int i = 1; i <= m; ++i)
		left_[0][i] = 999999999,
		right_[0][i] = 999999999;
	
	for (int i = 1; i <= n; ++i)
	{
		lz = 0;
		for (int j = 1; j <= m; ++j)
			if (ma[i][j] != c) 
			{
				lz = j;
				left_[i][j] = 99999999;
				continue;
			}
			else
			{
				up[i][j] = up[i - 1][j] + 1;
				left_[i][j] = min(left_[i - 1][j], j - lz);
			}
				
	}
		
	for (int i = 1; i <= n; ++i)
	{
		rz = m + 1;
		for (int j = m; j >= 1; --j)
			if (ma[i][j] != c) 
			{
				rz = j;	
				right_[i][j] = 99999999;
				continue;
			}
			else
				right_[i][j] = min(right_[i - 1][j], rz - j);
	}
		
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			ans = max(ans, up[i][j] * (left_[i][j] + right_[i][j] - 1));
			bns = max(bns, min(up[i][j], (left_[i][j] + right_[i][j] - 1)) * min(up[i][j], (left_[i][j] + right_[i][j] - 1)));
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
		{
			scanf("%d", &ma[i][j]);
			if ((i + j) & 1) ma[i][j] = abs(ma[i][j] - 1);
		}
	ans = -1;
	bns = -1;
	color_(1);
	color_(0);
	cout << bns << endl << ans;
}
