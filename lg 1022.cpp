#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char s[100],x;
int k,d=0;
bool f=true;
int cnt1,cnt2;
int main()
{
	gets(s);
	if((s[0]>'9'||s[0]<'0')&&s[0]!='+'&&s[0]!='-')d=1;
	for(int i=0;i<strlen(s);i++)
	{
		if(s[i]>='a'&&s[i]<='z') x=s[i];
		if(s[i]=='=') 
		{
			if(s[i-1]>'9'||s[i-1]<'0')
			{
				
				if(s[i-2]>'9'||s[i-2]<'0') d=1;
				if(f==true) cnt1+=d,d=0;
				if(f==false) cnt1-=d,d=0;
			}
			else 
			{
				if(f==true) cnt2-=d,d=0;
				if(f==false) cnt2+=d,d=0;
			}
			f=true;
			k=i;break;
		}
		else if(i==0&&s[i]=='-') f=false;
		else if(s[i]=='+')
		{	
			if(s[i-1]>'9'||s[i-1]<'0')
			{
				if(s[i-2]>'9'||s[i-2]<'0') d=1;
				if(f==true) cnt1+=d,d=0;
				if(f==false) cnt1-=d,d=0;
			}
			else 
			{
				if(f==true) cnt2-=d,d=0;
				if(f==false) cnt2+=d,d=0;
			}
			f=true;
		}
		else if(s[i]=='-')
		{	
			if(s[i-1]>'9'||s[i-1]<'0')
			{
				if(s[i-2]>'9'||s[i-2]<'0') d=1;
				if(f==true) cnt1+=d,d=0;
				if(f==false) cnt1-=d,d=0;
			}
			else 
			{
				if(f==true) cnt2-=d,d=0;
				if(f==false) cnt2+=d,d=0;
			}
			f=false;
		}
		else if(s[i]>'9'||s[i]<'0');
		else d=d*10+s[i]-'0';
	} 
	f=true;
	for(int i=k+1;i<strlen(s);i++)
	{
		if(s[i]>='a'&&s[i]<='z') x=s[i];
		if(i==k+1&&s[i]=='-') f=false;
		else if(i==strlen(s)-1) 
		{
			if(s[i]>'9'||s[i]<'0')
			{
				if(s[i-1]>'9'||s[i-1]<'0') d=1;
				if(f==true) cnt1-=d,d=0;
				else cnt1+=d,d=0;
			}
			else 
			{
				d=d*10+s[i]-'0';
				if(f==true) cnt2+=d,d=0;
				else cnt2-=d,d=0;
			}
			f=true;
		}
		else if(s[i]=='+')
		{	
			if(s[i-1]>'9'||s[i-1]<'0')
			{
				if(s[i-2]>'9'||s[i-2]<'0') d=1;
				if(f==true) cnt1-=d,d=0;
				else cnt1+=d,d=0;
			}
			else 
				if(f==true) cnt2+=d,d=0;
				else cnt2-=d,d=0;
			f=true;
		}
		else if(s[i]=='-')
		{	
			if(s[i-1]>'9'||s[i-1]<'0')
			{
				if(s[i-2]>'9'||s[i-2]<'0') d=1;
				if(f==true) cnt1-=d,d=0;
				else cnt1+=d,d=0;
			}
			else 
				if(f==true) cnt2+=d,d=0;
				else cnt2-=d,d=0;
			f=false;
		}
		else if(s[i]>'9'||s[i]<'0');
		else d=d*10+s[i]-'0';
	}
	double ans=1.0*cnt2/cnt1*1.0;
	printf("%c=%.3lf",x,ans);
}
