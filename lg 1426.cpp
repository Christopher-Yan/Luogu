#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int s,x;
double sp[98],n;
int main()
{
	scanf("%d%d",&s,&x);
	int s1=s-x;
	int s2=s+x;
	sp[0]=7.142857142857;
	for(int i=1;i<=s;i++)
	{
		sp[i]=sp[i-1]*0.98;
		n+=sp[i];
		if(n>=s1&&s1+sp[i]>=s2) 
		{
			printf("n");
			return 0;
		 } 
		 if(n>=s1&&s1+sp[i]<=s2) 
		 {
		 	printf("y");
		 	return 0;
		}
	}
}
