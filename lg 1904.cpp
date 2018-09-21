#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>

#define root 1, n, 1
#define lson l, mid, u << 1
#define rson mid + 1, r, u << 1 | 1

using namespace std;

const int MAXN = 10010;

struct Segment_Tree {
	int w;
	int f;
}t[MAXN << 2];

struct Ask {
	int x;
	int y;
	int z;
	bool operator < (const Ask &A) const {
		return this->z > A.z;
	}
}a[MAXN >> 1];

int x, y, z;

void update(int u)
{
	t[u].w = t[u << 1].w + t[u << 1 | 1].w;
}

void down(int fa, int l, int r, int u)
{
	t[u].f = t[fa].f;
	if (u % 2 != 0) t[fa].f = 0;
	return;
}

void build(int l, int r, int u)
{
	t[u].f = 0;
	if (l == r)
	{
		t[u].w = 0;
		return;
	}

	int mid = (l + r) >> 1;
	
	build(lson);
	build(rson);

	update(u);
}

void change(int l, int r, int u)
{
	if (l >= x && r <= y)
	{
		t[u].w = z * (r - l + 1);
		t[u].f = z;
		return;
	}

	int mid = (l + r) >> 1;

	down(u, lson);
	down(u, rson);

	if (x <= mid) change(lson);
	if (y > mid) change(rson);

	update(u);
	return;
}

int query(int l, int r, int u)
{
	if (l == x && r == x) return t[u].w;
	if (l > x || r < x) return 0;

	int mid = (l + r) >> 1;

	down(u, lson);
	down(u, rson);
	int ans = 0;
	ans += query(lson);
	ans += query(rson);

	return ans;
}

int main()
{
	int n = 10000;
	int las = 0;
	int cnt = 1;
	bool f = true;
	while (cin >> a[cnt].x >> a[cnt].z >> a[cnt].z)	++cnt;

	sort(a + 1, a + 1 + cnt);

	for (int i = 1; i <= cnt; ++i)
	{
		x = a[i].x;
		y = a[i].y;
		z = a[i].z;
		change(root);
	}
	for (int i = 1; i <= n; ++i)
	{
		x = i;
		int now = query(root);
		cout << now << " ";
		if (now != las)
		{
	//		cout << i << " ";
			x = i + 1;
	//		int cur = query(root);
	//		if (cur < now) cout << cur << " ";
	//		else cout << now << " ";
		}
		las = now;
	}
	char c = getchar();
	return 0;
}












