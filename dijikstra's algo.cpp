#include<bits/stdc++.h>

#define ll long long int
#define llu unsigned long long int
#define f(n) for(ll i=0;i<n;i++)
#define fr(n) for(ll i=n-1;i>=0;i--)
#define endl "\n"
#define INF 1e7
using namespace std;

typedef pair<ll, ll> pi;
vector<vector<ll>> v(1000000);
vector<vector<ll>> path(1000000);
priority_queue< pi , vector<pi>, greater<pi> > pq; 
vector<ll> dis(1000000,INF);
ll n,m;
void cl()
{
	f(n+1)
	{
		v[i].clear();
		dis[i]=INF;
		path[i].clear();
	}
}
int main()
{
	//#ifdef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	//B#endif
	std::ios_base::sync_with_stdio(false);
	ll t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		f(m)
		{
			ll a,b,c;
			cin>>a>>b>>c;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		ll src=1;
		pq.push(pi(0,src));
		dis[src]=0;
		while(!pq.empty())
		{
			ll u=pq.top().second;
			pq.pop();
			for(ll i=0;i<v[u].size();i++)
			{
				if(dis[v[u][i]]>dis[u]+1)
				{
					dis[v[u][i]]=dis[u]+1;
					path[v[u][i]].clear();
					path[v[u][i]].insert(path[v[u][i]].begin(),path[u].begin(),path[u].end());
					path[v[u][i]].push_back(u);
					pq.push(pi(dis[v[u][i]],v[u][i]));
				}
			}
		}
		for(ll i=1;i<=n;i++)
		{
			cout<<i<<" - " <<dis[i]<<"--";
			for(ll j=0;j<path[i].size();j++)
			{
				cout<<path[i][j]<<" ";
			}
			cout<<endl;
		}
		cl();
	}
	return 0;
}
