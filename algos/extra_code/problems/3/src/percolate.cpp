#include "../include/percolate.h"

template <class T, size_t N, size_t S> Percolation<T, N, S>::Percolation() {
  size = 0;
  // build n x n grid
  for (T i = 0; i < N; i++) {
    for (T j = 0; j < S; j++) {
      // initilize all spaces to be closed, i.e. 0
      grid[i][j] = 1;
    }
  }
}

// opens the site (row, col) if it is not open already
template <class T, size_t N, size_t S>
void Percolation<T, N, S>::Open(T row, T col) {
    if (grid[row][col] == 0) {
       return; 
    }
    grid[row][col] = 0;

    int p = Index(row, col);
    int q = Index(row, col);

    if (!weighted.isConnected(p, q+1)) {
        weighted.Union(p, q+1);
    }

    if (!weighted.isConnected(p, q-1)) {
        weighted.Union(p, q-1);
    }

    if (!weighted.isConnected(p+1, q)) {
        weighted.Union(p+1, q);
    }

    if (!weighted.isConnected(p-1, q)) {
        weighted.Union(p-1, q);
    }

    size++;
}

// is the site (row, col) open?
template <class T, size_t N, size_t S>
bool Percolation<T, N, S>::isOpen(T row, T col) {
    switch (grid[row][col]) {
        case 0:
            return true;
        case 1:
            return false;
    }
}

// is the site (row, col) full?
template <class T, size_t N, size_t S>
bool Percolation<T, N, S>::isFull(T row, T col) {
   switch (grid[row][col]) {
        case 0:
            return false;
        case 1:
            return true;
   } 
}

// returns the number of open sites
template <class T, size_t N, size_t S>
T Percolation<T, N, S>::numberOfOpenSites() {
    return size;
}

// calculate index value from row and column
template<class T, size_t N, size_t S>
T Percolation<T, N, S>::Index(T row, T col) {
    int n = static_cast<int>(S);
    return row * n + col - (n - 1);
}

// does the system percolate?
template <class T, size_t N, size_t S>
bool Percolation<T, N, S>::percolates() {
    int col = static_cast<int>(S);
    int row = static_cast<int>(N);

    // Check if any site in the top row is connected to any site in the bottom row
    for (int j = 0; j < col; j++) {
        int topSite = Index(0, j);
        int bottomSite = Index(row - 1, j);

        if (weighted.isConnected(topSite, bottomSite)) {
            return true;
        }
    }

    // If no connection is found, return false
    return false;
}

