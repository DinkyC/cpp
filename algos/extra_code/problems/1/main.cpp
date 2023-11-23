#include <boost/tuple/tuple.hpp>
#include <cstddef>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>

template <typename T> using tupel_list = std::vector<boost::tuple<T, T, T>>;

template <class T, size_t N> class Solution {
public:
  T firstTimeStamp(tupel_list<T>);
  void Union(T, T);

private:
  tupel_list<T> id;
  T sz[N];

private:
  T root(T n) {
    while (n !=
           boost::get<1>(id.at(static_cast<std::vector<int>::size_type>(n)))) {
      n = boost::get<1>(id.at(static_cast<std::vector<int>::size_type>(n)));
    }
    return n;
  }
};

template <class T, size_t N> void Solution<T, N>::Union(T p, T q) {
  T i = root(p);
  T j = root(q);

  if (i == j) {
    return;
  }

  if (sz[i] < sz[j]) {
    boost::get<1>(id.at(static_cast<std::vector<int>::size_type>(i))) = j;
    sz[j] += boost::get<1>(id.at(static_cast<std::vector<int>::size_type>(i)));
  } else {
    boost::get<1>(id.at(static_cast<std::vector<int>::size_type>(j))) = i;
    sz[i] += boost::get<1>(id.at(static_cast<std::vector<int>::size_type>(j)));
  }
}

template <class T, size_t N> T Solution<T, N>::firstTimeStamp(tupel_list<T> n) {
  size_t count = 0;
  for (auto &i : n) {
    T p = boost::get<1>(i);
    T q = boost::get<2>(i);
    if (p != q) {
      Solution<T, N>::Union(p, q);
      count++;
    }
    if (count >= N) {
      return boost::get<0>(i);
    }
  }
  return 0;
}

int main() {
  Solution<int, 4> sol;
  tupel_list<int> test = {
      {170000, 0, 1}, {170001, 1, 2}, {170002, 0, 3}, {170007, 1, 4}};

  sol.firstTimeStamp(test);
  return 0;
}
