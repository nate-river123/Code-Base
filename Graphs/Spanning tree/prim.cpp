/**
  *		author: nate_river
  */
#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false)
using namespace std;
typedef long long int ll;
const ll inf = INT_MAX;
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
	ll key[v+1];
	fill_n(key,v+1,inf);    //key array is -->   0 INF INF INF INF...
	key[0] = 0;

	bool mst[v+1];
	fill_n(mst,v+1,false);  //mst array is -->   T F F F F...
	mst[0] = true;
	
	ll parent[v+1];
	parent[0] = -1;         //parent of added node is set to be -1
	
	for(ll i=0;i<v-1;i++)
	{
		ll minval=inf,u;
		
		for(ll j=0;j<v;j++)    //take out min value from an array can 
										//be carried out in O(log n) using priority queue
		{
			if(!mst[j] && key[j]<minval)
				minval = key[j], u = j;
		}

		mst[u] = true;
		
		for(auto j:g[u])
		{
			ll v1 = j.first,w = j.second;
			if(!mst[v1] && key[v1] > w)
				parent[v1] = u, key[v1] = w;
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