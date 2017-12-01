#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> iPair;

class DisjointSets{
    public:
        int *parent, *rank;
        int n;
        
    DisjointSets(int n){
        this->n = n;
        parent = new int[n + 1];
        rank = new int[n + 1];
        for (int i = 0; i <= n; i++){
            rank[i] = 0;
            parent[i] = i;
        }
    }
    
    
    int findSet(int u){
        if (u != parent[u])
            parent[u] = findSet(parent[u]);
        return parent[u];
    }
    
    void unionSet(int x, int y){
        x = findSet(x);
        y = findSet(y);
        
        if (rank[x] > rank[y])
            parent[y] = x;
        else
            parent[x] = y;
        
        if(rank[x] == rank[y])
            rank[y]++;
    }
};

class Graph{
    
    public:
        int V, E;
        vector< pair<int, iPair> > edges;
        
        Graph(int V, int E){
            this->V = V;
            this->E = E;
            
        }
        
        void addEdge(int u, int v, int w){
            edges.push_back({ w, {u,v} });
        }
        
        int kruskalMST(){
            int mst_wt = 0;
            sort(edges.begin(),edges.end());
            DisjointSets ds(V);
            vector< pair<int, iPair> >::iterator it;
            for (it = edges.begin(); it != edges.end(); it++){
                int u = it->second.first;
                int v = it->second.second;
                int set_u = ds.findSet(u);
                int set_v = ds.findSet(v);
                
                if (set_u != set_v){
                    cout << u << " - " << v << endl;
                    mst_wt += it->first;
                    ds.unionSet(set_u,set_v);
                
                }
                
            }
            return mst_wt;
        }
    
};


int main(){
    int n = 9;
    int m = 14;
    Graph g(n, m);
    
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
    
    cout<< "Edges of MST are \n";
    int mstWeight = g.kruskalMST();
    
    cout<< "\nWeight of MST is " << mstWeight;
    
    cin.get();
    return 0;
}