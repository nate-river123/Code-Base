/**
 *    author: nate_river
 *    created: 2/22/2018 
**/
#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false)
using namespace std;
typedef long long int ll;
void dfs(auto &g,auto &tc,ll u,ll v)
{
	tc[(int)(u)][(int)(v)] = 1;
	for(ll i:g[v])
	{
		if(!tc[u][i])
		{
			dfs(g,tc,u,i);
		}
	}
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
		ll a,b;
		cin>>a>>b;	
		g[a].push_back(b);
		//g[b].push_back(a);
	}
	bool vst[v+1];
	fill_n(vst,v+1,false);
	//int tc[v][v];
	vector<vector<ll> > tc(v);
	
	for(ll i=0;i<v;i++)
	for(ll j=0;j<v;j++)
	tc[i].push_back(0);
	
	for(ll i=0;i<v;i++)
	//if(!vst[i])
	dfs(g,tc,i,i);
	
	for(ll i=0;i<v;i++)
	{
		for(ll j=0;j<v;j++)
		cout<<tc[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}

