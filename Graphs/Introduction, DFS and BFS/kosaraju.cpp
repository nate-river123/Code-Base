/**
 *    author: nate_river
 *    created: 2/27/2018 
**/
#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false)
using namespace std;
typedef long long int ll;
void dfs_scc(auto &g,bool vst[],ll s)
{
	vst[s] = true;
	cout<<s<<" ";
	for(ll i:g[s])
	{
		if(!vst[i])dfs_scc(g,vst,i);
	}
	
}
void dfs_topo(auto &g,bool vst[],auto &topo,ll s)
{
	vst[s] = true;
	for(ll i:g[s])
	{
		if(!vst[i])dfs_topo(g,vst,topo,i);
	}
	topo.push(s);
}
int main()
{
	io;
	freopen("input.txt", "r", stdin);
	ll v,e;cin>>v>>e;
	vector<vector<ll> > g(v+1),grev(v+1);
	for(ll i=0;i<e;i++)
	{
		ll a,b;
		cin>>a>>b;
		g[a].push_back(b);
		grev[b].push_back(a);
	}
	bool vst[v+1];
	fill_n(vst,v+1,false);
	stack<ll> topo;
	for(ll i=0;i<v;i++)
	{
		if(!vst[i])dfs_topo(g,vst,topo,i);
	}
	fill_n(vst,v+1,false);
	
	while(!topo.empty())
	{
		if(!vst[topo.top()])
		{
			dfs_scc(grev,vst,topo.top());
			cout<<endl;
		}
		topo.pop();
	}
	return 0;
}

