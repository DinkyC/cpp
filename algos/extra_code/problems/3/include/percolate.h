#pragma once
#include "union.h"

template <class T, size_t N, size_t S> class Percolation {
public:
  Percolation();
  void Open(T, T);
  bool isOpen(T, T);
  bool isFull(T, T);
  T numberOfOpenSites();
  bool percolates();
  T Index(T, T);

private:
  WeightedUnion<T, N*S> weighted;
  T grid[N][S];
  T size;
};
