#ifndef COMBINATORIAL_GENERATORS_H
#define COMBINATORIAL_GENERATORS_H

#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <numeric>
#include <string>

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



#endif /* COMBINATORIAL_GENERATORS_H */
