#include<bits/stdc++.h>
#define m 8
using namespace std;
char a[5];
char b[5];
int vis[65];
int dis[65];
queue<int>q;
int d;
void bfs(int v)
{
//	cout<<(a[0]-'a')*8+a[1]-'1'<<" "<<(b[0]-'a')*8+b[1]-'1'<<" ";
//	cout<<v<<" ";
	dis[v]=0;
	q.push(v);
//	cout<<dis[v];
	vis[v]=1;
	while(!q.empty())
	{
		d=q.front();
	//	cout<<d<<" ";
	//	dis[d]=0;
		q.pop();
		if(d==((b[0]-'a')*8+b[1]-'1')){
		while(!q.empty())
		q.pop();
		break;
	}
		else
		{
		  if(d/m+2 <= 7 && d%m+1 <= 7 && vis[(d/m+2)*8+d%m+1]==0)
		{
			q.push((d/m+2)*8+d%m+1);
			dis[(d/m+2)*8+d%m+1]=dis[d]+1;
			vis[(d/m+2)*8+d%m+1]=1;	
		}
			if(d/m+2 <= 7 && d%m-1 >=0 && vis[(d/m+2)*8+d%m-1]==0)
		{
			q.push((d/m+2)*8+d%m-1);
			dis[(d/m+2)*8+d%m-1]=dis[d]+1;
			vis[(d/m+2)*8+d%m-1]=1;	
		}
			if(d/m-2 >=0  && d%m+1 <=7 && vis[(d/m-2)*8+d%m+1]==0)
		{
			q.push((d/m-2)*8+d%m+1);
			dis[(d/m-2)*8+d%m+1]=dis[d]+1;	
			vis[(d/m-2)*8+d%m+1]=1;
		}
			if(d/m-2 >= 0 && d%m-1 >=0 && vis[(d/m-2)*8+d%m-1]==0)
		{
			q.push((d/m-2)*8+d%m-1);
			dis[(d/m-2)*8+d%m-1]=dis[d]+1;	
			vis[(d/m-2)*8+d%m-1]=1;
		}
			if(d/m+1 <= 7 && d%m+2 <=7 && vis[(d/m+1)*8+d%m+2]==0)
		{
			q.push((d/m+1)*8+d%m+2);
			dis[(d/m+1)*8+d%m+2]=dis[d]+1;
			vis[(d/m+1)*8+d%m+2]=1;	
		}
			if(d/m-1 >= 0 && d%m+2 <=7 && vis[(d/m-1)*8+d%m+2]==0)
		{
			q.push((d/m-1)*8+d%m+2);
			dis[(d/m-1)*8+d%m+2]=dis[d]+1;
			vis[(d/m-1)*8+d%m+2]=1;	
		}
			if(d/m+1 <= 7 && d%m-2 >=0 && vis[(d/m+1)*8+d%m-2]==0)
		{
			q.push((d/m+1)*8+d%m-2);
			dis[(d/m+1)*8+d%m-2]=dis[d]+1;	
			vis[(d/m+1)*8+d%m-2]=1;
		}
			if(d/m-1 >= 0 && d%m-2 >=0 && vis[(d/m-1)*8+d%m-2]==0)
		{
			q.push((d/m-1)*8+d%m-2);
			dis[(d/m-1)*8+d%m-2]=dis[d]+1;	
			vis[(d/m-1)*8+d%m-2]=1;
		}
	//	cout<<" d = "<<d<<" ";
	//	cout<<dis[d]<<" ";		
	
		}
	}
}

int main()
{
	int t,i;
	cin>>t;
	while(t--)
	{
		cin>>a;
		cin>>b;
	//	cout<<(a[0]-'a')*8+a[1]-'1'<<" "<<(b[0]-'a')*8+b[1]-'1'<<" ";
	    for(int i=0;i<64;i++)
	    {
	    	vis[i]=0;
	    	dis[i]=999999;
		}
		bfs((a[0]-'a')*8+a[1]-'1');
		cout<<dis[(b[0]-'a')*8+b[1]-'1']<<endl;
	}
	return 0;
}
