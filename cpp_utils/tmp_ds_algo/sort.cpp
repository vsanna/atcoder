#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;
const ll INF = numeric_limits<ll>::max();
const int MOD = 1000000007;

/*
- */

// find min from unsorted part
// O(N**2)
template <typename T>
void selectSort(vector<T>& original) {
  // [0,i) is sorted = [i, len-1] is unsorted
  for (int i = 0; i < original.size(); i++) {
    T min = INF;
    ll minIdx = -1;
    // compare n times
    for (int j = i; j < original.size(); j++) {
      if (min > original[j]) {
        min = original[j];
        minIdx = j;
      }
    }
    cout << "min:" << min << endl;
    if (minIdx >= 0) {
      swap(original[i], original[minIdx]);
    }
  }
}

// 底(右)から初めて軽いものを上(左)へ
template <typename T>
void bubbleSort(vector<T>& original) {
  // [0,i) is sorted = [i, len-1] is unsorted
  for (int i = 0; i < original.size(); i++) {
    // compare n-1 times
    for (int j = original.size() - 1; j >= i + 1; j--) {
      if (original[j - 1] > original[j]) {
        swap(original[j - 1], original[j]);
      }
    }
  }
}

int main() {
  // 10, -2, 4, 23, -12, 0, -34, 13, 243, 345, 93, -13, -34: -34
  // -34, -2, 4, 23, -12, 0, -34, 13, 243, 345, 93, -13, 10: -34
  // -34, -34, 4, 23, -12, 0, -2, 13, 243, 345, 93, -13, 10: -13
  // -34, -34, -13, 23, -12, 0, -2, 13, 243, 345, 93, 4, 10: -12
  // -34, -34, -13, -12, 23, 0, -2, 13, 243, 345, 93, 4, 10: -2
  // -34, -34, -13, -12, -2, 0, 23, 13, 243, 345, 93, 4, 10:

  // -34, -34, -13, -12, -1, 0, 23, 13, 243, 345, 93, 4, 10
  // -34, -34, -13, -12, 23, 0, -2, 13, 243, 345, 93, 4, 10
  // -34, -34, -13, -12, 23, 0, -2, 13, 243, 345, 93, 4, 10
  vector<int> arr = {10, -2, 4, 23, -12, 0, -34, 13, 243, 345, 93, -13, -34};
  selectSort(arr);
  for (auto val : arr) {
    cout << val << endl;
  }
}