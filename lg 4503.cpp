#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef unsigned long long ull;

const int base = 233;

char s[30005][205];

int n;

ull hs[30005][205];
ull pw[205];

void hash_it(int x, char c[])
{
	hs[x][0] = 0;
	int n = strlen(c);
	for (int i = 1; i <= n; ++i)
	{
		hs[x][i] = hs[x][i - 1] * base + c[i];
	}
}

int main()
{
	cin >> n;

	pw[0] = 1;

	for (int i = 1; i <= 200; ++i) pw[i] = pw[i - 1] * base;
	for (int i = 1; i <= n; ++i)
	{
		cin >> s[i];
		hash_it(i, s[i]);

	}
}