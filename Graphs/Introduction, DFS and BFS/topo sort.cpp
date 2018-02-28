/**
 *    author: nate_river
 *    created: 2/9/2018 
**/
#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false)
using namespace std;
typedef long long int ll;
void topo_using_dfs(vector<vector<ll> > &g,bool vst[],stack<ll> &ans, ll s)
{
	vst[s] = true;
	for(ll i:g[s])
	{
		if(!vst[i])topo_using_dfs(g,vst,ans,i);
	}
	ans.push(s);
}
int main()
{
	io;
	ll v,e;
	cin>>v>>e;
	vector<vector<ll> > g(v+1);
	for(ll i=0;i<e;i++)
	{
		ll a,b;
		cin>>a>>b;	
		g[a].push_back(b);
	}
	bool vst[v+1];
	fill_n(vst,v+1,false);
	stack<ll> ans;
	for(ll i=0;i<v;i++)
	if(!vst[i])
	topo_using_dfs(g,vst,ans,i);
	while(!ans.empty())
	{
		cout<<ans.top()<<" ";
		ans.pop();
	}
	return 0;
}

