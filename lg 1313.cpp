#include<bits/stdc++.h>
using namespace std;
typedef int LL;
LL a,b,k,n,m,ans;
int rec[1010][1010];
const int mod=10007;
int C(int n,int r){
    if(n==r || r==0)    return rec[n][r]=1;
    if(rec[n][r])    return rec[n][r];
    return rec[n][r]=(C(n-1,r)+C(n-1,r-1))%mod;
}
long long ksm(long long a,LL b)
{
    long long ex=1;
    while(b)
    {
        if(b&1) ex*=a;
        b>>=1;a=a*a;
        while(a>=mod) a-=mod;
        while(ex>=mod) ex-=mod;
    }
    while(a>=mod) a-=mod;
    return ex;
}
int main()
{
    scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
    ans=(C(k,min(m,n))*ksm(a,n))%mod*ksm(b,m)%mod;
    printf("%d",ans);
    return 0;
}
