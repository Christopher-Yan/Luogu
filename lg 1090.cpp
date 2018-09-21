#include<bits/stdc++.h>
using namespace std;
int heap[20020],a[20020],n,l=0,ans=0;
void putt(int g)
{
    heap[++l]=g;
    int k=l;
    while((k>>1)!=0&&heap[k]<heap[k>>1])
    {
        swap(heap[k>>1],heap[k]);
        k>>=1;
    }
}
int gett()
{
    int res=heap[1];
    heap[1]=heap[l--];
    int k=1;
    while((k<<1)<=l)
    {
        int nex=(k<<1);
        if(heap[nex+1]<heap[nex]&&nex<l) nex++;
        if(heap[k]<=heap[nex]) return res;
        swap(heap[nex],heap[k]);
        k=nex;
    }
    return res;
}
inline int read()
{
    int k=1;
    int x=0;
    char c=getchar();
    if(c=='-') k=-k;
    while(c<'0'||c>'9') c=getchar();
    while(c<='9'&&c>='0') 
    {
        x=x*10+c-'0';
        c=getchar();
    }
    return k*x;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) 
    {
        a[i]=read();
        putt(a[i]); 
    } 
    for(int i=1;i<n;i++) 
    {
        int l1=gett();
        int l2=gett();
        putt(l1+l2);
        ans+=l1+l2;
    }
    cout<<ans;
    
}
