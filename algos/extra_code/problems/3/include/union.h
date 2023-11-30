#pragma once
#include "common.h"

template <class T, size_t N> class WeightedUnion {
public:
  WeightedUnion();
  bool isConnected(T, T);
  void Union(T, T);

private:
  std::vector<T> parent, sz;

private:
  T root(T n) {
    while (n != parent[n]) {
        parent[n] = parent[parent[n]];
        n = parent[n];
    }
    return n;
  }
};
