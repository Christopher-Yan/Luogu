#include <algorithm>
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdio>

#define root 1, n, 1
#define lson l, mid, u << 1
#define rson mid + 1, r, u << 1 | 1 

using namespace std;

const int MAXN = 1000000;

int tree[MAXN << 2];

int n, k, x, y;

int read()
{
	int x = 0;
	int k = 1;
	char c = getchar();
	
	while (!isdigit(c)) 
		if (c == '-') k = -1, c = getchar();
		else c = getchar();
	while (isdigit(c))
		x = x * 10 + c - '0',
		c = getchar();
		
	return k * x;
}

void pushup(int u) { tree[u] = tree[u << 1] + tree[u << 1 | 1]; }

void build(int l, int r, int u)
{
	if (l == r) return;
	
	int mid = (l + r) >> 1;
	
	build(lson);
	build(rson);
	
	return;
}

void down(int u)
{
	
}

void Change(int l, int r, int u)
{
	
}

int main()
{
	n = read();
	k = read();
	build(root);
	
	while (k--)
	{
		x = read();
		y = read();
		Change(root);
	}
}
