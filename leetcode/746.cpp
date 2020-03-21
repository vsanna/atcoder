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
  int minCostClimbingStairs(vector<int> &cost) {
    vector<int> dp = vector<int>(cost.size() + 1, 0);
    for (int i = 2; i <= cost.size(); i++) {
      dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }
    return dp[cost.size()];
  }
};

int main() {
  Solution s = Solution();
  // vector<int> cost = vector<int>{1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
  // vector<int> cost = vector<int>{10, 15, 20};
  vector<int> cost = vector<int>{10, 15};
  cout << s.minCostClimbingStairs(cost) << endl;
}