#include <array>
#include <cstddef>
#include <iostream>

template <typename T, size_t N> class QuickUnion {
public:
  QuickUnion();
  bool isConnected(T, T);
  void QUnion(T, T);

private:
  // Array
  T id[N];

  // Size of the array
  T sz[N];

private:
  // Find root
  T root(T n) {
    while (n != id[n]) {
      /* While not the root value
       * Check if the given value n is equal
       * to the n index
       */

      // Set to the grandfather node to flatten tree
      id[n] = id[id[n]];

      // set n to the value of the next node
      n = id[n];
    }
    return n;
  }
};

// Contructor to build array of size N
template <typename T, size_t N> QuickUnion<T, N>::QuickUnion() {
  for (int i = 0; i < static_cast<int>(N); i++) {
    id[i] = i;
  }
}

// Check if they are connected by comparing the values of root
template <typename T, size_t N> bool QuickUnion<T, N>::isConnected(T p, T q) {
  return root(p) == root(q);
}

// Union function 
template <typename T, size_t N> void QuickUnion<T, N>::QUnion(T p, T q) {
  // Find the roots of both p and q
  T i = root(p);
  T j = root(q);
  
  // if they are equal return [BASE_CASE]
  if (i == j)
    return;
  
  // Weighted union
  if (sz[i] < sz[j]) {
    // Connect the smaller tree to the larger tree
    id[i] = j;
    // increase the sz array (number of objects)
    sz[j] += id[i];
  } else {
    id[j] = i;
    sz[i] += id[j];
  }
}

int main() {
  QuickUnion<int, 20> un;

  un.QUnion(2, 10);
  bool test = un.isConnected(2, 10);

  std::cout << test << '\n';
}
