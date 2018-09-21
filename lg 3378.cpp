#include<bits/stdc++.h>
using namespace std;
int heap[20020],n,g,l=0,p;
void putt()
{
    heap[++l]=g;
    int k=l;
    while((k>>1)!=0&&heap[k]<heap[k>>1])
    {
        swap(heap[k>>1],heap[k]);
        k>>=1;
    }
}
void gett()
{
    heap[1]=heap[l--];
    int k=1;
    while((k<<1)<=l)
    {
        int nex=(k<<1);
        if(heap[nex+1]<heap[nex]&&nex<l) nex++;
        if(heap[k]<=heap[nex]) return;
        swap(heap[nex],heap[k]);
        k=nex;
    }
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
        scanf("%d",&p);
        if(p==1)
        {
            scanf("%d",&g);
            putt();
        }
        if(p==2) printf("%d\n",heap[1]);
        if(p==3) gett();
        
    }
}
