#include<bits/stdc++.h>
using namespace std;
map<string,int> ma;
string a[7],c=".";
int b[7];
int mo(int x,int y)
{
	while(x>=y) x-=y;
	return x;
}
int main()
{
	ma["a"]=1;
	ma["one"]=1;
	ma["two"]=2;
	ma["three"]=3;
	ma["four"]=4;
	ma["five"]=5;
	ma["six"]=6;
	ma["seven"]=7;
	ma["eight"]=8;
	ma["nine"]=9;
	ma["ten"]=10;
	ma["eleven"]=11;
	ma["twelve"]=12;
	ma["thirteen"]=13;
	ma["fourteen"]=14;
	ma["fifteen"]=15;
	ma["sixteen"]=16;
	ma["seventeen"]=17;
	ma["eighteen"]=18;
	ma["nineteen"]=19;
	ma["twenty"]=20;
	ma["zero"]=0;
	ma["one"]=1;
	ma["two"]=2;
	ma["three"]=3;
	ma["four"]=4;
	ma["five"]=5;
	ma["six"]=6;
	ma["seven"]=7;
	ma["eight"]=8;
	ma["nine"]=9;
	ma["ten"]=10;
	ma["eleven"]=11;
	ma["twelve"]=12;
	ma["thirteen"]=13;
	ma["fourteen"]=14;
	ma["fifteen"]=15;
	ma["sixteen"]=16;
	ma["seventeen"]=17;
	ma["eighteen"]=18;
	ma["nineteen"]=19;
	ma["twenty"]=20;
	for(int i=1;i<=6;i++)
		cin>>a[i];
	for(int i=1;i<=6;i++)
	{
		b[i]=ma[a[i]]*ma[a[i]];
		b[i]=mo(b[i],100);
	}
	sort(b+1,b+1+6);
	int f=1;
	for(int i=1;i<=6;i++) 
		if(b[i]==0) 
		{
			f++;
			continue;
		}
		else if(b[i]<10&&i!=f) 
		{
			cout<<"0"<<b[i];
			f=999;
		}
		else 
		{
			f=999;
			cout<<b[i];
		}
	if(f!=999) cout<<"0";
	return 0;
} 
