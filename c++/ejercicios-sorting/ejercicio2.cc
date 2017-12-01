#include<iostream>
#include "quicksort.h"

using namespace std;

void printSeries(int arr[], int n1, int n2){
    if(n1 == n2){
        cout<<arr[n2];
    }else {
        cout<<arr[n1]<<", ";
        printSeries(arr,n1 +1,n2);
    }
}

void printArray(int arr[], int n, string title){
    cout<<title<<endl;
    printSeries(arr,0,n-1);
    cout<<endl;
}

int main(){
    int arr[] = {4,3,5,2,1,3,2,3};
    int n = sizeof(arr) / sizeof(*arr);
    
    printArray(arr,n,"Original Array");
    
    QuickSort* qs = new QuickSort();
    qs->sort(arr,0,n-1);
    
    printArray(arr,n,"Ordered Array");
    
    return 0;
}

