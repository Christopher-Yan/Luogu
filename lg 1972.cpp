#include <algorithm>
#include <iostream> 
#include <cstring>
#include <cstdio>

#define root 1, n, 1
#define lson l, mid, u << 1
#define rson mid + 1, r, u << 1 | 1

using namespace std;

const int MAXN = 1001010;

struct Segment_Tree{
	int w;
}t[MAXN << 2];

struct Ask{
	int left;
	int right;
	int num;
	bool operator < (const Ask &aa) const{
		return right < aa.right;
	}
}a[MAXN >> 1];

int ANS[MAXN];
int n, m, x, y, ans;
int pre[MAXN];
int ar[MAXN];

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
		
	return x * k;
}

void update(int u)
{
	t[u].w = t[u << 1].w + t[u << 1 | 1].w;
}

void build(int l, int r, int u)
{
	if (l == r)
	{
		t[u].w = 1;
		return;
	}
	
	int mid = (l + r) >> 1;
	
	build(lson);
	build(rson);
	
	update(u); 
}

void Change(int l, int r, int u)
{
	if(l == r && x == l)
	{
		t[u].w = 0;
		return;
	}
	
	int mid = (l + r) >> 1;
	
	if (x <= mid) Change(lson);
	if (x > mid) Change(rson);
	
	update(u);
}

int query(int l, int r, int u)
{
	if (r < x || l > y)
		return 0;
	if (l >= x && r <= y)
		return t[u].w;
	int mid = (l + r) >> 1;
	return query(lson) + query(rson); 
}

void Query(int l, int r, int u)
{
	if (l >= x && r <= y)
	{
		ans += t[u].w;
		return;
	}
	
	int mid = (l + r) >> 1;
	
	if (x <= mid) Query(lson);
	if (y > mid) Query(rson);
}

int main()
{
	n = read();
	for (int i = 1; i <= n; ++i) 
		ar[i] = read();
		
	build(root);
	
	m = read();
	for (int i = 1; i <= m; ++i) a[i].left = read(), a[i].right = read(),a[i].num = i;

	memset(pre, -1, sizeof pre);
	
	int now = 1;
	
	sort(a + 1, a + 1 + m);

	for (int i = 1; i <= n; ++i)
	{
		if (pre[ar[i]] != -1)
		{
			x = pre[ar[i]];
			Change(root);
			pre[ar[i]] = i;
		}
		else pre[ar[i]] = i;
		
		while (i == a[now].right)
		{
			x = a[now].left;
			y = a[now++].right;
			ans = 0;
			Query(root);
			ANS[a[now - 1].num] = ans;
		}
	}
	
	for (int i = 1; i <= m; ++i)
	{
		cout << ANS[i] <<endl;
	}
	return 0;
}
