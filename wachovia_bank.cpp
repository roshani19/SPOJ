#include<iostream>
#include<vector>
using namespace std;
int val[55];
int wt[55];
int fun(int n,int w)
{
	int i,j,dp[n+1][w+1];
	for(i=0;i<=n;i++)
		{
			for(j=0;j<=w;j++)
			{
				if(i==0 || j==0)
				dp[i][j]=0;
				else if(wt[i-1]>j)
				dp[i][j]=dp[i-1][j];
				else
				dp[i][j]=max(dp[i-1][j],val[i-1]+dp[i-1][j-wt[i-1]]);
			}
		}
	
	return dp[n][w];
}
int main()
{
	int t,w,n,i,j;
	cin>>t;
	while(t--)
	{
		cin>>w>>n;
		for(i=0;i<n;i++)
		cin>>wt[i]>>val[i];
	    int ans=fun(n,w);
	    cout<<"Hey stupid robber, you can get "<<ans<<"."<<endl;
	}
}
