#include<bits/stdc++.h>
using namespace std;
map<string,float> m;
char s[222];
bool f=false;
string q1,q2;
int now=0;
int ans=0;
int k=1,hk;
float khx,x=0;
int main()
{
	m["H"]=1;
	m["C"]=12;
	m["N"]=14;
	m["O"]=16;
	m["F"]=19;
	m["Na"]=23;
	m["Mg"]=24;
	m["Al"]=27;
	m["Si"]=28;
	m["P"]=31;
	m["S"]=32;
	m["Cl"]=35.5;
	m["K"]=39;
	m["Ca"]=40;
	m["Mn"]=55;
	m["Fe"]=56;
	m["Cu"]=64;
	m["Zn"]=65;
	m["Ag"]=108;
	m["I"]=127;
	m["Ba"]=137;
	m["Hf"]=178.5;
	m["Pt"]=195;
	m["Au"]=197;
	m["Hg"]=201;
	gets(s);
	int l=strlen(s);
	while(1)
	{
		if(s[now]==' '||now>1+l) break;
		if(s[now]>='0'&&s[now]<='9') 
		{
			k=int(s[now]-'0');
			while(s[now+1]>='0'&&s[now+1]<='9')
				++now,k=k*10+s[now]-'0',++now;
		}
		if(s[now]=='(') f=true,khx=0;
		if(s[now]>='A'&&s[now]<='Z')
		{
			q1=s[now];
			if(s[now+1]>='a'&&s[now+1]<='z') 
			{
				++now;
				q2=s[now];
				q1+=q2;
			}
			hk=1;
			if(s[now+1]=='_')
			{
				now+=3;
				if(s[now]>='0'&&s[now]<='9') 
				{
					hk=int(s[now]-'0');
					while(s[now+1]>='0'&&s[now+1]<='9')
						++now,hk=hk*10+s[now]-'0';
				}
				++now;
			}
			if(f) khx+=hk*m[q1];
			else x+=hk*m[q1];
		}
		if(s[now]==')') 
		{
			hk=1;
			if(s[now+1]=='_')
			{
				now+=3;
				if(s[now]>='0'&&s[now]<='9') 
				{
					hk=int(s[now]-'0');
					while(s[now+1]>='0'&&s[now+1]<='9')
						++now,hk=hk*10+s[now]-'0',++now;
				}
				++now;
				khx*=hk;
			}
			x+=khx;
			f=false;
		}
		if(s[++now]=='~')
		{
			++now;
			ans+=k*x;
			x=0;k=1;
		}
	}
	cout<<ans+k*x;
}
