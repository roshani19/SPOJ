#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
long long int n,c,a[100005];
long long int bs(long long int l,long long int h)
{
	long long int mid,max=0,co,i,j;
	while(l<h)
	{
		
		co=0;
		mid=l+(h-l)/2;
	//	printf("%lld ",mid);
		for(i=0,j=1;i<n-1,j<n;)
		{
	       if(a[j]-a[i]>=mid)
	       {
	       	i=j;
	       	co++;
	       	j=i+1;
		   }
		   else
		   j++;
		}
//		printf("%lld ",co);
		if((co+1)<c)
		{
			h=mid;
		}
		else
		{
		//	printf("%lld ",mid);
			if(mid>max){
		//	printf("%lld ",mid);
			max=mid;}
			l=mid+1;
		}
	//	printf("1");
		
	}
	return max;
}
int main()
{
	long long int t,i,ans;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld %lld",&n,&c);
		for(i=0;i<n;i++){
		scanf("%lld",&a[i]);
   }
    sort(a,a+n);
//	for(i=0;i<n;i++){
//		printf("%lld",a[i]);
//   }
	ans=bs(a[0],a[n-1]);
	printf("%lld\n",ans);
//	printf("1");
}
return 0;
}
