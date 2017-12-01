#include <iostream>
#include <string>
#include "prefix.h"

using namespace std;

int main(){
    string arr[] = {"perdurar", "perpetuar", "perseverar", "permanecer", "pertenecer", "permanente"};
    
    int n = sizeof(arr) / sizeof(arr[0]);

    Prefix* pf = new Prefix();
    string ans = pf->findCommonPrefix(arr,0,n-1);
    
    if(ans.length())
    cout<< "The longest common prefix is => "<< ans;
    else
    cout<< "There is no common prefix ";
    
    return(0);

}
