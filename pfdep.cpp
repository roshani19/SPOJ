#include<bits/stdc++.h>
#include<iostream>
#include<stack>

using namespace std;
int adj[105][105],vis[105],n;
stack<int> s;
void topo(int v)
{
//	printf("%d ",v);
	int i;
	vis[v]=1;
	for(i=n;i>=1;i--)
	{
		if(adj[v][i]==1 && vis[i]!=1)
		topo(i);
	}
	s.push(v);
	
}
int main()
{
	int m,k,v,u,i,j;
	scanf("%d %d",&n,&m);
	while(m--)
	{
		scanf("%d %d",&v,&k);
		while(k--)
		{
			scanf("%d",&u);
			adj[u][v]=1;
		}
	}
	
	for(i=n;i<=n;i++)
	vis[i]=0;
	for(i=n;i>=1;i--){
	if(vis[i]!=1)
	topo(i);
}
	for(i=1;i<=n;i++){
	
	printf("%d ",s.top());
	s.pop();
}
printf("\n");
/*	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
	printf("%d ",adj[i][j]);
	printf("\n");
}*/
 
return 0;	
}
