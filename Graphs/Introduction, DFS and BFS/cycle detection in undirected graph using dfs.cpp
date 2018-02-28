/**
 *    author: nate_river
 *    created: 2/8/2018 
**/
#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false)
using namespace std;
typedef long long int ll;
bool dfs(vector<vector<ll> > &g,bool vst[],ll s,ll p)   //returns true if cycle
{
	//if(p!=-1 && vst[p]==true && )
	vst[s] = true;
	//cout<<s<<" ";
	for(ll i:g[s])
	{
		if(!vst[i])
		{
			if(dfs(g,vst,i,s))return true;
		}
		else if(i!=p)return true;
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
	string res = "no cycle";
	for(ll i=0;i<v;i++)
	{
		if(!vst[i])
		{
			bool ans = dfs(g,vst,i,-1);
			if(ans){
				res = "cycle";
				break;
			}
		}
	}
	cout<<res<<endl;
	return 0;
}

