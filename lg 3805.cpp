#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int MAXN = 33300999;

char s[MAXN],ss[MAXN];

int f[MAXN>>1],ll,l,p,ans=-1;

void manacher()
{
	l = strlen(s+1);
	f[1] = 1;
	
	int nowr = 1;
	int nowm = 1;
	for (int i=2; i<=l; ++i)
	{
		if (i > nowr) f[i] = 1;
		else 
			p = (nowm << 1) - i,
			f[i] = min(f[p], (nowr-i)<<1|1);
		int x=f[i]/2+1;
		while (i-x>=1 && i+x<=l && s[i+x] == s[i-x])
		{
			++x;
			f[i] += 2;
		}
		if (i+x-1 > nowr)
		{
			nowr = i+x-1;
			nowm = i;
		}
		ans = max(ans,f[i]);
	}
}

int main()
{
	scanf("%s",ss+1);
	ll = strlen(ss+1);
	s[1]='#';
	for (int i=1; i<=ll; ++i)
	{
		s[i<<1] = ss[i];
		s[i<<1|1] = '#';
	}
	ss[(ll<<1)+2] = '\0';
	manacher();
	cout << ans/2;
}
