/**
  *		author: nate_river
  */
#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false)
using namespace std;
typedef long long int ll;
ll v;
void alltoposort(auto &g,bool vst[],auto& res,ll indeg[])
{
	bool f = false;
	for(ll i=0;i<v;i++)
	{
		if(!vst[i] && indeg[i]==0)
		{	
			for(ll j:g[i])indeg[j]--;
			vst[i] = true;
			res.push_back(i);
			alltoposort(g,vst,res,indeg);
			for(ll j:g[i])indeg[j]++;
			vst[i] = false;
			res.pop_back();
			f = true;	
		}
	}
	if(!f)
	{
		for(ll i:res)cout<<i<<" ";
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
	list<ll> res;
	bool vst[v+1];
	fill_n(vst,v+1,false);
	alltoposort(g,vst,res,indeg);
	return 0;
}