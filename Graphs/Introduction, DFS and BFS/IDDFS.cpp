/**
 *    author: nate_river
 *    created: 2/24/2018 
**/
#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false)
using namespace std;
typedef long long int ll;
bool DLS(auto &g, ll s, ll t, ll depth)
{
	if(s==t)return true;
	if(depth<=0)return false;
	for(ll i:g[s])
	{
		if(DLS(g,i,t,depth-1))return true;
	}
	return false;
}
bool IDDFS(auto &g,ll s,ll t,ll maxdepth)
{
	for(ll i=0;i<=maxdepth;i++)
	{
		if(DLS(g,s,t,i))return true;
	}
	return false;
}

int main()
{
	io;
	freopen("input.txt", "r", stdin);
	ll v,e;
	cin>>v>>e;
	vector<vector<ll> > g(v+1);
	for(ll i=0;i<e;i++)
	{
		ll u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	ll t,s,d;
	cin>>t>>s>>d;
	if(IDDFS(g,s,t,d))cout<<"Target is reachable from the source within max-depth\n";
	else cout<<"NOT reachable within max depth\n";
	return 0;
}

