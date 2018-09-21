#include<bits/stdc++.h>
using namespace std;
map<double,bool> M;
int top=0;
double a,b,c,d;
bool pd(double x)
{
	if(x*x*x*a+x*x*b+x*c+d>-0.01&&x*x*x*a+x*x*b+x*c+d<0.01)
		{
			printf("%.2lf ",x);
			return true;
		}
	return false;
}
void divid(double l,double r)
{
	double m=(l+r)/2;
	double y1=
	if(r-l<=0.00005) return;
	double m1,m2;
	m1=m2=m;
	if(pd(m)) m1-=1.0,m2+=1.0; 
	divid(l,m1);
	divid(m2,r);
	
}
int main()
{
	scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
	divid(-100,100);
} 
