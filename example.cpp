#include <iostream>
#include "combinatorial_generators.h"
using namespace std;

int main() {
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	vector<int> v2 = rand_perm(v1);
	for (int i = 0; i < (int)v2.size(); i++) {
		cout << v2[i] << endl;
	}
	return 0;
}
