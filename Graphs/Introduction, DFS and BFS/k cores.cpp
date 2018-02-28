/**
 *    author: nate_river
 *    created: 2/23/2018 
**/
#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false)
using namespace std;
typedef long long int ll;
bool modified_dfs(auto &g,bool vst[],ll vdeg[],ll s,ll k)
{
	vst[s] = true;
	for(ll i:g[s])
	{
		if(vdeg[s]<k)
			vdeg[i]--;
		
		if(!vst[i])
		{
			if(modified_dfs(g,vst,vdeg,i,k))
				vdeg[s]--;	
		}	
	}
	return (vdeg[s]<k);
}
int main()
{
	io;
	freopen("input.txt", "r", stdin);
	ll v,e,k;
	cin>>v>>e;
	vector<vector<ll> > g(v+1);
	for(ll i=0;i<e;i++)
	{
		ll a,b;
		cin>>a>>b;	
		g[a].push_back(b);
		g[b].push_back(a);
	}
	cin>>k;
	bool vst[v+1];
	fill_n(vst,v+1,false);
	ll vdeg[v];
	ll mindeg=INT_MAX,sv=0;
	for(ll i=0;i<v;i++)
	{
		vdeg[i] = g[i].size();
		if(vdeg[i] < mindeg)
		{
			mindeg = vdeg[i];
			sv = i;
		}
	}
	modified_dfs(g,vst,vdeg,sv,k);
	for(ll i=0;i<v;i++)
	{
		if(!vst[i])
			modified_dfs(g,vst,vdeg,i,k);
	}
	for(ll i=0;i<v;i++)
	{
		if(vdeg[i]>=k)
		{
			cout<<"["<<i<<"]"<<"-> ";
			for(ll j:g[i])
			{
				if(vdeg[j]>=k)
				cout<<j<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}

