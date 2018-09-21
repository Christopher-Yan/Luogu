#include<iostream>
#include<algorithm>
using namespace std;
int a[10001],b;
int n,m;
int ans=-6666666;
int kk[600];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i<=m) kk[i]=a[i];
    }
    for(int i=m+1;i<=n;i++)
    {
        sort(kk+1,kk+1+m);
        kk[1]+=a[i];
    }
    for(int i=1;i<=m;i++)
    {
        ans=max(kk[i],ans);
    }
    cout<<ans;
}


