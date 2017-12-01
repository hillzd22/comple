#include<iostream>
#include<list>
#include<queue>

using namespace std;

class Graph {
    private:
        int n;
        list<int>* listAd;
        int* incoming;
    public:
        Graph(int n=10);
        void addEdge(int v, int w);
        bool existsIncomingVertex();
        void topologicalSort();

};

Graph::Graph(int n){
    this->n = n;
    listAd = new list<int>[n];
    //--
    incoming = new int[n];
    for(int i=0; i<n; i++)
        incoming[i]=-1;
        //incoming[i]=0;
}


/*void Graph::addEdge(int u, int v){
    listAd[u].push_back(v);
    incoming[v]++;
}*/

void Graph::addEdge(int u, int v){
    listAd[u].push_back(v);
    //------------
    if(incoming[u]<0) //source
        incoming[u]=0;
    //------------
    if(incoming[v]<0) //target
        incoming[v]=1;
    else
        incoming[v]++;
}

bool Graph::existsIncomingVertex(){
    for(int i=0; i<n;i++){
        if(incoming[i] == 0)
            return(true); 
    }
    return(false);
}

void Graph::topologicalSort(){
    queue<int> q;
    
    if(!existsIncomingVertex()) return;
    //--
    for(int i=0; i<n; i++){
        if(incoming[i] == 0)
            q.push(i);
    }
    //--
    while(!q.empty()){
        int u = q.front();
        q.pop();
        cout<<u<<" ";
        list<int>::iterator i;
        for (i = listAd[u].begin(); i != listAd[u].end(); ++i){
            int v =*i;
            incoming[v]--;
            if(incoming[v]==0){
                q.push(v);        
            }
        }
    }   
}

int main(){
      Graph g(8);
    g.addEdge(4,2);
    g.addEdge(4,0);
    g.addEdge(0,7);
    g.addEdge(3,5);
    g.addEdge(3,6);
    g.addEdge(3,7);
    g.addEdge(4,6);
    g.addEdge(2,7);
    g.topologicalSort();
    return(0);
    
    /*Graph g(10);
    g.addEdge(7,0);
    g.addEdge(7,8);
    g.addEdge(5,0);
    g.addEdge(3,8);
    g.addEdge(3,6);
    g.addEdge(0,2);
    g.addEdge(0,9);
    g.addEdge(0,6);
    g.addEdge(8,9);
    g.topologicalSort();
    return(0);*/
}

