#ifndef COMBINATORIAL_GENERATORS_H
#define COMBINATORIAL_GENERATORS_H

#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <numeric>
#include <string>

/*
  Return an integer uniformly drawn from range [mini,maxi]
*/
int rand_int(int mini, int maxi) {
	return rand() % (maxi - mini + 1) + mini;
}


/*
  Return the result of std::random_shuffle on the input vector (which
  is given by value)
*/
template<typename T>
std::vector<T> rand_perm(std::vector<T> v) {
	std::random_shuffle(v.begin(), v.end());
	return v;
}


/*
  Return a vector of length 2*nbPairs, where each integer in [0,nbPairs) appears
  twice, defining a balanced list of parentheses uniformly drawn.
*/
std::vector<int> rand_parentheses(int nbPairs) {
	// we use the cyclic lemma
	std::vector<int> signs = std::vector<int>(nbPairs, 1);
	std::vector<int> minus(nbPairs + 1, -1);
	signs.insert(signs.end(), minus.begin(), minus.end());
	std::random_shuffle(signs.begin(), signs.end());

	std::vector<int> cum(2 * nbPairs + 1);
	std::partial_sum(signs.begin(), signs.end(), cum.begin());
	int iMin = min_element(cum.begin(), cum.end()) - cum.begin();
	std::rotate(signs.begin(), signs.begin() + iMin + 1, signs.end());
	signs.pop_back();

	std::vector<int> res;
	std::vector<int> idStack;
	int cur = 0;
	for (int i = 0; i < 2 * nbPairs; i++) {
		if (signs[i] == 1) {
			idStack.push_back(cur);
			cur++;
			res.push_back(idStack.back());
		} else {
			res.push_back(idStack.back());
			idStack.pop_back();
		}
	}
	return res;
}


/*
  Rand uniformly a spanning tree of the complete graph on vertex
  set {0,1,..,n-1}. The result is given as a list of edges.
*/
std::vector< std::pair<int,int> > rand_tree(int nbNodes) {
	// we use Prufer encoding
	std::vector<int> pruferCode;
	for(int i = 0; i < nbNodes - 2; i++) {
		pruferCode.push_back(rand_int(0, nbNodes - 1));
	}
	pruferCode.push_back(nbNodes - 1);

	std::vector< std::pair<int,int> > resEdges;
	std::vector<int> nbChildren(nbNodes, 0);
	for(int i = 0; i < nbNodes - 1; i++) {
		nbChildren[pruferCode[i]]++;
	}
	int posInCode = 0;
	for(int idNode = 0; idNode < nbNodes - 1; idNode++) {
		int idCur = idNode;
		while(idCur <= idNode && nbChildren[idCur] == 0) {
			int idFather = pruferCode[posInCode];
			posInCode++;
			resEdges.push_back(std::make_pair(idCur, idFather));
			nbChildren[idFather]--;
			idCur = idFather;
		}
	}
	return resEdges;
}


#endif /* COMBINATORIAL_GENERATORS_H */
