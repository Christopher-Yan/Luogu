#include<bits/stdc++.h>
using namespace std;
int mx,my,ex,ey;
bool v[25][25];
long long ans=0;
void dfs(int x,int y)
{
	if(x==ex&&y==ey) ans++;
	if(x>ex || y>ey) return;
	if(v[x+1][y]==0 && x+1<=ex) dfs(x+1,y);
	if(v[x][y+1]==0 && y+1<=ey) dfs(x,y+1);
	return;   
}
int main()
{
	memset(v,0,sizeof(0));
	scanf("%d%d%d%d",&ex,&ey,&mx,&my);
	v[mx][my]=1;
	v[mx-1][my-2]=1;v[mx+2][my+1]=1;v[mx+1][my+2]=1;v[mx-2][my+1]=1;
	v[mx-1][my+2]=1;v[mx+2][my-1]=1;v[mx+1][my-2]=1;v[mx-2][my-1]=1;
	dfs(0,0);
	printf("%lld",ans);
	return 0;
} 
