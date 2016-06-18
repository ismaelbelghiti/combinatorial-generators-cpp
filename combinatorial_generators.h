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
	std::random_shuffle(v.begin(),v.end());
	return v;
}


#endif /* COMBINATORIAL_GENERATORS_H */
