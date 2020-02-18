#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> v(100000);
vector<int> ve(100000,0);
void bfs(int u)
{
	queue<int>q;
	q.push(u);
	ve[u]=1;
	while(!q.empty())	
	{
		int f=q.front();
		q.pop();
		cout<<f<<" ";
		for(int i=0;i<v[f].size();i++)
		{
			if(!ve[v[f][i]])
			{
				q.push(v[f][i]);
				ve[v[f][i]]=1;
			}
		}
	}
}
int main()
{
	int V,t;
	cin>>V>>t;
	while(t--)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
	}
	for(int i=1;i<=V;i++)
	{
		if(!ve[i])
		bfs(i);
	}
}
