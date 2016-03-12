#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <queue>
#include <string.h>
#include <list>
using namespace std;
class Graph{
   private:
   			int vertices;
   			list<int >* adj;
   public: 
   			Graph(int v)
   			{this->vertices=v;
   				 adj=new list<int>[vertices];
   			}
   			void addEdge(int u,int v)
   			{adj[u].push_back(v);
   				//cout<<"oh ";
   			}
   			void dfsutil(bool visited[],int u,int *path,int len)
   			{visited[u]=true;int flag=0;
   				path[len++]=u;
   				list<int>::iterator y;
   				for(y=adj[u].begin();y!=adj[u].end();y++)
   				{if(!visited[*y])
   					{flag=1;
   					break;
   					}


   				}
   				if(flag==0)
   				{
   				for(int i=0;i<len;i++)
   						cout<<path[i]<<" ";
   					cout<<endl;

   				}
   				list<int>::iterator t;
   				for(t=adj[u].begin();t!=adj[u].end();t++)
   				{if(!visited[*t])
   					dfsutil(visited,*t,path,len);

   				}


   			}
   			void dfs(int src)
   			{bool visited[vertices];
   				for(int i=0;i<vertices;i++)
   					visited[i]=false;
   				int path[vertices];
   				int len=0;
   				dfsutil(visited,src, path,len);


   			}
   			bool isreachableutil(bool visited[],int u,int v)
   			{visited[u]=true;
   				if(u==v)
   					return true;
   				list<int >::iterator t;
   				for(t=adj[u].begin();t!=adj[u].end();t++)
   				{if(!visited[*t])
   					{if( isreachableutil(visited,*t,v))
   						return true;
   					}

   				}
   				return false;
   			}
   			bool isReachable(int u,int v)
   			{bool visited[vertices];
   				for(int i=0;i<vertices;i++)
   					visited[i]=false;
   				return isreachableutil(visited,u,v);


   			}
   			void bfs(int u)
   			{queue<int>q;
   				bool visited[vertices];
   				for(int i=9;i<vertices;i++)
   					visited[i]=false;
   				q.push(u);
   				//visited[u]=true;
   				q.push(-1);
   				while(!q.empty())
   				{int temp=q.front();
   					q.pop();
   					if(temp==-1)
   					{if(!q.empty())
   						q.push(-1);
   						cout<<endl;

   					}
   					else {cout<<temp<<" ";
   						visited[temp]=true;

   					list<int >::iterator t;
   					for(t=adj[temp].begin();t!=adj[temp].end();t++)
   						{if(!visited[*t])
   							q.push(*t);
   					//visited[*t]=true;
   				}

   				}


   				}

   			}
   			bool iscyclicutil(bool visited[],int u)
   			{if(visited[u])
   				return true;
   				visited[u]=true;
   				list<int>::iterator t;
   				for(t=adj[u].begin();t!=adj[u].end();t++)
   				{
   					if(iscyclicutil(visited,*t))
   						return true;
   				}
   				visited[u]=false;
   				return false;

   			}
   			bool isCyclic()
   			{bool visited[vertices];
   				for(int i=0;i<vertices;i++)
   					visited[i]=false;
   				return iscyclicutil(visited,0);



   			}
   			void topologicalsortutil(bool* visited,int u,stack<int>& s)
   			{visited[u]=true;
   				list<int>::iterator t;
   				for(t=adj[u].begin();t!=adj[u].end();t++)
   				{if(!visited[*t])
   					topologicalsortutil(visited,*t,s);

   				}
   				s.push(u);

   			}
   			void topologicalSort(satck<int>& s)
   			{bool visited[vertices];
   				for(int i=0;i<vertices;i++)
   				{visited[i]=false;

   				}
   				//stack<int> s;
   				for(int i=0;i<vertices;i++)
   					{if(!visited[i])
   				topologicalsortutil(visited,i,s);
   			}
   				

   			}
   			bool isbipartiteutil(bool* visited,int* color,int u,int index)
   			{visited[u]=true;
   				color[u]=index;
   				list<int>::iterator t;
   				for(t=adj[u].begin();t!=adj[u].end();t++)
   				{if(!visited[*t]&&isbipartiteutil(visited,color,*t,1-index))
   					return true;
   				else if(visited[*t]&&color[*t]==color[u])
   					return false;
   				else if(visited[*t]&&color[*t]!=color[u])
   					return true;

   				}
   				

   			}
   			bool isbipartite()
   			{bool visited[vertices];
   				for(int i=0;i<vertices;i++)
   					visited[i]=false;
   				int color[vertices];
   				for(int i=0;i<vertices;i++)
   					color[i]=-1;
   				for(int i=0;i<vertices;i++)
   				{if(!visited[i])
   					{if(!isbipartiteutil(visited,color,i,0))
   						return false;

   					}

   				}
   				return true;

   			}

   			void longestPath(int s)
   			{stack<int> s;
   				topologicalSort(s);

   				int dist[vertices];
   				for(int i=0;i<vertices;i++)
   					dist[i]=-100000;
   				dist[s]=0;


   			}
   			Graph gettranspose()
   			{Graph g(vertices);
   				for(int i=0;i<vertices;i++)
   				{list<int>::iterator t;
   					for(t=adj[i].begin();t!=adj[i].end();t++)
   					{g.adj[*t].push_back(i);

   					}

   				}

   				return 
   			}
   			void isscutil(int u,int* visited)
   			{visited[u]=true;
   				list<int >::iterator t;
   				for(t=adj[u].begin();t!=adj[u].end();t++)
   				{if(!visited[*t])
   					iscutil(*t,visited);

   				}

   			}
   			bool isSC()
   			{bool visited[vertices];
   				for(int i=0;i<vertices;i++)
   					visited[i]=false;
   					isscutil(0,visited);
   					for(int i=0;i<vertices;i++)
   					if(visited[i]==false)
   					return false;
   					Graph g2=gettranspose();
   					for(int i=0;i<vertices;i++)
   					visited[i]=false;
   					g2.isscutil(0,visited);
   					for(int i=0;i<vertices;i++)
   					if(visited[i]==false)
   					return false;

   				return true;	


   			}
   			void aputil(bool *visited,int* parent,bool* ap,int *disc,int *low,int u)
   			{static time=0;
   				visited[u]=true;
   				int children=0;
   				disc[u]=low[u]=++time;
   				list<int>::iterator t;
   				for(t=adj[u].begin();t!=adj[u].end();t++)
   				{int v=*t;
   					if(!visited[v])
   					{children++;
   						parent[v]=u;
   						dfsutil(visited,parent,ap,disc,low,v);
   						low[u]=min(low[u],low[v]);
   						if(children>1&&parent[u]==-1)
   							ap[u]=true;
   						if(low[v]>=disc[u]&&parent[u]!=-1)
   							ap[u]=true;

   					}
   					else if(v!=parent[u])
   						low[u]=min(low[u],disc[v]);

   				}



   			}
	   		void AP()
   			{
   				bool visited[vertices];
   			int parent[vertices];
   			bool ap[vertices];
   			int disc[vertices]	;
   			int low[vertices];
   			for(int i=0;i<vertices;i++)
   			{parent[i]=-1;
   				ap[i]=false;
   				disc[i]=low[i]=0;
   				visited[i]=false;
   				for(int i=0;i<vertices;i++)
   				{if(!visited[i])
   				aputil(visited,parent,ap,disc,low,i)
   			}

   			}
   			}





};

void countSort(char* str)
{int hash[255]={0};
for(int i=0;i<strlen(str);i++)
hash[str[i]]++;
for(int i=1;i<255;i++)
{hash[i]=hash[i]+hash[i-1];

}
int output[strlen(str)];
for(int i=strlen(str)-1;i>=0;i--)
{output[hash[str[i]]]=str[i];
	hash[str[i]]--;

}




}




int main()
{
	 

// Create graphs given in the above diagrams
    Graph g1(5);
    g1.addEdge(0, 1);
    g1.addEdge(1, 2);
    g1.addEdge(2, 3);
    g1.addEdge(3, 0);
    g1.addEdge(2, 4);
    g1.addEdge(4, 2);
    g1.isSC()? cout << "Yes\n" : cout << "No\n";

    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.isSC()? cout << "Yes\n" : cout << "No\n";

    return 0;




	return 0;
}