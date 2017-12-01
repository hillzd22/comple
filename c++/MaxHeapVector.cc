// BinaryHeap.cpp: archivo de proyecto principal.

#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

class BinaryHeap {
public:
	map<int, string> mapa;
	vector<int> a;
	int k = 0;
	BinaryHeap() {}

	void mostrar() {
		for (int i = 0; i < a.size(); i++) {
			cout <<"a[" << i << "] -> " << a[i] <<" -> "<< mapa[a[i]]<< endl;
		}
		cout << endl;
	}

	void insertar(string s, int num) {
		cout << "Insertando " << num << endl;
		mapa[num] = s;
		a.insert(a.end(), num);
		int child = a.size() - 1;
		int parent = (child - 1) / 2;
		while (a[parent] > a[child]) {
			swap(a[parent], a[child]);
			child = parent;
			parent = child / 2;
		}
	}

	int parent(int pos) {
		return (pos - 1) / 2;
	}
	int get_l_pos(int pos) {
		return 2 * pos + 1;
	};
	int get_l_val(int pos) {
		return a[2 * pos + 1];
	};
	int get_r_pos(int pos) {
		return 2 * pos + 2;
	};
	int get_r_val(int pos) {
		return a[2 * pos + 1];
	};

	int min() {
		return a[0];
	}

	int max() {
		int m = a[0];
		for (int i = 1; i < a.size(); i++) {
			if (a[i] > m)
				m = a[i];
		}
		return m;
	}

	int extract() {
		int r = a[0];
		a[0] = a[a.size() - 1];
		a.erase(a.end()-1);

		for (int i = 0; i < a.size(); i++) {
			int child = i;
			int parent = (child-1) / 2;
			while (a[parent] > a[child]) {
				swap(a[parent], a[child]);
				child = parent;
				parent = child / 2;
			}
		}
		return r;
	}
};

	int main()
	{
		locale::global(locale("spanish"));
		BinaryHeap b;
		b.insertar("Jimena",13);
		b.mostrar();
		b.insertar("Andrés",67);
		b.mostrar();
		b.insertar("Juan",15);
		b.mostrar();
		b.insertar("Alberto",2);
		b.mostrar();
		b.insertar("Lucho",5);
		b.mostrar();
		b.insertar("Flavia",1);
		b.mostrar();
		b.insertar("Pathy",89);
		b.mostrar();
		cout << "Mínimo: " << b.min() << endl;
		cout << "Máximo: " << b.max() << endl << endl;
		cout << "Elemento extraído: " << b.extract() << endl;
		b.mostrar();
	}