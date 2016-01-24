#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int dp[1010][1010];
int fun(int h,int a,int c,int f)
{
	if(h<=0 || a<=0)
	return c;
	if(dp[h][a]!=-1)
	return dp[h][a];
	else
	{
		if(f==1)
		{
			dp[h][a]=max(dp[h][a],max(fun(h-5,a-10,c+1,2),fun(h-20,a+5,c+1,3)));
		}
		else if(f==2)
		dp[h][a]=max(dp[h][a],fun(h+3,a+2,c+1,1));
		else
		dp[h][a]=max(dp[h][a],fun(h+3,a+2,c+1,1));
		return dp[h][a];
	}
}
int main()
{
	int t,h,a,i,j,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&h,&a);
		memset(dp, -1, sizeof(dp));
	    if(h<=0|| a<=0)
	    printf("-1\n");
	    else{
		
		int a1=fun(h+3,a+2,0,1);
		printf("%d\n",a1);
	}
	
	}
	return 0;
}
