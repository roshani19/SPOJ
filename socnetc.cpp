#include<bits/stdc++.h>
#include<vector>
using namespace std;
vector<int>par;
int n;
vector<int>index1;
int getParent(int i)
{
	if(par[i]==i)
	return i;
	else
	return par[i]=getParent(par[i]);
}
int check(int x,int y)
{
	if(getParent(x)==getParent(y))
	return 1;
	else
	return 0;
}
void union1(int x,int y)
{
	if(!check(x,y)){
	int par1=getParent(x);
	int par2=getParent(y);
	par[par1]=par2;
	index1[par2]=index1[par1]+index1[par2];
}
}
int main()
{
	int m,q,p1,p2,i;
	scanf("%d %d",&n,&m);
	par.resize(n+1);
	index1.resize(n+1);
	for(i=1;i<=n;i++){
	par[i]=i;
	index1[i]=1;
}
	char ch;
	scanf("%d",&q);
	for(i=0;i<q;i++)
	{
		ch=getchar();
		if(ch=='\n')
		i--;
		else if(ch=='A')
		{
			scanf("%d %d",&p1,&p2);
			  if(index1[getParent(p1)]+index1[getParent(p2)] <= m)
			union1(p1,p2);
		}
		else if(ch=='E')
		{
			scanf("%d %d",&p1,&p2);
			if(!check(p1,p2))
			printf("No\n");
			else
			printf("Yes\n");
		}
		else
		{
			scanf("%d",&p1);
			int ans=index1[getParent(p1)];
			printf("%d\n",ans);
		}
	}
	return 0;


}
