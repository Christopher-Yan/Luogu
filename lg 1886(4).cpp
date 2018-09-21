#include<cstdio>
#include<cstring>
#include<iostream>
int n,m;
int a[1000300];

struct queue
{
	int q[1000300];
	int t[1000300];
	int tail = 0;
	int head = 1;
	
	queue(){
		memset(q,0,sizeof q);
		tail = 0;
		head = 1;
	}
	
	void push(int x,int y)
	{
		while (head<=tail && q[tail]>x) --tail;
		q[++tail] = x;
		t[tail] = y;
	}
	
	void check(int y)
	{
		int k = y-m;
		while (head<=tail && t[head]<=k)  ++head;
	}
	
	void pop()
	{
		++head;
	}
	
	int front()
	{
		return q[head];
	}
	
	int size()
	{
		return  tail-head+1;
	}
	void clear()
	{
		tail = 0;
		head = 1;
	}
}q;

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1; i<=n; ++i)
	{
		scanf("%d",&a[i]);
		q.push(a[i],i);
		q.check(i);
		if (i>=m) 
			printf("%d ",q.front());
	}
	std::cout<<::endl;
	q.clear();
	for (int i=1; i<=n; ++i)
	{
		q.push(-a[i],i);
		q.check(i);
		if (i>=m) 
			printf("%d ",-q.front());
	}
}
