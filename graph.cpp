#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <queue>
#include <vector>
#include <list>
using namespace std;
struct node
{int dest;
	int weight;

};
class Graph
{private:
	int v;
	list<struct node> * adj;
public:
	Graph(int v)
	{this->v=v;
		adj=new list<struct node>[v];


	}
	void addEdge(int src,int dest,int weight)
	{struct node n;
		n.dest=dest;
		n.weight=weight;
		adj[src].push_back(n);

	}
	void topologicalSortutil(int v,stack<int>& s,bool* visited)
	{visited[v]=true;
		list<struct node>::iterator i;
		for(i=adj[v].begin();i!=adj[v].end();i++)
		{if(!visited[(*i).dest])
			topologicalSortutil((*i).dest,s,visited);

		}
		s.push(v);

	}
	void topologicalSort(stack<int>& s)
	{
		bool visited[this->v];
		for(int i=0;i<this->v;i++)
			visited[i]=false;
		for(int i=0;i<this->v;i++)
		{if(!visited[i])
			topologicalSortutil(i,s,visited);

		}

		
	}

	void longestPath(int src)
	{stack<int>s;
		topologicalSort(s);

		int dist[this->v];
		for(int i=0;i<this->v;i++)
			{dist[i]=-100000;}
			dist[src]=0;
			list<struct node>::iterator f;
			while(!s.empty())
			{int temp=s.top();
				s.pop();
				if(dist[temp]!=-100000)
				{for(f=adj[temp].begin();f!=adj[temp].end();f++)
					{if(dist[temp]+(*f).weight>dist[(*f).dest])
						dist[(*f).dest]=dist[temp]+(*f).weight;



					}

				}




			}

			for(int i=0;i<this->v;i++)
				 (dist[i] == -100000)? cout << "INF ": cout << dist[i] << " ";

	}
};
bool biutil(int g[][4],int src,int color[][4],bool* visited,int p){
visited[k]=true;
color[k]=p;
for(int i=0;i<4;i++)
{

}



}
bool isBipartite(int g[][4],0)
{int color[4];int p=0;
	
	for(int j=0;j<4;j++)
		color[j]=-1;

	
bool visited[4]=false;
for(int k=0;k<4;k++)
{if(!visited[k])
	{if(biutil(g,k,color,visited,p)==false)
		return false;
	}
}
return true;
}
int main()
{   int V=4;
	int G[][V] = {{0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}
    };
 
    isBipartite(G, 0) ? cout << "Yes" : cout << "No";
	return 0;
}


