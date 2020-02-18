
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<vector<ll>> v(10000000);

vector<ll> path;
 ll s,d;
void dfs(ll u,string ss,vector<ll> vis)
{
	if(vis[u]==0)
	{
    	vis[u]=1;
    	ss=ss+char(u+48);
    	if(u==d)
    	{
    		cout<<ss<<endl;
    		return;
    		//vis[u]=0;
    	}
    	for(ll i=0;i<v[u].size();i++)
    	{
    		dfs(v[u][i],ss,vis);	
		}
	}
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        for(ll i=0;i<m;i++)
        {
            ll x,y;
            cin>>x>>y;
            v[x].push_back(y);
        }
       
        cin>>s>>d;
        vector<ll> vis(10000000,0);
       
        string ss;
        ss=ss+char(s+48);
        vis[s]=1;
        for(ll i=0;i<v[s].size();i++)
        {
        	dfs(v[s][i],ss,vis);
        }
    }
}

