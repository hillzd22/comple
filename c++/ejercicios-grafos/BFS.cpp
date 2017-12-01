
#include <iostream>
#include <list>

using namespace std;

class Graph{
    private:
    
        int n;
        list<int>* listAd;
        void BFSUtil(int u, bool visited[]);
    
    
    public:
        Graph(int n=10);
        void addEdge(int v, int w);
        void BFS(int s);
};

Graph::Graph(int n){
    this->n = n;
    listAd = new list<int>[n];
    
}

void Graph::addEdge(int u, int v){
    listAd[u].push_back(v);
}

void Graph::BFSUtil(int v, bool visited[]){
    visited[v] = true;
    cout << v << " ";
    
    list<int>::iterator i;
    for(i = listAd[v].begin(); i!= listAd[v].end();++i)
        if(!visited[*i])
        BFSUtil(*i, visited);
}


void Graph::BFS(int s){
    bool *visited = new bool[n];
    for(int i=0; i<n; i++)
        visited[i]=false;
        
    list<int> queue;
    visited[s] = true;
    queue.push_back(s);
    
    list<int>::iterator it;
    
    while(!queue.empty()){
        s = queue.front();
        cout<< s << " ";
        queue.pop_front();
        
        for(it = listAd[s].begin(); it != listAd[s].end(); ++it){
            if(!visited[*it]){
                visited[*it] = true;
                queue.push_back(*it);
                
            }
            
        }
        
    }
    
    
}

int main(){
    //<--Grafos no dirigidos-->
    //Graph g(4); 
    int n=4,s=2;
    Graph gr(n);
    gr.addEdge(0,1);
    gr.addEdge(0,2);
    gr.addEdge(1,2);
    gr.addEdge(2,0);
    //gr.addEdge(2,1);
    gr.addEdge(2,3);
    //gr.addEdge(3,3);
    
    cout<< "BFS traversal : initial vertex 2)"<<endl;
    //g.BFS(2);
    gr.BFS(s);
    
    
    return 0;
}