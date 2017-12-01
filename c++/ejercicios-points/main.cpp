using namespace std;

int main(){
    Point P[] = {{2,3}, {12,30}, {40,50}, {5,1}, {12,10}, {3,4}};
    FinderPoints* fp = new FinderPoints();
    int n = sizeof(P) / sizeof(P[0]);
    cout<<"The smallest distance(BF)=>"<<fp->closestPairBF(P,n)<<endl;
    return(0);
    
}