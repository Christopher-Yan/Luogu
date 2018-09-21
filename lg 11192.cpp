#include<bits/stdc++.h>
using namespace std;
const int mod=100003;
int f[100200]; 
int n,m;
int main()
{
    scanf("%d%d",&n,&m);
    f[0]=1;
    f[1]=1;
    for(int i=2;i<=n;i++)
        for(int j=1;j<=m&&i-j>=0;j++)
            f[i]=(f[i]+f[i-j])%mod;
    cout<<f[n]%mod;
}
