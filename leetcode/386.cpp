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
  vector<int> lexicalOrder(int n) {
    vector<int> result;
    rec(result, 0, n);
    return result;
  }

  void rec(vector<int> &result, int num, int target) {
    // cout << "num:" << num << ", target: " << target << endl;
    for (int i = 0; i <= 9; i++) {
      int candidate = num * 10 + i;
      if (candidate <= target && candidate != 0) {
        result.push_back(candidate);
        rec(result, candidate, target);
      }
    }
  }
};

int main() {
  Solution s = Solution();

  // for (auto n : s.lexicalOrder(5000000)) {
  //   cout << n << endl;
  // }
  // cout << endl;

  // for (auto n : s.lexicalOrder(174)) {
  //   cout << n << endl;
  // }
  // cout << endl;
}