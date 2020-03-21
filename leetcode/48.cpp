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
const int IINF = 1e9;
const ll INF = 1e18;
const int MOD = 1e9 + 7;

#define dump(x) cout << #x << " = " << (x) << endl;
#define YES(n) cout << ((n) ? "YES" : "NO") << endl

template <typename T>
void dumpvec(vector<T> vec) {
  for (T cnt : vec) {
    cout << cnt << ", ";
  }
  cout << endl;
}

void chmin(ll &a, ll b) {
  if (a > b) {
    a = b;
  }
}
void chmax(ll &a, ll b) {
  if (a < b) {
    a = b;
  }
}

class Solution {
 public:
  void rotate(vector<vector<int>> &matrix) { rec(matrix, 0); }

  void rec(vector<vector<int>> &matrix, int layer) {
    int maxlayer = (matrix.size() - 1) / 2;

    if (layer > maxlayer) {
      return;
    }

    int scanlen = matrix.size() - (1 + layer * 2);
    dump(scanlen);

    for (int i = 0; i < scanlen; i++) {
      dump(i);
      int tmp = matrix[layer][layer + i];
      matrix[layer][layer + i] = matrix[layer + scanlen - i][layer];
      matrix[layer + scanlen - i][layer] =
          matrix[layer + scanlen][layer + scanlen - i];
      matrix[layer + scanlen][layer + scanlen - i] =
          matrix[layer + i][layer + scanlen];
      matrix[layer + i][layer + scanlen] = tmp;
    }

    rec(matrix, layer + 1);
  }
};

int main() {
  Solution s = Solution();
  vector<vector<int>> matrics{
      vector<int>{1, 2, 3},
      vector<int>{4, 5, 6},
      vector<int>{7, 8, 9},
  };

  // matrics = vector<vector<int>>{
  //     vector<int>{1, 2},
  //     vector<int>{3, 4},
  // };

  for (auto row : matrics) {
    dumpvec(row);
  }

  s.rotate(matrics);

  for (auto row : matrics) {
    dumpvec(row);
  }
}