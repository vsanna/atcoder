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
class ResultObject {
 public:
  T result;
  bool err;  // TODO error object
  ResultObject(T result, bool err) {
    this->result = result;
    this->err = err;
  }
};

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
  int kthSmallest(vector<vector<int>> &matrix, int k) {
    int n = matrix.size();
    vector<int> indices = vector<int>(n, 0);

    vector<int> results = vector<int>();
    for (int i = 0; i < k; i++) {
      ll min = INF;
      int minIdx = -1;
      for (int j = 0; j < n; j++) {
        if (indices[j] == n) continue;
        if (matrix[j][indices[j]] < min) {
          min = matrix[j][indices[j]];
          minIdx = j;
        }
      }
      indices[minIdx]++;
      results.push_back(min);
    }

    return results[results.size() - 1];
  }
};

int main() {
  Solution s = Solution();
  vector<vector<int>> tokens1 = vector<vector<int>>{
      vector<int>{1, 5, 9},
      vector<int>{10, 11, 13},
      vector<int>{12, 13, 15},
  };
  cout << s.kthSmallest(tokens1, 8) << endl;
}