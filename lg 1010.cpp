#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,k,k1,x;
bool f = true;
void aha(int now)
{
	if (now == 0) {	printf("%d",k1); return;}
	while (now > 0);
	{
		if (now == 1) { printf("2(0)"); return; }
		for (int j = 1; j <= now; j++)
		{
			k1 = 0;
			x = pow(2,j);
			if (now <= x) now -= pow(2,j-1), k1 = j - 1;
			if (k1 != 0) j = now + 1; 
		}
		if (k1 == 1) { printf("2"); return; }
		cout<<"2(";
		aha(k1);
		cout<<")";
	}
	
}
int main()
{
	scanf("%d",&n);
	int cur = n;
	while (cur > 0)
	{
		if (cur == 1) { printf("2(0)"); return 0; }
		for (int i = 1; i <= n; i++)
		{
			k = 0; 
			x = pow(2,i);
			if (cur <= x) cur -= pow(2,i-1), k = i - 1;
			if (k != 0) i = n + 1; 
		}
		aha(pow(2,k));
		cout<<"+";
	}
	
}
