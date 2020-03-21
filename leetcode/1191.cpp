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
  int kConcatenationMaxSum(vector<int> &arr, int k) {
    ll maxSubSum;
    vector<ll> arr2;
    arr2.insert(arr2.end(), arr.begin(), arr.end());
    if (k > 1) {
      // NOTE: vectorのconcat
      arr2.insert(arr2.end(), arr.begin(), arr.end());
    }
    vector<ll> sums = vector<ll>(arr2.size(), 0);
    sums[0] = arr2[0];
    ll min = 0;
    maxSubSum = arr2[0];

    for (int i = 1; i < arr2.size(); i++) {
      sums[i] = (sums[i - 1] + arr2[i]) % MOD;
      sums[i] = sums[i] % MOD;
      chmin(min, sums[i]);
      chmax(maxSubSum, (sums[i] - min));
    }

    if (k < 3 || sums[arr2.size() - 1] <= 0) {
      return maxSubSum;
    }

    // sum > 0 && k >= 3の場合は
    // maxSubSumFromTail + sum(arr) * (k-2) + maxSubSumFromHead
    ll sum = 0;
    ll maxSubSumFromHead = 0;
    for (int i = 0; i < arr.size(); i++) {
      sum += arr[i];
      sum = sum % MOD;
      chmax(maxSubSumFromHead, sum);
    }

    sum = 0;
    ll maxSubSumFromTail = 0;
    for (int i = arr.size() - 1; i >= 0; i--) {
      sum += arr[i];
      sum = sum % MOD;
      chmax(maxSubSumFromTail, sum);
    }
    maxSubSum = sum * (k - 2) % MOD;
    maxSubSum = (maxSubSum + maxSubSumFromHead) % MOD;
    maxSubSum = (maxSubSum + maxSubSumFromTail) % MOD;

    return maxSubSum;
  }
};

int main() {
  Solution s = Solution();
  vector<int> nums = vector<int>{1, 2};
  cout << s.kConcatenationMaxSum(nums, 3) << endl;
  nums = vector<int>{-5, -2, 0, 0, 3, 9, -2, -5, 4};
  cout << s.kConcatenationMaxSum(nums, 5) << endl;
  cout << s.kConcatenationMaxSum(nums, 1) << endl;
  nums = vector<int>{-1, -2};
  cout << s.kConcatenationMaxSum(nums, 5) << endl;
  cout << s.kConcatenationMaxSum(nums, 1) << endl;
  nums = vector<int>{1, 2};
  cout << s.kConcatenationMaxSum(nums, 1) << endl;
}