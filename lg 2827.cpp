#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <cmath>

using namespace std;

int n, m, q, u, v, t, x;
int zk = 0;

double p;

priority_queue <int> Q;

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
    int lar = Q.top() + zk;

    if (flag) printf("%d ", lar);

    Q.pop();
    int f1 = floor(lar * p);
    int f2 = lar - f1;

    f1 -= q + zk, f2 -= q + zk;
    zk += q;

   //     cout << endl <<f1 << " " << f2 << endl;
    Q.push(f1); Q.push(f2);
}

void solve(void)
{
    for (int i = 1; i <= m; ++i)
    {
        bool flag = false;
        if (i % t == 0)
        {
            flag = true;
        }
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

    for (int i = 1; i <= n; ++i)
    {
        x = read();
        Q.push(x);
    }

    solve(); puts("");

    int rate = 1;
    while (!Q.empty())
    {
        if (rate % t == 0) printf("%d ", Q.top() + zk);
        Q.pop();
        ++rate;
    }
}
