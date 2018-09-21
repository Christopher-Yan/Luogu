#include<bits/stdc++.h>
using namespace std;
int n;
map<char,int> m;
string a[11][11];
int main()
{
	scanf("%d",&n);
	--n;
	for(int i=1;i<=n;i++) m[a[0][i][0]]=-1; 
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
		{
			cin>>a[i][j];
			if(i==j&&a[i][j]==a[i][0]&&a[i][j]==a[0][j]&&a[i][j].size()==1)
				m[a[i][j][0]]=0;
		}
			
	m[a[n][n][0]]=1;
	int b=n;
	while(b--)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(a[i][j].size()==1&&m[a[i][0][0]]!=-1&&m[a[0][j][0]]!=-1)
				    m[a[i][j][0]]=m[a[i][0][0]]+m[a[0][j][0]];
				else if(!a[i][j].size()&&m[a[i][0][0]]!=-1&&m[a[0][j][0]]!=-1)
					m[a[i][j][1]]=m[a[i][0][0]]+m[a[0][j][0]]-n;
	for(int i=1;i<=n;i++) printf("%c=%d ",a[0][i][0],m[a[0][i][0]]);
	printf("\n%d",n);
	return 0;
}
