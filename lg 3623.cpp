#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 201010;

int n, m, K, x, y, z, aid, bid;
int fa[MAXN];

struct edge{
	int u;
	int v;
}a[MAXN], b[MAXN];

bool va[MAXN], vb[MAXN];

int read()
{
	int x = 0;
	int k = 1;
	char c = getchar();
	
	while (c > '9' || c < '0')
		if (c == '-') k = -1, c = getchar();
		else c = getchar();
	while (c <= '9' && c >= '0')
		x = (x << 1) + (x << 3) + c - '0',
		c = getchar();
		
	return k * x;
}

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

int main()
{
	n = read();
	m = read();
	K = read();
	
	for (int i = 1; i <= m; ++i)
	{
		x = read();
		y = read();
		z = read();
		if (z == 1) a[++aid].u = x, a[aid].v = y;
		else b[++bid].u = x, b[bid].v = y;
	} 
	
	if (bid < K) 
	{
		cout << "no solution";
		return 0;
	}
	
	for (int i = 1; i <= n; ++i) fa[i] = i; 
	
	for (int i = 1; i <= aid; ++i)
		if (find(fa[a[i].u]) != find(fa[a[i].v])) 
			fa[find(a[i].u)] = find(fa[a[i].v]);
	
	int tmp = 0;
	
	for (int i = 1; i <= bid; ++i)
		if (find(fa[b[i].u]) != find(fa[b[i].v])) 
			fa[find(b[i].u)] = find(fa[b[i].v]),
			vb[i] = true,
			++tmp;
			
	if (tmp > K) 
	{
		cout << "no solution";
		return 0;
	}
	
	for (int i = 2; i <= n; ++i)
		if (find(i) != find(i - 1))
		{
			cout << "no solution";
			return 0;
		}
			
	for (int i = 1; i <= n; ++i) fa[i] = i;
	
	for (int i = 1; i <= bid; ++i) 
		if (vb[i])
			fa[find(b[i].u)] = find(fa[b[i].v]);
	
	for (int i = 1; i <= bid && tmp < K; ++i)
		if (!vb[i] && find(b[i].u) != find(b[i].v))
			++tmp,
			fa[find(b[i].u)] = find(fa[b[i].v]),
			vb[i] = true;
	
	if (tmp < K) 
	{
		cout << "no solution";
		return 0;
	}
	
	for (int i = 1; i <= aid; ++i)
		if (find(a[i].u) != find(a[i].v))
			va[i] = true,
			fa[find(a[i].u)] = find(fa[a[i].v]);
			
	for (int i = 1; i <= bid; ++i)
		if (vb[i])
			printf("%d %d %d\n", b[i].u, b[i].v, 0);
			
	for (int i = 1; i <= aid; ++i)
		if (va[i])
			printf("%d %d %d\n", a[i].u, a[i].v, 1);
			
	return 0;
}
