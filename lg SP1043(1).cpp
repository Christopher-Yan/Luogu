#include <iostream>
#include <cstdio>
#include <cmath>
						
#define root 1, n, 1
#define lson l, mid, u << 1
#define rson mid + 1, r, u << 1 | 1

using namespace std;

const int MAXN = 50010;

struct segmenttree{
	int l;
	int r;
	int w;
	int a;
	int f;
	int pre;
	int suf;
} t[MAXN << 2];

int n, m, x, y;
int ans;

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

void update(int u)
{
	t[u].pre = max(t[u<<1].pre, t[u<<1].w + t[u<<1|1].pre);
	t[u].suf = max(t[u<<1|1].suf, t[u<<1|1].w + t[u<<1].suf);
	t[u].w = max(max(t[u].pre, t[u].suf), t[u].w);
	return;
}

void build(int l, int r, int u)
{
	t[u].l = l;
	t[u].r = r;
	
	if (l == r)
	{
		t[u].f = 0;
		t[u].w = read();
		t[u].w = t[u].w;
		t[u].pre = t[u].w;
		t[u].suf = t[u].w;
		return;
	}
	
	int mid = (l + r) >> 1;
	build(lson);
	build(rson);
	update(u);
}

void Query(int l, int r, int u)
{
	if (l >= x && r <= y)
	{
		ans = max(ans, t[u].w);
		return;
	}
	
	int mid = (l + r) >> 1;
	if (x <= mid) Query(lson);
	if (y > mid) Query(rson);
	update(u);
}

int main()
{
	n = read();
	build(root);
	m = read();
	
	for (int i = 1; i <= m; ++i)
	{
		x = read();
		y = read();
		ans = -1;
		Query(root);
		cout << ans << endl;
	}
	return 0;
}
