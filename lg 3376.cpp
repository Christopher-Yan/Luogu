#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <cctype>

using namespace std;

const int MAXN = 10010;
const int INF = 99999999;

struct Edge {
	int from;
	int to;
	int w;
	int next;
}e[MAXN << 5];

int n, m, s, t, x, y, z;
int cnt = -1;
int f[MAXN];
int pre[MAXN];
int flow[MAXN];

queue <int> q;

int min(int a, int b)
{
	if (a <= b) return a;
	else return b;
}

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

int BFS(int s, int t)
{
	while (!q.empty()) q.pop();
	memset(pre, -1, sizeof(pre));
	memset(flow, 0x7f, sizeof(flow));
	pre[s] = 0;
	q.push(s);
	flow[s] = INF;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		if (cur == t) break;

		for (int i = f[cur]; i != -1; i = e[i].next)
		{
			if (pre[e[i].to] == -1 && e[i].w > 0)
			{
				pre[e[i].to] = i;
				flow[e[i].to] = min(flow[cur], e[i].w);
				q.push(e[i].to);
			}
		}
			
	}
	if (pre[t] == -1) return -1;
	return flow[t];
}

void Add_edge(int from, int to, int w)
{
	++cnt;
	e[cnt].from = from;
	e[cnt].to = to;
	e[cnt].w = w;
	e[cnt].next = f[from];
	f[from] = cnt;
}

int EK(int s, int t)
{
	int DIS = 0;
	int ans = 0;
	while ((DIS = BFS(s, t)) != -1)
	{
		int cur = t;
		while (cur != s)
		{
			e[pre[cur]].w -= DIS;
			e[pre[cur] ^ 1].w += DIS;
			cur = e[pre[cur]].from;
		}
		ans += DIS;
	}
	return ans;
}

int main()
{
	n = read();
	m = read();
	s = read();
	t = read();

	memset(f, -1, sizeof(f));

	for (int i = 1; i <= m; ++i)
	{
		x = read();
		y = read();
		z = read();
		Add_edge(x, y, z);
		Add_edge(y, x, 0);
	}

	cout << EK(s, t);
	char c = getchar();
	return 0;
}