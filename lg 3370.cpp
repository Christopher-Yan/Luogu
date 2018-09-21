#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>

#define ull unsigned long long

using namespace std;

const ull MAXN = 300030;
const ull base = 233;

char s[MAXN];

int n, l, cnt;
ull hs;
ull a[MAXN];
ull bit[MAXN];

void got_bit(void)
{
	bit[0] = 1;
	for (int i = 1; i <= n; ++i) bit[i] = bit[i - 1] * base;
}

void hash_it(char c[], int len)
{
	hs = 0;
	for (int i = 1; i <= len; ++i)
		hs = hs * base + c[i - 1];
	a[++cnt] = hs;
}

int main()
{
	cin >> n;
	while (n--)
	{
		cin >> s;
		int l = strlen(s);
		hash_it(s, l);
	}

	sort(a + 1, a + 1 + cnt);
	cout << unique(a + 1, a + 1 + cnt) - a - 1;

	return 0;
}
