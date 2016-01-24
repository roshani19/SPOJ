#include<iostream>
using namespace std;
long long int dp[105];
int main()
{
	long long int i;
	for(i=1;i<=100;i++)
	{
		dp[i]=dp[i-1]+i*i;
	}
	int n;
	while(1)
	{
		cin>>n;
		if(n==0)
		break;
		else
		printf("%lld\n",dp[n]);
	}
	return 0;
}
