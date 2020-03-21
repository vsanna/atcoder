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

// 観察系. 法則がわかればかんたん
class Solution {
 public:
  int minCostToMoveChips(vector<int> &chips) {
    // 全チップをeven/oddで足し合わせ、少ない方を他方に移動させる
    int odd = 0;
    int even = 0;

    for (int i = 0; i < chips.size(); i++) {
      if (chips[i] % 2 == 0) {
        odd++;
      } else {
        even++;
      }
    }

    return odd < even ? odd : even;
  }
};

int main() {
  Solution s = Solution();
  vector<int> chips = vector<int>{1, 2, 3};
  cout << s.minCostToMoveChips(chips) << endl;
  chips = vector<int>{2, 2, 2, 3, 3};
  cout << s.minCostToMoveChips(chips) << endl;
}