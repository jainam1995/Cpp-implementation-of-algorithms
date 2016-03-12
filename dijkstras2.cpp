#include <bits/stdc++.h>
 
using namespace std;
 

#define INF (1 << 30)

#define pii pair<int, int>


#define Max 100000
struct Graph{
int vertices;
vector<struct edge >* adj;



};
struct edge{
int dest;
int weight;

};
 Graph* createGraph(int v)
 {struct Graph* graph=(struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices=v;
    graph->adj=new vector<struct edge>[v];

    return graph;

 }
void addEdge(struct Graph* graph,int u,int v,int weight)
{struct edge temp;
    temp.dest=v;
    temp.weight=weight;
    graph->adj[u].push_back(temp);
    temp.dest=u;
    graph->adj[v].push_back(temp);



}
class Compare {
public:
    int operator() ( const struct edge& p1, const struct edge& p2 ) {
        return p1.weight >= p2.weight;
    }
 
};
 
priority_queue <struct edge, vector<struct edge >, Compare> q;
//vector < struct edge > adj[Max + 1];
//int dis[Max + 1];
//int N;
 

 
int dijkstra(struct Graph* graph,int &src,int& des) {
   q = priority_queue <struct edge, vector< struct edge >, Compare > ();
   int dis[graph->vertices];
    for(int i = 0; i < graph->vertices; ++i) dis[i] = INF;
    dis[src] = 0;
struct edge temp;
temp.dest=src;
temp.weight=0;
    q.push(temp);
    while(!q.empty()) {
        int u = (q.top()).dest;
        q.pop();
        if(u == des) return dis[des];
        for(int i = 0, n = (int)graph->adj[u].size(); i < n; ++i) {
            int v = (graph->adj[u][i]).dest;
            int cost = (graph->adj[u][i]).weight;
 
            if(dis[v] > dis[u] + cost) {
                dis[v] = dis[u] + cost;
                struct edge temp;
                temp.dest=v;
                temp.weight=dis[v];
                q.push(temp);
            }
        }
    }

for(int i=0;i<graph->vertices;i++)
{cout<<"Verte "<<i<<" ------- "<<dis[i];
cout<<"\n";

}

    return -1;
}


int main(void) {
     // create the graph given in above fugure
    int V = 9;
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 7, 8);
    addEdge(graph, 1, 2, 8);
    addEdge(graph, 1, 7, 11);
    addEdge(graph, 2, 3, 7);
    addEdge(graph, 2, 8, 2);
    addEdge(graph, 2, 5, 4);
    addEdge(graph, 3, 4, 9);
    addEdge(graph, 3, 5, 14);
    addEdge(graph, 4, 5, 10);
    addEdge(graph, 5, 6, 2);
    addEdge(graph, 6, 7, 1);
    addEdge(graph, 6, 8, 6);
    addEdge(graph, 7, 8, 7);
int src=0;int des=11;
   int ans= dijkstra(graph, src,des);
   // cout<<(graph->adj[0][1]).weight;
   cout<<ans;

}