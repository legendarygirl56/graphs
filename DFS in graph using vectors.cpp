#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> v(100000);
vector<int> ve(100000,0);
void dfs(int u)
{
	if(!ve[u])
	{
	ve[u]=1;
	cout<<u<<" ";	
	for(int i=0;i<v[u].size();i++)
		{
			dfs(v[u][i]);
		}
	}
}
int main()
{
	int V;
	cin>>V;
	int t;
	cin>>t;
	while(t--)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);//for undirected graph
	}
	for(int i=1;i<=V;i++)
	{
		dfs(i);
	}	
}
