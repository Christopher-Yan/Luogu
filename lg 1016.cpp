#include <iostream>
#include <cstdio>

using namespace std;

double case_, abili, nowc = 0.0, ans = 0.0;
double dis[10], pri[10];

int n, nowid = 0;

int main()
{
	scanf("%lf%lf%lf%lf%d", &dis[0], &case_, &abili, &pri[0], &n);
	
	for (int i = 1; i <= n; ++i)
		scanf("%lf%lf", &dis[i], &pri[i]);
	dis[n + 1] = 99999999;
	
	while (1)
	{
		if (nowid >= n + 1) break;
		int i = nowid + 1, u = nowid;
		double minn = pri[nowid];
		double dist = dis[nowid] + case_ * abili;
		while (dis[i] < dist)
		{
			if (pri[i] <= minn)
				minn = pri[i], u = i;
			++i;
		}
		if (u == nowid) ans += (case_ - nowc) * pri[u], nowid = i - 1;
		else ans += (dis[u] - dis[nowid]) / abili * pri[nowid], nowid = u;
		
		if (nowid >= n + 1) break; 
	}
	
	printf("%.2lf", ans);
	return 0;
} 
