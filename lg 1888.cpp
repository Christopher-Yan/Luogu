#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int gcd(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	return gcd(b, a%b);
}

int main()
{
	int a[3];
	cin >> a[0] >> a[1] >> a[2];
	
	sort(a, a + 3);

	int g = gcd(a[0], a[2]);

	cout << a[0] / g << "/" << a[2] / g;

	return 0;
}