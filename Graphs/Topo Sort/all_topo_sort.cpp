/**
  *		author: nate_river
  */
#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false)
using namespace std;
typedef long long int ll;
ll v;
void dfs(auto &g,bool vst[],auto &stk,ll s)
{
	vst[s] = true;
	for(ll i:g[s])
	{
		if(!vst[i])
		{
			dfs(g,vst,stk,i);
		}
	}
	stk.push_front(s);
}


void alltopo(auto &g,ll indeg[],bool vst[],auto &res)
{
	bool flg = false;
	for(ll i=0;i<v;i++)
	{
		if(!vst[i] && indeg[i]==0)
		{
			for(ll j:g[i])
			{
				indeg[j]--;
			}
			res.push_back(i);
			vst[i] = true;
			alltopo(g,indeg,vst,res);

			vst[i] = false;
			res.pop_back();
			for(ll j:g[i])
			{
				indeg[j]++;
			}
			flg = true;
		}
	}

	if(!flg)
	{
		for(ll i:res)
			cout<<i<<" ";
		cout<<endl;
	}
}

int main()
{
	io;
	ll e;
	cin>>v>>e;
	vector<vector<ll> > g(v+1);
	ll indeg[v+1];
	fill_n(indeg,v+1,0);
	for(ll i=0;i<e;i++)
	{
		ll a,b;
		cin>>a>>b;
		g[a].push_back(b);
		indeg[b]++;
	}
	bool vst[v+1];
	fill_n(vst,v+1,false);
	list<ll> res;
	alltopo(g,indeg,vst,res);
	return 0;
}