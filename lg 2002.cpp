#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAXN = 500010;

int n, m, cnt, top, sid, col, ans, x, y;
int f[MAXN >> 2];
int c[MAXN >> 2];
int ind[MAXN >> 2];
int stk[MAXN >> 2];
int dfn[MAXN >> 2];
int low[MAXN >> 2];

bool instk[MAXN >> 2];

struct edge{
	int u;
	int v;
	int next;
}e[MAXN];

int read()
{
	int x = 0;
	int k = 1;
	char c = getchar();
	
	while (c < '0' || c > '9')
		if (c == '-') k = -1, c = getchar();
		else c = getchar();
	while (c <= '9' && c >= '0')
		x = x * 10 + c - '0',
		c = getchar();
	
	return k * x;
} 

void Addedge(int x, int y)
{
	++cnt;
	e[cnt].u = x;
	e[cnt].v = y;
	e[cnt].next = f[x];
	f[x] = cnt;
}

void dfs(int u)
{
	dfn[u] = low[u] = ++sid;
	stk[++top] = u;
	instk[u] = true;
	
	for (int i = f[u]; i != -1; i = e[i].next)
		if (!dfn[e[i].v]) 
		{
			dfs(e[i].v);
			low[u] = min(low[u], low[e[i].v]);
		}
		else if (instk[e[i].v]) 
			low[u] = min(low[u], dfn[e[i].v]);
	
	int cur;
	if (dfn[u] == low[u])
	{
		++col;
		while (cur != u)
		{
			cur = stk[top--];
			instk[cur] = false;
			c[cur] = col;
		}
		instk[u] = false;		
	}
}

int main()
{
	n = read();
	m = read();
	
	memset(f, -1, sizeof(f));
	
	for (int i = 1; i <= m; ++i)
	{
		x = read();
		y = read();
		Addedge(x, y);
	}
	
	for (int i = 1; i <= n; ++i)
		if (!dfn[i]) dfs(i);
		
	for (int i = 1; i <= m; ++i)
		if (c[e[i].v] != c[e[i].u])
			++ind[c[e[i].v]];
	
	for (int i = 1; i <= col; ++i)
		if (ind[i] == 0) ++ans;
		
	cout << ans;
}
