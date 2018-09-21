#include<bits/stdc++.h> 
using namespace std;
int n;
string s[100100],ss;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) cin>>s[i];	
	cin>>ss;
	sort(s+1,s+n+1);
	for(int i=1;i<=n;i++)
	{
		string sss=s[i].substr(0,ss.size());
		if(sss==ss) cout<<s[i]<<endl;
	}
	return 0;
}
