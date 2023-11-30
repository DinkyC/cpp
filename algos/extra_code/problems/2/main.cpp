#include <algorithm>
#include <cstddef>
#include <iostream>

template <class T, size_t N> class Solution {
public:
  Solution();
  bool isConnected(T, T);
  void Union(T, T);
  T Find(T);

private:
  T id[N];
  T sz[N];

private:
  T root(T n) {
    while (n != id[n]) {
      id[n] = id[id[n]];
      n = id[n];
    }
    return n;
  }
};

template <class T, size_t N> Solution<T, N>::Solution() {
  std::fill(sz.begin(), sz.end(), T());
  for (int i = 0; i < static_cast<int>(N); i++) {
    id[i] = i;
  }
};

template <class T, size_t N> bool Solution<T, N>::isConnected(T a, T b) {
  return root(a) == root(b);
};

template<class T, size_t N> void Solution<T, N>::Union(T p, T q) {
    T i = root(p);
    T j = root(q);

    if (sz[i] < sz[j]) {
        id[i] = j;
        sz[j] += id[i];    
    } else {
        id[j] = i;
        sz[i] += id[j];
    }
};

int main() { return 0; }
