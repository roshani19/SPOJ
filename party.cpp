#include<bits/stdc++.h>
using namespace std;
int dp[104+1][500+5];
/*int recur(int i,int c[],int f[],int j)
{
	if(i==0 || j==0)
	return dp[i][j];
	else
	{
		if(dp[i][j]==dp[i-1][j] && dp[i][j]==dp[i-1][j-c[i-1]]+f[i-1])
		return (min(c[i-1]+recur(i-1,c,f,j-c[i-1]) , recur(i-1,c,f,j)));
		else if(dp[i][j]==dp[i-1][j])
		return recur(i-1,c,f,j);
		else
		return c[i-1]+recur(i-1,c,f,j-c[i-1]);
	}
}*/
int fun(int w,int c[],int f[],int n)
{
	
	int i,j;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=w;j++)
		{
			if(i==0 || j==0)
			dp[i][j]=0;
			else if(c[i-1]>j)
			dp[i][j]=dp[i-1][j];
			else
			{
				
				dp[i][j]=max(f[i-1]+dp[i-1][j-c[i-1]],dp[i-1][j]);
			}
		}
	}
/*	for(i=0;i<=n;i++)
	{
		for(j=0;j<=w;j++)
		printf("%d ",dp[i][j]);
		printf("\n");
	}*/
	return dp[n][w];
}

int main()
{
	int w,n,i,j;
	int c[105],f[105];
	while(1)
	{
		cin>>w>>n;
		if(w==0 && n==0)
		break;
		else
		{
			int co=0;
			for(i=0;i<n;i++)
			cin>>c[i]>>f[i];
		//	for(i=0;i<n;i++)
		//	printf(" %d  %d\n",c[i],f[i]);
		for(i=0;i<=n;i++)
		{
			for(j=0;j<=w;j++)
			dp[i][j]=0;
		}
			
			int fu=fun(w,c,f,n);
		   // co=recur(w,c,f,n);
		   for(i=0;i<=w;i++)
		   {
		   	if(dp[n][i]==fu)
		   	{
		   		co=i;
		   		break;
			   }
		   }
			
			printf("%d %d\n",co,fu);				
			
		}
	}
	return 0;
}
