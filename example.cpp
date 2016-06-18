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

void display_edges(vector< pair<int,int> > edges) {
	for (int i = 0; i < (int)edges.size(); i++) {
		cout << "(" << edges[i].first << ","<< edges[i].second << ") ";
	}
}

void rand_tree_example() {
	cout << "rand_tree_example:" << endl;
	int nbNodes = 6;
	vector< pair<int,int> > edges = rand_tree(nbNodes);
	display_edges(edges);
	cout << endl << endl;
}

/*
  This graph will be used as input for different examples.
  The result is on the form (nbNodes, edgeList).
*/
pair<int, vector< pair<int,int> > > small_graph() {
	int nbNodes = 8;
	vector< pair<int,int> > edges;
	edges.push_back(make_pair(0, 1));
	edges.push_back(make_pair(0, 2));
	edges.push_back(make_pair(1, 3));
	edges.push_back(make_pair(2, 3));
	edges.push_back(make_pair(3, 4));
	edges.push_back(make_pair(4, 5));
	edges.push_back(make_pair(4, 6));
	edges.push_back(make_pair(5, 7));
	edges.push_back(make_pair(6, 7));
	return make_pair(nbNodes, edges);
}
	
void rand_spanning_tree_example() {
	cout << "rand_spanning_tree_example:" << endl;
	pair<int, vector< pair<int,int> > > g = small_graph();
	int nbNodes = g.first;
	vector< pair<int,int> > edges = g.second;
	vector< pair<int,int> > treeEdges = rand_spanning_tree(nbNodes, edges);
	display_edges(treeEdges);
	cout << endl << endl;
}
	
int main() {
	rand_perm_example();
	rand_parentheses_example();
	rand_tree_example();
	rand_spanning_tree_example();
	return 0;
}
