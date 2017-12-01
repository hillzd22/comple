#ifndef QUICKSORT_H
#define QUICKSORT_H

using namespace std;
class QuickSort{
    public:
        void swap (int* a, int* b){
            int t= *a;
            *a = *b;
            *b = t;
        }
        
        int partition (int arr[], int l, int h){
            int x =arr[h];
            int i =(l-1);
            
            for(int j=l; j<=h-1; j++){
                if(arr[j] <= x){
                    i++;
                    swap (&arr[i], &arr[j]);
                }
            }
            swap(&arr[i+1], &arr[h]);
            return(i+1);
        }
        
        void sort(int A[], int l, int h){
            if(l < h){
                int p = partition(A,l,h);
                sort(A,l,p-1);
                sort(A,p+1,h);
            }
        }
};
#endif