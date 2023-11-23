#include <array>
#include <cstddef>
#include <iostream>
#include <iterator>

template <class T, size_t N> class QuickFind {
public:
  QuickFind();
  bool connected(T, T);
  void unionAdd(T, T);

private:
  T id[N];
};

template <class T, size_t N> QuickFind<T, N>::QuickFind() {
  for (int i = 0; i < static_cast<int>(N); i++) {
    id[i] = i;
  }
}

template <class T, size_t N> bool QuickFind<T, N>::connected(T p, T q) {
  return id[p] == id[q];
}

template <class T, size_t N> void QuickFind<T, N>::unionAdd(T p, T q) {
  T pid = id[p];
  T qid = id[q];

  for (int i = 0; i < static_cast<int>(N); i++) {
    if (id[i] == pid) {
      id[i] = qid;
    }
  }
}

int main() {
    QuickFind<int, 10> find;
    
    find.unionAdd(2, 4);
    bool test = find.connected(2, 4);
    std::cout << test << '\n';
    return 0;
}
