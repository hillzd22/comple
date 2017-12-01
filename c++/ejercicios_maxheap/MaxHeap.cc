#include <iostream>
using namespace std;

void swaper(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}


class MaxHeap{
private:
	int *heap;
	int capacity;
	int position;
public:
	MaxHeap(int cap){
		position = 1;        //heap[1]...heap[capacity]
		capacity = cap+1;    //6 
		heap = new int[capacity];
	}

	void insert(int value){
		if (position == capacity){
			cout << endl << "No se pueden insertar la clave" << endl;
			return;
		}

		heap[position++] = value;
		int child = position - 1;
		int parent = child / 2;

		while (heap[parent]<heap[child] && parent>0){
			swap(heap[parent], heap[child]); //library function
			//swaper(&heap[parent], &heap[child]); //own function
			child = parent;
			parent = child / 2;
		}
	}
	//---
	int extract(){
		//
		if(capacity<1)
			cout<<"Heap Overflow";
		//
	    int val = heap[1];
	    heap[1]=heap[position-1];
	    heap[position-1]=0;
	    position--;
	    int i=1;
	    while(i<=capacity){
	        int lc = 2*i;
	        int rc = 2*i+1;
	        if(lc>capacity && rc>capacity) break;
	        int cc = (heap[lc]>heap[rc])?lc:rc;
	        if(heap[i]<heap[cc])
	            swap(heap[i], heap[cc]);
	        i++;
	    }
	    return(val);
	}
	//----
	void increase(int i, int key){// i es index
		if(key<heap[i])	cout<<"Error"<<endl;
		//---
		heap[i]=key;
		int child = i;
		int parent = child/2;
		while(heap[parent]<heap[child] && parent>0 ){
			swap(heap[parent], heap[child]);
			child=parent;
			parent=child/2;
			
		}
	}
	//-----
	
	void show(){
		for (int i = 0; i<capacity; i++){
			cout << "heap[" << i << "]=> " << heap[i] << endl;
		}
	}
	//
	int* heapSort(){
		int* a = new int[capacity+1];
		a[0]=-1;
		for(int i=1; i<capacity;i++){
			a[i]=extract();
		}
		return(a);
	}
};
//
int main(){
	MaxHeap *heap = new MaxHeap(6);
	heap->insert(12);
	heap->insert(7);
	heap->insert(6);
	heap->insert(10);
	heap->insert(8);
	heap->insert(20);
	//
	cout<<" Showing ..."<<endl;
	heap->show();
	//
	cout<<endl;
	cout<<"increasing 6 position to 600"<<endl;
	heap->increase(6,600);
	cout<<" Showing ..."<<endl;
	heap->show();
	
	cout<<endl<<"Ordering..."<<endl;
	int*v = heap->heapSort();
	for(int i=1; i<=6;i++)
		cout<<v[i]<<" ";
	//
	
	
	return(0);
}
