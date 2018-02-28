/**
 *    author: nate_river
 *    created: 2/12/2018 
**/
#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false)
using namespace std;
typedef long long int ll;
const ll INF =  - INT_MAX;
void dfs_topo(auto &g,bool vst[],stack<ll> &st,ll s)
{
	vst[s] = true;
	for(auto i:g[s])
	{
		if(!vst[i.first])
		dfs_topo(g,vst,st,i.first);
	}
	st.push(s);
}
int main()
{
	io;
	ll v,e;
	cin>>v>>e;
	vector<vector<pair<ll,ll> > > g(v+1);
	for(ll i=0;i<e;i++)
	{
		ll a,b,c;
		cin>>a>>b>>c;	
		g[a].push_back({b,c});
		//g[b].push_back(a);
	}
	bool vst[v+1];
	fill_n(vst,v+1,false);
	stack<ll> s;
	for(ll i=0;i<v;i++)
	{
		if(!vst[i])
		{
			dfs_topo(g,vst,s,i);
		}
	}
	ll dist[v+1];
	for(ll i=0;i<v;i++)dist[i] = INF;
	cout<<"Enter the source:";
	ll src;cin>>src;
	//cout<<"Enter the sink:";
	//ll snk;cin>>snk;
	dist[src] = 0;
	while(!s.empty())
	{
		ll u = s.top();
		s.pop();
		//if(dist[u] != INF)
		for(auto v:g[u])
		{
			dist[v.first] = max (dist[v.first],dist[u]+v.second);
		}
	}
	for(ll i=0;i<v;i++)
	cout<<dist[i]<<endl;
	return 0;
}

