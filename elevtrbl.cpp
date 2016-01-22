#include<vector>
#include<queue>
#include<iostream>
#define ll long long int
using namespace std;
ll f,s,g,u,d1;

vector<ll>vis;
ll c;
queue<ll>q;
vector<ll>pred;
vector<ll>dis;
void bfs(ll v)
{
	ll i;
	vis[v]=1;
	dis[v]=0;
//	pred[v]=-1;
	q.push(v);
	while(!q.empty())
	{
		
		ll d=q.front();
		q.pop();
//		 printf("%lld %lld ",d,c);
		vis[d]=2;
	//	printf("%lld ",1);
	//	printf("1");
			if(d+u <=f && vis[d+u]==0){
			
			q.push(d+u);
			vis[d+u]=1;
			dis[d+u]=dis[d]+1;
			if(d+u == g)
			{
				c=dis[d+u];
				break;
			}
		}
			if(d-d1>=1 && vis[d-d1]==0)
			{
			//	printf("1");
			q.push(d-d1);
			vis[d-d1]=1;
			//pred[d-d1]=d;
			dis[d-d1]=dis[d]+1;
			if(d-d1==g)
			{
				
				c=dis[d-d1];
				break;
				
			}
		}
		
	
	}
	
	
	
}
int main()
{
	ll i,j;
	cin>>f>>s>>g>>u>>d1;
	vis.resize(f+1);
	pred.resize(f+1);
	dis.resize(f+1);
	for(i=1;i<=f;i++){
	vis[i]=0;
//	pred[i]=-1;
	dis[i]=999999999;
    }
	bfs(s);
	if(c==0 && s!=g)
	cout<<"use the stairs"<<endl;
	else
	cout<<c<<endl;
	return 0;
}
