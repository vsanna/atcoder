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

ll gcd(ll a, ll b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

class Solution {
 public:
  bool checkSubarraySum(vector<int> &nums, int k) { return normal(nums, k); }

  bool normal(vector<int> &nums, int k) {
    if (nums.size() < 2) {
      return false;
    }

    if (k == 0) {
      for (int i = 1; i < nums.size(); i++) {
        if (nums[i] + nums[i - 1] == 0) return true;
      }
      return false;
    }

    for (int i = 1; i < nums.size(); i++) {
      ll remainder = nums[i];
      for (int j = i - 1; j >= 0; j--) {
        remainder = (remainder + nums[j]) % k;
        if (remainder == 0) {
          return true;
        }
      }
    }

    return false;
  }

  bool dp(vector<int> &nums, int k) {
    if (nums.size() < 2) {
      return false;
    }

    // 0の倍数 = 0 * N = 0のみ
    // 0「は」すべての数の倍数
    if (k == 0) {
      for (int i = 1; i < nums.size(); i++) {
        if (nums[i] + nums[i - 1] == 0) return true;
      }
      return false;
    }

    if (k < 0) {
      k = k * -1;
    }

    // i以前の要素をp個連続して選んだ際のあまりの分類
    vector<vector<int>> dp =
        vector<vector<int>>(nums.size(), vector<int>(k, 0));

    for (int i = 0; i < nums.size(); i++) {
      if (i > 0) {
        for (int j = 0; j < k; j++) {
          if (dp[i - 1][j] > 0) {
            dp[i][((j + nums[i]) % k)] = dp[i - 1][j] + 1;
          }
        }
        // 更新できていない場合はi番目の要素のみの配列を考えて1
        if (dp[i][nums[i] % k] == 0) {
          dp[i][nums[i] % k] = 1;
        }
      } else {
        dp[i][nums[i] % k] = 1;
      }
    }

    for (int i = 1; i < nums.size(); i++) {
      if (dp[i][0] > 1) return true;
    }

    return false;
  }
};

int main() {
  Solution s = Solution();
  vector<int> nums1 = vector<int>{1, 0};

  cout << s.checkSubarraySum(nums1, 100000000) << endl;
}