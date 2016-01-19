#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#define ll long long int
#define pb push_back
#define mk make_pair
using namespace std;
vector<ll>parent;
ll getParent(ll idx)
{
	if(parent[idx]==idx)
	return idx;
	else{
	
    parent[idx]=getParent(parent[idx]);
    return parent[idx];
}
}
ll check(ll x,ll y)
{
	if(getParent(x)==getParent(y))
	return 1;
	else
	return 0;
}
int main()
{
	int t;
	long long int n,m,u,v,s,i;
	
	scanf("%d",&t);
	while(t--)
	{
		vector<pair<ll,pair<ll,ll> > >a;
		scanf("%lld %lld",&n,&m);
		parent.resize(n+1);
		for(i=1;i<=n;i++)
		parent[i]=i;
		for(i=0;i<m;i++)
		{
			scanf("%lld %lld %lld",&u,&v,&s);
			a.pb(mk(s,mk(u,v)));
		}
		pair<ll,pair<ll,ll> >p;
		sort(a.begin(),a.end());
		for(i=(m-1);i>=0;i--)
		{
			ll x=a[i].second.first;
			ll y=a[i].second.second;
		  	if(!check(x,y))
		  	parent[getParent(x)]=getParent(y);
		  	if(check(1,n)==1)
		  	{
		  		printf("%lld\n",a[i].first);
		  		break;
			}
	}
	if(check(1,n)!=1)
	printf("-1\n");
	}
	return 0;
}
