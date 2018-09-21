#include <cstdio>

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
	return k * x;
}

char s1[] = "pb wins";
char s2[] = "zs wins";

int main()
{
	int n = read();
	for (;n > 0;)
	{
		--n;
		int x = read();
		if (x & 1) puts(s1);
		else puts(s2);
	}
}
