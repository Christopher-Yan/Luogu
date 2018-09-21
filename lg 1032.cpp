#include<bits/stdc++.h>
using namespace std;
struct node{
	int st;
	string c;
}fir,cur,now;
queue<node> q;
map<string,short> v;
map<string,short> k;
string s1,s2,s,s3[8],ss,s4[8];
int n=0;
void bfs()
{
	cin>>s1>>s2;
	fir.c=s1;
	fir.st=0;
	k[s1]=0;
	k[s2]=0;
	while(cin>>s3[++n],cin>>s4[n]);--n;
	q.push(fir);
	fir.c=s2;
	q.push(fir);
	v[s1]=1;
	v[s2]=2;
	while(!q.empty())
	{
		cur=q.front();
		s=ss=cur.c;
		q.pop();
		//cout<<s<<endl;
		for(int i=1;i<=n;i++)
		{
			int x=0;
			while(s.find(s3[i],0)!=-1)
			{
				s.replace(s.find(s3[i],0),s3[i].size(),s4[i]);
				if((v[s]==1||v[s]==2)&&v[cur.c]!=v[s])
				{
					printf("%d",cur.st+1+k[s]);
					exit(0);
				}
				v[s]=v[cur.c];
				//cout<<s<<cur.st+1<<" "<<s3[i]<<" "<<s4[i]<<endl;
				now.st=cur.st+(++x);
				k[s]=cur.st+x;
				now.c=s;
				if(now.st<10) q.push(now);
				if(s==s2) {
					printf("%d",now.st);
					exit(0);
				} 
			}
			s=ss;
		}	
	}
	printf("NO ANSWER!");
	exit(0);
}
int main()
{bfs();} 
