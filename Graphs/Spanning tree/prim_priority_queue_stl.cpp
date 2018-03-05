/**
  *		author: nate_river
  */
#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false)
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> ipair;
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
		g[b].push_back({a,c});
	}	
	vector<bool> mst(v+1,false);
	vector<ll> key(v+1,INT_MAX);
	vector<ll> parent(v+1,-1);
	priority_queue<ipair,vector<ipair>,greater<ipair> > pq;   //Take out the max of {key,vertex} pair
	ll src = 0;
	key[src] = 0;
	pq.push({key[src],src});
	while(!pq.empty())
	{
		ll u = pq.top().second;
		pq.pop();
		mst[u] = true;
		for(auto i:g[u])
		{
			ll v1 = i.first,w = i.second;
			if(!mst[v1] && key[v1]>w)parent[v1] = u, key[v1] = w, pq.push({key[v1],v1});
		}
	}

	for(ll i=1;i<v;i++)
	{
		ll v1 = i;
		ll u = parent[i];
		for(auto j:g[u])
			if(j.first==v1)
			{
				cout<<u<<" "<<v1<<" "<<j.second;
				cout<<endl;
				break;
			}
	}
	return 0;
}