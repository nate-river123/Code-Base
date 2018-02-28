/**
 *    author: nate_river
 *    created: 2/9/2018 
**/
#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false)
using namespace std;
typedef long long int ll;
bool dfs(vector<vector<ll> > &g, bool vst[], ll col[], ll s, ll p)
{
	vst[s] = true;
	if(p!=-1)col[s] = 1-col[p];
	for(ll i:g[s])
	{
		if(!vst[i])
		{
			if(dfs(g,vst,col,i,s))return true;
		}
		else if(col[i] == col[s])return true;
	}
	return false;
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
		g[b].push_back(a);
	}
	bool vst[v+1];
	fill_n(vst,v+1,false);
	ll col[v+1];
	fill_n(col,v+1,-1);
	//vst[0] = 0;
	string res = "bipartite\n";
	for(ll i=0;i<v;i++)
	{
		if(!vst[i])
		{
			if(col[i]==-1)col[i] = 0;
			if(dfs(g,vst,col,i,-1))
			{
				res = "Not bipartite\n";
				break;
			}
		}
	}
	
	cout<<res<<endl;
	return 0;
}

