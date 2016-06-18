#include <iostream>
#include "combinatorial_generators.h"
using namespace std;

void rand_perm_example() {
	cout << "rand_perm_example:" << endl;
	vector<int> v1;
	for (int i = 0; i < 8; i++) {
		v1.push_back(i);
	}
	vector<int> v2 = rand_perm(v1);
	for (int i = 0; i < (int)v2.size(); i++) {
		cout << v2[i] << " ";
	}
	cout << endl << endl;
}

void rand_parentheses_example() {
	cout << "rand_parentheses_example:" << endl;
	int nbPairs = 10;
	vector<int> v = rand_parentheses(nbPairs);
	for (int i = 0; i < (int)v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl << endl;
}

void rand_tree_example() {
	cout << "rand_tree_example:" << endl;
	int nbNodes = 6;
	vector< pair<int,int> > edges = rand_tree(nbNodes);
	for (int i = 0; i < (int)edges.size(); i++) {
		cout << "(" << edges[i].first << ","<< edges[i].second << ") ";
	}
	cout << endl << endl;
}

/*
  This graph will be used as input for different examples.
  The result is on the form (nbNodes, edgeList).
*/
pair<int, vector< pair<int,int> > > small_graph() {
	int nbNodes = 8;
	vector< pair<int,int> > edgeList;
	edgeList.push_back(make_pair(0, 1));
	edgeList.push_back(make_pair(0, 2));
	edgeList.push_back(make_pair(1, 3));
	edgeList.push_back(make_pair(2, 3));
	edgeList.push_back(make_pair(3, 4));
	edgeList.push_back(make_pair(4, 5));
	edgeList.push_back(make_pair(4, 6));
	edgeList.push_back(make_pair(5, 7));
	edgeList.push_back(make_pair(6, 7));
	return make_pair(nbNodes, edgeList);
}
	
	void rand_spanning_tree_example() {
	}
	
int main() {
	rand_perm_example();
	rand_parentheses_example();
	rand_tree_example();
	return 0;
}
