#include<iostream>

using namespace std;

class UfdsRankPathCom{
private: 
	int* parent;
	int* rank;
	int length;

public: 
	UfdsRankPathCom(int N){
		length = N;
		parent = new int[N];
		rank = new int[N];
		//---
		for (int i = 0; i < N; i++){
			parent[i] = i;
			rank[i]=0;
		}
	}
	//
	bool sameSet(int x, int y){
	    return findSet(x) == findSet(y);
	}
	//
	int findSet(int x){
	    if( x != parent[x] )
	        parent[x] = findSet(parent[x]);
	    return parent[x];
	}
	//
	void unionSetUtil(int x, int y){
	    if(!sameSet(x, y) ){
	        if( rank[x] > rank[y] ){
	            parent[y] = x;
	        }
	        else{
	            parent[x] = y;
	            if(rank[x] == rank[y])
	                rank[y] = rank[y] + 1;
	        }
	
	    }
	}
	
	void unionSet(int x, int y){
	    unionSetUtil(findSet(x), findSet(y) );
	}	
	
	//
	void showSet(){
		for (int i = 0; i < length; i++)
			cout<<"parent of: "<<i<<" is " << parent[i]<<endl;
	}
};

///

int main(){
	UfdsRankPathCom* ubrpc = new UfdsRankPathCom(6);
	ubrpc->showSet();
	cout<<endl;
	//
	ubrpc->unionSet(1,2);
	ubrpc->unionSet(2,4);
	ubrpc->unionSet(0,2);
	ubrpc->unionSet(3,5);
	//
	cout<<endl;
	ubrpc->showSet();
	cin.get();
	return(0);
}