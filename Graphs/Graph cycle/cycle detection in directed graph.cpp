/**
 *    author: nate_river
 *    created: 2/27/2018 
**/
#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false)
using namespace std;
typedef long long int ll;
int main()
{
	io;
	freopen("input.txt", "r", stdin);
	ll v,e;
	cin>>v>>e;
	vector<vector<ll> > g(v+1);
	for(ll i=0;i<v;i++)
	{
		ll a,b;
		cin>>a>>b;
		g[a].push_back(b);
	}
	bool vst[]
	return 0;
}

