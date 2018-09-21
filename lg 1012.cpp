#include<bits/stdc++.h>
using namespace std;
int n;
string s[25],ans;
bool cmp(string a,string b) {return a>b;}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		cin>>s[i];
	sort(s+1,s+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		if(s[i][0]==s[i+1][0])
		{
			for(int j=0;j<min(s[i].size(),s[i+1].size());j++)
				if(s[i][j]!=s[i+1][j]) 
					goto as;
			if(s[i].size()>s[i+1].size())
				if(s[i+1][0]>s[i][s[i].size()-1]) swap(s[i+1],s[i]);
			if(s[i].size()<s[i+1].size())
				if(s[i][0]<s[i+1][s[i].size()-1]) swap(s[i+1],s[i]);
		}
		as:;
		ans+=s[i];
	}
	cout<<ans;
} 
