#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
bool v[10];
int a,b,c,p=0;
int n,n2,n3;
int main()
{
	cin>>a>>b>>c;
	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=9;j++)
		{
			for(int k=1;k<=9;k++)
			{
				memset(v,false,sizeof(v));
				v[i]=true;
				v[j]=true;
				v[k]=true;
				n=i*100+j*10+k;
				n2=n/a*b;
				n3=n/a*c;
				v[n3%10]=true;
				v[n2%10]=true;
				v[n3/100]=true;
				v[n2/100]=true;
				v[n2/10%10]=true;
				v[n3/10%10]=true;
				for(int o=1;o<=9;o++)
					if(v[o]==false) goto au;
				if(n*b==n2*a) cout<<n<<" "<<n2<<" "<<n3<<endl;
				p++;
				au:;
			}
		}
	}
	if(p==0) cout<<"No!!!";
	return 0;
}
