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
  int rob(vector<int> &nums) {
    vector<vector<int>> dp = vector<vector<int>>(nums.size(), vector<int>(nums.size(), -1)); 
    if(nums.size() == 0) {return 0;}
    if(nums.size() == 1) {return nums[0];}
    ll ansForWithoutHead = rec(dp, nums, 1, nums.size()-1);
    ll ansForWithoutTail = rec(dp, nums, 0, nums.size()-2);
    return (ansForWithoutHead > ansForWithoutTail ? ansForWithoutHead : ansForWithoutTail);
  }

  int rec(vector<vector<int>> &dp, vector<int> &houses, int low, int high) {
    // cout << "low: " << low << ", high: " << high << endl;
    if (low > high) {
      return 0;
    }
    if (low == high) {
      return houses[low];
    }
    if (low + 1 == high) {
      return max(houses[low], houses[high]);
    }
    // NOTE: 0が最適解のこともある
    if(dp[low][high] >= 0) {
      return dp[low][high];
    }

    ll maxSum = -INF;
    for (int i = low; i <= high; i++) {
      chmax(maxSum, rec(dp, houses, low, i - 2) + rec(dp, houses, i + 2, high) +
                        houses[i]);
    }

    dp[low][high] = maxSum;
    // cout << "dp = " << maxSum << endl;

    return maxSum;
  }
};

int main() {
  Solution s = Solution();
  vector<int> nums1 = vector<int>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  vector<int> nums2 = vector<int>{1,2,3,1};
  vector<int> nums3 = vector<int>{1};
  vector<int> nums4 = vector<int>{};
  cout << s.rob(nums1) << endl;
  cout << s.rob(nums2) << endl;
  cout << s.rob(nums3) << endl;
  cout << s.rob(nums4) << endl;
}