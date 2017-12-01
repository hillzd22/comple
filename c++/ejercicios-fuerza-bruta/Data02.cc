#include<iostream>

using namespace std;

class Operation{
    
    public:
    int sum(int n){
        if(n <= 0) return 0;
        int total = n + sum(n-1);
        return total;
    }
    
    int mul(int n){
        
    }
    
    int sumRec(int*v, int minVal, int maxVal){
        if(minVal<=maxVal){
            return(v[minVal]);
        }
        
        int sumTotal = minVal + sumRec(v, minVal+1, maxVal);
        return sumTotal;
    }
};

int main(){
    
    Operation* op = new Operation();
    cout<<"sum(5)=> "<<op->sum(5)<<endl;
    cout<<"mul(5)=> "<<op->mul(5)<<endl;
    int val[]={-1,-2,0,1,2,3};
    int n = sizeof(val)/sizeof(int);
    cout<<op->sumRec(val,0,n-1);
    return 0;
}