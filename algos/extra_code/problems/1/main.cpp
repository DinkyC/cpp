#include <cstddef>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>

template <typename T> using tupel_list = std::vector<std::tuple<T, T, T>>;

template <class T, size_t N> class Solution {
public:
  T firstTimeStamp();
  void Union(T, T);
  void AddTuple(T, T, T);
  bool isConnected(T, T);
  bool allConnected();
  Solution() {
    std::fill(std::begin(sz), std::end(sz), T());
    for (int i = 0; i < static_cast<int>(N); ++i) {
      parent[i] = i;
    }
  }

private:
  tupel_list<T> id;
  T sz[N];
  T parent[N];

private:
  T root(T n) {
    while (n != parent[n]) {
      parent[n] = parent[parent[n]];
      n = parent[n];
    }
    return n;
  }
};

template <class T, size_t N> void Solution<T, N>::AddTuple(T a, T b, T c) {
  id.push_back(std::make_tuple(a, b, c));
}

template <class T, size_t N> bool Solution<T, N>::isConnected(T a, T b) {
  return root(a) == root(b);
}

template <class T, size_t N> bool Solution<T, N>::allConnected() {
  T firstRoot = root(parent[0]);
  for (int i = 1; i < static_cast<int>(N); ++i) {
    if (root(parent[i]) != firstRoot) {
      return false;
    }
  }
  return true;
}

template <class T, size_t N> void Solution<T, N>::Union(T p, T q) {
  T i = root(p);
  T j = root(q);

  if (i == j) {
    return;
  }

  if (sz[i] < sz[j]) {
    parent[i] = j;
    sz[j] += parent[i];
  } else {
    parent[j] = i;
    sz[i] += parent[j];
  }
}

template <class T, size_t N> T Solution<T, N>::firstTimeStamp() {
  for (auto &i : id) {
    T p = std::get<1>(i);
    T q = std::get<2>(i);
    if (!isConnected(p, q)) {
      Solution<T, N>::Union(p, q);
      if (allConnected()) {
        return std::get<0>(i);
      }
    }
  }
  return 0;
}

int main() {
  Solution<int, 5> sol;
  sol.AddTuple(170000, 0, 2);
  sol.AddTuple(170001, 0, 3);
  sol.AddTuple(170002, 2, 1);
  sol.AddTuple(170004, 3, 1);
  sol.AddTuple(170008, 4, 1);

  int result = sol.firstTimeStamp();
  std::cout << result << '\n';
  return 0;
}
