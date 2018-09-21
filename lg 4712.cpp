#include<bits/stdc++.h>
using namespace std;
int n;
bool v[110000];
long long sum;
struct animals{
    long long ne;
    long long w;
}a[109200];
bool cmp(animals a,animals b) {
return a.w<b.w;} 
int main()
{
    cin>>n>>sum;
    for(int i=1;i<=n;i++) cin>>a[i].ne>>a[i].w;
    a[n+1].ne=999999;
    a[n+1].w=999999;
    sort(a+1,a+1+n+1,cmp);
    for(int i=1;i<=n+1;i++)
    {
        long long h=0;
        for(int j=i;j>=1;j--)
            if(a[j].w<a[i].w&&v[j]==false)
                h+=a[j].ne,v[j]=true;
        if(i==n+1) 
        {
            if(h+sum==0) printf("-1");
            else printf("%lf",(double)(h+sum)/5.0);
            return 0;
        }
        long long r=5*a[i].ne;
        sum=sum+h-r;
        if(sum<0) 
        {
            printf("-1");
            return 0;
        }
    }
    return 0;
}
