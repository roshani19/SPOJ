#include<bits/stdc++.h>
#include<queue>
#include<utility>
#include<vector>
#include<iostream>
#define INF 500
int main()
{
	int a[200][200];
//	std::queue<std::pair<int,int> > q;
	int n,m,t,x,y,i,j;
	scanf("%d",&t);
	while(t--)
	{
	//	int s[200][200]={0};
	    std::vector<std::pair<int,int> >v;
		scanf("%d %d",&n,&m);
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				char c;
				std::cin>>c;
				if(c=='1'){
				a[i][j]=-INF;
				v.push_back(std::make_pair(i,j));
			}
			else
			a[i][j]=INF;
			} 
		}
		for(i=0;i<v.size();i++)
		{
			std::queue<std::pair<int,int> >q;
	        q.push(std::make_pair(v[i].first,v[i].second));
	        a[v[i].first][v[i].second]=0;
			while(!q.empty())
			{
				std::pair<int,int>p=q.front();
				q.pop();
				int x=p.first;
				int y=p.second;
				int dis=a[x][y]+1;
				if((y+1)<m && dis<a[x][y+1])
				{
					q.push(std::make_pair(x,y+1));
					a[x][y+1]=dis;
				}
				if((y-1)>=0 && dis<a[x][y-1])
				{
					q.push(std::make_pair(x,y-1));
					a[x][y-1]=dis;
				}
				if((x+1)<n && dis<a[x+1][y])
				{
					q.push(std::make_pair(x+1,y));
					a[x+1][y]=dis;
				}
				if((x-1)>=0 && dis<a[x-1][y])
				{
					q.push(std::make_pair(x-1,y));
					a[x-1][y]=dis;
				}
			}
		}
  	for(i=0;i<n;i++)
	  {
	  	for(j=0;j<m;j++)
	  	printf("%d ",a[i][j]);
	  	printf("\n");
		  }	
		  printf("\n");
	}
	return 0;
}
