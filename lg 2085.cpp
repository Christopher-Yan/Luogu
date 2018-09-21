#include<bits/stdc++.h>
using namespace std;
int a,b,c,n,m; 
int heap[102009],l=0;
void put(int g)
{
    heap[++l]=g;
    int k=l;
    while(k>>1!=0&&heap[k]>heap[k>>1])
    {
    	swap(heap[k>>1],heap[k]);
    	k>>=1;
    }
}
int get()
{
    int res=heap[1];
    heap[1]=heap[l--];
    int k=1;
    while((k<<1)<=l)
    {
        int nex=(k<<1);
        if(heap[nex+1]>heap[nex]&&nex<l) nex++;
        if(heap[k]>=heap[nex]) return res;
        swap(heap[nex],heap[k]);
        k=nex;
    }
    return res;
}
int main()
{
	heap[++l]=999999;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        for(int j=1;j<=m;j++)
        {
        	int sum=a*j*j+b*j+c;
            if(heap[1]>sum) put(sum);
        }
        while(l>m) int p=get();
    }
    sort(heap+1,heap+1+l);
    for(int i=1;i<=m;i++) printf("%d ",heap[i]);
} 
