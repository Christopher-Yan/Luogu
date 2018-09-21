#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int read()
{
	int x = 0;
	int k = 1;
	char c = getchar();
	
	while (c > '9' || c < '0') 
		if (c == '-') c = getchar(), k = -1;
		else c = getchar();
	while (c <= '9' && c >= '0')
		x = x * 10 + (c ^ 48),
		c = getchar();
	
	return k * x; 
}

int n;
int bed[60];

int ch;

bool g[60][60];
bool inscl[60]; 
bool gohom[60];
bool use[60];

bool find(int i)
{
	for (int j = 1; j <= n; ++j)
		if (!use[j] && g[i][j] && inscl[j])
		{
			use[j] = 1;
			if (!bed[j] || find(bed[j]))
			{
				bed[j] = i;
				return true;
			}
		}
	return false;
}

int main()
{
	int T = read();
	while (T--)
	{
		memset(g, 0, sizeof(g));
		memset(bed, 0, sizeof(bed));
		memset(inscl, 0, sizeof(inscl));
		memset(gohom, 0, sizeof(gohom));
		n = read();
		
		for (int i = 1; i <= n; ++i)
			inscl[i] = read();
		for (int i = 1; i <= n; ++i)
		{
			gohom[i] = read();
			if (inscl[i] && !gohom[i]) g[i][i] = 1;
		}		
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
			{
				ch = read();
				if (ch && inscl[j]) g[i][j] = 1;
			}
		bool flag = true;
		for (int i = 1; i <= n; ++i)
			if (!inscl[i] || (!gohom[i] && inscl[i]))
			{
				memset(use, 0, sizeof(use));
				if((!inscl[i] || !gohom[i]) && !find(i)) { flag = false; break; }
			}
		if (flag) puts("^_^");
		else puts("T_T");
	}
	return 0;
}
