#include <bits/stdc++.h>
using namespace std;
struct node{
int dest;int weight;


};
class Graph{
private:int v;
			list<struct node >* adj;
	public:Graph(int v)
			{this->v=v;
				adj=new list<struct node>[v];

				}
			void addEdge(int src,int dest,int weight)
			{struct node temp;
				temp.dest=dest;
				temp.weight=weight;
				adj[src].push_back(temp);



			}
			
			void longestPathutil(int src,bool* visited,stack<int>& s)
			{visited[src]=1;
				list<struct node>::iterator i;
				for(i=adj[src].begin();i!=adj[src].end();i++)
				{if(!visited[i->dest])
					longestPathutil(i->dest,visited,s);

				}
				s.push(src);

			}
			void longestPath(int src)
			{bool visited[v];
				for(int i=0;i<v;i++)
				visited[i]=false;
				stack<int>s;

				longestPathutil(src,visited,s);
				for(int i=0;i<v;i++)
				{if(!visited[i])
					longestPathutil(i,visited,s);

				}
				int dist[v];
				for(int i=0;i<v;i++)
				dist[i]=INT_MIN;
				dist[src]=0;
				while(!s.empty())
				{int u=s.top();
					s.pop();
					if(dist[u]!=INT_MIN)
					{list<struct node>::iterator r;
						for(r=adj[u].begin();r!=adj[u].end();r++)
						{if(dist[u]+r->weight>dist[r->dest])
							dist[r->dest]=dist[u]+r->weight;

						}

					}

				}
				for(int i=0;i<v;i++)
				{cout<<i+1<<" "<<dist[i]<<"\n";

				}


			}



};
void printWords(char[][3] a)
{

}
int main()
{
char boggle[M][N] = {{'G','I','Z'},
                         {'U','E','K'},
                         {'Q','S','E'}};

    cout << "Following words of dictionary are present\n";
    printWords(boggle);
    return 0;





}