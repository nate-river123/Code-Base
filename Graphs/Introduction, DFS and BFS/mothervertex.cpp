/**
 *    author: nate_river
 *    created: 2/19/2018 
**/
#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false)
using namespace std;
typedef long long int ll;
void dfs(vector<vector<ll> > &g,bool vst[],ll s)
{
	vst[s] = true;
	for(ll i:g[s])
	{
		if(!vst[i])
		dfs(g,vst,i);
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
	ll m;
	for(ll i=0;i<v;i++)
	{
		if(!vst[i])
		{
			dfs(g,vst,i);
			m = i;
		}
	}
	
	fill_n(vst,v+1,false);
	dfs(g,vst,m);
	ll res = 0;
	for(ll i=0;i<v;i++)
	{
		if(!vst[i])
		{
			res = -1;
			break;
		}
	}
	if(res == -1)cout<<res<<endl;
	else cout<<m<<endl;
	
	return 0;
}

