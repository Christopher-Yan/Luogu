#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <cmath>

using namespace std;

int n, m, q, u, v, t, lx, ly = 1, lz = 1, rx, ry, rz;
int x[100020];
int y[100020];
int z[100020];
int zk = 0;

double p;

priority_queue <int> Q;

bool cmp(const int & a, const int & b) { return a > b; }

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

void cut(bool flag)
{
    short llll = 1;
    int lar = -99999999;
    if (lx <= rx && lar < x[lx]) lar = x[lx++], llll = 3;
    if (ly <= ry && lar < y[ly])
    {
        if (llll == 3) --lx;
        lar = y[ly++], llll = 0;
    }
    if (lz <= rz && lar < z[lz])
    {
        lar = z[lz++];
        if (llll == 3) --lx;
        if (llll == 0) --ly;
    }
    lar += zk;

    if (flag) printf("%d ", lar);

    int f1 = floor(lar * p);
    int f2 = lar - f1;

    f1 -= q + zk, f2 -= q + zk;
    zk += q;

    y[++ry] = f1; z[++rz] = f2;
}

void solve(void)
{
    for (int i = 1; i <= m; ++i)
    {
        bool flag = false;
        if (i % t == 0) flag = true;
        cut(flag);
    }
}

int main()
{
    n = read();
    m = read();
    q = read();
    u = read();
    v = read();
    t = read();
    p = (u * 1.0) / (v * 1.0);

    for (int i = 1; i <= n; ++i) x[i] = read();
    lx = 1, rx = n;

    sort(x + 1, x + n + 1, cmp);

    solve(); puts("");

    int rate = 1, tot = n + m;
    while (tot--)
    {
        short llll = 1;
        int lar = -99999999;
        if (lx <= rx) lar = x[lx++], llll = 3;
        if (ly <= ry && lar < y[ly])
        {
            if (llll == 3) --lx;
            lar = y[ly++], llll = 0;
        }
        if (lz <= rz && lar < z[lz])
        {
            lar = z[lz++];
            if (llll == 3) --lx;
            if (llll == 0) --ly;
        }
        lar += zk;
        if (rate % t == 0) printf("%d ", lar);
        ++rate;
    }
}
