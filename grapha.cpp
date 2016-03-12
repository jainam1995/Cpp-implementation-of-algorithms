#include <bits/stdc++.h>
using namespace std;
class Graph{
	private:int vertices;
		list<int>* adj;
	public:
		Graph(int v)
		{this->vertices=v;
			adj=new list<int>[v];

		}
		void addEdge(int u,int v)
		{adj[u].push_back(v);
			adj[v].push_back(u);

		}
		void dfs(int s)
		{
			
		}




};
