#include<bits/stdc++.h>
using namespace std;
int n,x,y,tot=1,i=1,j=0;
bool a[10010][10010];
long long ans=0;
bool pd(int xx,int yy)
{
    if(xx==x&&yy==y) 
    {
        cout<<tot+ans-1;
        return 1;
    }
    return 0;
}
int main()
{
	scanf("%d%d%d",&n,&x,&y);
	int c=min(min(x-1,n-x),min(y-1,n-y));
	while(c--)
	{
		ans+=n*n-(n-2)*(n-2);
		n-=2;
		--x;--y;
	}
	while(tot<=n*n)
    {
        while(j+1<=n&&!a[i][j+1]) {++j;++tot;if(pd(i,j)) return 0;}
        while(i+1<=n&&!a[i+1][j]) {++i;++tot;if(pd(i,j)) return 0;}
        while(j-1>=1&&!a[i][j-1]) {--j;++tot;if(pd(i,j)) return 0;}
        while(i-1>=1&&!a[i-1][j]) {--i;++tot;if(pd(i,j)) return 0;}
    }
}
