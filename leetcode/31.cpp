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
  void nextPermutation(vector<int> &nums) {
    // [i, last]までをみて、ソートになっていなければその範囲で次を作る
    for (int i = nums.size() - 1; i >= 0; i--) {
      if (is_sorted(nums.begin() + i, nums.end(), greater<int>())) {
        if (i == 0) {
          // 最後まで来てもソート済みであれば終了
          sort(nums.begin(), nums.end());
          return;
        } else {
          continue;
        }
      }

      //   i [i+1, last]は降順
      // 2 4 7 5 3 2
      // 1. 4より大きい最小値を極力右側で探す
      // 2. そのidxとiの値をswap
      // 2 5 7 4 3 2
      // 3. i+1をreverse
      // 2 5 2 3 4 7

      int minidx = i + 1;
      ll min = INF;
      for (int j = i + 1; j < nums.size(); j++) {
        // 同じ値なら後ろの方を優先
        if (nums[j] > nums[i] && nums[j] <= min) {
          min = nums[j];
          minidx = j;
        }
      }
      swap(nums[i], nums[minidx]);
      reverse(nums.begin() + i + 1, nums.end());
      return;
    }
  }
};

int main() {
  Solution s = Solution();
  vector<int> nums{2, 3, 1, 3, 3};
  s.nextPermutation(nums);
  for (auto n : nums) {
    cout << n << ",";
  }
  cout << endl;

  s.nextPermutation(nums);
  for (auto n : nums) {
    cout << n << ",";
  }
  cout << endl;

  s.nextPermutation(nums);
  for (auto n : nums) {
    cout << n << ",";
  }
  cout << endl;

  s.nextPermutation(nums);
  for (auto n : nums) {
    cout << n << ",";
  }
  cout << endl;

  s.nextPermutation(nums);
  for (auto n : nums) {
    cout << n << ",";
  }
  cout << endl;

  s.nextPermutation(nums);
  for (auto n : nums) {
    cout << n << ",";
  }
  cout << endl;

  s.nextPermutation(nums);
  for (auto n : nums) {
    cout << n << ",";
  }
  cout << endl;
}