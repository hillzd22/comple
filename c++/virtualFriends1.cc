#include <iostream>
#include <cstring>  //memset
#include <utility>
#include <map>      // key value

#define N 10 // the problem specify 10^6 
using namespace std;

int parent[N];   /// vertice representativo
map <string, int> m;  /// <personName numPersonInSocitalNetwork>

int numAmistades; 
int idx; ///max  x red social
//---
int findParent(int n) {
	if (parent[n] < 0) 
		return n;
	return	
		parent[n] = findParent(parent[n]);
}
//---

void checkFriendShip(int numAmistades) {
	for (int i = 0; i < numAmistades; i++) {
		string first, second;
		cin >> first >> second;

		if (!m[first])
			m[first] = idx++;
		if (!m[second])
			m[second] = idx++;

		int vf = m[first];
		int vs = m[second];
		
		int p = findParent(vf);
		int q = findParent(vs);

		if (p == q) {
			cout<<(parent[p] * -1)<<endl;
			continue;
		}

		if (parent[p] < parent[q]) {
			parent[p] += parent[q];
			parent[q] = p;
			cout<<(parent[p] * -1)<<endl;
		}else {
			parent[q] += parent[p];
			parent[p] = q;
			cout<<(parent[q] * -1)<<endl;
		}
	}
}

//-------------------
int main(){
	int numTest;
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin>>numTest;
	while (numTest--) {
		cin>>numAmistades;
		memset(parent, -1, sizeof(parent));
		idx = 1;
		checkFriendShip(numAmistades);
	}
	return 0;
}
