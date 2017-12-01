
#include "maxheap.h"


class PriorityQueue{
private:
    MaxHeap* h;
public:
    PriorityQueue(int n){
        h = new MaxHeap(n);
    }
    //
    void addElement(int item){
        h->insert(item);
    }
    //
    int deleteElemento(){
        return(h->extract());
    }
    //---
    void addElementPriority(){
        h->insert(9999);
    }
    void service(){
        cout<<"served: " << deleteElemento();
    }
    void showQueue(){
        h->show();
    }
};
///
int main(){
    srand(time(NULL));
    int n=10;
    PriorityQueue* pq  = new PriorityQueue(n);
    for(int i=0;i<=n;i++){
        if(i%2 == 0) 
            pq->addElementPriority();
        //
        pq->addElement(10+rand()%10);
    }
    //
    pq->showQueue();
    return(0);
}