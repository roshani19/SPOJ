#include<iostream>
#include<vector>
#include<queue>
using namespace std;
char a[1005][1005];
int n,m;
vector<int>vis;
int c=1;
queue<int>q;

void bfs(int i,int j)
{
	//cout<<i<<" "<<j<<" ";
	int l;
	int arr[n*m +1];
	q.push(m*i+j);
	int k=0;
	while(!q.empty())
	{
		int d=q.front();
		arr[k++]=d;
		q.pop();
		vis[m*(d/m) +(d%m) ]=c;
		if(a[d/m][d%m]=='S' && (d/m)+1 < n && vis[m*((d/m)+1)+(d%m)]==0)
		q.push(m*((d/m)+1)+(d%m));
		else if(a[d/m][d%m]=='N' && (d/m)-1 >=0 && vis[m*((d/m)-1)+(d%m)]==0)
		q.push(m*((d/m)-1)+(d%m));
		else if(a[d/m][d%m]=='E' && (d%m)+1 < m && vis[m*((d/m))+(d%m + 1)]==0)
		q.push(m*((d/m))+(d%m + 1));
		else if(a[d/m][d%m]=='W' && (d%m)-1 >= 0 && vis[m*((d/m))+(d%m)-1]==0)
		q.push(m*((d/m))+(d%m)-1);
		else if(a[d/m][d%m]=='W' && (d%m)-1 >= 0 && vis[m*((d/m))+(d%m)-1]!=c){
		for(l=0;l<k;l++)
		{
			vis[arr[l]]=vis[m*((d/m))+(d%m)-1];
		}
		c--;
     	}   
     	else if(a[d/m][d%m]=='N' && (d/m)-1 >=0  && vis[m*((d/m)-1)+(d%m)]!=c){
		for(l=0;l<k;l++)
		{
			vis[arr[l]]=vis[m*((d/m)-1)+(d%m)];
		}
		c--;
     	}
		 	else if(a[d/m][d%m]=='S' &&(d/m)+1 < n  >= 0 && vis[m*((d/m)+1)+(d%m)]!=c){
		for(l=0;l<k;l++)
		{
			vis[arr[l]]=vis[m*((d/m)+1)+(d%m)];
		}
		c--;
     	}  
		 	else if(a[d/m][d%m]=='E' && (d%m)+1 < m && vis[m*((d/m))+(d%m + 1)]!=c){
		for(l=0;l<k;l++)
		{
			vis[arr[l]]=vis[m*((d/m))+(d%m + 1)];
		}
		c--;
     	}    
	}
//	cout<<c<< " ";
	c++;
}
int main()
{
	int i,j;
	cin>>n>>m;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		cin>>a[i][j];
	}
	vis.resize(n*m +1);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		vis[m*i + j]=0;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		if(!vis[m*i+j])
		bfs(i,j);
	}
	cout<<c-1<<endl;
}
