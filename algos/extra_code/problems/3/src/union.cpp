#include "../include/union.h"

template <class T, size_t N> WeightedUnion<T, N>::WeightedUnion() {    
    std::fill(sz.begin(), sz.end(), T());
    int len = static_cast<int>(N);
    for (int i = 0; i < len; i++) {
       parent[i] = i; 
    }
}

template<class T, size_t N> bool WeightedUnion<T, N>::isConnected(T p, T q){
    return root(p) == root(q);
}

template<class T, size_t N> void WeightedUnion<T, N>::Union(T p, T q) {
   T i = root(p);
   T e = root(q);
   
   if (sz[i] < sz[e]) {
       parent[i] = e;
       sz[e] += parent[i];
   } else {
       parent[e] = i;
       sz[i] += parent[e];
   }
} 
