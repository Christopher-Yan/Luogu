#include<iostream>
using namespace std;
int n,m;
char map[1005][1005];
int main()
{
  cin>>n>>m;
  for(int i=1; i<=n; i++)
    for(int j=1; j<=m; j++) cin>>map[i][j];
  int ans=0;
  for(int i=1; i<=n; i++)
    for(int j=1; j<=m; j++)
      if(map[i][j]=='h')
      {
        if(map[i-1][j]=='e'&&map[i-2][j]=='h'&&map[i-3][j]=='e') ans++; //向上穷举
        if(map[i+1][j]=='e'&&map[i+2][j]=='h'&&map[i+3][j]=='e') ans++; //向下穷举
        if(map[i][j-1]=='e'&&map[i][j-2]=='h'&&map[i][j-3]=='e') ans++; //向左穷举
        if(map[i][j+1]=='e'&&map[i][j+2]=='h'&&map[i][j+3]=='e') ans++; //向右穷举
      }
  cout<<ans<<endl; 
  return 0;
}
