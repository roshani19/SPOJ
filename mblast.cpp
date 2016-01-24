#include<bits/stdc++.h>
#include<iostream>
using namespace std;
char a[2005];
char b[2005];
int n,m,s;
//int sum;
int dp[2000+5][2000+5];
int main()
{
	int i,j;
	cin>>a;
	cin>>b;
	cin>>s;
	n=strlen(a);
	m=strlen(b);
	
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			if(i==0 && j==0)
			dp[i][j]=0;
			else if(i==0)
			dp[i][j]=j*s;
			else if(j==0)
			dp[i][j]=i*s;
			else
			{
				dp[i][j]=min(dp[i-1][j-1]+s*2,min(dp[i-1][j-1]+abs(a[i-1]-b[j-1]),min(dp[i-1][j]+s,dp[i][j-1]+s)));
			}
		}
	}
//	for(i=0;i<=n;i++)
//	{
//		for(j=0;j<=m;j++)
//		cout<<dp[i][j];
//		cout<<endl;
//	}
	cout<<dp[n][m]<<endl;
	return 0;
}
