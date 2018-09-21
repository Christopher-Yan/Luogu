#include<bits/stdc++.h>
using namespace std;
double v,a;
int main()
{
	scanf("%lf%lf",&v,&a);
	double t=v*cos(a)/10;
	printf("%lf %lf",v*sin(a)*t,t*10*t/2);
}
